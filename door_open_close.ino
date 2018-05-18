#include<Servo.h>

Servo servo;
 
int close_pos = 100;
int open_pos = 1;
bool door_close = true;

void setup() 
{ 
  Serial.begin(9600);
  servo.attach(9);
  servo.write(close_pos); 
} 

void loop() 
{
  while(Serial.available()) 
  {
    char ch = Serial.read();
    Serial.println(ch);
    if (ch == '0') {
      if(door_close){
        door_function();
        door_close = false;
      }
      else{
        door_function();
        door_close = true;
      }
    }
  }
}

void door_function()
{
  if(door_close)
  {
    int i = close_pos;
    while( i >= open_pos)
    {
      servo.write(i);
      Serial.println(i);
      delay(10);
      i -= 1;
    }
    Serial.println("Door Opened");
  }
  else
  {
    int i = open_pos;
    while( i <= close_pos)
    {
      servo.write(i);
      Serial.println(i);
      delay(10);
      i += 1;
    }
    Serial.println("Door Closed");
  }
}

