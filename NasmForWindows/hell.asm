extern _printf
global _WinMain@16
section .text
_WinMain@16:
push hello
call _printf
add esp, 4
xor eax, eax
ret
section .data
hello db "Hey, bro! Nice ASSembler!", 10, 0