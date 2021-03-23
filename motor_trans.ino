#include <LiquidCrystal.h>
#include <Servo.h>

// пины для подключения контактов STEP, DIR
#define PIN_STEP 3
#define PIN_DIR 2

#define buttonPin1 6
#define buttonPin2 7
#define buttonPin3 8
// количество шагов на 1 оборот
#define STEP_ROUND 200
// скорость двигателя
#define SPEED1 9


Servo myservo;
LiquidCrystal lcd(12, 11, 10, 9, 13, 5);


bool buttonState1 = LOW;         // variable for reading the pushbutton status
bool buttonState2 = LOW;         // variable for reading the pushbutton status
bool buttonState3 = LOW;         // variable for reading the pushbutton status
float STEP_ROUND_TURN = 0;
int n = 1;
const int shift = 35;
const int angle_shift = 0;

int pos = 116;
int spins = 0;
int j = 0;

void lcd_shit(int sum, int last)
{
  if (last == 40) {
  lcd.setCursor(8,0);
  lcd.print(last);
  lcd.setCursor(10,0);
  lcd.print(" ");
  }
  else {
  lcd.setCursor(8,0);
  lcd.print(last);
  }
  
  
  lcd.setCursor(6,1);
  lcd.print(sum);

}

void setup() {
  
myservo.attach(4);
myservo.write(pos);
lcd.begin(16, 2);
lcd.setCursor(1,0);
lcd.write("SPINS: ");
lcd.setCursor(1,1);
lcd.write("ALL: " + spins);


// режим для STEP и DIR как OUTPUT
pinMode(PIN_STEP, OUTPUT);
pinMode(PIN_DIR, OUTPUT);
// начальные значения
digitalWrite(PIN_STEP, 1);
digitalWrite(PIN_DIR, 0);

pinMode(buttonPin1, INPUT);
pinMode(buttonPin2, INPUT);
pinMode(buttonPin3, INPUT);


}

void loop() {
if (digitalRead(buttonPin1))
{ 
  digitalWrite(PIN_DIR, HIGH);
  while(digitalRead(buttonPin1)) {
    digitalWrite(PIN_STEP, HIGH);
    delay(SPEED1);
    digitalWrite(PIN_STEP, LOW);
    j++;
    if (j%200 == 0){
      n +=1;
      pos-= pow(-1, n) + angle_shift * pow(-1, n);
      spins = spins - 1;
      lcd_shit(spins, -1);
      myservo.write(pos);
      delay(10);
    }
  }
}
j = 0;
if (digitalRead(buttonPin2))
{  
  STEP_ROUND_TURN = STEP_ROUND * 40;
  digitalWrite(PIN_DIR, LOW);
  while(j <= STEP_ROUND_TURN - 1) {
    digitalWrite(PIN_STEP, HIGH);
    delay(SPEED1);
    digitalWrite(PIN_STEP, LOW);
    if (j%200 == 0){
     spins = spins + 1;
     pos+= pow(-1, n) + angle_shift * pow(-1, n);
     if (spins % shift == 0){
      n +=1;
     }
     myservo.write(pos);
     delay(10);  
    }
    lcd_shit(spins, 40);
    if (digitalRead(buttonPin1))
    { 
      break; 
    }
    j++;
    }
}
j = 0;
if (digitalRead(buttonPin3))
{
  STEP_ROUND_TURN = STEP_ROUND * 130;
  digitalWrite(PIN_DIR, LOW);
  while(j <= STEP_ROUND_TURN - 1) {
    digitalWrite(PIN_STEP, HIGH);
    delay(SPEED1);
    digitalWrite(PIN_STEP, LOW);
    if (j%200 == 0){
     spins = spins + 1;
     pos+= pow(-1, n) + angle_shift * pow(-1, n);
     if (spins % shift == 0){
      n +=1;
     }
     myservo.write(pos);
     delay(10);  
    }    
     if (digitalRead(buttonPin1))
    { 
      break; 
    }
    lcd_shit(spins, 130);
    j++;   
    }
}
j = 0;
STEP_ROUND_TURN = 0;
}
