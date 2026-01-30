#include <LiquidCrystal.h> 
LiquidCrystal lcd(45, 43, 41, 39, 37, 35);

int8_t dizi[16] = {0, 1, -1, 0, -1, 0, 0, 1, 0, 0, -1, 1, 0, 1, -1, 0};

 volatile long enk = 0; 
uint8_t eskisayi = 0;

float x0 = 0;
float x1 = 0;
float x2 = 0;


const float deltaT = 0.1; 
unsigned long sonzaman = 0;

void setup() {
  lcd.begin(16, 2); 
  Serial.begin(9600); 
  

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(2), encoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), encoder, CHANGE);
  
  lcd.clear();
}

void loop() {

  if (millis() - sonzaman >= 100) {
    sonzaman = millis(); 

    
    x2 = x1;      
    x1 = x0;     
    
    noInterrupts();
    x0 = enk;   
    interrupts(); 
    

    
    float hiz = (3.0 * x0 - 4.0 * x1 + x2) / (2.0 * deltaT); 

    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Konum: ");
    lcd.print((int)x0);
    
    lcd.setCursor(0, 1);
    lcd.print("Hiz: ");
    lcd.print(hiz);
  }
}


void encoder() {
  int sayi = 2*digitalRead(2) + digitalRead(3); 
  
  
  enk += dizi[4 * sayi + eskisayi]; 
  eskisayi = sayi;
}