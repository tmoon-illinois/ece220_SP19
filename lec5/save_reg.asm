;
	.ORIG	x3000
	;suppose R2 = #4
	AND	R2,R2,#0
	ADD	R2,R2,#4
	;load R1
	AND	R1,R1,#0
	ADD	R1,R1,#1
	;caller-save
	;ST	R2,SaveR2_MAIN	
	ADD	R0,R2,#0
	JSR	PUSH
	;perform negate
	JSR	NEG
	;restore reg
	;LD	R2,SaveR2_MAIN
	JSR	POP
	ADD	R2,R0,#0
	HALT
SaveR2_MAIN	.BLKW	#1
;NEG: R2 = -R1
;IN: R1
;OUT: R2
NEG	
;callee-save
	ADD	R0,R7,#0
	JSR	PUSH
	;ST	R1,SaveR1_NEG
	ADD	R0,R1,#0
	JSR	PUSH
;perform negate
	NOT	R1,R1
	ADD	R2,R1,#1
;restore regs
	;LD	R1,SaveR1_NEG
	JSR	POP
	ADD	R1,R0,#0
	JSR	POP
	ADD	R7,R0,#0
	RET
SaveR1_NEG	.BLKW	#1

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
