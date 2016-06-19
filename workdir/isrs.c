#include <system.h> // idt_set_gate, isr0, puts, putchar, regs, outb

#define PIC0_COMMAND_PORT 0x20
#define PIC0_DATA_PORT    0x21
#define PIC1_COMMAND_PORT 0xA0
#define PIC1_DATA_PORT    0xA1
#define PIC_EOI		        0x20

// PIC initialization: http://wiki.osdev.org/PIC#Programming_with_the_8259_PIC
void irq_pic_remap() {
  outb(PIC0_COMMAND_PORT, 0x11);
  outb(PIC1_COMMAND_PORT, 0x11);
  outb(PIC0_DATA_PORT, 0x20); // = 32: interrupt number offset for IRQ0 to IRQ7
  outb(PIC1_DATA_PORT, 0x28); // = 40: interrupt number offset for IRQ8 to IRQ15
  outb(PIC0_DATA_PORT, 0x04);
  outb(PIC1_DATA_PORT, 0x02);
  outb(PIC0_DATA_PORT, 0x01);
  outb(PIC1_DATA_PORT, 0x01);
  outb(PIC0_DATA_PORT, 0x0);
  outb(PIC1_DATA_PORT, 0x0);
}

void isrs_install() {
  irq_pic_remap();
  // TODO: figure out meaning of 0x08 (selector) and 0x8E (flags)
  // TODO: for now, handle only three
  idt_set_gate(0, (uint32_t)isr0, 0x08, 0x8E);
  idt_set_gate(32, (uint32_t)isr32, 0x08, 0x8E);
  idt_set_gate(33, (uint32_t)isr33, 0x08, 0x8E);

}

void isr_main(struct regs *r) {
  // show as ascii (numbers starts from 0d48)
  puts("r->int_no : "); putchar(r->int_no + 48); putchar('\n');

  if (r->int_no < 32) {
    // cpu exception handler

  } else {
    // irq handler: IRQ0 to IRQ 15

    if (40 <= r->int_no && r->int_no < 47) {
      // IRQ8 to IRQ 15
      outb(PIC1_COMMAND_PORT, PIC_EOI);
    }

    outb(PIC0_COMMAND_PORT, PIC_EOI);
  }

  for(;;);
}
