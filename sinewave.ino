// Cycles through all possible combinations of RGB based on a sine wave per color

// Pin locations
#define rPin 11
#define gPin 10
#define bPin 9

// Initialize vars
int R,G,B,x;

// Brightness from 1 to 255
int l = 255;

// Speed of cycle
int s = 10;
 
void setup(void) {
  l=(l/2);
}

// Main function loop
void loop(void) {
  x++;
  if(x > (l*4)*PI/2){
    x=0;
  }
  
  R = l*sin(x/127.5)+l;
  G = l*sin(x/127.5+(2*PI/3))+l;
  B = l*sin(x/127.5+(4*PI/3))+l;
  
  analogWrite(rPin, R);
  analogWrite(gPin, G);
  analogWrite(bPin, B);

  delay(s);
}
