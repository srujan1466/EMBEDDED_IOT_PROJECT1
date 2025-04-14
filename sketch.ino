#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,26,25,33,32);

int button=22;
int button2=21;
volatile int count=0;
volatile int button_press;
volatile int button_last=0;
int a=0;
void IRAM_ATTR isr(){
  button_press=millis();
  if (button_press-button_last>250){
  count++;
  button_last=button_press;
  }
}

void setup(void) {
  Serial.begin(115200);
  pinMode(button,INPUT_PULLUP);
  attachInterrupt(button,isr,FALLING);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("HELLO");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("COUNT=0");
}

void loop(void) {
  if(a!=count){
  a=count;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("COUNT=");
  lcd.print(count);
  delay(10);
  }
}