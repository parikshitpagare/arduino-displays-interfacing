/*
 * Interfacing Arduino with Character LCD 16x2
 * 
 * Author: Parikshit Pagare
 * linkedin.com/in/parikshitpagare
 * github.com/parikshitpagare
 */

#include <LiquidCrystal.h>

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/* Custom characters */
byte heart[] = {
  0b00000, 0b01010, 0b10101, 0b10001, 0b01010, 0b00100, 0b00000, 0b00000
};

byte upArrow[] = {
    0b00100, 0b01110, 0b10101, 0b00100, 0b00100, 0b00100, 0b00100, 0b00100
};

byte smiley[] = {
   0b00000, 0b00000, 0b01010, 0b00000, 0b00000, 0b10001, 0b01110, 0b00000
};

void setup() {
  /* Initialize LCD */
  lcd.begin(16, 2);               
  
  /* Create new characters */
  lcd.createChar(0, upArrow);
  lcd.createChar(1, heart);
  lcd.createChar(2, smiley);

  /* Clear dsiplay */
  lcd.clear();  
}

void loop() {
  /* Printing text */
  lcd.print("Arduino is fun!");       
  delay(5000);
  lcd.clear();
  lcd.print("Embedded Systems");      
  delay(5000);
  lcd.clear();
  
 /* Printing numbers from 0 to 9 */  
  lcd.setCursor(0, 0);
  lcd.print("Count 0 to 9");
  lcd.setCursor(0, 1);  
  delay(2000);
  for (int i = 0; i < 10; i++) {
    lcd.print(i);
    delay(1000);
  }
  delay(5000);
  lcd.clear();
  
  /* Printing custom characters */  
  lcd.setCursor(0, 0);
  lcd.print("Custom character");  
  lcd.setCursor(0, 1);
  delay(2000);
  /* When calling lcd.write() must be cast as a byte */
  lcd.write(byte(0));
  lcd.print(" ");
  delay(2000); 
  lcd.write(byte(1));
  lcd.print(" ");
  delay(2000);
  lcd.write(byte(2));
  lcd.print(" ");
  delay(2000);
  lcd.clear();
}


