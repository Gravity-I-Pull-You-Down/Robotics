// AUTHOUR : SUCHEENDRADAS VR
// VERSION : LFR 1.0
// DATE    : 24/03/17
const int motorRPin1 = 5; 
const int motorRPin2 = 3;  
const int motorREnable ; 

const int motorLPin1 = 6;          
const int motorLPin2 = 9;
const int motorLEnable ; 

//const int irPins[8] = {4,A5,A4,A3,A2,A1,A0,7};
const int irPins[8] = {7,A0,A1,A2,A3,A4,A5,4};
int irSensorDigital[8] = {0,0,0,0,0,0,0,0};
int i,j = 0;
int d = 1000;
int value[8];
int irSensors = B00000000;  

int motorLSpeed = 255;
int motorRSpeed = 255;
int error = 140;   // 145 best 200  //  normal 255  // mad 0 
void setup() {
  
  
  Serial.begin(9600);
  
  
  pinMode(motorLPin1,OUTPUT);        
  pinMode(motorLPin2,OUTPUT);
  //pinMode(motorLEnable,OUTPUT);
  
  pinMode(motorRPin1,OUTPUT);        
  pinMode(motorRPin2,OUTPUT);
  //pinMode(motorREnable,OUTPUT);
   
  /* Set-up IR sensor pins as input */
  for (int i = 0; i <= 7; i++) 
  {pinMode(irPins[i], INPUT);}
 

}

void loop() {
     scanD();
     for(int i=0;i<8;i++){
      Serial.print(bitRead(irSensors,i));
     }
     Serial.println('\n');
     check(); 
}     
     
void check( ) 
{    
     switch (irSensors) {
     
     /*
     //case B11111110:
    // case B11111101:
     //case B11111011:
    // case B11111100:
     //case B11111001:
     //case B11110011:
     case B11111000:
     //case B11110001:
     //case B11100011:
     case B11110000:
     case B11100000:
     case B11000000:
     case B10000000:*/

     case B11111000:
     case B11110000:
     case B11100000:
     right();
     //delay(200);
     break;

     //case B11011111:
     //case B10111111:
     //case B01111111:
     //case B11001111:
     //case B10011111:
     //case B00111111:
     //case B11000111:
    // case B10001111:
     case B00001111:
     case B00000111:
     case B00011111:
     left();
     //delay(200);
     break;

     case B11000000 :
     case B10011111 :
     case B11001111 :
    // case B11101111 :
     softLeft();
     break;

     case B11110011 :
     case B00000011 :
     case B11111001 :
  //   case B11110111 :
     softRight();
     break;
     
     case B00000000:
     stopme();
     break;

     case B11100111 :
     case B11101111:
     case B11110111:
     
     go();
     break;

     
     default:
     Serial.print("Unhandled case: ");   
     
  }
 
}





void right() 

{
     Serial.println("                         right motor forward (spin)");
     //analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, HIGH);
     digitalWrite(motorRPin2, LOW);
     
     //analogWrite(motorLEnable, motorLSpeed-error);
     digitalWrite(motorLPin1, LOW);
     digitalWrite(motorLPin2,HIGH);
  
}


void left()  //turn left
{
     Serial.println("                         left  motor forward (spin)");
     //analogWrite(motorREnable, motorRSpeed-error);
     digitalWrite(motorRPin1, LOW);
     digitalWrite(motorRPin2, HIGH);
     
     //analogWrite(motorLEnable, motorLSpeed);
     digitalWrite(motorLPin1, HIGH);
     digitalWrite(motorLPin2, LOW);
  
}

void go()
{
    Serial.println("                         forward ");
     //analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, HIGH);
     digitalWrite(motorRPin2, LOW);
     
     //analogWrite(motorLEnable, motorLSpeed);
     digitalWrite(motorLPin1, HIGH);
     digitalWrite(motorLPin2, LOW);
  
}

void stopme()
{
     Serial.println("                         stop");
     //analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, LOW);
     digitalWrite(motorRPin2, LOW);
     
     //analogWrite(motorLEnable, motorLSpeed);
     digitalWrite(motorLPin1, LOW);
     digitalWrite(motorLPin2, LOW);
  
}
void softRight(){

      Serial.println("                         right motor forward (spin)");
     //analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, HIGH);
     digitalWrite(motorRPin2, LOW);
     
     //analogWrite(motorLEnable, motorLSpeed-error);
     digitalWrite(motorLPin1, LOW);
     digitalWrite(motorLPin2,LOW);
 
 
 }

 void softLeft(){
       Serial.println("                         Left motor forward (spin)");
     //analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, LOW);
     digitalWrite(motorRPin2, LOW);
     
     //analogWrite(motorLEnable, motorLSpeed-error);
     digitalWrite(motorLPin1, HIGH);
     digitalWrite(motorLPin2,LOW);
 }



void scanD()
{
  for ( byte count = 0; count < 8;count++ )
{
  bitWrite(irSensors, count, !digitalRead( irPins[count] ));
} 
}
