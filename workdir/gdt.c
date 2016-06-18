#include <stdint.h> // uint?_t
#include <system.h> // gdt_flush

// 64 bit
struct gdt_entry {
  uint16_t limit_low;
  uint16_t base_low;
  uint8_t base_middle;
  uint8_t access;
  uint8_t flags_and_limit_high;
  uint8_t base_high;
} __attribute__((packed));

// 48 bit
struct gdt_ptr {
  uint16_t size;
  uint32_t offset;
} __attribute__((packed));

struct gdt_entry gdt[3];
// `lgdt (gdtp)` will be called in boot.s
struct gdt_ptr gdtp;

void gdt_set_gate(int num,
                  uint32_t base, uint32_t limit,
                  uint8_t access, uint8_t flags) {
  gdt[num].base_low = base & 0xFFFF;
  gdt[num].base_middle = (base >> 16) & 0xFF;
  gdt[num].base_high = (base >> 24) & 0xFF;

  gdt[num].limit_low = limit & 0xFFFF;
  gdt[num].flags_and_limit_high = (limit >> 16) & 0x0F;
  gdt[num].flags_and_limit_high |= (flags << 4) & 0xF0;

  gdt[num].access = access;
}

void gdt_install() {
  gdtp.size = (sizeof(struct gdt_entry) * 3) - 1;
  gdtp.offset = (uint32_t)gdt;

  gdt_set_gate(0, 0, 0, 0, 0);

  // access bit fields:
  //   - 0x9? => Pr = 1 (present)
  //   - 0x?A => Ex = 1 (executable)
  //             RW = 1 (readable)
  //   - 0x?2 => RW = 1 (writable)

  // flags bit fields:
  //   - 0xC => Gr = 1 (4KiB page granuality)
  //            Sz = 1 (32 bit protected mode)
  gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xC);
  gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xC);

  // this is defined in boot.s
  gdt_flush();
}
