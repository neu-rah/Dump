#include <Dump.h>
#include <Streaming.h>//https://github.com/scottdky/Streaming

void setup() {
  Serial.begin(115200);
  while(!Serial);
}

void loop() {
  Serial<<"Dump RAM example"<<endl;
  dumpRam(Serial,0x100,64);
  Serial<<endl<<"Dump Flash/Progmem example"<<endl;
  dumpPgm(Serial,0x100,64);
  delay(2000);
}
