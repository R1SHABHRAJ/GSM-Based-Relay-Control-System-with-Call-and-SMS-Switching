/* GSM Based Relay Control System with Call and SMS switching and whitelisting feature
 * Author@ Rishabh Raj
 */

#include <SoftwareSerial.h>
const int relayPin=4;
bool relayStatus=1;
const String phone="***********";  // white list phone include +91 or your country code

SoftwareSerial gsmSerial(7,8);

String responseData;
String senderNumber;
String incomingData;

void setup(){
  responseData.reserve(200);
  phone.reserve(20);
  pinMode(relayPin,OUTPUT);
  digitalWrite(relayPin,HIGH);
  Serial.begin(9600);
  gsmSerial.begin(9600);
  delay(100);
  gsmSerial.write("AT\r");// because of SIM800L autobounding mode
  delay(100);
  gsmSerial.write("AT+IPR=9600\r");
  delay(100);
  gsmSerial.write("AT+CMGF=1\r");
  delay(500);
  gsmSerial.write("AT+CNMI=2,2,0,0,0\r");
  delay(100);
  Serial.print(gsmSerial.readString());
  gsmSerial.write("AT+CLIP=1\r\n");
  delay(100);
}

void loop(){
  if (gsmSerial.available()>0) {
    responseData = gsmSerial.readStringUntil('\n');
    //incomingData = gsmSerial.readString();
    //Serial.println(incomingData);
    Serial.println(responseData);
    parse();
    delay(1000);
  }
}

void parse(){
  if (responseData.indexOf("CLIP:")>0){
  senderNumber=responseData.substring(responseData.indexOf("+CLIP: ") +8,responseData.indexOf("+CLIP: ") +21); //PARSE CALLER ID 
  Serial.println("Caller number   :");
  Serial.println(senderNumber);
   if (senderNumber == phone){
    Serial.println("Sender number White list : ok");
    relayStatus=!relayStatus;
    digitalWrite(relayPin,relayStatus);
    gsmSerial.write("ATH\r");  // disconnect call & then send SMS
    gsmSerial.print("AT+CMGS=\""+phone+"\"\r");
    delay(1000);
    gsmSerial.print("Relay status 1:off 0:on  ");
    gsmSerial.print(relayStatus);
    delay(200);
    gsmSerial.write(0x1A); //  ctrl+z to send message
    delay(100);
    
     }
    gsmSerial.write("ATH\r");
    delay(500);
  }
  //incomingData = gsmSerial.readString();
  if(responseData.indexOf("Led_on")>=0)
  {
    relayStatus=!relayStatus;
    digitalWrite(relayPin,relayStatus);
  }
  
  // if received command is to turn off relay
  else if(responseData.indexOf("Led_off")>=0)
  {
    relayStatus=!relayStatus;
    digitalWrite(relayPin,relayStatus);
  }
}
