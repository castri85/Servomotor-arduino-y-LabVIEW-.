/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
#define DEBUG(a) Serial.println(a);

Servo myservo;  // create servo object to control a servo

int foto = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int pos=0;
char valor;
int angulo;
String grado;
void setup() {
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  
}
void loop() {
  if (Serial.available()>0)
  {
    valor=Serial.read();
   
    if(valor=='a')
    { 
    delay(1000);
    //val = analogRead(foto);            // reads the value of the potentiometer (value between 0 and 1023)
    
    //angulo = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
    for (pos = 0; pos <= 180; pos += 5) // goes from 0 degrees to 180 degrees
       {
    // in steps of 1 degree
    val = analogRead(foto);  
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.print(pos);
    Serial.print(" ");
    Serial.println(val);
    delay(1000);                      // waits 15 ms for the servo to reach the position
       } 
    }
    
   if(valor=='b')
    {Serial.print(0);}
    
    if(valor=='c'){
      
    int data = Serial.parseFloat();
    DEBUG(data);
    myservo.write(data);
    if (valor=='\n'){ //Recibe un espacio     
    //angulo=grado.toInt();
      //Convierte en número el valor
    
 
    }
    }
    
      }
  
    
  }
