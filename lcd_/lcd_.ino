#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 15, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);  
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(2, 0);
  lcd.print("Papa Ba GAYE");
  lcd.setCursor(4, 1);
  lcd.write("Senegal");
  delay(2000);
  lcd.clear();
  delay(500);
}
