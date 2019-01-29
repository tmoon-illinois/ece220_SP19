;
	.ORIG x3000
	;(3+4)+2
	;3
	AND	R0,R0,#0
	ADD	R0,R0,#3
	JSR	PUSH
	;4
	AND	R0,R0,#0
	ADD	R0,R0,#4
	JSR	PUSH
	;+
	JSR	OpADD
	;2
	AND	R0,R0,#0
	ADD	R0,R0,#2
	JSR	PUSH
	;+
	JSR	OpADD

	JSR	POP


	HALT
;operate addition (calling POP and PUSH subroutine)
;IN: data from stack
;OUT: -R5 (status, 0:success, 1:fail)
;     -result in stack
;R0: load/store data for stack
;R1: temp storage
;R7: nested-subroutines
;R6: STACK_TOP pointer
OpAdd
;callee-save
	ST	R0,ADD_SaveR0
	ST	R1,ADD_SaveR1
	ST	R7,ADD_SaveR7
	ST	R6,ADD_SaveR6
;first pop
	JSR	POP
	ADD	R5,R5,#0
	BRp	EXIT
	ADD	R1,R0,#0
;second pop
	JSR	POP
	ADD	R5,R5,#0
	BRp	RESTORE_ADD
;perform addition and push the result
	ADD	R0,R0,R1
	;JSR	CHECK_RANGE
	;ADD	R5,R5,#0
	;BRp	RESTORE_ADD2
	JSR	PUSH
	BRnzp	EXIT
;put back first number
RESTORE_ADD
	LD	R6,STACK_TOP
	ADD	R6,R6,#-1
	ST	R6,STACK_TOP
	BRnzp	EXIT
;put back both numbers
RESTORE_ADD2
	LD	R6,STACK_TOP
	ADD	R6,R6,#-2
	ST	R6,STACK_TOP
	BRnzp	EXIT
;restore registers
EXIT
	LD	R0,ADD_SaveR0
	LD	R1,ADD_SaveR1
	LD	R7,ADD_SaveR7
	LD	R6,ADD_SaveR6
	RET
ADD_SaveR0	.BLKW	#1
ADD_SaveR1	.BLKW	#1
ADD_SaveR7	.BLKW	#1
ADD_SaveR6	.BLKW	#1
;PUSH subroutine
;IN: R0 (value)
;OUT: R5(0-success, 1-fail)
;R3: STACK_END
;R6: STACK_TOP
PUSH
;callee-save & initialize registers
	ST	R3,PUSH_SaveR3	
	ST	R6,PUSH_SaveR6
	AND	R5,R5,#0	
	LD	R3,STACK_END
	LD	R6,STACK_TOP
;overflow?
;Check if STACK_TOP = STACK_END - 1
;Or check if STACK_TOP - (STACK_END - 1) = 0
	ADD	R3,R3,#-1
	NOT	R3,R3
	ADD	R3,R3,#1
	ADD	R3,R3,R6
	BRz	OVERFLOW ;stack is full
;it it NOT overflow
	STR	R0,R6,#0
	ADD	R6,R6,#-1
	ST	R6,STACK_TOP
	BRnzp	DONE_PUSH

;it is overflow
OVERFLOW
	ADD	R5,R5,#1

;restore registers
DONE_PUSH
	LD	R3,PUSH_SaveR3
	LD	R6,PUSH_SaveR6
	RET

;POP subroutine
;IN: none
;OUT: R0 (value)
;OUT: R5 (0: success, 1: fail)
;R3: STACK_START
;R6: STACK_TOP
POP
;callee-save & initialize registers
	ST	R3,POP_SaveR3
	ST	R6,POP_SaveR6
	AND	R5,R5,#0	
	LD	R3,STACK_START
	LD	R6,STACK_TOP
;underflow?
;Check if STACK_TOP = STACK_START
;Or check if STACK_TOP - STACK_START = 0
	NOT	R3,R3
	ADD	R3,R3,#1
	ADD	R3,R3,R6
	BRz	UNDERFLOW ;stack is empty
;it it NOT underflow
	ADD	R6,R6,#1
	LDR	R0,R6,#0
	ST	R6,STACK_TOP
	BRnzp	DONE_POP

;it is underflow
UNDERFLOW
	ADD	R5,R5,#1

;restore registers
DONE_POP
	LD	R3,POP_SaveR3
	LD	R6,POP_SaveR6
	RET


PUSH_SaveR3	.BLKW	#1
PUSH_SaveR6	.BLKW	#1
POP_SaveR3	.BLKW	#1
POP_SaveR6	.BLKW	#1

STACK_START	.FILL	x4000
STACK_END	.FILL	x3FF0
STACK_TOP	.FILL	x4000
	.END
