# Intel vs. AT&T Syntax Cheatsheet

| Feature                    | Intel Syntax                          | AT&T Syntax                            |
|----------------------------|---------------------------------------|----------------------------------------|
| **Operand Order**          | `dest, src`                          | `src, dest`                           |
| **Instruction Mnemonics**  | Case-insensitive, e.g., `MOV`         | Case-insensitive, e.g., `mov`         |
| **Register Names**         | No prefix, e.g., `eax`, `r8`         | `%` prefix, e.g., `%eax`, `%r8`       |
| **Immediate Values**       | No prefix, e.g., `42`, `0x2A`        | `$` prefix, e.g., `$42`, `$0x2A`      |
| **Memory Operands**        | `[base + offset]`                    | `offset(base)`                        |
| **Segment Overrides**      | `fs:[eax]`                           | `%fs:(%eax)`                          |
| **Dereferencing Registers**| `[eax]`                              | `(%eax)`                              |
| **Instruction Suffixes**   | Optional (determined by operands)    | Required for operand size, e.g., `movl` |
| **Pointer Sizes**          | `BYTE PTR`, `WORD PTR` for size hint | Size suffix in instruction, e.g., `movb` |
| **Hexadecimal Numbers**    | Prefixed with `0x`, e.g., `0x2A`     | Postfixed with `h`, e.g., `2Ah`       |
| **Assembly Directives**    | Begins with `.`, e.g., `.data`       | Same, e.g., `.data`                   |
| **Comments**               | `;` for comments                    | `#` for comments                      |

### Example Comparison

#### Intel Syntax
```asm
mov eax, [ebx+4]
add eax, 42
mov BYTE PTR [edx], al
```

#### AT&T Syntax
```asm
movl 4(%ebx), %eax
addl $42, %eax
movb %al, (%edx)
```

This table and examples should provide a quick reference to the differences in syntax, enabling you to switch between the two with ease. Let me know if you’d like additional examples or clarifications!

