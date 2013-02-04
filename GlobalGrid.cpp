#include"GlobalGrid.h";


int GlobalGrid::GlobalGrid::findLinePositionOfGridNode(int x, int y) {
	
	Logger::pushMethodStack("Find Line Number Of Grid Node");
	
	//Open the file
	if(!SD.exists("GMAP.map")) {
		return -1;
	}
	File globalGrid = SD.open("GMAP.map", FILE_READ);
	Logger::log(Logger::GlobalGrid, Logger::DEBUG, "Found the map");

	int tempX,tempY;
	char * quote = new char;
	*quote = '\"';
	char * openBrace = new char;
	*openBrace = '{';

	if(globalGrid) {
		while(globalGrid.available()) {
			Logger::pushMethodStack("Finding Line Number Loop");
			//Find the first quotation
			globalGrid.find(quote);

			//Read in the x value
			tempX = globalGrid.parseInt();

			if(globalGrid.read() != ',') {
				Logger::log(Logger::GlobalGrid,Logger::ERROR,"Map is not proper format");
				break;
			}

			//Read in the y value
			tempY = globalGrid.parseInt();
			
			if(tempX == x && tempY == y) {
				globalGrid.find(openBrace);
				int pos = globalGrid.position();
				Logger::logHeader(Logger::GlobalGrid, Logger::DEBUG, "Found the node at position");
				Serial.print(pos,DEC);
				Logger::logFooter(Logger::GlobalGrid, Logger::DEBUG);
				Logger::popMethodStack();
				Logger::popMethodStack();
				return pos;
			}
			
			Logger::log(Logger::GlobalGrid,Logger::DEBUG, "Skipping current grid node");
			globalGrid.find(openBrace);
			int nestLevel = 1;
			do {
				char c = globalGrid.read();
				
				if(c == '{') {
					nestLevel++;
				} 

				if(c == '}') {
					nestLevel--;
				} 


			} while(nestLevel > 0);
				Logger::log(Logger::GlobalGrid,Logger::DEBUG, "End of iteration");
		}
	} else {
		Logger::popMethodStack();
		//Make this verbose because map may intially be empty
		Logger::log(Logger::GlobalGrid, Logger::VERBOSE, "Map not avaliable for reading");
		return -1;
	}
	Logger::logHeader(Logger::GlobalGrid, Logger::DEBUG, "Global Grid Node Not Found:");
	Serial.print("X: ");
	Serial.println(x,DEC);
	Serial.print("Y: ");
	Serial.println(y,DEC);
	Logger::logFooter(Logger::GlobalGrid, Logger::DEBUG);
	//We didn't find it
	Logger::popMethodStack();
	Logger::popMethodStack();
	return -1;
}

/** Get the LocalGrid for the specified RobotPose. The robot pose is considered to be the center. */
LocalGrid::LocalGrid GlobalGrid::GlobalGrid::getLocalGrid(RobotPose::RobotPose pose) {
	int x = pose.getX();
	int y = pose.getY();
}

void GlobalGrid::GlobalGrid::update(LocalGrid::LocalGrid localGrid) {
	int x = localGrid.getX();
	int y = localGrid.getY();
	int position =  findLinePositionOfGridNode(x,y);
	GlobalGridNode centerNode(position);
}


GlobalGrid::GlobalGrid::GlobalGrid() {
        Logger::pushMethodStack("GlobalGridConstructor");
        Logger::log(Logger::GlobalGrid, Logger::INFO ,"Constructing global grid...");
	
	    Logger::log(Logger::GlobalGrid, Logger::DEBUG,"Checking for file", "GMMETA.mta"); 
        
		if(SD.exists("GMMETA.mta"))  // If the meta file exists we load data from it. 
        {
           Logger::log(Logger::GlobalGrid, Logger::INFO, "Meta file exists... loading map from file");
        } 
        else // Else we have to create it ourselves 
        {
            Logger::log(Logger::GlobalGrid, Logger::INFO, "Meta file does not exists... creating now");

		    Logger::log(Logger::GlobalGrid, Logger::INFO, "Creating MetaData file");
            
			File metaFile = SD.open("GMMETA.mta", FILE_WRITE);
			if(metaFile) {
				Logger::log(Logger::GlobalGrid, Logger::DEBUG, "File created...Writing initialization data to meta file");
				metaFile.write("+++GLOBALMETAFILE+++\n");
				metaFile.write("MAPFILENAME=GMAP.map\n");
				metaFile.flush();
				metaFile.close();
			} else {
				Logger::log(Logger::GlobalGrid, Logger::ERROR, "Unable to write to meta file... the code cannot continue like this");
			}

            Logger::log(Logger::GlobalGrid, Logger::INFO, "Creating Global Map");            
            
            if(SD.exists("GMAP.map")) {
				Logger::log(Logger::GlobalGrid, Logger::DEBUG, "No meta file found, but map file found", "Deleting map file");
                SD.remove("GMAP.map");
            }
			//Create the gridmap file 
			File globalGridFile = SD.open("GMAP.map", FILE_WRITE);
			//Close the file
			globalGridFile.close();
			
        } 
 }
 
GlobalGrid::GlobalGridNode::GlobalGridNode(int lineNumber) {
	lineNumber_ = lineNumber;
}
 
