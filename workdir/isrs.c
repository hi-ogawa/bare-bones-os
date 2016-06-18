#include <system.h> // idt_set_gate, isr0, puts, putchar, regs

void isrs_install() {
  idt_set_gate(0, (uint32_t)isr0, 0x08, 0x8E);
}

char *exception_messages[] = {
  "Division By Zero",
  "WTF"
};

void fault_handler(struct regs *r) {
  puts("Exception is handled!\n");
  // show as ascii (numbers starts from 0d48)
  puts("r->int_no : "); putchar(r->int_no + 48); putchar('\n');
  puts("r->err_code: "); putchar(r->err_code + 48); putchar('\n');
  for(;;);
}
