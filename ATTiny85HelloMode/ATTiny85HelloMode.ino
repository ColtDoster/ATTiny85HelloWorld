//COLT DOSTER

//appropriate pins for both button and LED
int ledPin = 1;
int butPin = 0;

//WILL RECORD THE DIGITAL READ OF THE BUTTON
// AND WHETHER THE BUTTON HAS BEEN PRESSED OR NOT
int butVal;
int previousVal = 0;



//STATE LABELS CORRESPOND TO WHAT THE LED WILL BE DOING
enum State {
  OFF,
  ON,
  BLINK

};

State currentState;

//THIS VARIABLE WILL BE COMAPRED TO THE MILLIS TIME TO SEE IF IT IS LARGER THAN THE TIMER
long lastTime;
//THIS VARIABLE WILL SIMPLY HOLD A 100 VALUE BECAUSE I WANT THE LED TO FLASH IN 100 MILLISECOND INTERVALS
long timer;

// boolean to represent if the button was pressed or not
boolean light;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(butPin, INPUT);

//WHEN THE CODE IS RUN THE LED WILL BE OFF
  currentState = OFF;

 
  
  lastTime = 0;
  timer = 100;

  
}

void loop() {
  // put your main code here, to run repeatedly:
  butVal = digitalRead(butPin);
  


//BOOLEAN MANAGES WHETHER OR NOT LED IS LIT
if(light == true){
digitalWrite(ledPin,HIGH);
}else {
  digitalWrite(ledPin,LOW);
}

//// DIRECTIONS FOR LIGHTING THE LED  
  if(currentState == OFF){
    light = false;
  } else if (currentState == ON){
    light = true;
  } else if (currentState == BLINK){
    if(millis() - lastTime >= timer){
    light = !light;
    lastTime = millis();
    }
  }




//THE STATE MANAGES WHEN ONE STATE SWITCHES TO THE NEXT
  
    switch(currentState) {
      
      case OFF:
     if(butVal == 1 && previousVal == 0){
        butVal = previousVal;
        delay(80);
        currentState = BLINK;
      }
      break;

/*NOTE: I have double and triple checked, I am not sure why the BLINK state turns the LED on 
and the ON state has the LED blinking. That is why they are in this order. 
This order does have the LED correctly run through the states*/

      case BLINK:
      if(butVal == 1 && previousVal == 0){
        butVal = previousVal;
        delay(80);
        currentState = ON;
      }
      break;

      case ON:
      if(butVal == 1 && previousVal == 0){
        butVal = previousVal;
        delay(80);
        currentState = OFF;
      }
      break;
      
    }



}
