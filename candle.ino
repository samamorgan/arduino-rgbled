// Pin locations
#define rPin 11
#define gPin 10
#define bPin 9

// Initialize vars
int i,d,last;

// RGB Color
int R=255,G=100,B=10;
// Brightness ratio, 0.0 to 1.0
float b = 1;
void setup(void) {
}

// Main function loop
void loop() {
  i = 127+random(128); // Minimum intensity plus a random number, combined 255
  d = 2+random(8); // Random delay between brightness levels

  // Instead of just setting a value per loop, this smoothly incriments
  // between brightness levels for a more organic look
  if(i > last) {
    for(int x = last; x < i; x++) {
      analogWrite(rPin, R*b*x/255);
      analogWrite(gPin, G*b*x/255);
      analogWrite(bPin, B*b*x/255);
      delay(d);
    }
  }
  else {
    for(int x = last; x >= i; x--) {
      analogWrite(rPin, R*b*x/255);
      analogWrite(gPin, G*b*x/255);
      analogWrite(bPin, B*b*x/255);
      delay(d);
    }
  }
  last = i;
}
