// Pin locations
#define rPin 11
#define gPin 10
#define bPin 9

// Initialize vars
int r,g,b,x;

// Intensity from 1 to 255
float i = 255;

// Speed in ms
int s = 1000;

void setup(void) {
  s=s/i;
  i=(i/2);
}

// Main function loop
void loop(void) {
  x++;

  int wave1 = i*sin(x/i+PI/2)+i;
  int wave2 = -i*sin(x/i+PI/2)+i;
  
  if(x < i*PI) {
    r = wave1;
    g = 0;
    b = wave2;
  }
  else if(x < i*2*PI) {
    r = 0;
    g = wave1;
    b = wave2;
  }
  else if(x < i*3*PI) {
    r = wave2;
    g = wave1;
    b = 0;
  }
  else {
    x=0;
  }
  
  analogWrite(rPin, r);
  analogWrite(gPin, g);
  analogWrite(bPin, b);

  delay(s);
}
