
//int led = 13;
int greenPin = 11;
int redPin = 10;
int bluePin =9;
int counter = 0;
//byte RGB[3];
String RGB;
//int RGB[3];
char data;
int toggleSwitchPin = 5;
bool toggleSwitchStatus;
void setup() {

Serial.begin(9600);
//pinMode(led,OUTPUT);
pinMode(toggleSwitchPin,INPUT_PULLUP);
pinMode(greenPin,OUTPUT);
pinMode(redPin,OUTPUT);
pinMode(bluePin,OUTPUT);
toggleSwitchStatus = LOW;

}

void loop() {



// Get/Set colors

 
if (Serial.available()){ 
    // Receive Commands 
   RGB = Serial.readString();
  
    }

  delay(100);

//sendBack received string (mostly used for troubleshooting)

//  for (int i = 0; i < RGB.length(); i++)
//   {
//     Serial.write(RGB[i]);   // Push each char 1 by 1 on each loop pass
//   }
   
  delay(10);

// convert received string to bytes 
  String red;
  red += RGB[0];
  red += RGB[1];
  red += RGB[2];
  int redInt = red.toInt();
  
  String green;
  green += RGB[3];
  green += RGB[4];
  green += RGB[5];
  int greenInt = green.toInt();
  
  String blue;
  blue += RGB[6];
  blue += RGB[7];
  blue += RGB[8];
  int blueInt = blue.toInt();
  
  analogWrite(redPin,redInt);
  analogWrite(greenPin,greenInt);
  analogWrite(bluePin,blueInt);


  //Read pysical user input toggle switch 

toggleSwitchStatus = digitalRead(toggleSwitchPin);

  if(toggleSwitchStatus == HIGH)
    {
      Serial.write('U'); // Unlocked game files 
    }
 else
    {
      Serial.write('L'); // Locked game files 
    }
    
  }
    
      

