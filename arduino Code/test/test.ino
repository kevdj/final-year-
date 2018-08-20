
#include <MFRC522.h>
#include <SPI.h>

 
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
char myStrings[]={"chocolate,0.50,2,tesco"};// "chocolate,5.00,1,odeon" "chocolate,1.00,4,UDF" "chocolate,2.00,2,tesco"
 String inData = "";
 String temp = "";

 
void setup() 
{
  Serial.begin(9600);
  SPI.begin();// Initiate a serial communication
  mfrc522.PCD_Init();
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  
 

}
void loop() 
{ 

   while(Serial.available()> 0){
    char sdata = Serial.read();
      temp = sdata;
    inData = temp;
    if(inData== "1"){
      digitalWrite(5, HIGH);
     delay(1000);
     digitalWrite(5,LOW);
     }

     else{
     
       digitalWrite(6, HIGH);
     delay(1000);
     digitalWrite(6,LOW);  
    
    
  }
  
        }
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

  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
   
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();

      
  
  if (content.substring(1) == "E7 51 55 C5")
  {
   
  
     Serial.println(myStrings);

//      digitalWrite(5, HIGH);
//       delay(1000);
//       digitalWrite(5,LOW);
   
    delay(500);
  }

   else   {
    Serial.println(" Access denied");
    delay(1000);

  }
  
   
 

} 

