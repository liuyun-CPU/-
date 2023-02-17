	.file	"filetest.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "hello world!\0"
.LC1:
	.ascii "a+\0"
.LC2:
	.ascii "test1.txt\0"
.LC3:
	.ascii "create ok\0"
.LC4:
	.ascii "r\0"
.LC5:
	.ascii "read num is %d\15\12\0"
.LC6:
	.ascii "file rw end!\0"
	.text
	.globl	FileRW
	.def	FileRW;	.scl	2;	.type	32;	.endef
	.seh_proc	FileRW
FileRW:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$1088, %rsp
	.seh_stackalloc	1088
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	leaq	.LC0(%rip), %rax
	movq	%rax, 944(%rbp)
	movabsq	$7235421423440394092, %rax
	movq	%rax, 904(%rbp)
	movl	$1818585120, 912(%rbp)
	movw	$28524, 916(%rbp)
	movb	$0, 918(%rbp)
	leaq	.LC1(%rip), %rdx
	leaq	.LC2(%rip), %rcx
	call	fopen
	movq	%rax, 936(%rbp)
	movq	944(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	movl	%eax, 932(%rbp)
	movl	$15, 928(%rbp)
	cmpq	$0, 936(%rbp)
	je	.L2
	leaq	.LC3(%rip), %rcx
	call	puts
	movl	932(%rbp), %eax
	movslq	%eax, %rdx
	movq	936(%rbp), %rcx
	movq	944(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movl	$1, %edx
	movq	%rax, %rcx
	call	fwrite
	movq	936(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
.L2:
	leaq	.LC4(%rip), %rdx
	leaq	.LC2(%rip), %rcx
	call	fopen
	movq	%rax, 936(%rbp)
	cmpq	$0, 936(%rbp)
	je	.L3
	movq	936(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %r9
	movl	$1000, %r8d
	movl	$1, %edx
	movq	%rax, %rcx
	call	fread
	movl	%eax, 924(%rbp)
	movl	924(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC5(%rip), %rcx
	call	printf
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	puts
.L3:
	leaq	.LC6(%rip), %rcx
	call	puts
	movq	936(%rbp), %rax
	movl	$2, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	fseek
	movq	936(%rbp), %rax
	movq	%rax, %rcx
	call	ftell
	movl	%eax, 920(%rbp)
	movl	$1, 956(%rbp)
	jmp	.L4
.L5:
	movl	956(%rbp), %eax
	negl	%eax
	movl	%eax, %edx
	movq	936(%rbp), %rax
	movl	$2, %r8d
	movq	%rax, %rcx
	call	fseek
	movq	936(%rbp), %rax
	movq	%rax, %rcx
	call	getc
	movb	%al, 919(%rbp)
	movsbl	919(%rbp), %eax
	movl	%eax, %ecx
	call	putchar
	addl	$1, 956(%rbp)
.L4:
	movl	956(%rbp), %eax
	cmpl	920(%rbp), %eax
	jle	.L5
	movq	936(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	nop
	addq	$1088, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	FileIO
	.def	FileIO;	.scl	2;	.type	32;	.endef
	.seh_proc	FileIO
FileIO:
	.seh_endprologue
	nop
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	fwrite;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	fread;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	fseek;	.scl	2;	.type	32;	.endef
	.def	ftell;	.scl	2;	.type	32;	.endef
	.def	getc;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
