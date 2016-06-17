#include <stdint.h> // uint?_t
#include <system.h>

#define IDT_SIZE 256

// 64 bit
struct idt_entry {
  uint16_t base_low;
  uint16_t selector;
  uint8_t always0;
  uint8_t flags;
  uint16_t base_high;
} __attribute__((packed));

// 48 bit
struct idt_ptr {
  uint16_t size;
  uint32_t offset;
}  __attribute__((packed));


struct idt_entry idt[IDT_SIZE];
// `lidt (idtp)` will be called from boot.s
struct idt_ptr idtp;


void idt_set_gate(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags) {
  idt[num].base_low = base & 0x00FF;
  idt[num].base_high = (base >> 16) & 0x00FF;

  idt[num].selector = selector;
  idt[num].always0 = 0x00;
  idt[num].flags = flags;
}

void idt_install() {
  idtp.size = (sizeof (struct idt_entry) * IDT_SIZE) - 1;
  idtp.offset = (uint32_t)idt;

  for (int i = 0; i < IDT_SIZE; i++) {
    idt[i].base_low = 0x0000;
    idt[i].base_high = 0x0000;
    idt[i].selector = 0x0000;
    idt[i].always0 = 0x00;
    idt[i].flags = 0x00;
  }

  // defined in `boot.s`
  idt_load();
}
