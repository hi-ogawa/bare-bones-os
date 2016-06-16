#include <system.h> // terminal_initialize, terminal_writestring

void kernel_main() {
  terminal_initialize();
  terminal_writestring("Hello, kernel World!\nHello, again!");
}
