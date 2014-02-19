int ledPins[] = { 7,8,9,10,11,12 };//an array of pin ubers
int pinCount = 6;// number of pins unsed in array

int sensorPin = A0;//declare sensro pin for potentiometer
int sensorValue = 0;


void setup() { 
  //initialize seriall communication
  Serial.begin(9600);
  
  //use the for loop to init. ea pin as output
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    //note local variable thisPin
    pinMode(ledPins[thisPin], OUTPUT);//set all pins to array value as output
  }
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  //loop from the lowest pin to highest
  for (int thisPin = 0; thisPin < pinCount; thisPin ++) {
    //note local variable thisPin declared again
  //begin loopin thru pins
  //turn pins on
    digitalWrite(ledPins[thisPin], HIGH);
    delay(sensorValue);
    //turn pins off
    digitalWrite(ledPins[thisPin], LOW);
  }
}
