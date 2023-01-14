#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN D4   
#define RST_PIN D3
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
int a;
int b;

MFRC522 mfrc522(SS_PIN, RST_PIN); // Instance of the class
  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
Serial.begin(9600);
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
display.clearDisplay();
  display.display();
  display.setTextColor(WHITE); // or BLACK);
  display.setTextSize(2);
  display.setCursor(10,0); 
  display.print("RFID Lock");
  display.display();

  
    //display.drawFastHLine(0, 32, SSD1306_LCDWIDTH, WHITE);
SPI. begin();
// Init SPI bus
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
//int test=Serial.println();
//display.println(test);
  rfid.PCD_Init(); // Init MFRC522 

}
void loop() 
{
  if(  rfid.PICC_IsNewCardPresent())
  {
      readRFID();
  }
  delay(100);

}

Serial.println(); 
mfrc522.PICC_HaltA();
display.println(a);
display.print(b);
display.display(); 



}
}
}
void readRFID()
{
  
  rfid.PICC_ReadCardSerial();
  Serial.print(F("\nPICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }}

  void clearUID()
  {
    display.setTextColor(BLACK); // or BLACK);
    display.setTextSize(1);
    display.setCursor(30,20); 
    display.print(uidString);
    display.display();
  }

  void printUID()
  {
    display.setTextColor(WHITE); // or BLACK);
    display.setTextSize(1);
    display.setCursor(0,20); 
    display.print("UID: ");
    display.setCursor(30,20); 
    display.print(uidString);
    display.display();
  }
  
