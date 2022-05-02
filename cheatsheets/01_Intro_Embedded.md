# Notes on **Introduction to Embedded Systems Software and Development Environments**

## Build Process

```mermaid
flowchart TD
    A[Source Files: *.c, *.h] --> B([Preprocessor: gcc])
    B --> C[Preprocessed Files: *.i]
    C --> D([Compiler: gcc])
    D --> E(Assembly: *.s)
    E --> F([Assembler: as])
    F --> G(Object Files: *.o)
    G --> H([Linker: ld])
    H --> I(Relocatable File)
    I --> J([Locator: ld])
    J --> K(Executable)
```

TODO: add slide 14 details with .a library files?

## Tool Checks
* `ll /usr/bin/*gcc`
    - e.g. `... /usr/bin/gcc -> gcc-7` (native compiler)
* ARCH-VENDOR-OS-ABI
    - e.g. `arm-none-eabi-gcc` (cross compiler)
        * Arch = ARM, Vendor = N/A, OS = None (Bare-Metal), ABI = EABI
    - e.g. `arm-linux-gnueabi-gcc` (cross compiler)
        * Arch = ARM, Vendor = N/A, OS = Linux OS, ABI = GNUEABI

## Compiler Flags
### General
* `-c` compile and assemble; do not link
* `-o <FILE>` compile, assemble, and link
* `-g` generate debug info
* `-Wall` all warning messages
* `-Werror` treat warnings as errors
* `-I<DIR>` include DIR to look for header files
* `-ansi` or `-std=STANDARD` specify standard, e.g. c89, c99
* `-v` verbose
### Architecture Specific
* `-mcpu=[NAME]` specify target ARM processor and architecture, e.g. cortex-m0plus
* `-march=[NAME]` target ARM architecture, e.g. armv7-m, thumb
* `-mtune=[NAME]` target ARM processor, e.g. cortex-m0plus
* `-mthumb` generate code in Thumb States (ISA)
* `-marm` generate code in ARM State (ISA)
* `-mthumb-interwork` generate code that supports calling between ARM and Thumb (ISA)
* `-mlittle-endian` little endian mode
* `-mbig-endian` big endian mode

## Preprocessor Directives
* `#define`, `#undef`
* `#ifndef`, `#ifdef`, `#endif`
* `#include`
* `#warning`, `#error`
* `#pragma` - give specific instructions to compiler; ignored if not recognized
    - e.g. `#pragma GCC target ("arch=armv6")
    - e.g. `#pragma GCC poison printf` - disallow using printf
    - e.g. `#pragma once` - a non-portable, non-standard one-liner include guard

## Compile Time Switch
* `-D<MACRO-NAME>`
* `gcc -DMSP_PLATFORM -o main.out main.c`

## Creating Modules
* Implementation files (\*.c)
    - contains function definitions, the actual implementations
* Header files (\*.h)
    - contains function declarations, macros, derived data type definitions
    - the **interface**, should comment the inputs and outputs

## Compiled Libraries
* Static Libraries
    - directly linked into output executable
    - create using archiver
* Shared Libraries
    - pre-installed onto target
    - create with **shared** flag

## Linkers
* combine object files into a single executable
    - object code uses symbols to reference functions/variables
* invoke *indirectly* from compiler (gcc) with no options
* use the `-T` option to specify a **Linker File**
    - LF details how to map compiled data into physical memory regions
* must know **name** and **path** to library to link with it
* `-nostdlib` flag stops automatic linking with standard libraries
* after *locating*, symbols are removed and direct addresses are assigned into the object code

## Executable File Formats
* ELF, executable and linkable format
* COFF, common object file format
* Intel Hex Record
* SREC, Motorola S Record
* AIF, ARM image format

## Linker Flags
### Actual Linker Flags
* `-map [NAME]` outputs memory map from the result of linking
* `-T [NAME]` specifies linker script
* `-o [NAME]` place output in specified filename
* `-O<#>` level of optimization
* `-Os` optimize for memory size
* `-z stacksize=[SIZE]` amount of stack space to reserve
* `-shared` produce a shared library
* `-l[LIB]` link with library
* `-L[DIR]` include library path
* `-Wl,<OPTION>` pass option to linker from compiler
* `-Xlinker <OPTION>` pass option to linker from compiler
### Flags Passed to Linker from Compiler
* `gcc <options...> -Xlinker -Map=main.map`
* `gcc <options...> -Xlinker -T=mk125z_lnk.ld`
* `gcc <options...> -Wl,option`
* `gcc <options...> -Wl,-Map,main.map`
