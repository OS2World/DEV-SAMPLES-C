        NAME    c0
        PAGE    60,132
;[]------------------------------------------------------------[]
;|      C0-OS2.ASM -- Turbo C Start Up Code for OS/2            |
;|                                                              |
;|      Copyright (c) 1988 by Sam Denton                        |
;|      All Rights Reserved.                                    |
;[]------------------------------------------------------------[]

;       Segment and Group declarations

_TEXT   SEGMENT BYTE PUBLIC 'CODE'
_TEXT   ENDS
_DATA   SEGMENT PARA PUBLIC 'DATA'
_DATA   ENDS
_BSS    SEGMENT WORD PUBLIC 'BSS'
os2_parms       dd      ?               ; pointer to actual os/2 cmd line
args            db      128 dup(?)      ; gets parsed copy of arguments
argc            dw      ?               ; C: int
argv            dd      ?               ; C: char **
environ         dd      ?               ; C: char **
_BSS    ENDS
_BSSEND SEGMENT BYTE PUBLIC 'BSSEND'
_BSSEND ENDS
SSEG    SEGMENT STACK 'STACK'
        dw      200 dup(?)
SSEG    ENDS

DGROUP  GROUP   _DATA, _BSS, _BSSEND
        ASSUME  CS:_TEXT, DS:DGROUP

;       External References

        extrn   _main:far
        extrn   _exit:far

        SUBTTL  Start Up Code
        PAGE
;/*                                                     */
;/*-----------------------------------------------------*/
;/*                                                     */
;/*     Start Up Code                                   */
;/*     -------------                                   */
;/*                                                     */
;/*-----------------------------------------------------*/
;/*                                                     */
_TEXT   SEGMENT
STARTX          PROC    NEAR

;       save vital information

                mov     word ptr os2_parms+2,ax ; get environment segment
                mov     word ptr os2_parms+0,bx ; get offset to cmd line

;       parse command line into arguments

                les     di,os2_parms    ; get pointer
                mov     cx,-1           ; no limit for SCASB
                xor     al,al           ; look for end-of-string sentinel
          repne scasb                   ; now pointing past command

        ASSUME  ES:DGROUP, DS:nothing
                mov     ax,ds
                mov     bx,es
                mov     ds,bx
                mov     es,ax
                mov     si,di           ; point to command
                lea     di,args         ; put result in own area
                lea     bp,s_start      ; initalize finite state machine

fsm_driver:     lodsb                   ; check type of next character
                cmp     al,' '          ;
                je      got_white       ;
                cmp     al,9            ;
                je      got_white       ;
                cmp     al,'"'          ;
                je      got_quote       ;
                cmp     al,0            ;
                jne     got_other       ;
got_zero:       add     bp,4            ; point to proper sub-entry in table
got_quote:      add     bp,4            ;
got_white:      add     bp,4            ;
got_other:     ;nop
                mov     bx,cs:0[bp]     ; get action to take
                mov     bp,cs:2[bp]     ; get new state
                call    bx              ; take action
                jmp     fsm_driver      ; do it all over again

;       The following table defines the finite state machine.
;       Each state has entries for each of the four types of characters.
;       Each entry points to an action to take and to a new state.

; character type -->    -----got_other----- ---got_white---- ----got_quote---- --got_zero--
s_start         dw      sto_al,   s_word,   ignore,s_start,  ignore, s_string, finish, 0
s_word          dw      sto_al,   s_word,   sto_0 ,s_start,  sto_0 , s_string, finish, 0
s_string        dw      sto_al,   s_string, sto_al,s_string, ignore, s_pend,   finish, 0
s_pend          dw      sto_0_al, s_word,   sto_0 ,s_start,  sto_al, s_string, finish, 0

sto_0_al:       call    sto_0           ;
sto_al:         stosb                   ;
ignore:         ret                     ;
sto_0:          mov     byte ptr es:[di],0      ;
                inc     di              ;
                ret                     ;
finish:         mov     word ptr es:[di],0      ;
                pop     ax              ; discard return address
                mov     ax,es
                mov     ds,ax
        ASSUME  DS:DGROUP, ES:nothing

;       build array of pointers to arguments

                lea     di,args         ; ES still points to DGROUP
                call    count_em        ; see how many
                inc     dx              ; don't forget command name
                mov     argc,dx
                mov     bp,sp           ; allocate space
                sub     bp,dx
                sub     bp,dx
                sub     bp,dx
                sub     bp,dx
                sub	bp,4            ; additional room for null pointer
                mov	sp,bp
                mov     word ptr argv,bp
                mov     word ptr argv+2,ss
                mov     ax,word ptr os2_parms+2 ; save ofs to cmd
                mov     word ptr [bp+2],ax
                mov     ax,word ptr os2_parms   ; save seg of cmd
                mov     word ptr [bp],ax        
                add     bp,4                    ; advance array index
                dec     dx                      ; reduce counter
                call    point_em

;       build array of pointers to environment strings

                mov     ax,word ptr os2_parms+2
                mov     es,ax
                mov     di,0
                call    count_em        ; see how many
                mov     bp,sp           ; allocate space
                sub     bp,dx
                sub     bp,dx
                sub     bp,dx
                sub     bp,dx
                sub	bp,4            ; additional room for null pointer
                mov	sp,bp
                mov     word ptr environ,bp
                mov     word ptr environ+2,ss
                call    point_em

;       ExitCode = main(argc,argv,envp);

                push    word ptr environ+2
                push    word ptr environ
                push    word ptr argv+2
                push    word ptr argv
                push    argc
                call    _main

;       exit(ExitCode);

                push    ax
                call    _exit

STARTX          ENDP

COUNT_EM        PROC    NEAR

;       Count number of strings in environment (or similar structure)
;       [ES:DI] points to the strings, count returned in DX

                push    di              ; save pointer for others
                xor     ax,ax           ; end-of-string sentinel
                mov     dx,ax           ; initialize counter
count_loop:
                inc     dx              ; count this one
                mov     cx,-1           ; no limit to how big
          repne scasb                   ; look for sentinel
                scasb                   ; two in a row signals end
                jne     count_loop
                pop     di              ; restore pointer for others
                ret

COUNT_EM        ENDP

POINT_EM        PROC    NEAR

;       Builds an array of pointers to environment strings
;       (or any similar structure)
;       [SS:BP] points to the array, [ES:DI] points to the strings,
;       DX contains number of strings

                xor     ax,ax           ; end-of-string sentinel
                jmp     point_save      ; start in mid-loop
point_loop:
                mov     cx,-1           ; no limit to how big
          repne scasb                   ; look for sentinel
point_save:
                mov     word ptr [bp],di        ; save pointer to string
                mov     word ptr [bp+2],es
                add     bp,4                    ; advance array index
                dec     dx                      ; reduce counter
                jnz     point_loop              ; process next string
                mov     word ptr [bp],ax        ; end-of-array sentinel
                mov     word ptr [bp+2],ax
                ret

POINT_EM        ENDP

_TEXT   ENDS
        END     STARTX
