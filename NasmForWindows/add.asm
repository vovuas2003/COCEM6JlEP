extern _printf
extern _scanf
global _WinMain@16
section .text
_WinMain@16:
push y
push x
push vvod
call _scanf
add esp, 12
mov eax, [x]
mov ebx, [y]
add eax, ebx
push eax
push vivod
call _printf
add esp, 8
xor eax, eax
ret
section .data
vvod db "%d %d", 0
vivod db "%d", 10, 0
section .bss
x resd 1
y resd 1