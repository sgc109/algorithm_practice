.data


.text

.globl main

main:
	li		$v0,	1		# read n
	syscall
	move	$a0,	$v0
	jal		fact			# fact(n)
	move	$a0,	$v0
	li		$v0,	1		# print(fact(n))
	syscall
	li		$v0,	10		# exit(0)
	syscall

fact:
	addi	$1,		$0,		1
	beq		$a0,		$1,		return1		# if(n==1) return 1
continue:
	addi	$29,	$0,		-12
	sw		$30,	8($29)
	sw		$31,	4($29)
	sw		$a0,	0($29)
	addi	$a0,	$0,		-1
	jal		fact
	move	$t1,	$v0
	lw		$t0,	0($29)
	mult	$t0,	$t1
	mflo	$v0
	lw		$31,	4($29)
	lw		$30,	8($29)
	addi	$29,	$0,		12
	jr		$31

return1:
	li		$v0,	1
	jr		$31