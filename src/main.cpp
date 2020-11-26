#include <Arduino.h>
#include "protothreads.h"

/////////////////////////////////////////////////
/// pt1 and pt2 are protothread structures
/// they hold the current state of the running
/// protothread so that when we switch back into
/// them, the instruction we left off on is resumed
/////////////////////////////////////////////////
pt pt1, pt2;

/////////////////////////////////////////////////
/// Because a protothread is a stackless concurrency
/// library, we have to store the states of our running
/// threads local variables separately. i1 and i2 are the loop variables
/// in our f1() and f2() functions. Everytime we yield (PT_YIELD),
/// we are leaving the current scope of that function and everything is lost.
/// This could be improved through the use of pointers, but to keep things simple,
/// we will stick with global instance variables.
/////////////////////////////////////////////////
int i1, i2;

int f1(struct pt* pt) {
  PT_BEGIN(pt); // Marks the beginning of the protothread and executes the macro
  i1 = 0;
  while(i1 <= 10) {
    Serial.print("f1: ");
    Serial.println(i1);
    i1++;
    PT_YIELD(pt); // Yields the current running process to the scheduler
  }
  PT_END(pt); // Marks the end of a protothread and sets the return code
}

int f2(struct pt* pt) {
  PT_BEGIN(pt); // Marks the beginning of the protothread and executes the macro
  i2 = 0;
  while(i2 <= 10) {
    Serial.print("f2: ");
    Serial.println(i2);
    i2++;
    PT_YIELD(pt); // Yields the current running process to the scheduler
  }
  PT_END(pt); // Marks the end of a protothread and sets the return code
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  PT_SCHEDULE(f1(&pt1)); // Schedules function f1() passing in their protothread structures for storing state
  PT_SCHEDULE(f2(&pt2)); // Schedules function f2() passing in their protothread structures for storing state
}
