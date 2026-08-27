# Custom Virtual Machine

A custom virtual machine and assembler built in C++. This project allows users to enter instructions using a custom assembly language, which are parsed and converted into machine-code opcodes before being loaded into virtual memory and executed by the VM.

The project was built to explore low-level programming concepts including instruction set architecture, opcode encoding and decoding, registers, memory, bit manipulation, branching, and the fetch-decode-execute cycle.

## Features

* Custom instruction set architecture
* Custom assembly syntax
* Terminal-based assembly input
* Assembly instructions converted into machine-code opcodes
* Opcode storage in virtual memory
* Register-based architecture
* Fetch-decode-execute cycle
* Arithmetic operations
* Bitwise operations
* Memory load/store operations
* Branching and jump instructions
* Stack support

## How It Works

The program follows this pipeline:

```text
Assembly Input
      ↓
Assembler / Parser
      ↓
Opcode Generation
      ↓
Virtual Memory
      ↓
Fetch → Decode → Execute
```

Users enter assembly instructions through the terminal. The assembler parses each instruction and converts it into a 16-bit opcode based on the VM's custom instruction format.

The generated opcodes are stored in memory and executed by the virtual machine.

## Example

Example input:

```text
LDI R1, 10
LDI R2, 5
ADD R1, R2
end
```

Execution:

```text
R1 = 15
R2 = 5
```

## Instruction Set

| Instruction | Description                                 |
| ----------- | ------------------------------------------- |
| `LDI`       | Load an immediate value into a register     |
| `LDR`       | Load data using a register                  |
| `STR`       | Store a register value into memory          |
| `LD`        | Load data from memory                       |
| `INC`       | Increment a register                        |
| `DEC`       | Decrement a register                        |
| `BEQ`       | Branch if two values/registers are equal    |
| `ADD`       | Add values                                  |
| `SUB`       | Subtract values                             |
| `AND`       | Bitwise AND                                 |
| `OR`        | Bitwise OR                                  |
| `XOR`       | Bitwise XOR                                 |
| `JMP`       | Jump to another instruction/address         |
| `PUSH`      | Push the value of a register onto the stack |
| `RET`       | Return/pop from the stack                   |
| `JSR`       | Jump to subroutine/register-based address   |

> Note: The exact behavior and opcode encoding of each instruction are defined by this project's custom instruction set architecture.

## Opcode Design

Instructions are encoded into a 16-bit opcode.

The VM uses bit shifting and masking to extract portions of each instruction during the decode stage.

Conceptually:

```text
16-bit instruction
┌────┬────┬────┬────┐
│ OP │ X  │ Y  │ IMM│
└────┴────┴────┴────┘
 4b   4b   4b   4b
```

Each 4-bit section can represent information such as:

* Opcode
* Register X
* Register Y
* Immediate value or additional instruction data

The assembler converts the user's assembly instruction into the corresponding bit pattern, while the VM decodes the pattern using bitwise operations.

## Running the Project

Compile and run the C++ program.

Once running, enter assembly instructions one line at a time:

```text
Enter your line of assembly (put end to finish):
```

Example:

```text
LDI R1, 10
LDI R2, 20
ADD R1, R2
end
```

After entering `end`, the program assembles the instructions, loads the resulting opcodes into memory, and begins execution.

## Concepts Explored

This project was created to gain experience with:

* Virtual machine architecture
* Assembly language design
* Instruction set design
* Opcode encoding
* Bit manipulation
* Registers
* Virtual memory
* Stack operations
* Program counters
* Branching and control flow
* Parsing terminal input
* C++ containers and data structures
* The fetch-decode-execute cycle

## Future Improvements

Possible future improvements include:

* Assembly file support
* Labels and symbolic jump locations
* A debugger with step-by-step execution
* Register and memory visualization
* Improved error handling
* Additional instructions
* Expanded stack and subroutine support
* SDL-based graphical interface
* Disassembler support

## Version

**Current Version: v1.0**

This version focuses on implementing a functional custom assembler and virtual machine capable of translating user-entered assembly instructions into machine code and executing them through a custom fetch-decode-execute cycle.
