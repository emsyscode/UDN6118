uint8_t hexNumber = 0x00;
uint8_t grid = 0x01;

char list[18]= {0b11000000, //0
                0b11111001, //1
                0b10100100, //2
                0b10110000, //3
                0b10011001, //4
                0b10010010, //5
                0b10000010, //6
                0b11111000, //7
                0b10000000, //8
                0b10011000, //9
                0b10001000, //A
                0b10000011, //B
                0b11000110, //C
                0b10100001, //D
                0b10000110, //E
                0b10001110, //F
                0b11000010, //g  
                0b10001001  //H
};
char msgHello[9]=  {0b10001001, //H
                    0b10000110, //E
                    0b11000111, //L
                    0b11000111, //L
                    0b11000000, //O
                    0b11111111, //empty
                    0b11111111, //empty
                    0b11111111, //empty
                    0b11111111  //empty
};

char msgPeople[9]=  {0b10001100, //P
                     0b10000110, //E
                     0b11000000, //O
                     0b10001100, //P
                     0b11000111, //L
                     0b10000110, //E
                     0b11111111, //empty
                     0b11111111, //empty
                     0b11111111  //empty
};
//This is the values in HEX format: {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x98,0x88,0x83,0xC6,0x81,0x86,0x8E}
//Please don't forget they are on format inverted, "0" is a segment on, "1" is a segment off, this happen because the 
//type of display be a Anode Commun.

void setup() {
  // put your setup code here, to run once:
  DDRA = 0xFF;
  DDRC = 0xFF;

  PORTA = 0xFF;
  PORTC = 0xFF;

}

void msgH(){
  for(uint8_t s = 0x00; s < 155; s++){
    grid=0x01;
    for(uint8_t i = 0x00; i < 8; i++){
        PORTC = grid;
        hexNumber = (msgHello[i]);
        PORTA = ~hexNumber;
        delay(2);
          if(grid >= 0x80){
            grid=0x01;
          }
        grid = grid << 1;
      }
  }
}
void msgP(){
  for(uint8_t s = 0x00; s < 155; s++){
    grid=0x01;
    for(uint8_t i = 0x00; i < 8; i++){
        PORTC = grid;
        hexNumber = (msgPeople[i]);
        PORTA = ~hexNumber;
        delay(2);
          if(grid >= 0x80){
            grid=0x01;
          }
        grid = grid << 1;
      }
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(24, HIGH);
  digitalWrite(25, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
  digitalWrite(29, HIGH);

  digitalWrite(30, HIGH);
  digitalWrite(31, HIGH);
  digitalWrite(32, HIGH);
  digitalWrite(33, HIGH);
  digitalWrite(34, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(36, HIGH);
  digitalWrite(37, HIGH);

  delay(1000);
  PORTA = 0x00;
  PORTC = 0x00;
  delay(1000);
  PORTA = 0xFF;
  PORTC = 0xFF;
  delay(1000);

  for(uint8_t i = 0x00; i < 18; i++){
        PORTC = grid;
        hexNumber = (list[i]);
        PORTA = ~hexNumber;
        delay(1000);
          if(grid >= 0x80){
            grid=0x01;
          }
        grid = grid << 1;
    }

  while(1){
      msgH();
      msgP();  
  }

}
