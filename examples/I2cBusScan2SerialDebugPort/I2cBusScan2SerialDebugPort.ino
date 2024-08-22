/*
 Name:		I2cBusScan2SerialDebugPort.ino
 Created:	8/22/2024 1:34:01 PM
 Author:	Mitchell Baldwin

 Test basic function of the I2CBusClass from the I2CBus library

*/
#include <I2CBus.h>

#include <HardwareSerial.h>
HardwareSerial USBSerial(0);				// Uses the same UART device as "Serial" but does not allow use of "Serial"?

// the setup function runs once when you press reset or power the board
void setup() {
	
	USBSerial.begin(115200);
	if (!USBSerial)
	{
		while (!USBSerial);		// Wait for serial debug port
	}
	else
	{
		USBSerial.println("");
		USBSerial.println("Serial debug port initialized");
	}

	if (I2CBus.Init(GPIO_NUM_21, GPIO_NUM_26))
	{
		I2CBus.Scan();
		USBSerial.println(I2CBus.GetActiveI2CAddressesString());
	}
	else
	{
		USBSerial.println("Error initializing I2C bus...");
	}

}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
