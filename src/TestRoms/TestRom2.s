; sekelton if you want to add on to the tests

; for testing the CRT affect shader
.segment "HEADER"
  ; .byte "NES", $1A      ; iNES header identifier
  .byte $4E, $45, $53, $1A
  .byte 2               ; 2x 16KB PRG code
  .byte 1               ; 1x  8KB CHR data
  .byte $01, $01        ; mapper 0, vertical mirroring
.segment "VECTORS"
  ;; When an NMI happens (once per frame if enabled) the label nmi:
    .addr nmi
    ;; When the processor first turns on or is reset, it will jump to the label reset:
    .addr reset ; reset vector
.segment "STARTUP"
reset:
  jmp test
nmi:
  lda test
  ; jmp test2
  rti
t2:
  lda #32
  lda #11
test:
  lda #64
  beq test2

test2:
  bne test
  rti
.segment "CHARS" ; for graphics
; .incbin  "rom.chr"