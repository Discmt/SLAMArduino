#include <SD.h>

void setup()
{

	//Initialize serial communication 
	Serial.begin(9600);
	
	//Initialization of SD Card
	if (!SD.begin(4)) {
		Serial.println("initialization failed!");
		return;
	}

	GlobalGrid::GlobalGrid grid;






}

void loop()
{

  /* add main program code here */

}
