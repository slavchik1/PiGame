#define _LCD_TYPE 1
#include "LiquidCrystal_I2C.h"
#include "LCD_1602_RUS_ALL.h"
#include "IRremote.hpp"


LCD_1602_RUS lcd(0x27, 16, 2);


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
    tone(buz, ton);
    delay(1000);
    noTone(buz);
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
  for (int i = 0; i < Size; i++) {
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
    if (IrReceiver.decode()) {
      Serial.print("IrReceiver.decodedIRData.decodedRawData=");
      Serial.println(IrReceiver.decodedIRData.decodedRawData);
      if (IrReceiver.decodedIRData.decodedRawData == 2907897600) {
        IrReceiver.resume();
        return 0;
      } else if (IrReceiver.decodedIRData.decodedRawData == 3910598400) {
        IrReceiver.resume();
        return 1;
      } else if (IrReceiver.decodedIRData.decodedRawData == 3860463360) {
        IrReceiver.resume();
        return 2;
      } else if (IrReceiver.decodedIRData.decodedRawData == 4061003520) {
        IrReceiver.resume();
        return 3;
      } else if (IrReceiver.decodedIRData.decodedRawData == 4077715200) {
        IrReceiver.resume();
        return 4;
      } else if (IrReceiver.decodedIRData.decodedRawData == 3877175040) {
        IrReceiver.resume();
        return 5;
      } else if (IrReceiver.decodedIRData.decodedRawData == 2707357440) {
        IrReceiver.resume();
        return 6;
      } else if (IrReceiver.decodedIRData.decodedRawData == 4144561920) {
        IrReceiver.resume();
        return 7;
      } else if (IrReceiver.decodedIRData.decodedRawData == 3810328320) {
        IrReceiver.resume();
        return 8;
      } else if (IrReceiver.decodedIRData.decodedRawData == 2774204160) {
        IrReceiver.resume();
        return 9;
      } else if (IrReceiver.decodedIRData.decodedRawData == 0) {
        IrReceiver.resume();
        continue;
      } else {
        IrReceiver.resume();
        return -1;
      }
    }
    delay(100); // Small delay to prevent overwhelming the serial output
  }
}

void wait() {
  getDigit();
  lcd.clear();
  lcd.setCursor(0, 0);
  tone(buz, 500);
  delay(100);
  noTone(buz);
}

void newLine(String text) {
  lcd.setCursor(0, 1);
  lcd.print(text);
  wait();
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

  IrReceiver.begin(5);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  Serial.begin(9600);
  makeNumber(8);
  delay(1000);

  lcd.print("HaTиcHiTь");
  newLine("бyдь яKy KHoпKy.");

  /*lcd.print("BiTaю y п гpi.");
  wait();

  lcd.print("Гpy для BиBчeHHя");
  newLine("чиcла п.");

  lcd.print("Цiль гpи - BчиTи");
  newLine("чиcлo п.");

  lcd.print("П гpa пiдTpиMyє");
  newLine("159 3HaKiB пicля");

  lcd.print("KoMи числа п.");
  wait();

  lcd.print("y п грi бyдyTь");
  newLine("3'яBляTиcя цифpи");

  lcd.print("чиcлa п");
  newLine("пo пopядKу,");

  lcd.print("а Baшa цiль -");
  newLine("HaTиcKaTи їx");

  lcd.print("ПoпopядKy.");
  wait();

  lcd.print("Правила яcHi,");
  newLine("TaK щo.");

  lcd.print("Поїхали!");
  wait();*/

}

void loop() {
  // game();
  Serial.println("getdigit=" + String(getDigit()));
}

int game() {
  int t = 1;
  String line1 = "п=";
  String line2 = "";

  while (true) {
    if (t > 15) {
      return -1;
    } else {
      for (int i = 0; i <= t; i++) {
        Serial.println("i=" + String(i));
        makeNumber(pi[i]);
      }
      for (int i = 0; i <= t; i++) {
        int d = getDigit();
        Serial.println("getDigit=" + String(d));
        if (d == pi[i]) {
          lcd.print("a");
        } else {
          return t;
        }
      }
      t++;
    }
  }
}
