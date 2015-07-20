// calibrated for http://www.bapihvac.com/content/uploads/2010/11/thermistor_100k.pdf

// the value of the 'other' resistor
#define SERIESRESISTOR 100000

// Pin locations
#define THERMISTORPIN 0
#define rPin 11
#define gPin 10
#define bPin 9

// RGB stored value init
int R,G,B;

// Temp ranges in F
int bottom = 72, top = 80;
 
void setup(void) {
  Serial.begin(9600);
}

// Returns averaged thermistor value over # readings
float tAvg(void){
  float t[128]; // # readings
  int n = sizeof(t)/sizeof(t[0]);
  float r;
  
  for(int x=0; x<n; x++) {
    t[x]=analogRead(THERMISTORPIN);
  }
  
  for(int x=0; x<n; x++) {
    r = r + t[x];
  }
  
  return r/n;
}

// Takes thermistor value, returns temperature in F 
double thermistor(float t) {
  // Steinhart-Hart thermistor coefficients
  // Calculated from http://www.thinksrs.com/downloads/programs/Therm%20Calc/NTCCalibrator/NTCcalculator.htm
  double a = -1.968687378*pow(10,-3);
  double b = 5.884163834*pow(10,-4);
  double c = -9.512985864*pow(10,-7);
  double temp;

  // Apply Steinhart-Hart thermistor equation
  float ln = log(SERIESRESISTOR*(1024.0/t-1));  
  temp = 1/(a+b*ln+c*pow(ln,3));
  temp = temp - 273.15;            // Convert Kelvin to Celcius
  temp = (temp * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
  return temp;
}

// Create linear equation relating possible LED values to temperature
float fX(int x1, int x2, float x) {
  float m = (0-255)/(x2-x1); // Slope
  float b = 255-m*x1; // Y-intercept
  return m*x+b; // Point-slope form: f(x)=mx+b
}

// Main function loop
void loop(void) {
  float temp = thermistor(tAvg());
  float val = fX(top, bottom, temp);
  
  if(temp >= top){
    R=255;
    G=0;
    B=0;
  }
  else if(temp <= bottom){
    R=0;
    G=0;
    B=255;
  }
  else{
    R = 2*val-255;
    G = -abs(2*val-255)+255;
    B = -2*val+255;
  }

  // Correct for negatives
  if (R < 0) {R = 0;}
  if (B < 0) {B = 0;}
  
  analogWrite(rPin, R);
  analogWrite(gPin, G);
  analogWrite(bPin, B);

  delay(10); //LED delay
}
