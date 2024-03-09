#define _LCD_TYPE 1
#define DECODE_HASH
#include "LiquidCrystal_I2C.h"
#include "LCD_1602_RUS_ALL.h"
#include "IRremote.h"


LCD_1602_RUS lcd(0x27, 16, 2);
IRrecv irrecv(2);
decode_results result;


const int pi[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 1, 6, 9, 3, 9, 9, 3, 7, 5, 1, 0, 5, 8, 2, 0, 9, 7, 4, 9, 4, 4, 5, 9, 2, 3, 0, 7, 8, 1, 6, 4, 0, 6, 2, 8, 6, 2, 0, 8, 9, 9, 8, 6, 2, 8, 0, 3, 4, 8, 2, 5, 3, 4, 2, 1, 1, 7, 0, 6, 7, 9, 8, 2, 1, 4, 8, 0, 8, 6, 5, 1, 3, 2, 8, 2, 3, 0, 6, 6, 4, 7, 0, 9, 3, 8, 4, 4, 6, 0, 9, 5, 5, 0, 5, 8, 2, 2, 3, 1, 7, 2, 5, 3, 5, 9, 4, 0, 8, 1, 2, 8, 4, 8, 1, 1, 1, 7, 4, 5, 0};
const byte buz = 13;
const byte ports0[] = {12, 10, 9, 8, 7, 6};
const byte ports1[] = {9, 6};
const byte ports2[] = {11, 10, 9, 8, 7};
const byte ports3[] = {11, 10, 9, 7, 6};
const byte ports4[] = {12, 11, 9, 6};
const byte ports5[] = {12, 11, 10, 7, 6};
const byte ports6[] = {12, 11, 10, 8, 7, 6};
const byte ports7[] = {10, 9, 6};
const byte ports8[] = {12, 11, 10, 9, 8, 7, 6};
const byte ports9[] = {12, 11, 10, 9, 7, 6};





void endShowing(int ton) {
  //tone(buz, ton);
  delay(1000);
  //noTone(buz);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
}

template<size_t Size>
void showNumber(const byte (&ports)[Size]) {
  for (int i; i < Size; i++) {
    digitalWrite(ports[i], HIGH);
  }
}

void makeNumber(int n) {
  if (n == 0) {
    showNumber(ports0);
    endShowing(500);
  } else if (n == 1) {
    showNumber(ports1);
    endShowing(530);
  } else if (n == 2) {
    showNumber(ports2);
    endShowing(561);
  } else if (n == 3) {
    showNumber(ports3);
    endShowing(595);
  } else if (n == 4) {
    showNumber(ports4);
    endShowing(630);
  } else if (n == 5) {
    showNumber(ports5);
    endShowing(667);
  } else if (n == 6) {
    showNumber(ports6);
    endShowing(707);
  } else if (n == 7) {
    showNumber(ports7);
    endShowing(749);
  } else if (n == 8) {
    showNumber(ports8);
    endShowing(793);
  } else if (n == 9) {
    showNumber(ports9);
    endShowing(840);
  }
}



int getDigit() {
  while (true) {
    if (irrecv.decode(&result)) {
      Serial.println("ir=" + String(result.value));
      if (result.value == 465573243) {
        irrecv.resume();
        return 0;
      } else if (result.value == 3238126971) {
        irrecv.resume();
        return 1;
      } else if (result.value == 2538093563) {
        irrecv.resume();
        return 2;
      } else if (result.value == 4039382595) {
        irrecv.resume();
        return 3;
      } else if (result.value == 2534850111) {
        irrecv.resume();
        return 4;
      } else if (result.value == 1033561079) {
        irrecv.resume();
        return 5;
      } else if (result.value == 1635910171) {
        irrecv.resume();
        return 6;
      } else if (result.value == 2351064443) {
        irrecv.resume();
        return 7;
      } else if (result.value == 1217346747) {
        irrecv.resume();
        return 8;
      } else if (result.value == 71952287) {
        irrecv.resume();
        return 9;
      } else {
        irrecv.resume();
        continue;
      }
    }
  }
}

void wait() {
  getDigit();
  lcd.clear();
  lcd.setCursor(0, 0);
}

void newLine(String text) {
  lcd.setCursor(0, 1);
  lcd.print(text);
  getDigit();
  lcd.clear();
  lcd.setCursor(0, 0);
}




void setup() {
  pinMode(buz, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  irrecv.enableIRIn();
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  makeNumber(8);
  delay(500);

  lcd.print("HaTиcHiTь");
  newLine("бyдь яKy цифpy.");
}

void loop() {
  int gameResult = game();
  if (gameResult == -1) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Bи BиBчили");
    newLine("  yci 159 зпK!");
  } else if (gameResult == 0) {
        lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Bи BиBчили");
    newLine("     Hiчoгo!");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Bи BиBчили");
    newLine("    " + String(gameResult - 1) + " 3HaKiB!");
  }
}

int game() {
  int t = 0;
  String line1 = "п=";
  String line2 = "";
  
  lcd.clear();
  lcd.setCursor(13, 0);
  lcd.print("Зн.");

  while (true) {
    if (t > 159) {
      return -1;
    } else {
      for (int i = 0; i <= t; i++) {
        Serial.println("i=" + String(i));
        makeNumber(pi[i]);
      }
      delay(100);
      for (int i = 0; i <= t; i++) {
        int d = getDigit();
        Serial.println("getDigit=" + String(d));
        if (d == pi[i]) {
          Serial.print("test");
        } else {
          return t;
        }
      }
      lcd.setCursor(13, 1);
      lcd.print(String(t));
      t++;
    }
  }
}
