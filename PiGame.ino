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




void setup() {
  pinMode(buz, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}


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



void loop() {
  makeNumber(0);
  makeNumber(1);
  makeNumber(2);
  makeNumber(3);
  makeNumber(4);
  makeNumber(5);
  makeNumber(6);
  makeNumber(7);
  makeNumber(8);
  makeNumber(9);
}
