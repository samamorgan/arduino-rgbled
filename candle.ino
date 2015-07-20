// Pin locations
#define rPin 11
#define gPin 10
#define bPin 9

// Initialize vars
int i,d,last;

void setup(void) {
}

// Main function loop
void loop() {
  i = 127+random(128); // Minimum brightness plus a random number, combined 255
  d = 2+random(8); // Random delay between brightness levels

  // Instead of just setting a value per loop, this smoothly incriments
  // between brightness levels for a more organic look
  if(i > last) {
    for(int x = last; x < i; x++) {
      analogWrite(rPin, 255*x/255);
      analogWrite(gPin, 100*x/255);
      analogWrite(bPin, 10*x/255);
      delay(d);
    }
  }
  else {
    for(int x = last; x > i; x--) {
      analogWrite(rPin, 255*x/255);
      analogWrite(gPin, 100*x/255);
      analogWrite(bPin, 10*x/255);
      delay(d);
    }
  }
  last = i;
}
