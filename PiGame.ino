#define _LCD_TYPE 1
#define DECODE_HASH
#include "LiquidCrystal_I2C.h"
#include "LCD_1602_RUS_ALL.h"
#include "IRremote.hpp"


LCD_1602_RUS lcd(0x27, 16, 2);
// IRrecv irrecv(3);
decode_results result;


const int pi[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 1, 6, 9, 3, 9, 9, 3, 7, 5, 1, 0, 5, 8, 2, 0, 9, 7, 4, 9, 4, 4, 5, 9, 2, 3, 0, 7, 8, 1, 6, 4, 0, 6, 2, 8, 6, 2, 0, 8, 9, 9, 8, 6, 2, 8, 0, 3, 4, 8, 2, 5, 3, 4, 2, 1, 1, 7, 0, 6, 7, 9, 8, 2, 1, 4, 8, 0, 8, 6, 5, 1, 3, 2, 8, 2, 3, 0, 6, 6, 4, 7, 0, 9, 3, 8, 4, 4, 6, 0, 9, 5, 5, 0, 5, 8, 2, 2, 3, 1, 7, 2, 5, 3, 5, 9, 4, 0, 8, 1, 2, 8, 4, 8, 1, 1, 1, 7, 4, 5, 0};
const byte buz = 13;
const byte ports0[] = {12, 11, 9, 8, 7, 6};
const byte ports1[] = {7, 6};
const byte ports2[] = {8, 7, 10, 11, 12};
const byte ports3[] = {8, 7, 10, 6, 12};
const byte ports4[] = {6, 7, 10, 9};
const byte ports5[] = {12, 6, 10, 9, 8};
const byte ports6[] = {8, 9, 10, 11, 6, 12};
const byte ports7[] = {8, 7, 6};
const byte ports8[] = {12, 11, 10, 9, 8, 7, 6};
const byte ports9[] = {12, 10, 9, 8, 7, 6};





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

int getDigit() {
    /*
     * Check if received data is available and if yes, try to decode it.
     * Decoded hash result is in IrReceiver.decodedIRData.decodedRawData
     */
    while(true){
      if (IrReceiver.available()) {
          IrReceiver.initDecodedIRData(); // is required, if we do not call decode();
          IrReceiver.decodeHash();
          IrReceiver.resume(); // Early enable receiving of the next IR frame
          /*
          * Print a summary and then timing of received data
          */
          // IrReceiver.printIRResultShort(&Serial);
          // IrReceiver.printIRResultRawFormatted(&Serial, true);

          Serial.println();

          /*
          * Finally, check the received data and perform actions according to the received command
          */
          auto data = IrReceiver.decodedIRData.decodedRawData; // uint32_t on 8 and 16 bit CPUs and uint64_t on 32 and 64 bit CPUs
          if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) {
              Serial.println(F("Repeat received. Here you can repeat the same action as before."));
          } else {
              if(data == 0){
                continue; // Ignore noise
              }

              // Serial.print(F("IR received = "));
              // Serial.println(data);
              if (data == 465573243) {
                return 0;
              }
              if (data == 3238126971) {
                return 1;
              }
              if (data == 2538093563){
                return 2;
              } 
              if (data == 4039382595){
                return 3;
              } 
              if (data == 2534850111){
                return 4;
              }
              if (data == 1033561079){
                return 5;
              } 
              if (data == 1635910171){
                return 6;
              } 
              if (data == 2351064443){
                return 7;
              } 
              if (data == 1217346747){
                return 8;
              } 
              if (data == 71952287){
                return 9;
              } 

              // Serial.print(F("Unrecognized"));
              continue;
              // Serial.print(F("Command received"));
              // Serial.println(IrReceiver.decodedIRData.command);
              // if (IrReceiver.decodedIRData.command == 0x10) {
              //     // do something
              // } else if (IrReceiver.decodedIRData.command == 0x11) {
              //     // do something else
              // }
          }
      }
    }
}

void setup() {
  Serial.begin(9600);
  Serial.println("Inizialising . . .");
  //pinMode(buz, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  IrReceiver.begin(3, ENABLE_LED_FEEDBACK);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  makeNumber(8);
  delay(500);

  lcd.print("HaTиcHiTь");
  newLine("бyдь яKy цифpy!");

  Serial.println("Started sucesfully!");
}

void loop() {
  // auto digit = getDigit();
  // Serial.print(F("digit="));
  // // Serial.println(digit);
  // for (int i = 0; i < 10; i++) {
  //   makeNumber(i);
  //   delay(100);
  // }
  // Serial.println("Test");
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
  // String line1 = "п=";
  // String line2 = "";
  
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
