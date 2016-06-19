#include <system.h> // putchar

char half_byte_to_hex_char(uint8_t half_byte) {
  switch (half_byte) {
    case 0x0 : return '0';
    case 0x1 : return '1';
    case 0x2 : return '2';
    case 0x3 : return '3';
    case 0x4 : return '4';
    case 0x5 : return '5';
    case 0x6 : return '6';
    case 0x7 : return '7';
    case 0x8 : return '8';
    case 0x9 : return '9';
    case 0xA : return 'A';
    case 0xB : return 'B';
    case 0xC : return 'C';
    case 0xD : return 'D';
    case 0xE : return 'E';
    case 0xF : return 'F';
    default  : return '?';
  }
}

void hexdump(uint32_t *addr, uint32_t size) {
  for (uint32_t i = 0; i < size; i++) {
    for (int j = 0; j < 4; j++) {
      putchar(half_byte_to_hex_char((*(addr + i) >> (j * 8))     & 0xF));
      putchar(half_byte_to_hex_char((*(addr + i) >> (j * 8 + 4)) & 0xF));
      putchar(' ');
    }
    putchar('\n');
  }
}

void hexdump_spec() {
  uint64_t val = 0x123456789ABCDEF;
  hexdump((uint32_t *)&val, 2);
  // should print
  //   FE DC BA 98
  //   76 54 32 10
}
