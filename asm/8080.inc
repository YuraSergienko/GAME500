B equ 0
C equ 1
D equ 2
E equ 3
H equ 4
L equ 5
M equ 6
A equ 7
SP equ 7
PSW equ 7

b equ 0
c equ 1
d equ 2
e equ 3
h equ 4
l equ 5
m equ 6
a equ 7
sp equ 7
psw equ 7

condition_nz equ 0
condition_z  equ 1
condition_nc equ 2
condition_c  equ 3
condition_po equ 4
condition_pe equ 5
condition_p  equ 6
condition_m  equ 7

ds equ rb

macro nop {
    db 0 }
macro hlt {
    db 076h }
macro ei {
    db 0FBh }
macro di {
    db 0F3h }
macro mov r1,r2 {
    db 040h + (r1 shl 3) + r2 }
macro mvi r1,imm {
    db (r1 shl 3) + 6,imm } 
macro lxi r1,imm {
    db ((r1 and 6) shl 3) + 1
    dw imm }
macro stax r1 {
    db ((r1 and 2) shl 3) or 2 }        
macro ldax r1 {
    db ((r1 and 2) shl 3) or 10 }   
macro sta imm {  
    db 032h 
    dw imm }
macro lda imm {  
    db 03Ah 
    dw imm }
macro shld imm {  
    db 022h
    dw imm }
macro lhld imm {  
    db 02Ah 
    dw imm }
macro xchg {  
    db 0EBh }
macro push r1 {
    db ((r1 and 6) shl 3) or 0C5h }
macro pop r1 {
    db ((r1 and 6) shl 3) or 0C1h }
macro xthl {  
    db 0E3h }
macro sphl {  
    db 0F9h }
macro inx r1 {
    db ((r1 and 6) shl 3) or 3 }    
macro dcx r1 {
    db ((r1 and 6) shl 3) or 0Bh }    
macro jmp imm {
    db 0C3h
    dw imm }
macro jc imm {
    db 0C2h or (condition_c shl 3)
    dw imm }    
macro jnc imm {
    db 0C2h or (condition_nc shl 3)
    dw imm }    
macro jz imm {
    db 0C2h or (condition_z shl 3)
    dw imm }    
macro jnz imm {
    db 0C2h or (condition_nz shl 3)
    dw imm }    
macro jp imm {
    db 0C2h or (condition_p shl 3)
    dw imm }    
macro jm imm {
    db 0C2h or (condition_m shl 3)
    dw imm }    
macro jpo imm {
    db 0C2h or (condition_po shl 3)
    dw imm }    
macro jpe imm {
    db 0C2h or (condition_pe shl 3)
    dw imm } 
macro pchl {  
    db 0E9h }
macro call imm {
    db 0CDh
    dw imm }
macro cc imm {
    db 0C4h or (condition_c shl 3)
    dw imm }    
macro cnc imm {
    db 0C4h or (condition_nc shl 3)
    dw imm }    
macro cz imm {
    db 0C4h or (condition_z shl 3)
    dw imm }    
macro cnz imm {
    db 0C4h or (condition_nz shl 3)
    dw imm }    
macro cp imm {
    db 0C4h or (condition_p shl 3)
    dw imm }    
macro cm imm {
    db 0C4h or (condition_m shl 3)
    dw imm }    
macro cpo imm {
    db 0C4h or (condition_po shl 3)
    dw imm }    
macro cpe imm {
    db 0C4h or (condition_pe shl 3)
    dw imm } 
macro ret {  
    db 0C9h }
macro rc  {
    db 0c0h or (condition_c shl 3) }    
macro rnc  {
    db 0c0h or (condition_nc shl 3) }    
macro rz  {
    db 0c0h or (condition_z shl 3) }    
macro rnz  {
    db 0c0h or (condition_nz shl 3) }    
macro rp  {
    db 0c0h or (condition_p shl 3)  }    
macro rm  {
    db 0c0h or (condition_m shl 3) }    
macro rpo  {
    db 0c0h or (condition_po shl 3) }    
macro rpe  {
    db 0c0h or (condition_pe shl 3) } 
