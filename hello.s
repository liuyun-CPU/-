	.file	"hello.c"
	.text
	.globl	s
	.bss
	.align 4
s:
	.space 4
	.globl	s1
	.align 4
s1:
	.space 4
	.comm	lock, 8, 3
	.text
	.globl	myfunc
	.def	myfunc;	.scl	2;	.type	32;	.endef
	.seh_proc	myfunc
myfunc:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	s(%rip), %eax
	addl	$1, %eax
	movl	%eax, s(%rip)
	addl	$1, -4(%rbp)
.L2:
	cmpl	$99999, -4(%rbp)
	jle	.L3
	movl	$0, %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	myfunclock
	.def	myfunclock;	.scl	2;	.type	32;	.endef
	.seh_proc	myfunclock
myfunclock:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	lock(%rip), %rax
	movq	%rax, %rcx
	call	pthread_mutex_lock
	movl	$0, -4(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L6
.L7:
	movl	s1(%rip), %eax
	addl	$1, %eax
	movl	%eax, s1(%rip)
	addl	$1, -4(%rbp)
.L6:
	cmpl	$99999, -4(%rbp)
	jle	.L7
	leaq	lock(%rip), %rax
	movq	%rax, %rcx
	call	pthread_mutex_unlock
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "start!\15\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	leaq	.LC0(%rip), %rcx
	call	puts
	call	FileRW
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	pthread_mutex_lock;	.scl	2;	.type	32;	.endef
	.def	pthread_mutex_unlock;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	FileRW;	.scl	2;	.type	32;	.endef
