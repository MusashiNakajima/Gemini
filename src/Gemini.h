#ifndef Gemini_h
#define Gemini_h

#include <ArdOSC.h>
#include <ESP8266WiFi.h>
#include "Token.h"

//tokenのosc	アドレスは，
//（コーディネータIP）/（Geminiネーム）/（番号）

class Gemini {
public:
	Gemini();
	~Gemini();
	
	void begin();
	void monitor();
	void output(int_16 v);
	int input();
	void sendInfo();
	void sendInitTokenReq();
	void sendDelTokenReq();

private:
	WiFiUDP udp;
	WiFiClient client;
	WiFiServer server(6341);

	OSCDecoder decorder;
	OSCEncoder encoder;
	Pattern parser;
	int_16 input, output;
	void addFunc();
	void infoReqReceved(OSCMessage *_mes);
	void initReqReceved(OSCMessage *_mes);
	void delReqReceved(OSCMessage *_mes);
	void dataReceived(OSCMessage *_mes);
};
#endif
