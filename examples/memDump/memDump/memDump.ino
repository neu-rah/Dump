#include <Dump.h>

void setup() {
  Serial.begin(115200);
  while(!Serial);
}

void loop() {
  Serial.println("Dump RAM example");
  dumpRam(Serial,0x100,64);
  Serial.println();
  Serial.println("Dump Flash/Progmem example");
  dumpPgm(Serial,0x100,64);
  delay(2000);
}
