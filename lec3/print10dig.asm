	.ORIG	x3000
	LEA	R3,Binary
	LD	R6,ASCII
	LD	R7,COUNT
AGAIN	ST	R7,CCOUNT
	TRAP	x23
	ADD	R0,R0,R6
	STR	R0,R3,#0
	ADD	R3,R3,#1
	LD	R7,CCOUNT
	ADD	R7,R7,#-1
	BRp	AGAIN
	
ASCII	.FILL	xFFD0
COUNT	.FILL	#10
CCOUNT	.BLKW	#1
Binary	.BLKW	#10
	.END
