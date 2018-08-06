
int led = 13;
char data;
int toggleSwitchPin = 5;
bool toggleSwitchStatus;
void setup() {

Serial.begin(9600);
pinMode(led,OUTPUT);
pinMode(toggleSwitchPin,INPUT_PULLUP);
toggleSwitchStatus = LOW;
}

void loop() {


if (Serial.available()){ 
    // receive commands 
   data = Serial.read();
    
         //Serial.write("hello");
       switch (data){
          
          case 'O': 
          digitalWrite(led,HIGH);
          
          break;
          case 'F': 
          digitalWrite(led,LOW);
          break;
       }

   
    }

    delay(100);
     toggleSwitchStatus = digitalRead(toggleSwitchPin); 

          

         if(toggleSwitchStatus == 1)
         {
            Serial.write('Y');  
         }
         else
         {
          Serial.write('N');
         }
      //send commands 
//   toggleSwitchStatus = digitalRead(toggleSwitchPin);
//    
//       switch (toggleSwitchStatus){
//          
//          case 0:
//          Serial.write(0);
//          break;
//      
//          case 1:
//           Serial.write(1);
//          break;
//         }
        
    }

