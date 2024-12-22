section .text
global _start

_start:
    ; Pass arguments to main() and call it
    mov rdi, [rsp]          ; argc (first argument, number of arguments)
    lea rsi, [rsp+8]        ; argv (second argument, pointer to arguments array)
    lea rdx, [rsi + rdi*8]  ; envp (third argument, pointer to environment variables)

    call main               ; Call main(argc, argv, envp)

    ; Handle return value from main
    mov rdi, rax            ; Set exit status
    mov rax, 60             ; syscall: exit
    syscall

