	.file	"2_ram_band.c"
	.text
	.globl	create_list
	.type	create_list, @function
create_list:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	$0, -24(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	$0, -24(%rbp)
	jmp	.L2
.L3:
	movl	$16, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	addq	$1, -24(%rbp)
.L2:
	movq	-24(%rbp), %rax
	cmpq	-48(%rbp), %rax
	jb	.L3
	movq	-16(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	create_list, .-create_list
	.section	.rodata
.LC0:
	.string	"%d %lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	$0, -44(%rbp)
	movl	$16, %edi
	call	malloc
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	movl	$1000, %esi
	movq	%rax, %rdi
	call	create_list
	movq	$0, -24(%rbp)
#APP
# 52 "2_ram_band.c" 1
	cpuid
# 0 "" 2
# 52 "2_ram_band.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -56(%rbp)
	movl	%edx, -60(%rbp)
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	addl	%eax, -44(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
#APP
# 52 "2_ram_band.c" 1
	rdtscp
# 0 "" 2
#NO_APP
	movl	%eax, -48(%rbp)
	movl	%edx, -52(%rbp)
#APP
# 52 "2_ram_band.c" 1
	cpuid
# 0 "" 2
#NO_APP
	movl	-56(%rbp), %eax
	movl	%eax, %edx
	movl	-60(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -40(%rbp)
	movl	-48(%rbp), %eax
	movl	%eax, %edx
	movl	-52(%rbp), %eax
	movl	%eax, %eax
	salq	$32, %rax
	orq	%rdx, %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %rax
	subq	%rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	testq	%rax, %rax
	js	.L5
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	jmp	.L6
.L5:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L6:
	movl	$4, %esi
	movl	$.LC0, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
