#include"GlobalGrid.h";


int GlobalGrid::GlobalGrid::findPositionOfGridNode(int x, int y) {
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

GlobalGrid::GlobalGrid::GlobalGrid() {
         numberOfNodes_ = 0;
	 Logger::log(Logger::GlobalGrid, Logger::DEBUG,"Checking for file", "GMMETA.txt"); 
         if(SD.exists("GMMETA.txt")) {
	      SD.remove("GMMETA.txt");
         }

        if(SD.exists("GMMETA.txt"))  // If the meta file exists we load data from it. 
        {
            Logger::log(Logger::GlobalGrid, Logger::INFO, "Meta file exists... loading map from file");
        } 
        else // Else we have to create it ourselves 
        {
  	  File metaFile = SD.open("GMMETA.txt", FILE_WRITE);
	  if(metaFile) {
	    metaFile.write("+++GLOBALMETAFILE+++\n");
	    metaFile.write("MAPFILENAME=GMAP.txt");
	  } else {
  	      return;
	  }
          metaFile.flush();
          metaFile.close();

          Logger::log(Logger::GlobalGrid, Logger::INFO, "Creating Global Map");
          if(SD.exists("GMAP.txt")) {
             SD.remove("GMAP.txt");
  	  }         
          writeNode(0,0, LocalGrid::White);
          writeNode(0,1, LocalGrid::Black);
  
       } 
 }

void GlobalGrid::GlobalGrid::update(LocalGrid::LocalGrid localGrid) {
		File map = SD.open("GMAP.txt", FILE_WRITE);
		map.flush();
		map.close();
}


/** Write a node at the specified coordinates. If a node is currently there then overwrite. */
void GlobalGrid::GlobalGrid::writeNode(int x,int y, LocalGrid::Color color) {
	File map = SD.open("GMAP.TXT",FILE_WRITE);
	if(map) {
                if(numberOfNodes_ > 0) {
	           map.write(',');
                   map.write('\n');
		} 
		map.write('\"');
		writeNumber(map,x);
		map.write(',');
		writeNumber(map,y);
		map.write('\"');
		map.write('{');
		map.write('\n');
		writeColor(map,color, false);
		map.write('\n');
		map.write('}');
	} else {
               //Serial.println("Map file was not avaliable for writing");
        }
        map.flush();
        map.close();
        numberOfNodes_++;
}

void GlobalGrid::writeNumber(File file, int i) {
	switch(i) {
		case 0:
			file.write("0");
                        break;
		case 1:
		        file.write("1");
			break;
		case 2:
			file.write("2");
			break;
		case 3:
			file.write("3");
			break;
		case 4:
			file.write("4");
			break;
		case 5:
			file.write("5");
			break;
		case 6:
			file.write("6");
			break;
		case 7:
			file.write("7");
			break;
		case 8:
			file.write("8");
			break;
		case 9:
			file.write("9");
			break;
	}
}
 
void GlobalGrid::writeColor(File file, LocalGrid::Color i, bool addComma) {
	switch(i) {
		case LocalGrid::White:
			file.write("White");
                        break;
		case LocalGrid::Black:
		        file.write("Black");
			break;
		case LocalGrid::Gray:
			file.write("Gray");
			break;
	}
        if(addComma) {
            file.write(",");
        }
}
 
