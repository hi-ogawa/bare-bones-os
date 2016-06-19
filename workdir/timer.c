#include <system.h> // outb, puts

#define PIT0_DATA_PORT   0x40
#define PIT_COMMAND_PORT 0x43
#define TIMER_HZ 100

int timer_ticks = 0;

// PIT initialization: http://www.osdever.net/bkerndev/Docs/pit.htm
void init_PIT() {
  outb(PIT_COMMAND_PORT, 0x36);
  outb(PIT0_DATA_PORT, (1193180 / TIMER_HZ) & 0xFF);
  outb(PIT0_DATA_PORT, (1193180 / TIMER_HZ) >> 8);
}

void timer_handler() {
  timer_ticks++;
  if (timer_ticks % TIMER_HZ == 0) {
    puts("one second has passed (roughly)\n");
  }
}
