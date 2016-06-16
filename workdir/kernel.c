#include <system.h> // terminal_initialize, puts, gdt_install

void kernel_main() {
  gdt_install();
  terminal_initialize();
  puts("Hello, kernel World!\nHello, again!");
}
