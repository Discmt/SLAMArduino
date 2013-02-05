#include <SD.h>
#include"Logger.h";
#include"GlobalGrid.h";


char * convertToChar(int i);


void setup()
{
	//pinMode(10,OUTPUT);
	////Initialize serial communication 
	Serial.begin(9600);
	//Serial.println("Serial Communication Initialized");
	//
	//Logger::pushMethodStack("Arduino Setup");
	//
	//Initialization of SD Card
	if (!SD.begin()) {
		Logger::log(Logger::File, Logger::ERROR, "SD Card Initialization failed");
		return;
	}
	Logger::log(Logger::File, Logger::INFO, "SD Card Sucessfully Initialized");
        GlobalGrid::GlobalGrid globalGrid;
        //globalGrid.writeNode(0,0,LocalGrid::White);
	//if(SD.exists("GMMETA.txt")){
	//	SD.remove("GMMETA.txt");
	//}

	//
	//Logger::log(Logger::GlobalGrid, Logger::INFO, "Meta file does not exists... creating now");

	//Logger::log(Logger::GlobalGrid, Logger::INFO, "Creating MetaData file");
 //           
	//File metaFile = SD.open("GMMETA.txt", FILE_WRITE);
	//if(metaFile) {
	//	Logger::log(Logger::GlobalGrid, Logger::DEBUG, "File created...Writing initialization data to meta file");
	//	metaFile.write("+++GLOBALMETAFILE+++\n");
	//	metaFile.write("MAPFILENAME=GMAP.txt");
	//	metaFile.flush();
	//	metaFile.close();
	//} else {
	//	Logger::log(Logger::GlobalGrid, Logger::ERROR, "Unable to write to meta file... the code cannot continue like this");
	//	return;
	//}

	//Logger::log(Logger::GlobalGrid, Logger::INFO, "Creating Global Map");            
	////writeNode(0,0, LocalGrid::White);
	//if(SD.exists("GMAP.txt")) {
	//	Logger::log(Logger::GlobalGrid, Logger::DEBUG, "No meta file found, but map file found", "Deleting map file");
	//	SD.remove("GMAP.txt");
	//}
	//

	////GlobalGrid::GlobalGrid grid;
	//	File map = SD.open("GMAP.txt", FILE_WRITE);
	//////Logger::pushMethodStack("Write Node");
	//int x = 0;
	//int y = 0;
	//if(map) {
	//	map.write('0');
	//	//Serial.print(convertToChar(x));
	//	//map.write('\"');
	//	//map.write(convertToChar(x));
	//	//map.write(',');
	//	//map.write(convertToChar(y));
	//	//map.write('\"');
	//	//map.write('{');
	//	//map.write('\n');
	//	//map.write(convertToChar(LocalGrid::White));
	//	//map.write('\n');
	//	//map.write('}');
	//	//if(map.available() != 0) {
	//	//	map.write(',');
	//	//} 
	//	map.flush();
	//	map.close();
	//	map = SD.open("GMAP.txt", FILE_READ);;
	//	while(map.available() > 0) {
	//		Serial.println(map.read());
	//	}
	//	map.close();

		//Logger::logHeader(Logger::GlobalGrid, Logger::VERBOSE, "Wrote Node");
		//String s;
		//s+="Color:";
		////s+=LocalGrid::White;
		//s+='\n';
		//s+="x:";
		//s+=x;
		//s+='\n';
		//s+="y:";
		//s+=y;
		//Serial.print(s);
		//Logger::popMethodStack();
		//map.flush();
		//map.close();
	

		

}




 int convertToInt(char i) {
	int c;
	switch(i) {
		case 0:
			c =  0;
		case 1:
			c =  1;
			break;
		case 2:
			c =  2;
			break;
		case 3:
			c =  3;
			break;
		case 4:
			c = 4;
			break;
		case 5:
			c = 5;
			break;
		case 6:
			c = 6;
			break;
		case 7:
			c = 7;
			break;
		case 8:
			c = 8;
			break;
		case 9:
			c = 9;
			break;
	}
	return c;
}

void loop()
{
        Serial.println("Im in a loop!");


}
