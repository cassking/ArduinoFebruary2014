int ledPins[] = { 7,8,9,10,11,12 };//an array of pin ubers
int pinCount = 6;// number of pins unsed in array

int sensorPin = A0;//declare sensro pin for potentiometer
int sensorValue = 0;
int buttonValue = 0;
const int buttonPin = 2;
//we added a potentiometer
//we added a button

void setup() { 
  //initialize seriall communication
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  
  //use the for loop to init. ea pin as output
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    //note local variable thisPin
    pinMode(ledPins[thisPin], OUTPUT);//set all pins to array value as output
   
  }
}

void loop() {
  sensorValue = analogRead(sensorPin);
  buttonValue = digitalRead(buttonPin);
  
  Serial.println(sensorValue);
  
  
  if (buttonValue == HIGH) {
    //loop from lowestpin to highest
    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    
      //turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);
    delay(sensorValue);
    //turn the pin Off
    digitalWrite(ledPins[thisPin], LOW);
    }
  }
  
  else if (buttonValue == LOW) {
  
    digitalWrite(ledPins[4], HIGH);
    digitalWrite(ledPins[5], HIGH);
    delay(100);
    digitalWrite(ledPins[4], LOW);
    digitalWrite(ledPins[5], LOW);
    delay(100);
  
  }
}
   