macro rst imm {
    db 0C7h or (imm shl 3) }
macro inr r1 {
    db (r1 shl 3) or 4 }
macro dcr r1 {
    db (r1 shl 3) or 5 }
macro add r1 {
    db 080h or r1 }
macro adc r1 {
    db 088h or r1 }
macro adi imm {
    db 0C6h,imm }
macro aci imm {
    db 0CEh,imm }
macro sub r1 {
    db 090h or r1 }
macro sbb r1 {
    db 098h or r1 }
macro sui imm {
    db 0D6h,imm }
macro sbi imm {
    db 0DEh,imm }
macro dad r1 {
    db ((r1 and 6) shl 3) or 9 } 
macro ana r1 {
    db 0A0h or r1 }
macro xra r1 {
    db 0A8h or r1 }
macro ora r1 {
    db 0B0h or r1 }
macro cmp r1 {
    db 0B8h or r1 }
macro ani imm {
    db 0E6h,imm }
macro xri imm {
    db 0EEh,imm }
macro ori imm {
    db 0F6h,imm }
macro cpi imm {
    db 0FEh,imm }
macro rlc {
    db 07h }
macro rrc {
    db 0Fh }
macro ral {
    db 17h }
macro rar {
    db 1Fh }
macro cma {
    db 2Fh }
macro stc {
    db 37h }
macro cmc {
    db 3Fh }
macro daa {
    db 27h }
macro in imm {
    db 0DBh,imm }
macro out imm {
    db 0D3h,imm }

DS      equ rb

MACRO NOP {
    DB 0 }
MACRO HLT {
    DB 076H }
MACRO EI {
    DB 0FBH }
MACRO DI {
    DB 0F3H }
MACRO MOV R1,R2 {
    DB 040H + (R1 SHL 3) + R2 }
MACRO MVI R1,IMM {
    DB (R1 SHL 3) + 6,IMM } 
MACRO LXI R1,IMM {
    DB ((R1 AND 6) SHL 3) + 1
    DW IMM }
MACRO STAX R1 {
    DB ((R1 AND 2) SHL 3) OR 2 }        
MACRO LDAX R1 {
    DB ((R1 AND 2) SHL 3) OR 10 }   
MACRO STA IMM {  
    DB 032H 
    DW IMM }
MACRO LDA IMM {  
    DB 03AH 
    DW IMM }
MACRO SHLD IMM {  
    DB 022H
    DW IMM }
MACRO LHLD IMM {  
    DB 02AH 
    DW IMM }
MACRO XCHG {  
    DB 0EBH }
MACRO PUSH R1 {
    DB ((R1 AND 6) SHL 3) OR 0C5H }
MACRO POP R1 {
    DB ((R1 AND 6) SHL 3) OR 0C1H }
MACRO XTHL {  
    DB 0E3H }
MACRO SPHL {  
    DB 0F9H }
MACRO INX R1 {
    DB ((R1 AND 6) SHL 3) OR 3 }    
MACRO DCX R1 {
    DB ((R1 AND 6) SHL 3) OR 0BH }    
MACRO JMP IMM {
    DB 0C3H
    DW IMM }
MACRO JC IMM {
    DB 0C2H OR (condition_c SHL 3)
    DW IMM }    
MACRO JNC IMM {
    DB 0C2H OR (condition_nc SHL 3)
    DW IMM }    
MACRO JZ IMM {
    DB 0C2H OR (condition_z SHL 3)
    DW IMM }    
MACRO JNZ IMM {
    DB 0C2H OR (condition_nz SHL 3)
    DW IMM }    
MACRO JP IMM {
    DB 0C2H OR (condition_p SHL 3)
    DW IMM }    
MACRO JM IMM {
    DB 0C2H OR (condition_m SHL 3)
    DW IMM }    
MACRO JPO IMM {
    DB 0C2H OR (condition_po SHL 3)
    DW IMM }    
MACRO JPE IMM {
    DB 0C2H OR (condition_pe SHL 3)
    DW IMM } 
MACRO PCHL {  
    DB 0E9H }
MACRO CALL IMM {
    DB 0CDH
    DW IMM }
