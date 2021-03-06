#ifndef _CPU_H_
#define _CPU_H_

#define MAX_ADDR 0xff
#define CPU_FLAG 0x00
// cpu struct
typedef struct cpu
{
  unsigned char fl;
  unsigned char pc; // unsigned makes sure value is positive
  unsigned char reg[8]; // registers (array)
  unsigned ram[MAX_ADDR + 1]; // ram (array)nb
} CPU;
// Flags
#define FL_EQ (1<<0)
#define FL_GT (1<<1)
#define FL_LT (1<<2)

//Other general purpose register names
#define SP 7

// memeory locations
#define START_OF_PROGRAM_ADDR 0x00
#define START_OF_STACK_ADDR 0xf4
#define INTERRUPT_MASK 0x00
#define INTERRUPTS 0x00

// ALU operations
enum alu_op
{
  ALU_CMP,
  ALU_ADD,
  ALU_DIV,
  ALU_MOD,
  ALU_MUT,
  ALU_SUB

};

// Instructions

// These use binary literals. If these aren't available with your compiler, hex
// literals should be used.

#define LDI 0b10000010
#define PRN 0b01000111
#define HLT 0b00000001
#define MUT 0b10100010
#define ADD 0b10100000
#define POP 0b01000110
#define PUSH 0b01000101
#define JMP 0b01010100
#define JEQ 0b01010101
#define JNE 0b01010110
#define CMP 0b10100111
// TODO: more instructions here. These can be used in cpu_run().

// Function declarations

extern void cpu_load(struct cpu *cpu, char *filename);
extern void cpu_init(struct cpu *cpu);
extern void cpu_run(struct cpu *cpu);

extern unsigned char cpu_ram_read(struct cpu *cpu, unsigned char address);
extern void cpu_ram_write(struct cpu *cpu, unsigned char address,  unsigned char value);

#endif
