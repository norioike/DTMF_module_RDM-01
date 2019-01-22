//PIN ASSIGN
#define StD 2 //割り込みピンを使うと、取得できたらすぐにチェックすることが可能
#define Q4 3
#define Q3 4
#define Q2 5
#define Q1 6


String Decode[] = {
  "1", "2", "3", "4",
  "5", "6", "7", "8",
  "9", "0", "*", "#",
  "A", "B", "C", "D"
};

byte decodeTable[] = {
  B00000001, B00000010, B00000011, B00000100,
  B00000101, B00000110, B00000111, B00001000,
  B00001001, B00001010, B00001011, B00001100,
  B00001101, B00001110, B00001111, B00000000
};


void setup() {
  Serial.begin(9600);
  pinMode(StD, INPUT);
  pinMode(Q4, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q1, INPUT);
  attachInterrupt(digitalPinToInterrupt(StD), getDTMF, RISING);
}

void loop() {

}

void getDTMF() {
  int val = (digitalRead(Q4) << 3) + (digitalRead(Q3) << 2) + (digitalRead(Q2) << 1) + (digitalRead(Q1));
  //compare to decodeTable[];
  int index = 0;
  for (int i = 0; i < 16; i++) {
    if (val == decodeTable[i]) {
      index = i;
      break;
    }
  }

  Serial.print("Catch DTMF sound :");
  Serial.println(Decode[index]);
}
