from pwn import *

context.update(arch='amd64', os='linux')
p = process("./noptime")

shellcode = asm('''
Your assembly here!''')

p.sendline(shellcode)
