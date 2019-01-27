const int redPin = 6;
const int greenPin = 9;
const int bluePin = 10;
const int buttonPin = 18;
int buttonState = LOW;
int buttonCounter = 0;

void setup() {
  // Start off with the LED off.
  setColourRgb(0,0,0);

  pinMode(buttonPin, INPUT);
}

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
 }
 
void buttoncheck() {
    buttonState = digitalRead(buttonPin);
      if (buttonState == HIGH) {
        buttonCounter ++;
        while (buttonState == HIGH) {
          buttonState = digitalRead(buttonPin);
        }
        delay(50);
    }
}

void loop () {
  unsigned int rgbColour[3];
  buttoncheck();
  
  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  // Choose the colours to increment and decrement.
  if (buttonCounter == 0) {
    for (int decColour = 0; decColour < 3; decColour ++) {
          int incColour = decColour == 2 ? 0 : decColour + 1;
          for(int i = 0; i < 255; i ++) {
            rgbColour[decColour] -= 1;
            rgbColour[incColour] += 1;
      
            setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
            delay(10);
            buttoncheck();
          }
    
    }
  }
    //Red
    else if (buttonCounter == 1) {
      setColourRgb(255,0,0);
    }
    //Orange
    else if (buttonCounter == 2) {
      setColourRgb(255,65,0);
    }
    //Yellow
    else if (buttonCounter == 3) {
      setColourRgb(255,240,0);
    }
    //Green
    else if (buttonCounter == 4) {
      setColourRgb(0,255,0);
    }
    //Light Blue
    else if (buttonCounter == 5) {
      setColourRgb(0,255,255);
    }
    //Blue
    else if (buttonCounter == 6) {
      setColourRgb(0,0,255);
    }
    //Purple
    else if (buttonCounter == 7) {
      setColourRgb(80,0,220);
    }
    //Fuscia
    else if (buttonCounter == 8) {
      setColourRgb(255,0,255);
    }
    //White
    else if (buttonCounter == 9) {
      setColourRgb(220,255,255);
    }
    else {
      buttonCounter = 0;
    }
    }

    // add in conditions for different color options (rainbow fade, presets)
    
    // Rainbow fade, cross-fade the two colours.
