		include	"8080.inc"
		org 	0x0000
		di
; move flash loader to 0xe000
		mvi c,0xff
		lxi d,begin+1
		lxi h,0xe000
zg1:		ldax d
		mov m,a
		inx d
		inx h
		dcr c
		jnz zg1

;lol1:		jmp lol1
		jmp 0xe000

begin:  	nop
		org 0xe000
	  	lxi sp,0xe800
		mvi a,82h
		out 04
mode2:
; turn MCU from mode 1 to mode2
		mvi a,0x00 ; reset clk pin
		out 0x05
		mvi a,0xaa
		out 0x07
		inx d	; delay
		inx d	; delay
		inx d	; delay
		inx d	; delay
		mvi a,0x55
		out 0x07
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
; send HI_OFFSET (0 - menu programm)
		mvi a,0x00
		out 0x07
; clock
		mvi a,0x10
		out 0x05
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
		mvi a,0x00
		out 0x05
		inx d	; delay	
		inx d	; delay
		inx d	; delay
		inx d	; delay	
; send LO_OFFSET
		mvi a,0x00
		out 0x07
; clock
		mvi a,0x10
		out 0x05
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
		mvi a,0x00
		out 0x05
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay
		lxi h,0x0000
;		lxi b,0x0000
read_file1:
; clock 
		mvi a,0x10
		out 0x05
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
		mvi a,0x00
		out 0x05
; delay before read
		inx d	; delay	
		inx d	; delay
		inx d	; delay
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay
		inx d	; delay
		inx d	; delay
; read byte form file 0
		in 6
		mov m,a
		inx h
		mov a,h
		cpi 0x80
		jnz read_file1
; turn MCU from mode2 to mode1
		mvi a,0x81
		out 0x07
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
; clock 
		mvi a,0x10
		out 0x05
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
		mvi a,0x00
		out 0x05
;
		inx d	; delay	
		inx d	; delay
		inx d	; delay
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay
		inx d	; delay
		inx d	; delay 
		mvi a,0x66
		out 0x07
; clock
		mvi a,0x10
		out 0x05
		inx d	; delay
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay	
		inx d	; delay
		inx d	; delay
		mvi a,0x00
		out 0x05
 		jmp 0x0100
;		insert some nop
DB		0x55, 0xaa


