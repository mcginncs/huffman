	.file	"huffman.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"0"
.LC1:
	.string	"01"
.LC2:
	.string	"010"
.LC3:
	.string	"0100"
.LC4:
	.string	"01001"
.LC5:
	.string	"010011"
.LC6:
	.string	"0100110"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB7:
	.text
.LHOTB7:
	.p2align 4,,15
	.globl	encode
	.type	encode, @function
encode:
.LFB60:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movq	%rdi, %r13
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	xorl	%ebp, %ebp
	movq	%rsi, %rbx
	subq	$20536, %rsp
	.cfi_def_cfa_offset 20576
	movq	%fs:40, %rax
	movq	%rax, 20520(%rsp)
	xorl	%eax, %eax
	movb	$0, 32(%rsp)
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L3:
	movsbq	%al, %rax
	leaq	32(%rsp), %rdi
	movl	$20480, %edx
	movq	indexedCodes(,%rax,8), %r12
	movq	%r12, %rsi
	call	__strcat_chk
	movq	%r12, %rdi
	call	strlen
	addl	%eax, %ebp
.L2:
	movq	%r13, %rdi
	call	fgetc
	cmpb	$-1, %al
	jne	.L3
	movq	%rbp, %rax
	andl	$7, %eax
	jmp	*.L6(,%rax,8)
	.section	.rodata
	.align 8
	.align 4
.L6:
	.quad	.L4
	.quad	.L17
	.quad	.L18
	.quad	.L19
	.quad	.L20
	.quad	.L21
	.quad	.L22
	.quad	.L12
	.text
	.p2align 4,,10
	.p2align 3
.L22:
	leaq	32(%rsp), %r12
.L11:
	movl	$20480, %edx
	movl	$.LC1, %esi
	movq	%r12, %rdi
	addl	$2, %ebp
	call	__strcat_chk
.L10:
	movl	$20480, %edx
	movl	$.LC2, %esi
	movq	%r12, %rdi
	addl	$3, %ebp
	call	__strcat_chk
.L9:
	movl	$20480, %edx
	movl	$.LC3, %esi
	movq	%r12, %rdi
	addl	$4, %ebp
	call	__strcat_chk
.L8:
	movl	$20480, %edx
	movl	$.LC4, %esi
	movq	%r12, %rdi
	addl	$5, %ebp
	call	__strcat_chk
.L7:
	movl	$20480, %edx
	movl	$.LC5, %esi
	movq	%r12, %rdi
	addl	$6, %ebp
	call	__strcat_chk
.L5:
	movl	$20480, %edx
	movl	$.LC6, %esi
	movq	%r12, %rdi
	addl	$7, %ebp
	call	__strcat_chk
.L4:
	sarw	$3, %bp
	testw	%bp, %bp
	jle	.L1
	leaq	32(%rsp), %r12
	xorl	%r13d, %r13d
	.p2align 4,,10
	.p2align 3
.L14:
	leal	0(,%r13,8), %esi
	leaq	16(%rsp), %rdi
	movl	$8, %edx
	addl	$1, %r13d
	movslq	%esi, %rsi
	addq	%r12, %rsi
	call	strncpy
	leaq	16(%rsp), %rdi
	xorl	%esi, %esi
	movl	$2, %edx
	movb	$0, 24(%rsp)
	call	strtol
	leaq	15(%rsp), %rdi
	movq	%rbx, %rcx
	movl	$1, %edx
	movl	$1, %esi
	movb	%al, 15(%rsp)
	call	fwrite
	cmpw	%r13w, %bp
	jg	.L14
