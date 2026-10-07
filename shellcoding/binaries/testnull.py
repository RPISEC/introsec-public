from pwn import *

context.update(arch='amd64', os='linux')
p = process("./nullbyte")

bytestring = b'\x01\x02\x03\x04\x05\x06\x07\x08\x09\x10' # Changed 0x00 -> 0x06

print(p.readline())
p.sendline(bytestring)
print(p.readline()[:-2])
print(p.readline()[:-2])
