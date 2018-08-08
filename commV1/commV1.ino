
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


if (Serial.available()){ 
    // Receive Commands 
   //Serial.readBytes(RGB, 3);
   RGB = Serial.readString();
  
    }

  delay(100);

  for (int i = 0; i < RGB.length(); i++)
  {
    Serial.write(RGB[i]);   // Push each char 1 by 1 on each loop pass
  }
  delay(3000);
  //Serial.write(RGB);
//  delay(1000);
 // Serial.write(RGB[1]);
//  delay(1000);
  //Serial.write(RGB[2]);
//  delay(2000);
  
//        data=Serial.read();
//         if((data=='O'))
//          {
//            digitalWrite(redPin,HIGH);
//            digitalWrite(led,HIGH);
//            RGB[0]=255;
//            RGB[1]=180;
//            RGB[1]=180;
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
 // digitalWrite(redPin,HIGH);
 // digitalWrite(greenPin,HIGH);
  //digitalWrite(led,HIGH);
  }
    
      

