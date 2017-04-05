	.file	"1_measure_time.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"Overhead for reading time: %llu cycles\n"
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
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
#APP
# 6 "1_measure_time.c" 1
	cpuid
# 0 "" 2
# 7 "1_measure_time.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -28(%rbp)
	movl	%edx, -32(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, %edx
	movl	-32(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -24(%rbp)
#APP
# 9 "1_measure_time.c" 1
	cpuid
# 0 "" 2
# 11 "1_measure_time.c" 1
	rdtscp
# 0 "" 2
#NO_APP
	movl	%eax, -28(%rbp)
	movl	%edx, -32(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, %edx
	movl	-32(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -8(%rbp)
#APP
# 14 "1_measure_time.c" 1
	rdtscp
# 0 "" 2
#NO_APP
	movl	%eax, -28(%rbp)
	movl	%edx, -32(%rbp)
#APP
# 15 "1_measure_time.c" 1
	cpuid
# 0 "" 2
#NO_APP
	movl	-28(%rbp), %eax
	movl	%eax, %edx
	movl	-32(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-24(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
