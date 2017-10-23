# Dump

Simple memory dump for AVR RAM and Flash (progmem)

## API

### RAM

```c++
void dumpRam(Print& out,void const*at,int sz)
```
dump ram values to output where:

- **out** : The output device, ex: Serial
- **at** : The memory pointer
- **sz** : The size o memory in bytes

### Flash / PROGMEM
```c++
void dumpPgm(Print& out,void const*at,int sz)
```
dump flash memory values to output where:

- **out** : The output device, ex: Serial
- **at** : The memory pointer
- **sz** : The size o memory in bytes

## Output example

```text
Dump RAM example
0x100: ......e. ......0. 00 00 00 00 E9 00 65 00  B2 00 90 00 A4 00 30 01
0x110: ...=.0.0 x.: .Dum 0D 0A 00 3D 00 30 00 30  78 00 3A 20 00 44 75 6D
0x120: p RAM ex ample.Du 70 20 52 41 4D 20 65 78  61 6D 70 6C 65 00 44 75
0x130: mp Flash /Progmem 6D 70 20 46 6C 61 73 68  2F 50 72 6F 67 6D 65 6D

Dump Flash/Progmem example
0x100: .+...... !....... 89 2B 11 F4 7E 01 02 C0  21 96 EC CF C7 01 DF 91
0x110: ........ ........ CF 91 1F 91 0F 91 FF 90  EF 90 DF 90 CF 90 08 95
0x120: ........ a....... FC 01 91 8D 82 8D 98 17  61 F0 82 8D DF 01 A8 0F
0x130: ..]..... ._.s.... B1 1D 5D 96 8C 91 92 8D  9F 5F 9F 73 92 8F 90 E0
```
