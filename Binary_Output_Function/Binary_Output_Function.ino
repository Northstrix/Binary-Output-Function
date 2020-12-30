// Binary Output Function for Arduino, ESP and every platform on which you will be able to run it
// Written by Maxim Bortnikov
// In this project I've used some code from:
/* Arduino 8 bit Binary LED Counter. Author: P.Marian */
/* source: https://www.electroschematics.com/9809/arduino-8-bit-binary-led/ */
// This project was created for research purposes only. If you're an owner of some part(s) of the code and you want this code to be removed, please contact me and I will remove it.
// binout(variable) - outputs a variable in binary
// resout() - turns all LEDs off
int n = 0; // Stores the value that will be outputted in binary
const byte numPins = 8; // How many LEDs are you going to use?
int state; // Stores two variables: HIGH or LOW
byte pins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Connect LEDs to these pins
// {least significant bit, ... , most significant bit}
void binout (int n){ // The function that converts a variable to the binary and outputs it into the LEDs
  resout(); // Turns all LEDs off
  String binNumber = String(n, BIN); // Convert variable into binary
  int binLength = binNumber.length(); 
    for(int i = 0, x = 1; i < binLength; i++, x+=2) {
      if(binNumber[i] == '0') state = LOW;
      if(binNumber[i] == '1') state = HIGH;
      digitalWrite(pins[i] + binLength - x, state); // Output a binary value to LEDs
    } 
}
void resout(){ // The function that turn all LEDs off
   for(int i = 0; i < numPins; i++) {
    digitalWrite(pins[i], 0);
  } 
}
// The part below isn't a part of the function
void setup()
{
  // Initialise all LED pins as outputs
  for(int i = 0; i < numPins; i++) {
    pinMode(pins[i], OUTPUT);
  }
  // LED test
  binout(pow (2, numPins) -1); // Light up every LED
  delay(1000); // Wait fot 1 second
  // The end of test
}
void loop()
{
// Binary counter test
for(int i = 0; i<256; i++){
  binout(i);
  delay(100);
}
// The end of the binary counter test
}


