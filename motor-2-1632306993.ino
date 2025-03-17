const int PinA1 = D4;  // (ШИМ) вывод 5 соединен с выводом А1
const int PinA2 = D3;  // (ШИМ) вывод 6 соединен с выводом А2
const int PinB1 = D5; // (ШИМ) вывод 10 соединен с выводом (pin) B1
const int PinB2 = D6;  //(ШИМ) вывод 11 соединен с выводом (pin)B2
int speed = 1023;  // измените это значение (0-1023), 
                  //чтобы управлять скоростью вращения двигателей
void setup() {
  pinMode(PinA1, OUTPUT); // установите контакты на выход
  pinMode(PinA2, OUTPUT);
  pinMode(PinB1, OUTPUT);
  pinMode(PinB2, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  Serial.println("Avanti");
  forward();
  delay(2000);
  STOP();
  Serial.println("Indietro");
  backward();
  delay(2000);
  STOP();
  Serial.println("Sinistra");
  left();
  delay(2000);
  STOP();
  Serial.println("Destra");
  right();
  delay(2000);
  STOP();
}
void backward() // Вперед.
{
  analogWrite(PinA1, 0);
  analogWrite(PinA2, speed);
  analogWrite(PinB1, 0);
  analogWrite(PinB2, speed);
}
void forward() //Назад...
{
  analogWrite(PinA1, speed);
  analogWrite(PinA2, 0);
  analogWrite(PinB1, speed);
  analogWrite(PinB2, 0);
}
void left() // В левую сторону
{
  analogWrite(PinA1, speed);
  analogWrite(PinA2, 0);
  analogWrite(PinB1, 0);
  analogWrite(PinB2, speed);
}
void right() //В правую сторону
{
  analogWrite(PinA1, 0);
  analogWrite(PinA2, speed);
  analogWrite(PinB1, speed);
  analogWrite(PinB2, 0);
}
void STOP() //Стоп
{
  analogWrite(PinA1, 0);
  analogWrite(PinA2, 0);
  analogWrite(PinB1, 0);
  analogWrite(PinB2, 0);
  delay (2000);
}
