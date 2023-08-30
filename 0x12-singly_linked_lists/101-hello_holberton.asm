section .data
    hello db "Hello, Holberton", 10, 0  ; Added 10 for newline character
    format db "%s", 0

section .text
    global main
    extern printf

main:
    sub rsp, 8             ; Align the stack
    mov rdi, format
    mov rsi, hello
    call printf
    add rsp, 8             ; Restore the stack
    ret

