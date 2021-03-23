// пины для подключения контактов STEP, DIR
#define PIN_STEP 3
#define PIN_DIR 2

// количество шагов на 1 оборот
#define STEP_ROUND 200

// скорость двигателя
#define SPEED 10

void setup() {
// режим для STEP и DIR как OUTPUT
pinMode(PIN_STEP, OUTPUT);
pinMode(PIN_DIR, OUTPUT);
// начальные значения
digitalWrite(PIN_STEP, HIGH);
digitalWrite(PIN_DIR, LOW);
}

void loop() {
// направление вращения
digitalWrite(PIN_DIR, HIGH);
// сделать 1 оборот
for(int j = 0; j < STEP_ROUND; j++) {
digitalWrite(PIN_STEP, HIGH);
delay(SPEED);
digitalWrite(PIN_STEP, LOW);
delay(SPEED);
}
// изменить направление вращения
digitalWrite(PIN_DIR, LOW);
// сделать 1 оборот
for(int j = 0; j < STEP_ROUND; j++) {
digitalWrite(PIN_STEP, HIGH);
delay(SPEED);
digitalWrite(PIN_STEP, LOW);
delay(SPEED);
}
}
