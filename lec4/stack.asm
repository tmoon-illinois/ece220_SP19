	.ORIG	x3000
	;User program
	;test push
	AND	R0,R0,#0
	ADD	R0,R0,#1
	JSR	PUSH
	AND	R0,R0,#0
	ADD	R0,R0,#2
	JSR	PUSH
	AND	R0,R0,#0
	ADD	R0,R0,#3
	JSR	PUSH
	;test pop
	JSR	POP
	JSR	POP
	JSR	POP

	HALT
;PUSH subroutine
;IN: R0 (value)
;OUT: R5(0-success, 1-fail)
;R3: STACK_END
;R6: STACK_TOP
PUSH
;callee-save & initialize registers
	ST	R3,PUSH_SaveR3
	ST	R6,PUSH_SaveR6
	LD	R3,STACK_END
	LD	R6,STACK_TOP
	AND	R5,R5,#0

;overflow?
;Check if STACK_TOP = STACK_END - 1
;Or check if STACK_TOP - (STACK_END - 1) = 0
	ADD	R3,R3,#-1
	NOT	R3,R3
	ADD	R3,R3,#1
	ADD	R3,R3,R6
	BRz	OVERFLOW

;it is NOT overflow
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
	LD	R3,STACK_START
	LD	R6,STACK_TOP
	AND	R5,R5,#0
;underflow?
;Check if STACK_TOP = STACK_START
;Or check if STACK_TOP - STACK_START = 0
	NOT	R3,R3
	ADD	R3,R3,#1
	ADD	R3,R3,R6
	BRz	UNDERFLOW

;it is NOT underflow
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

;temp memory
PUSH_SaveR3	.BLKW	#1
PUSH_SaveR6	.BLKW	#1
POP_SaveR3	.BLKW	#1
POP_SaveR6	.BLKW	#1
STACK_END	.FILL	x3FFF
STACK_START	.FILL	x4000	
STACK_TOP	.FILL	x4000	


	.END
