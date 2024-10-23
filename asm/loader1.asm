	include	"8080.inc"
	org	0x0100
	di
	mvi a,82h
	out 04
	lxi b,0x80
	lxi d,pzu1+1
	lxi h,0x8000
loop1:	ldax d
	mov m,a
	inx d
	inx h
	dcr b
	jnz loop1
	jmp 0x8000

pzu1:	nop
	org 0x8000
	lxi h,0x0000
pzu2:	mov a,l
	out 0x07
	mov a,h
	out 0x05
	in 0x6
	mov m,a
	inx h
	mov a,h
	cpi 0x80
	jnz pzu2
	jmp 0x0000


