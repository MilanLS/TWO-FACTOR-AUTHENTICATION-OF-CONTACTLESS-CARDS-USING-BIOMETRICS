#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MFRC522.h>
#include <DFRobot_ID809.h>
/*Use software serial when using UNO or NANO */
#if ((defined ARDUINO_AVR_UNO) || (defined ARDUINO_AVR_NANO))

#define SS_PIN D4
#define RST_PIN D3
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define NUMFLAKES     10 // Number of snowflakes in the animation example
MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup()
{
    while(fingerprint.isConnected() == false){
    Serial.println("Communication with device failed, please check connection");
    delay(1000);

}
Serial. begin(9600);
SPI. begin();
mfrc522.PCD_Init(); 
Serial.println("RFID reading UID");
}
void loop() 
{
    if((ID = fingerprint.getEmptyID()) == ERR_ID809){
    while(1){
      delay(1000);
    }
  }
  Serial.println(ID);
  i = 0;   //Clear sampling times 

  while(i < COLLECT_NUMBER){
    if((fingerprint.collectionFingerprint(/*timeout = */10)) != ERR_ID809){
      Serial.println("Sampling succeeds");
      i++;   //Sampling times +1
    }else{
      Serial.println("Sampling failed");
      /*Get error code information*/
      //desc = fingerprint.getErrorDescription();
      //Serial.println(desc);
    }
    Serial.println("Please release your finger");
    delay(1000);
  }
else{
    Serial.println("Saving failed");

}
MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  Serial.println(F("**Card Detected:**"));
  Serial.print(F("Name: "));
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 4, &key, &(mfrc522.uid)); //line 834 of MFRC522.cpp file
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }
  status = mfrc522.MIFARE_Read(block, buffer1, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Reading failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }
  for (uint8_t i = 0; i < 16; i++)
  {
    if (buffer1[i] != 32)
    {
      Serial.write(buffer1[i]);
    }
  Serial.print(" ");
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 1, &key,&(mfrc522.uid)); //line 834
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;

  display.clearDisplay();   
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Tap Your   Card");
  display.display();
  delay(5000);  
}
 if ( mfrc522.PICC_IsNewCardPresent())
{
if ( mfrc522.PICC_ReadCardSerial())
{
Serial.print("Tag UID:");
for (byte i = 0; i < mfrc522.uid.size; i++) {
Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
Serial.print(mfrc522.uid.uidByte[i], HEX);
}
Serial.println(); 
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Present Your Finger");
  display.display();
  delay(3000);
  
mfrc522.PICC_HaltA();
}
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 4, &key, &(mfrc522.uid)); //line 834 of MFRC522.cpp file
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

}
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 1);
  display.println("Biometrics Accepted");
  display.display();
  delay(5000);
}
  }
  Serial.println(ID);
  i = 0;   //Clear sampling times 

  while(i < COLLECT_NUMBER){
    if((fingerprint.collectionFingerprint(/*timeout = */10)) != ERR_ID809){
      Serial.println("Sampling succeeds");
      i++;   //Sampling times +1
    }else{
      Serial.println("Sampling failed");
      /*Get error code information*/
      //desc = fingerprint.getErrorDescription();
      //Serial.println(desc);
    }
    Serial.println("Please release your finger");
    delay(1000);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 1);
  display.println("Transaction Approved");
  display.display();
  delay(10000);
}
  }
  Serial.println(ID);
  i = 0;   //Clear sampling times 

  while(i < COLLECT_NUMBER){
    if((fingerprint.collectionFingerprint(/*timeout = */10)) != ERR_ID809){
      Serial.println("Sampling succeeds");
      i++;   //Sampling times +1
    }else{
      Serial.println("Sampling failed");
      /*Get error code information*/
      //desc = fingerprint.getErrorDescription();
      //Serial.println(desc);
    }
    Serial.println("Please release your finger");
    delay(1000);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 1);
  display.println("Biometrics Mismatched");
  display.display();
  delay(5000);
}
  while(fingerprint.isConnected() == false){
    Serial.println("Communication with device failed, please check connection");
    /*Get error code information*/
    //desc = fingerprint.getErrorDescription();
    //Serial.println(desc);
    delay(1000);
  }
}

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 1);
  display.println("Transaction Declined");
  display.display();
  delay(5000);
}
