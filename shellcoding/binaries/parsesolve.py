from pwn import *

context.update(arch='amd64', os='linux')
p = process("./byteparser")

shellcode = asm('''
# Your assembly here!
''')

p.interactive()
