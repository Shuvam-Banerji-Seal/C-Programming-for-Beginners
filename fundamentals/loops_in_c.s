	.file	"loops_in_c.c"
	.text
	.section	.rodata
.LC0:
	.string	"For Loop:"
.LC1:
	.string	"%d "
	.align 8
.LC2:
	.string	"The loop variable after the loop: %d"
.LC3:
	.string	"While Loop:"
.LC4:
	.string	"Do-While Loop:"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1, -12(%rbp)
	jmp	.L2
.L3:
	movl	-12(%rbp), %eax
	leaq	.LC1(%rip), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -12(%rbp)
.L2:
	cmpl	$5, -12(%rbp)
	jle	.L3
	movl	-12(%rbp), %eax
	leaq	.LC2(%rip), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$10, %edi
	call	putchar@PLT
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1, -8(%rbp)
	jmp	.L4
.L5:
	movl	-8(%rbp), %eax
	leaq	.LC1(%rip), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -8(%rbp)
.L4:
	cmpl	$5, -8(%rbp)
	jle	.L5
	movl	$10, %edi
	call	putchar@PLT
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1, -4(%rbp)
.L6:
	movl	-4(%rbp), %eax
	leaq	.LC1(%rip), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
	cmpl	$5, -4(%rbp)
	jle	.L6
	movl	$10, %edi
	call	putchar@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits
