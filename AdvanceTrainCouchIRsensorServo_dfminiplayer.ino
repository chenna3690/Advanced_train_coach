#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

DFRobotDFPlayerMini myDFPlayer;

// Initialize the LCD with the I2C address (usually 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;  // Create a Servo object

//connect df mini players tx to rx and rx to tx of nodemcu (remove them while program uploading)
//d1 and d2 connected to lcd
int servoPin = D4;  // Digital pin connected to the servo
int IR = D5;
int motor = D7;
int runflag = 0;

int station = 1;

void setup() 
{
  Serial.begin(9600);
  myServo.attach(servoPin); // Attach servo to the servoPin
  myServo.write(0); // Initialize servo to 0 degrees
  pinMode(IR, INPUT);
  pinMode(motor, OUTPUT);
  
  lcd.begin();
  lcd.backlight();
  if (!myDFPlayer.begin(Serial)) 
  {  // Initialize DFPlayer
    Serial.println("DFPlayer Mini not detected!");
    while (true);  // Stop execution if DFPlayer is not found
    lcd.print("DF PLAYER ERROR");
  }
  
  Serial.println("DFPlayer Mini ready.");
  myDFPlayer.volume(30);  // Set volume (0 to 30)
  
  Serial.println("System started");
  lcd.setCursor(0, 0);
  lcd.print("SYSTEM STARTED");
  delay(2000);
  lcd.clear();
}

void loop() 
{
  int IR_value = digitalRead(IR);
  
  if (IR_value == 0) 
  {
    Serial.println("Obstacle detected");
    lcd.setCursor(0, 0);
    lcd.print("STATION: ");
    lcd.print(station);
    
    digitalWrite(motor, LOW); // Stop the motor
    myDFPlayer.play(6);
    delay(1000);
    myServo.write(180);
    Serial.println("Train stopped");
    lcd.setCursor(0, 1);
    lcd.print("TRAIN STOPPED");
    station = station+1; // Increment the station number
    switch(station)
    {
      case 1:
      myDFPlayer.play(1);
      break;
      case 2:
      myDFPlayer.play(2);
      break;
      case 3:
      myDFPlayer.play(3);
      break;
      case 4:
      myDFPlayer.play(4);
      break;
      case 5:
      myDFPlayer.play(5);
      break;
    }
    // Countdown timer
    for (int i = 7; i > 0; i--) 
    {
        lcd.setCursor(0, 1);
        lcd.print("TRAIN STOPPED: ");
        lcd.print(i);
        lcd.print(" s");
        if(i==6)
        {
          myDFPlayer.play(7);
        }
        delay(1000);
    }
    if (station > 4) 
    {
      station = 1; // Reset to station 1 after 4
    }
    runflag = 1;
  }

  if (runflag == 1) 
  {
    lcd.clear();
    myServo.write(0);
    delay(1000);
    digitalWrite(motor, HIGH); // Start the motor
    Serial.println("Train started");
    lcd.setCursor(0, 1);
    lcd.print("TRAIN STARTED");
    delay(1000);
    lcd.clear();
    runflag = 0;
  }
  
  // Continue running the motor if no obstacle
  digitalWrite(motor, HIGH);
  Serial.println("Train running");
  lcd.setCursor(0, 1);
  lcd.print("TRAIN RUNNING");
  delay(10);
}
