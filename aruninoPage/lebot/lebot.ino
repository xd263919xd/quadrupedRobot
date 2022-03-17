/*
//  ----          ----
// | 00 |        | 03 |
//  ---- -------- ----
//      | 01  02 |
//      |        |
//      | 14  13 |
//  ---- -------- ----
// | 15 |        | 12 |
//  ----          ----
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "Wire.h"
#include "Adafruit_PWMServoDriver.h"
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define MIN_PULSE_WIDTH 600
#define MAX_PULSE_WIDTH 2600
#define FREQUENCY 50

ESP8266WebServer server(80);

const char* ssid = "bb319-5n2f-1-2.4G";
const char* pass = "0972326612";

void setup() {
  Serial.begin(115200);
  Serial.println();
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);



  //站立
  pwm.setPWM(0, 0, pulseWidth(90));
  pwm.setPWM(1, 0, pulseWidth(90));
  pwm.setPWM(2, 0, pulseWidth(90));
  pwm.setPWM(3, 0, pulseWidth(90));
  pwm.setPWM(12, 0, pulseWidth(90));
  pwm.setPWM(13, 0, pulseWidth(90));
  pwm.setPWM(14, 0, pulseWidth(90));
  pwm.setPWM(15, 0, pulseWidth(90));
  delay(500);
  pwm.setPWM(0, 0, pulseWidth(70));
  pwm.setPWM(1, 0, pulseWidth(90));
  pwm.setPWM(2, 0, pulseWidth(90));
  pwm.setPWM(3, 0, pulseWidth(110));
  pwm.setPWM(12, 0, pulseWidth(110));
  pwm.setPWM(13, 0, pulseWidth(90));
  pwm.setPWM(14, 0, pulseWidth(90));
  pwm.setPWM(15, 0, pulseWidth(70));


  WiFi.begin(ssid, pass);
  server.begin();

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  server.on("/", HTTP_POST, fun1);
   
  
  Serial.println();
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void fun1(){
  Serial.println();
  int s = server.arg("t1").toInt();
  Serial.print("s:");
  Serial.println(s);
  
  switch(s){
    case 1: //前進
      pwm.setPWM(0, 0, pulseWidth(70));
      pwm.setPWM(1, 0, pulseWidth(90));
      pwm.setPWM(2, 0, pulseWidth(30));
      pwm.setPWM(3, 0, pulseWidth(110));
      pwm.setPWM(12, 0, pulseWidth(110));
      pwm.setPWM(13, 0, pulseWidth(150));
      pwm.setPWM(14, 0, pulseWidth(90));
      pwm.setPWM(15, 0, pulseWidth(70));
      delay(200);
      pwm.setPWM(0, 0, pulseWidth(70));
      pwm.setPWM(1, 0, pulseWidth(90));
      pwm.setPWM(2, 0, pulseWidth(110));
      pwm.setPWM(3, 0, pulseWidth(90));
      pwm.setPWM(12, 0, pulseWidth(110));
      pwm.setPWM(13, 0, pulseWidth(150));
      pwm.setPWM(14, 0, pulseWidth(90));
      pwm.setPWM(15, 0, pulseWidth(70));
      delay(200);
      pwm.setPWM(0, 0, pulseWidth(70));
      pwm.setPWM(1, 0, pulseWidth(150));
      pwm.setPWM(2, 0, pulseWidth(90));
      pwm.setPWM(3, 0, pulseWidth(110));
      pwm.setPWM(12, 0, pulseWidth(110));
      pwm.setPWM(13, 0, pulseWidth(90));
      pwm.setPWM(14, 0, pulseWidth(110));
      pwm.setPWM(15, 0, pulseWidth(90));
      delay(200);
      pwm.setPWM(0, 0, pulseWidth(70));
      pwm.setPWM(1, 0, pulseWidth(150));
      pwm.setPWM(2, 0, pulseWidth(90));
      pwm.setPWM(3, 0, pulseWidth(110));
      pwm.setPWM(12, 0, pulseWidth(110));
      pwm.setPWM(13, 0, pulseWidth(90));
      pwm.setPWM(14, 0, pulseWidth(30));
      pwm.setPWM(15, 0, pulseWidth(70));
      delay(200);
      pwm.setPWM(0, 0, pulseWidth(90));
      pwm.setPWM(1, 0, pulseWidth(70));
      pwm.setPWM(2, 0, pulseWidth(90));
      pwm.setPWM(3, 0, pulseWidth(110));
      pwm.setPWM(12, 0, pulseWidth(110));
      pwm.setPWM(13, 0, pulseWidth(90));
      pwm.setPWM(14, 0, pulseWidth(30));
      pwm.setPWM(15, 0, pulseWidth(70));
      delay(200);
      pwm.setPWM(0, 0, pulseWidth(70));
      pwm.setPWM(1, 0, pulseWidth(90));
      pwm.setPWM(2, 0, pulseWidth(30));
      pwm.setPWM(3, 0, pulseWidth(110));
      pwm.setPWM(12, 0, pulseWidth(90));
      pwm.setPWM(13, 0, pulseWidth(70));
      pwm.setPWM(14, 0, pulseWidth(90));
      pwm.setPWM(15, 0, pulseWidth(70));
      delay(200);
      break;
    case 2: //左移
      pwm.setPWM(0, 0, pulseWidth(70));
      pwm.setPWM(1, 0, pulseWidth(110));
      pwm.setPWM(2, 0, pulseWidth(110));
      pwm.setPWM(3, 0, pulseWidth(110));
      pwm.setPWM(12, 0, pulseWidth(110));
      pwm.setPWM(13, 0, pulseWidth(110));
      pwm.setPWM(14, 0, pulseWidth(110));
      pwm.setPWM(15, 0, pulseWidth(70));
      delay(500);
      pwm.setPWM(0, 0, pulseWidth(70));
      pwm.setPWM(1, 0, pulseWidth(90));
      pwm.setPWM(2, 0, pulseWidth(90));
      pwm.setPWM(3, 0, pulseWidth(110));
      pwm.setPWM(12, 0, pulseWidth(110));
      pwm.setPWM(13, 0, pulseWidth(90));
      pwm.setPWM(14, 0, pulseWidth(90));
      pwm.setPWM(15, 0, pulseWidth(70));
      delay(200);
      break;

    case 3: //右移
      pwm.setPWM(0, 0, pulseWidth(70));
      pwm.setPWM(1, 0, pulseWidth(70));
      pwm.setPWM(2, 0, pulseWidth(70));
      pwm.setPWM(3, 0, pulseWidth(110));
      pwm.setPWM(12, 0, pulseWidth(110));
      pwm.setPWM(13, 0, pulseWidth(50));
      pwm.setPWM(14, 0, pulseWidth(50));
      pwm.setPWM(15, 0, pulseWidth(70));
      delay(500);
      pwm.setPWM(0, 0, pulseWidth(70));
      pwm.setPWM(1, 0, pulseWidth(90));
      pwm.setPWM(2, 0, pulseWidth(90));
      pwm.setPWM(3, 0, pulseWidth(110));
      pwm.setPWM(12, 0, pulseWidth(110));
      pwm.setPWM(13, 0, pulseWidth(90));
      pwm.setPWM(14, 0, pulseWidth(90));
      pwm.setPWM(15, 0, pulseWidth(70));
      delay(200);
      break;
    case 4: //後退
      pwm.setPWM(0, 0, pulseWidth(70));
      pwm.setPWM(1, 0, pulseWidth(90));
      pwm.setPWM(2, 0, pulseWidth(30));
      pwm.setPWM(3, 0, pulseWidth(110));
      pwm.setPWM(12, 0, pulseWidth(90));
      pwm.setPWM(13, 0, pulseWidth(70));
      pwm.setPWM(14, 0, pulseWidth(90));
      pwm.setPWM(15, 0, pulseWidth(70));
      delay(200);
      pwm.setPWM(0, 0, pulseWidth(90));
      pwm.setPWM(1, 0, pulseWidth(70));
      pwm.setPWM(2, 0, pulseWidth(90));
      pwm.setPWM(3, 0, pulseWidth(110));
      pwm.setPWM(12, 0, pulseWidth(110));
      pwm.setPWM(13, 0, pulseWidth(90));
      pwm.setPWM(14, 0, pulseWidth(30));
      pwm.setPWM(15, 0, pulseWidth(70));
      delay(200);
      pwm.setPWM(0, 0, pulseWidth(70));
      pwm.setPWM(1, 0, pulseWidth(150));
      pwm.setPWM(2, 0, pulseWidth(90));
      pwm.setPWM(3, 0, pulseWidth(110));
      pwm.setPWM(12, 0, pulseWidth(110));
      pwm.setPWM(13, 0, pulseWidth(90));
      pwm.setPWM(14, 0, pulseWidth(30));
      pwm.setPWM(15, 0, pulseWidth(70));
      delay(200);
      pwm.setPWM(0, 0, pulseWidth(70));
      pwm.setPWM(1, 0, pulseWidth(150));
      pwm.setPWM(2, 0, pulseWidth(90));
      pwm.setPWM(3, 0, pulseWidth(110));
      pwm.setPWM(12, 0, pulseWidth(110));
      pwm.setPWM(13, 0, pulseWidth(90));
      pwm.setPWM(14, 0, pulseWidth(110));
      pwm.setPWM(15, 0, pulseWidth(90));
      delay(200);
      pwm.setPWM(0, 0, pulseWidth(70));
      pwm.setPWM(1, 0, pulseWidth(90));
      pwm.setPWM(2, 0, pulseWidth(110));
      pwm.setPWM(3, 0, pulseWidth(90));
      pwm.setPWM(12, 0, pulseWidth(110));
      pwm.setPWM(13, 0, pulseWidth(150));
      pwm.setPWM(14, 0, pulseWidth(90));
      pwm.setPWM(15, 0, pulseWidth(70));
      delay(200);
      pwm.setPWM(0, 0, pulseWidth(70));
      pwm.setPWM(1, 0, pulseWidth(90));
      pwm.setPWM(2, 0, pulseWidth(30));
      pwm.setPWM(3, 0, pulseWidth(110));
      pwm.setPWM(12, 0, pulseWidth(110));
      pwm.setPWM(13, 0, pulseWidth(150));
      pwm.setPWM(14, 0, pulseWidth(90));
      pwm.setPWM(15, 0, pulseWidth(70));
      delay(200);
      break;
    case 0: //歸復
       pwm.setPWM(0, 0, pulseWidth(90));
       pwm.setPWM(1, 0, pulseWidth(90));
       pwm.setPWM(2, 0, pulseWidth(90));
       pwm.setPWM(3, 0, pulseWidth(90));
       pwm.setPWM(12, 0, pulseWidth(90));
       pwm.setPWM(13, 0, pulseWidth(90));
       pwm.setPWM(14, 0, pulseWidth(90));
       pwm.setPWM(15, 0, pulseWidth(90));
       delay(500);
       pwm.setPWM(0, 0, pulseWidth(70));
       pwm.setPWM(1, 0, pulseWidth(90));
       pwm.setPWM(2, 0, pulseWidth(90));
       pwm.setPWM(3, 0, pulseWidth(110));
       pwm.setPWM(12, 0, pulseWidth(110));
       pwm.setPWM(13, 0, pulseWidth(90));
       pwm.setPWM(14, 0, pulseWidth(90));
       pwm.setPWM(15, 0, pulseWidth(70));
    
      break;
  }
}

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
  }

void loop() {
  server.handleClient();

}