MACRO CC IMM {
    DB 0C4H OR (condition_c SHL 3)
    DW IMM }    
MACRO CNC IMM {
    DB 0C4H OR (condition_nc SHL 3)
    DW IMM }    
MACRO CZ IMM {
    DB 0C4H OR (condition_z SHL 3)
    DW IMM }    
MACRO CNZ IMM {
    DB 0C4H OR (condition_nz SHL 3)
    DW IMM }    
MACRO CP IMM {
    DB 0C4H OR (condition_p SHL 3)
    DW IMM }    
MACRO CM IMM {
    DB 0C4H OR (condition_m SHL 3)
    DW IMM }    
MACRO CPO IMM {
    DB 0C4H OR (condition_po SHL 3)
    DW IMM }    
MACRO CPE IMM {
    DB 0C4H OR (condition_pe SHL 3)
    DW IMM } 
MACRO RET {  
    DB 0C9H }
MACRO RC  {
    DB 0C0H OR (condition_c SHL 3) }    
MACRO RNC  {
    DB 0C0H OR (condition_nc SHL 3) }    
MACRO RZ  {
    DB 0C0H OR (condition_z SHL 3) }    
MACRO RNZ  {
    DB 0C0H OR (condition_nz SHL 3) }    
MACRO RP  {
    DB 0C0H OR (condition_p SHL 3)  }    
MACRO RM  {
    DB 0C0H OR (condition_m SHL 3) }    
MACRO RPO  {
    DB 0C0H OR (condition_po SHL 3) }    
MACRO RPE  {
    DB 0C0H OR (condition_pe SHL 3) } 
MACRO RST IMM {
    DB 0C7H OR (IMM SHL 3) }
MACRO INR R1 {
    DB (R1 SHL 3) OR 4 }
MACRO DCR R1 {
    DB (R1 SHL 3) OR 5 }
MACRO ADD R1 {
    DB 080H OR R1 }
MACRO ADC R1 {
    DB 088H OR R1 }
MACRO ADI IMM {
    DB 0C6H,IMM }
MACRO ACI IMM {
    DB 0CEH,IMM }
MACRO SUB R1 {
    DB 090H OR R1 }
MACRO SBB R1 {
    DB 098H OR R1 }
MACRO SUI IMM {
    DB 0D6H,IMM }
MACRO SBI IMM {
    DB 0DEH,IMM }
MACRO DAD R1 {
    DB ((R1 AND 6) SHL 3) OR 9 } 
MACRO ANA R1 {
    DB 0A0H OR R1 }
MACRO XRA R1 {
    DB 0A8H OR R1 }
MACRO ORA R1 {
    DB 0B0H OR R1 }
MACRO CMP R1 {
    DB 0B8H OR R1 }
MACRO ANI IMM {
    DB 0E6H,IMM }
MACRO XRI IMM {
    DB 0EEH,IMM }
MACRO ORI IMM {
    DB 0F6H,IMM }
MACRO CPI IMM {
    DB 0FEH,IMM }
MACRO RLC {
    DB 07H }
MACRO RRC {
    DB 0FH }
MACRO RAL {
    DB 17H }
MACRO RAR {
    DB 1FH }
MACRO CMA {
    DB 2FH }
MACRO STC {
    DB 37H }
MACRO CMC {
    DB 3FH }
MACRO DAA {
    DB 27H }
MACRO IN IMM {
    DB 0DBH,IMM }
MACRO OUT IMM {
    DB 0D3H,IMM }

;include "win2koi7.inc" ; for russian home-made pc ;) 

macro RKS_START _off {
  if _off eq 
     rks_org = 0
  else
     rks_org = _off
  end if
  dw rks_org   
  dw rks_end_ 
  org rks_org
}  

macro RKS_END {
  rks_end_ = $ - 1
  dw 0
}     
          
macro rks_start _off {
  local _org
  if _off eq 
     rks_org = 0
  else
     rks_org = _off
  end if
  dw rks_org   
  dw rks_end
  org rks_org
}  

macro rks_end {
  rks_end_ = $ - 1
  dw 0
}     
          
