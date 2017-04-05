	.file	"1_measure_loop.c"
	.section	.rodata
	.align 8
.LC1:
	.string	"Overhead for reading time: %llu cycles\n"
	.align 8
.LC3:
	.string	"Overhead for reading time: %.12Lf seconds\n"
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
	subq	$80, %rsp
	movl	%edi, -52(%rbp)
	movq	%rsi, -64(%rbp)
	movl	$0, -36(%rbp)
	fldt	.LC0(%rip)
	fstpt	-16(%rbp)
#APP
# 8 "1_measure_loop.c" 1
	cpuid
# 0 "" 2
# 9 "1_measure_loop.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -40(%rbp)
	movl	%edx, -44(%rbp)
#APP
# 10 "1_measure_loop.c" 1
	cpuid
# 0 "" 2
#NO_APP
	movl	-40(%rbp), %eax
	movl	%eax, %edx
	movl	-44(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -32(%rbp)
	movl	$0, -36(%rbp)
	jmp	.L2
.L3:
	addl	$1, -36(%rbp)
.L2:
	cmpl	$999, -36(%rbp)
	jle	.L3
#APP
# 16 "1_measure_loop.c" 1
	rdtscp
# 0 "" 2
#NO_APP
	movl	%eax, -40(%rbp)
	movl	%edx, -44(%rbp)
#APP
# 17 "1_measure_loop.c" 1
	cpuid
# 0 "" 2
#NO_APP
	movl	-40(%rbp), %eax
	movl	%eax, %edx
	movl	-44(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, -72(%rbp)
	fildq	-72(%rbp)
	testq	%rax, %rax
	jns	.L4
	fldt	.LC2(%rip)
	faddp	%st, %st(1)
.L4:
	fldt	-16(%rbp)
	fdivrp	%st, %st(1)
	leaq	-16(%rsp), %rsp
	fstpt	(%rsp)
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	addq	$16, %rsp
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 16
.LC0:
	.long	0
	.long	2592124150
	.long	16414
	.long	0
	.align 16
.LC2:
	.long	0
	.long	2147483648
	.long	16447
	.long	0
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
