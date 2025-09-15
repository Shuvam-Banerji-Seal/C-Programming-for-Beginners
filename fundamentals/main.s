    .intel_syntax noprefix 
    .globl main
    .extern printf     # tells the linker to import the external function printf

main:
    push rbp            #std function prologue
    mov rbp, rsp

    sub rsp, 16

    mov DWORD PTR [rbp-4], 10   #int a =10
    mov eax, DWORD PTR [rbp-4]
    mov esi, eax            # 2nd argument to printf : (integer in ESI)
    lea rdi, [rip+msg]      # 1st argument: address of the format string in rdi
    xor eax, eax            # varargs = 0 ; number of XMM registers used 
    call printf             # printf("Integer: %d\n", a)

    mov eax, 0 #return 0
    leave
    ret

    .section .rodata

msg:
    .string "Integer: %d \n"
