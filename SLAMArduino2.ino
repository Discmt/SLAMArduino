#include <BaseTsd.h>
#include <SoftwareSerial.h>
#include"GlobalGrid.h"
#include"Logger.h"
#include<SD.h>

void setup()
{
  
        //Initialize serial communication 
	Serial.begin(9600);
	
	 //setTime(0); 
        
        Logger::pushMethodStack("Arduino Setup");
        
	//Initialization of SD Card
	if (!SD.begin()) {
		Logger::log(Logger::File, "SD Card Initialization Failed", "Exiting program");
		return;
	}
        
        GlobalGrid::GlobalGrid globalGrid;
         Logger::popMethodStack();

        
        
        

}

void loop()
{

  /* add main program code here */

}
