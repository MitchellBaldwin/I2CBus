/*
 Name:		I2cBusScan2SerialDebugPort.ino
 Created:	8/22/2024 1:34:01 PM
 Author:	Mitchell Baldwin

 Test basic function of the I2CBusClass from the I2CBus library

*/
#include <I2CBus.h>

//#include <HardwareSerial.h>
//HardwareSerial Serial(0);	// Uses the same UART device as "Serial" but does not allow use of "Serial"?

// the setup function runs once when you press reset or power the board
void setup() {
	
	Serial.begin(115200);
	if (!Serial)
	{
		while (!Serial);		// Wait for serial debug port
	}
	else
	{
		Serial.println("");
		Serial.println("Serial debug port initialized");
	}

	if (I2CBus.Init(GPIO_NUM_43, GPIO_NUM_44))
	{
		I2CBus.Scan();
		Serial.println(I2CBus.GetActiveI2CAddressesString());
	}
	else
	{
		Serial.println("Error initializing I2C bus...");
	}

}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