.L1:
	movq	20520(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L26
	addq	$20536, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L17:
	.cfi_restore_state
	leaq	32(%rsp), %r12
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L18:
	leaq	32(%rsp), %r12
	jmp	.L7
	.p2align 4,,10
	.p2align 3
.L19:
	leaq	32(%rsp), %r12
	jmp	.L8
	.p2align 4,,10
	.p2align 3
.L20:
	leaq	32(%rsp), %r12
	jmp	.L9
	.p2align 4,,10
	.p2align 3
.L21:
	leaq	32(%rsp), %r12
	jmp	.L10
	.p2align 4,,10
	.p2align 3
.L12:
	leaq	32(%rsp), %r12
	movl	$20480, %edx
	movl	$.LC0, %esi
	addl	$1, %ebp
	movq	%r12, %rdi
	call	__strcat_chk
	jmp	.L11
.L26:
	call	__stack_chk_fail
	.cfi_endproc
.LFE60:
	.size	encode, .-encode
	.section	.text.unlikely
.LCOLDE7:
	.text
.LHOTE7:
	.section	.text.unlikely
.LCOLDB8:
	.text
.LHOTB8:
	.p2align 4,,15
	.globl	decode
	.type	decode, @function
decode:
.LFB61:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	xorl	%r12d, %r12d
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdi, %rbx
	movq	%rbx, %rdi
	movq	%rsi, %rbp
	subq	$16376, %rsp
	.cfi_def_cfa_offset 16416
	movq	%fs:40, %rax
	movq	%rax, 16360(%rsp)
	xorl	%eax, %eax
	movb	$0, (%rsp)
	call	fgetc
	cmpb	$-1, %al
	je	.L32
	.p2align 4,,10
	.p2align 3
.L56:
	movsbl	%al, %eax
	movl	%r12d, %esi
	movl	$7, %edx
.L31:
	movl	%edx, %ecx
	movl	%eax, %edi
	movl	%eax, %r8d
	sarl	%cl, %edi
	movl	%edi, %ecx
	movslq	%esi, %rdi
	andl	$1, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	addl	$49, %ecx
	movb	%cl, (%rsp,%rdi)
	leal	-1(%rdx), %ecx
	leal	1(%rsi), %edi
	sarl	%cl, %r8d
	movslq	%edi, %rdi
	movl	%r8d, %ecx
	andl	$1, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	subl	$2, %edx
	addl	$2, %esi
	addl	$49, %ecx
	cmpl	$-1, %edx
	movb	%cl, (%rsp,%rdi)
	jne	.L31
	movq	%rbx, %rdi
	addl	$8, %r12d
	call	fgetc
	cmpb	$-1, %al
	jne	.L56
.L32:
	movslq	%r12d, %r12
	movl	$1, %ecx
	movq	%rsp, %r13
	movb	$0, (%rsp,%r12)
	xorl	%r12d, %r12d
	jmp	.L33
	.p2align 4,,10
	.p2align 3
.L36:
	addl	$1, %ebx
	movslq	%ebx, %rbx
	movzbl	(%rsp,%rbx), %eax
	cmpb	$48, %al
	je	.L57
.L37:
	leal	1(%rcx,%rcx), %edx
	cmpb	$49, %al
	cmove	%edx, %ecx
	movslq	%ecx, %rax
	movsbl	lettersArray(%rax), %edi
	testb	%dil, %dil
	jne	.L58
.L39:
	addl	$2, %r12d
.L33:
	movq	%r13, %rdx
.L40:
	movl	(%rdx), %esi
	addq	$4, %rdx
	leal	-16843009(%rsi), %eax
	notl	%esi
	andl	%esi, %eax
	andl	$-2139062144, %eax
	je	.L40
	movl	%eax, %esi
	shrl	$16, %esi
	testl	$32896, %eax
	cmove	%esi, %eax
	leaq	2(%rdx), %rsi
	movl	%eax, %ebx
	cmove	%rsi, %rdx
	addb	%al, %bl
	movswq	%r12w, %rax
	sbbq	$3, %rdx
	subq	%r13, %rdx
	cmpq	%rdx, %rax
	jnb	.L59
	movswq	%r12w, %rax
	movq	%rax, %rbx
	movzbl	(%rsp,%rax), %eax
	cmpb	$48, %al
	je	.L60
	leal	1(%rcx,%rcx), %edx
	cmpb	$49, %al
	cmove	%edx, %ecx
.L35:
	movslq	%ecx, %rax
	movsbl	lettersArray(%rax), %edi
	testb	%dil, %dil
	je	.L36
	addl	$1, %ebx
	movq	%rbp, %rsi
	movslq	%ebx, %rbx
	call	_IO_putc
	movzbl	(%rsp,%rbx), %eax
	movl	$1, %ecx
	cmpb	$48, %al
	jne	.L37
.L57:
	addl	%ecx, %ecx
	movslq	%ecx, %rax
	movsbl	lettersArray(%rax), %edi
	testb	%dil, %dil
	je	.L39
.L58:
	movq	%rbp, %rsi
	call	_IO_putc
	movl	$1, %ecx
	jmp	.L39
	.p2align 4,,10
	.p2align 3
.L60:
	addl	%ecx, %ecx
	jmp	.L35
	.p2align 4,,10
	.p2align 3
.L59:
	movq	16360(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L61
	addq	$16376, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L61:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE61:
	.size	decode, .-decode
	.section	.text.unlikely
.LCOLDE8:
	.text
.LHOTE8:
	.section	.rodata.str1.1
.LC9:
	.string	"r"
.LC10:
	.string	"book.txt"
.LC11:
	.string	"w"
.LC12:
	.string	"encodedOutput.txt"
.LC13:
	.string	"decodedOutput.txt"
.LC14:
	.string	"Total Time = %d milliseconds\n"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC15:
	.string	"Encoding Time = %d milliseconds\n"
	.align 8
.LC16:
	.string	"Decoding Time = %d milliseconds\n"
	.section	.text.unlikely
.LCOLDB17:
	.section	.text.startup,"ax",@progbits
.LHOTB17:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB62:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	call	clock
	movl	$.LC9, %esi
	movl	$.LC10, %edi
	movq	%rax, %r15
	call	fopen
	movl	$.LC11, %esi
	movl	$.LC12, %edi
	movq	%rax, %r13
	call	fopen
	movq	%rax, %rbp
	call	clock
	movq	%rbp, %rsi
	movq	%r13, %rdi
	movq	%rax, %r14
	call	encode
	call	clock
	movq	%rbp, %rdi
	movq	%rax, %rbx
	call	fclose
	movl	$.LC9, %esi
	movl	$.LC12, %edi
	subl	%r14d, %ebx
	call	fopen
	movl	$.LC11, %esi
	movl	$.LC13, %edi
	movq	%rax, %r12
	call	fopen
	movq	%rax, %rbp
	call	clock
	movq	%rbp, %rsi
	movq	%r12, %rdi
	movq	%rax, (%rsp)
	call	decode
	call	clock
	movq	%r13, %rdi
	movq	%rax, 8(%rsp)
	call	fclose
	movq	%r12, %rdi
	call	fclose
	movq	%rbp, %rdi
	movl	$274877907, %ebp
	call	fclose
	call	clock
	movl	%eax, %ecx
	movl	$.LC14, %esi
	movl	$1, %edi
	subl	%r15d, %ecx
	movl	%ecx, %eax
	sarl	$31, %ecx
	imull	%ebp
	xorl	%eax, %eax
	sarl	$6, %edx
	subl	%ecx, %edx
	call	__printf_chk
	movl	%ebx, %eax
	sarl	$31, %ebx
	movl	$.LC15, %esi
	imull	%ebp
	movl	$1, %edi
	xorl	%eax, %eax
	sarl	$6, %edx
	subl	%ebx, %edx
	call	__printf_chk
	movl	8(%rsp), %ecx
	subl	(%rsp), %ecx
	movl	$.LC16, %esi
	movl	$1, %edi
	movl	%ecx, %eax
	imull	%ebp
	sarl	$31, %ecx
	xorl	%eax, %eax
	sarl	$6, %edx
	subl	%ecx, %edx
	call	__printf_chk
	addq	$24, %rsp
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE62:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE17:
	.section	.text.startup
.LHOTE17:
	.section	.rodata.str1.1
.LC18:
	.string	""
.LC19:
	.string	"0101"
.LC20:
	.string	"111"
.LC21:
	.string	"1100010"
.LC22:
	.string	"1101110"
.LC23:
	.string	"0100011"
.LC24:
	.string	"110110"
.LC25:
	.string	"100011100"
.LC26:
	.string	"100011001"
.LC27:
	.string	"100011000"
.LC28:
	.string	"100011011"
.LC29:
	.string	"100011010"
.LC30:
	.string	"100000101"
.LC31:
	.string	"100000100"
.LC32:
	.string	"100000111"
.LC33:
	.string	"100000110"
.LC34:
	.string	"100000001"
.LC35:
	.string	"01101111"
.LC36:
	.string	"0100010"
.LC37:
	.string	"100000000"
.LC38:
	.string	"110111101"
.LC39:
	.string	"110111100"
.LC40:
	.string	"01001101"
.LC41:
	.string	"100000011"
.LC42:
	.string	"100000010"
.LC43:
	.string	"01001100"
.LC44:
	.string	"00100"
.LC45:
	.string	"100001101"
.LC46:
	.string	"100001100"
.LC47:
	.string	"110001100"
.LC48:
	.string	"100001111"
.LC49:
	.string	"0100111"
.LC50:
	.string	"100011101"
.LC51:
	.string	"100001110"
.LC52:
	.string	"100001001"
.LC53:
	.string	"110001101"
.LC54:
	.string	"0110110"
.LC55:
	.string	"01101110"
.LC56:
	.string	"100001000"
.LC57:
	.string	"100001011"
.LC58:
	.string	"11000111"
.LC59:
	.string	"100001010"
.LC60:
	.string	"10001111"
.LC61:
	.string	"100010101"
.LC62:
	.string	"0011"
.LC63:
	.string	"0100000"
.LC64:
	.string	"0100001"
.LC65:
	.string	"01100"
.LC66:
	.string	"1011"
.LC67:
	.string	"10001001"
.LC68:
	.string	"000100"
.LC69:
	.string	"11010"
.LC70:
	.string	"11001"
.LC71:
	.string	"100010100"
.LC72:
	.string	"011010"
.LC73:
	.string	"10101"
.LC74:
	.string	"10100"
.LC75:
	.string	"0000"
.LC76:
	.string	"1001"
.LC77:
	.string	"100010111"
.LC78:
	.string	"100010110"
.LC79:
	.string	"00011"
.LC80:
	.string	"000101"
.LC81:
	.string	"0111"
.LC82:
	.string	"00101"
.LC83:
	.string	"100010001"
.LC84:
	.string	"110000"
.LC85:
	.string	"11011111"
.LC86:
	.string	"010010"
.LC87:
	.string	"100010000"
	.section	.rodata
	.align 32
	.type	indexedCodes, @object
	.size	indexedCodes, 1024
indexedCodes:
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC19
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC20
	.quad	.LC21
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC22
	.quad	.LC23
	.quad	.LC24
	.quad	.LC18
	.quad	.LC25
	.quad	.LC26
	.quad	.LC27
	.quad	.LC28
	.quad	.LC29
	.quad	.LC30
	.quad	.LC31
	.quad	.LC32
	.quad	.LC33
	.quad	.LC34
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC35
	.quad	.LC18
	.quad	.LC36
	.quad	.LC37
	.quad	.LC38
	.quad	.LC39
	.quad	.LC40
	.quad	.LC41
	.quad	.LC42
	.quad	.LC43
	.quad	.LC44
	.quad	.LC45
	.quad	.LC46
	.quad	.LC47
	.quad	.LC48
	.quad	.LC49
	.quad	.LC50
	.quad	.LC51
	.quad	.LC52
	.quad	.LC53
	.quad	.LC54
	.quad	.LC55
	.quad	.LC56
	.quad	.LC57
	.quad	.LC58
	.quad	.LC59
	.quad	.LC60
	.quad	.LC61
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC62
	.quad	.LC63
	.quad	.LC64
	.quad	.LC65
	.quad	.LC66
	.quad	.LC67
	.quad	.LC68
	.quad	.LC69
	.quad	.LC70
	.quad	.LC71
	.quad	.LC72
	.quad	.LC73
	.quad	.LC74
	.quad	.LC75
	.quad	.LC76
	.quad	.LC77
	.quad	.LC78
	.quad	.LC79
	.quad	.LC80
	.quad	.LC81
	.quad	.LC82
	.quad	.LC83
	.quad	.LC84
	.quad	.LC85
	.quad	.LC86
	.quad	.LC87
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.quad	.LC18
	.align 32
	.type	lettersArray, @object
	.size	lettersArray, 958
lettersArray:
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	32
	.byte	110
	.byte	0
	.byte	0
	.byte	97
	.byte	0
	.byte	10
	.byte	0
	.byte	116
	.byte	0
	.byte	111
	.byte	0
	.byte	101
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	114
	.byte	73
	.byte	117
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	100
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	109
	.byte	108
	.byte	0
	.byte	0
	.byte	0
	.byte	105
	.byte	104
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	103
	.byte	115
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	121
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	107
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	119
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	46
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	98
	.byte	99
	.byte	65
	.byte	45
	.byte	0
	.byte	0
	.byte	0
	.byte	78
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	83
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	33
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	44
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	72
	.byte	69
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	84
	.byte	63
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	102
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	89
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	87
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	120
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	66
	.byte	57
	.byte	71
	.byte	70
	.byte	54
	.byte	53
	.byte	56
	.byte	55
	.byte	85
	.byte	81
	.byte	88
	.byte	86
	.byte	75
	.byte	74
	.byte	80
	.byte	77
	.byte	122
	.byte	118
	.byte	0
	.byte	0
	.byte	106
	.byte	90
	.byte	113
	.byte	112
	.byte	50
	.byte	49
	.byte	52
	.byte	51
	.byte	48
	.byte	79
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	76
	.byte	82
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	68
	.byte	67
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2.1) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
