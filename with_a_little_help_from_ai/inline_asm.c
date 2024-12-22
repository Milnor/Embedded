__asm__(
    ".global _start\n"
    "_start:\n"
    "   mov %rdi, (%rsp)\n"          // Load argc from the stack
    "   lea %rsi, 8(%rsp)\n"         // Load argv pointer
    "   lea %rdx, (%rsi, %rdi, 8)\n" // Load envp pointer
    "   call main\n"                 // Call main(argc, argv, envp)
    "   mov %rdi, %rax\n"            // Move return value to rdi for exit
    "   mov $60, %rax\n"             // syscall: exit
    "   syscall\n"
);

int main(int argc, char** argv, char** envp) {
    // Your code here
    return 0;
}

