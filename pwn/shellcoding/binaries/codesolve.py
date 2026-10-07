from pwn import *

context.update(arch='amd64', os='linux')
p = process("./codeofyourown")

shellcode = asm('''
Your assembly here!''')

p.sendline(shellcode)
