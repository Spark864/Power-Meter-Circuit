#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

double powUsed;
void setup() {
  // put your setup code here, to run once:
lcd.begin(4, 20);


}

void loop() {
  // put your main code here, to run repeatedly:
  double vin = analogRead(18)*(5.0 / 1023.0);

  if (vin > 0.05){
    digitalWrite( 8, HIGH);
    double shunti = analogRead(19) * (5.0/ 1023.0);

    //Compute power every second
    long milisec = millis(); // calculate time in milliseconds
    long time = milisec/1000; // convert milliseconds to seconds
    double power = vin * shunti * time;
    powUsed = powUsed + power;

    lcd.print(power);
    lcd.print(vin);
    lcd.print(shunti);

    delay(1000);
  }





}