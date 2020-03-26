#include "Dump.h"

unsigned char memByteRam(const void* x) {return *(char*)x;}
unsigned char memBytePgm(const void* x) {return pgm_read_byte(x);}

void dump(Print& out,void const*at,int sz,unsigned char (*memByte)(const void*)) {
  while(sz>0) {
    out.print("0x");
    out.print((unsigned long)at < 0x10 ? "000" : (unsigned long)at<0x100 ? "00" : (unsigned long)at<0x1000 ? "0" : "");
    out.print((unsigned long)at,HEX);
    out.print(": ");
    for(int c=0;c<16;c++) {
      if (c==8) out.write(' ');
      if (sz-c>0) {
        // Because ISO C forbids `void*` arithmetic, we have to do some funky casting
        void *memAddress = (void *)((int)at + c);
        unsigned char v = memByte(memAddress);

        out.write((v>=32&&v<='z'/*&&v!=0xBF*/)?v:'.');
      } else out.write(' ');
    }
    out.write(' ');
    for (int c=0; c<16 && sz; c++, sz--) {
      // Because ISO C forbids `void*` arithmetic, we have to do some funky casting
      unsigned char v=memByte(at);
      at = (void *)((int)at + 1);

      if (c==8) out.write(' ');
      out.print(v<16?"0":"");
      out.print(v,HEX);
      out.write(' ');
    }
    out.println();
  }
}

void dumpRam(Print& out,void const*at,int sz) {return dump(out,at,sz,memByteRam);}
void dumpPgm(Print& out,void const*at,int sz) {return dump(out,at,sz,memBytePgm);}
