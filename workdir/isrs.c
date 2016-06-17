#include <system.h> // idt_set_gate, isr0, puts

void isrs_install() {
  idt_set_gate(0, (uint32_t)isr0, 0x08, 0x8E);
}

char *exception_messages[] = {
  "Division By Zero",
  "WTF"
};

void fault_handler() {
  puts("Exception is handled!");
}
