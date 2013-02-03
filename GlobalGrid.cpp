#include"GlobalGrid.h";


/** Get the LocalGrid for the specified RobotPose. The robot pose is considered to be the center. */
LocalGrid::LocalGrid GlobalGrid::GlobalGrid::getLocalGrid(RobotPose::RobotPose pose) {
	int x = pose.getX();
	int y = pose.getY();
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
				metaFile.write("MAPFILENAME=GMAP.map");
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
			SD.open("GMAP.map", FILE_WRITE);
            
			
        } 
 }
 
 
