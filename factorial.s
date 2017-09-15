.data

A:	.word	0
B:	.word	0
msg1:	.asciiz		"Factorial of "
msg2:	.asciiz		" is : "
msg3:	.asciiz		"input your number : "
.text
.globl main

readInt:
	li		$v0,	5
	syscall
	sw		$v0,	0($a0)
	jr		$ra

fact:	
	li		$t0,	0
	li		$t1,	1
	beq		$t0,	$a0,	return
	beq		$t1,	$a0,	return
	
	addi	$sp,	$sp,		-12
	sw		$fp,	4($sp)
	sw		$ra,	8($sp)
	la		$fp,	8($sp)

	sw		$a0,	0($sp)
	addi	$a0,	$a0,	-1
	jal		fact
	lw		$t2,	0($sp)
	mult	$v0,	$t2
	mflo	$v0

	lw		$ra,	8($sp)
	lw		$fp,	4($sp)
	addi	$sp,	$sp,		12

	jr		$ra

return:
	li		$v0,	1
	jr		$ra
	
main:
	la		$a0,	msg3
	li		$v0,	4
	syscall							# print("input your number : ")
	
	la		$a0,	A
	jal		readInt					# A = read_int()
	
	lw		$t6,	A

	la		$a0,	msg1			# print("Factorial of ")
	li		$v0,	4
	syscall
	add		$a0,	$0,		$t6
	li		$v0,	1
	syscall							# print(A)
	la		$a0,	msg2
	li		$v0,	4
	syscall							# print(" is : ")


	add		$a0,	$0,		$t6
	jal		fact 					# calc fact(A)

	add		$a0,	$0,		$v0		# print fact(A)
	li		$v0,	1
	syscall

	li		$v0,	10
	syscall

