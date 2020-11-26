#include <Arduino.h>
#include "protothreads.h"

pt pt1, pt2;
int i1, i2;

int f1(struct pt* pt) {
  PT_BEGIN(pt);
  i1 = 0;
  while(i1 <= 10) {
    Serial.print("f1: ");
    Serial.println(i1);
    i1++;
    PT_YIELD(pt);
  }
  PT_END(pt);
}

int f2(struct pt* pt) {
  PT_BEGIN(pt);
  i2 = 0;
  while(i2 <= 10) {
    Serial.print("f2: ");
    Serial.println(i2);
    i2++;
    PT_YIELD(pt);
  }
  PT_END(pt);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  PT_SCHEDULE(f1(&pt1));
  PT_SCHEDULE(f2(&pt2));
}
