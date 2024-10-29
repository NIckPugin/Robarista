#include <ESP8266WiFi.h>
#include <ESP8266LLMNR.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>

#ifndef STASSID
#define STASSID "Furhat-Coffeebot_2.4GHz"   // Wifi name
#define STAPSK  "Robarista"                 // Wifi password
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer web_server(80);

void setup(void) {
  pinMode(D8, INPUT); 
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  
  digitalWrite(D0, HIGH);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  digitalWrite(D5, HIGH);
  digitalWrite(D6, HIGH);
  digitalWrite(D7, HIGH);
    
  Serial.begin(9600);

  // Connect to WiFi network
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //Display details on wifi connection
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Start LLMNR responder
  LLMNR.begin("esp8266");
  Serial.println("LLMNR responder started");
  
  // Start HTTP server
  web_server.onNotFound(handle_http_not_found);
  web_server.on("/", handle_http_root);
  web_server.on("/test", handle_http_test);
  web_server.on("/rly1", handle_http_rly1);
  web_server.on("/rly2", handle_http_rly2);
  web_server.on("/rly3", handle_http_rly3);
  web_server.on("/rly4", handle_http_rly4);
  web_server.on("/rly5", handle_http_rly5);
  web_server.on("/rly6", handle_http_rly6);
  web_server.on("/rly7", handle_http_rly7);
  web_server.begin();
  Serial.println("HTTP server started.\nWe're good to go! c[_]");
}

void relay1(){
  Serial.println("Relay 1");
  digitalWrite(D0, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(D0, HIGH);
}

void relay2(){
  Serial.println("Relay 2");
  digitalWrite(D1, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(D1, HIGH);
}
void relay3(){
  Serial.println("Relay 3");
  digitalWrite(D2, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(D2, HIGH);  
}

void relay4(){
  Serial.println("Relay 4");
  digitalWrite(D3, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(D3, HIGH);  
}

void relay5(){
  Serial.println("Relay 5");
  digitalWrite(D4, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(D4, HIGH);  
}

void relay6(){
  Serial.println("Relay 6");
  digitalWrite(D5, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(D5, HIGH);  
}

void relay7(){
  Serial.println("Relay 7");
  digitalWrite(D6, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(D6, HIGH);  
}

//This is test that all the relays are working
void relayTest() {
    digitalWrite(D0, LOW);
    Serial.println("Relay 1");
    digitalWrite(D7, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(D0, HIGH);
    digitalWrite(D7, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)

    digitalWrite(D1, LOW);
    Serial.println("Relay 2");
    digitalWrite(D7, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(D1, HIGH);
    digitalWrite(D7, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)

    digitalWrite(D2, LOW);
    Serial.println("Relay 3");
    digitalWrite(D7, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(D2, HIGH);
    digitalWrite(D7, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)

    digitalWrite(D3, LOW);
    Serial.println("Relay 4");
    digitalWrite(D7, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(D3, HIGH);
    digitalWrite(D7, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)

    digitalWrite(D4, LOW);
    Serial.println("Relay 5");
    digitalWrite(D7, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(D4, HIGH);
    digitalWrite(D7, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)

    digitalWrite(D5, LOW);
    Serial.println("Relay 6");
    digitalWrite(D7, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(D5, HIGH);
    digitalWrite(D7, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    
    digitalWrite(D6, LOW);
    Serial.println("Relay 7");
    digitalWrite(D7, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(D6, HIGH);
    digitalWrite(D7, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)

    Serial.println("Test complete");
 }

// List of  

void handle_http_not_found() {
  web_server.send(404, "text/plain", "Not Found");
}

void handle_http_root() {
  web_server.send(200, "text/plain", "Is this thing on?\n\n    (  )   (   )  )\n     ) (   )  (  (\n     ( )  (    ) )\n     _____________\n    <_____________> ___\n    |             |/ _ \\\n    |   FURHAT      | | |\n    |  ROBOTICS     |_| |\n ___|             |\\___/\n/    \\___________/    \\\n\\_____________________/");
}

void handle_http_test() {
  web_server.send(200, "text/plain", "Hell yea! Looks like it's working! (^^,)\nRelays 1-7 should be activating one by one with a 1000ms delay.\n\n    (  )   (   )  )\n     ) (   )  (  (\n     ( )  (    ) )\n     _____________\n    <_____________> ___\n    |             |/ _ \\\n    |   FURHAT      | | |\n    |  ROBOTICS     |_| |\n ___|             |\\___/\n/    \\___________/    \\\n\\_____________________/\n");
  relayTest();  // Activate relay test sequence
}

void handle_http_rly1() {
  web_server.send(200, "text/plain", "This is activating relay 1. Which could for example make a coffee.");
  relay1();  // Activate relay 1 for 1 sec
}

void handle_http_rly2() {
  web_server.send(200, "text/plain", "This is activating relay 2. Which could for example make an espresso.");
  relay2(); // Activate relay 2 for 1 sec
}

void handle_http_rly3() {
  web_server.send(200, "text/plain", "This is activating relay 3. Which could for example Make 2 coffees.");
  relay3();  // Activate relay 3 for 1 sec
}

void handle_http_rly4() {
  web_server.send(200, "text/plain", "This is activating relay 4. Which could for example make 2 espressos.");
  relay4();  // Activate relay 4 for 1 sec
}

void handle_http_rly5() {
  web_server.send(200, "text/plain", "This is activating relay 5. Which could for example run the steamer.");
  relay5();  // Activate relay 5 for 1 sec
}

void handle_http_rly6() {
  web_server.send(200, "text/plain", "This is activating relay 6. Which could for example clean the machine.");
  relay6(); // Activate relay 6 for 1 sec
}

void handle_http_rly7() {
  web_server.send(200, "text/plain", "This is activating relay 7. Which could for example turn the machine ON/OFF.");
  relay7(); // Activate relay 7 for 1 sec
}

void loop(void) {
  web_server.handleClient();
  
/*
 //Not too sure this is needed.
  if (digitalRead(D8) == HIGH) {
    relayTest();
  } else {
    digitalWrite(D7, LOW);
    digitalWrite(D0, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
  }
*/  
}
