	.file	"2_measure_arg.c"
	.globl	x
	.data
	.align 4
	.type	x, @object
	.size	x, 4
x:
	.long	1
	.text
	.globl	func0
	.type	func0, @function
func0:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	x(%rip), %eax
	addl	$1, %eax
	movl	%eax, x(%rip)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	func0, .-func0
	.globl	func1
	.type	func1, @function
func1:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	x(%rip), %eax
	addl	$1, %eax
	movl	%eax, x(%rip)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	func1, .-func1
	.globl	func2
	.type	func2, @function
func2:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	x(%rip), %eax
	addl	$1, %eax
	movl	%eax, x(%rip)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	func2, .-func2
	.globl	func3
	.type	func3, @function
func3:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	x(%rip), %eax
	addl	$1, %eax
	movl	%eax, x(%rip)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	func3, .-func3
	.globl	func4
	.type	func4, @function
func4:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	%ecx, -16(%rbp)
	movl	x(%rip), %eax
	addl	$1, %eax
	movl	%eax, x(%rip)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	func4, .-func4
	.globl	func5
	.type	func5, @function
func5:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	%ecx, -16(%rbp)
	movl	%r8d, -20(%rbp)
	movl	x(%rip), %eax
	addl	$1, %eax
	movl	%eax, x(%rip)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	func5, .-func5
	.globl	func6
	.type	func6, @function
func6:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	%ecx, -16(%rbp)
	movl	%r8d, -20(%rbp)
	movl	%r9d, -24(%rbp)
	movl	x(%rip), %eax
	addl	$1, %eax
	movl	%eax, x(%rip)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	func6, .-func6
	.globl	func7
	.type	func7, @function
func7:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	%ecx, -16(%rbp)
	movl	%r8d, -20(%rbp)
	movl	%r9d, -24(%rbp)
	movl	x(%rip), %eax
	addl	$1, %eax
	movl	%eax, x(%rip)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	func7, .-func7
	.section	.rodata
	.align 8
.LC0:
	.string	"Number of cycles 0 arguments: %llu cycles\n"
	.align 8
.LC1:
	.string	"Number of cycles 1 argument: %llu cycles\n"
	.align 8
.LC2:
	.string	"Number of cycles 2 arguments: %llu cycles\n"
	.align 8
.LC3:
	.string	"Number of cycles 3 arguments: %llu cycles\n"
	.align 8
.LC4:
	.string	"Number of cycles 4 arguments: %llu cycles\n"
	.align 8
.LC5:
	.string	"Number of cycles 5 arguments: %llu cycles\n"
	.align 8
.LC6:
	.string	"Number of cycles 6 arguments: %llu cycles\n"
	.align 8
.LC7:
	.string	"Number of cycles 7 arguments: %llu cycles\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movl	$0, -20(%rbp)
	movl	$0, %eax
	call	func0
#APP
# 44 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
# 45 "2_measure_arg.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -16(%rbp)
	movl	$0, %eax
	call	func0
#APP
# 48 "2_measure_arg.c" 1
	rdtscp
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
#APP
# 49 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
#NO_APP
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
#APP
# 53 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
# 54 "2_measure_arg.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -16(%rbp)
	movl	$5, %edi
	call	func1
#APP
# 57 "2_measure_arg.c" 1
	rdtscp
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
#APP
# 58 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
#NO_APP
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
#APP
# 62 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
# 63 "2_measure_arg.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -16(%rbp)
	movl	$10, %esi
	movl	$5, %edi
	call	func2
#APP
# 66 "2_measure_arg.c" 1
	rdtscp
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
#APP
# 67 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
#NO_APP
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
#APP
# 71 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
# 72 "2_measure_arg.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -16(%rbp)
	movl	$15, %edx
	movl	$10, %esi
	movl	$5, %edi
	call	func3
#APP
# 75 "2_measure_arg.c" 1
	rdtscp
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
#APP
# 76 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
#NO_APP
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
#APP
# 80 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
# 81 "2_measure_arg.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -16(%rbp)
	movl	$20, %ecx
	movl	$15, %edx
	movl	$10, %esi
	movl	$5, %edi
	call	func4
#APP
# 84 "2_measure_arg.c" 1
	rdtscp
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
#APP
# 85 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
#NO_APP
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
#APP
# 89 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
# 90 "2_measure_arg.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -16(%rbp)
	movl	$25, %r8d
	movl	$20, %ecx
	movl	$15, %edx
	movl	$10, %esi
	movl	$5, %edi
	call	func5
#APP
# 93 "2_measure_arg.c" 1
	rdtscp
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
#APP
# 94 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
#NO_APP
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
#APP
# 98 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
# 99 "2_measure_arg.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -16(%rbp)
	movl	$30, %r9d
	movl	$25, %r8d
	movl	$20, %ecx
	movl	$15, %edx
	movl	$10, %esi
	movl	$5, %edi
	call	func6
#APP
# 102 "2_measure_arg.c" 1
	rdtscp
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
#APP
# 103 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
#NO_APP
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
#APP
# 107 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
# 108 "2_measure_arg.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -16(%rbp)
	subq	$8, %rsp
	pushq	$35
	movl	$30, %r9d
	movl	$25, %r8d
	movl	$20, %ecx
	movl	$15, %edx
	movl	$10, %esi
	movl	$5, %edi
	call	func7
	addq	$16, %rsp
#APP
# 111 "2_measure_arg.c" 1
	rdtscp
# 0 "" 2
#NO_APP
	movl	%eax, -24(%rbp)
	movl	%edx, -28(%rbp)
#APP
# 112 "2_measure_arg.c" 1
	cpuid
# 0 "" 2
#NO_APP
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
