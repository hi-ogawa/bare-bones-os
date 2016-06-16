#include <system.h> // terminal_initialize, puts

void kernel_main() {
  terminal_initialize();
  puts("Hello, kernel World!\nHello, again!");
}
