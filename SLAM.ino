#include <SD.h>
#include"Logger.h";
#include"GlobalGrid.h";

void setup()
{

	//Initialize serial communication 
	Serial.begin(9600);
	Serial.println("Serial Communication Initialized");
	
	Logger::pushMethodStack("Arduino Setup");
	
	//Initialization of SD Card
	if (!SD.begin()) {
		Logger::log(Logger::File, Logger::ERROR, "SD Card Initialization failed");
		return;
	}
	Logger::log(Logger::File, Logger::INFO, "SD Card Sucessfully Initialized");

	GlobalGrid::GlobalGrid grid;
	Logger::popMethodStack();

}

void loop()
{
	Logger::log(Logger::File, Logger::INFO,"iteration");
  /* add main program code here */

}
