#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#define LED_G 4 //define green LED pin
#define LED_R 3 //define red LED
#define SS_PIN 10
#define RST_PIN 9
#define BUZZER 5 //buzzer pin
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo servo; //define servo name
int angle = 12;
void setup() 
{
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  servo.attach(8); //servo pin
  servo.write(angle); //servo start position
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  Serial.println("Put your card to the reader...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "DB EC B7 15") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(LED_G, HIGH);
    Serial.println("Authorized access");
    Serial.println();
    tone(BUZZER, 500);
    delay(100);
    noTone(BUZZER);
    delay(1000);
    digitalWrite(LED_G, LOW);
    for(angle = 10; angle < 180; angle++)  
    {                                  
        servo.write(angle);              
        delay(15);                   
    }
    for(angle = 180; angle > 10; angle--)    
    {                                
        servo.write(angle);           
        delay(15);       
    } 
   
 }
 else if (content.substring(1) == "FA 55 9A 16") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(LED_G, HIGH);
    Serial.println("Authorized access");
    Serial.println();
    tone(BUZZER, 500);
    delay(100);
    noTone(BUZZER);
    digitalWrite(LED_G, LOW);
    for(angle = 10; angle < 180; angle++)  
    {                                  
        servo.write(angle);              
        delay(15);                   
    }
    for(angle = 180; angle > 10; angle--)    
    {                                
        servo.write(angle);           
        delay(15);       
    } 
  }
  else if (content.substring(1) == "EC 84 2D 2B") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(LED_G, HIGH);
    Serial.println("Authorized access");
    Serial.println();
    tone(BUZZER, 500);
    delay(1000);
    noTone(BUZZER);
    digitalWrite(LED_G, LOW);
    for(angle = 10; angle < 180; angle++)  
    {                                  
        servo.write(angle);              
        delay(15);                   
    }
    for(angle = 180; angle > 10; angle--)    
    {                                
        servo.write(angle);           
        delay(15);       
    } 
  }
  
  else if (content.substring(1) == "BD 12 10 2B") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(LED_G, HIGH);
    Serial.println("Authorized access");
    Serial.println();
    tone(BUZZER, 500);
    delay(100);
    noTone(BUZZER);
    digitalWrite(LED_G, LOW);
    for(angle = 10; angle < 180; angle++)  
    {                                  
        servo.write(angle);              
        delay(15);                   
    }
    for(angle = 180; angle > 10; angle--)    
    {                                
        servo.write(angle);           
        delay(15);       
    } 
  }
  else if (content.substring(1) == "20 6D 2D 2B") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(LED_G, HIGH);
    Serial.println("Authorized access");
    Serial.println();
    tone(BUZZER, 500);
    delay(100);
    noTone(BUZZER);
    digitalWrite(LED_G, LOW);
    for(angle = 10; angle < 180; angle++)  
    {                                  
        servo.write(angle);              
        delay(15);                   
    }
    for(angle = 180; angle > 10; angle--)    
    {                                
        servo.write(angle);           
        delay(15);       
    } 
  }
 else   {
    Serial.println(" Access denied");
    tone(BUZZER, 100);
    digitalWrite(LED_R, HIGH);
    delay(3000);
    noTone(BUZZER);
    digitalWrite(LED_R, LOW);
  }
} 
