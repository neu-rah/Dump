#include <Dump.h>

const unsigned char ramTest[]        ="@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@";
const unsigned char pgmTest[] PROGMEM="@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@";

void setup() {
  Serial.begin(115200);
  while(!Serial);
  delay(2000);
}

void loop() {
  Serial.println("Dump RAM example");
  dumpRam(Serial,ramTest,64);
  Serial.println();
  Serial.println("Dump Flash/Progmem example");
  dumpPgm(Serial,pgmTest,64);
  Serial.println();
  delay(2000);
}
