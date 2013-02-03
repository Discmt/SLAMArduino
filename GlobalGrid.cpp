#include"GlobalGrid.h";


/** Get the LocalGrid for the specified RobotPose. The robot pose is considered to be the center. */
LocalGrid::LocalGrid GlobalGrid::GlobalGrid::getLocalGrid(RobotPose::RobotPose pose) {
	int x = pose.getX();
	int y = pose.getY();
}

GlobalGrid::GlobalGrid::GlobalGrid() {
         Logger::pushMethodStack("GlobalGridConstructor");
         Logger::log(Logger::GlobalGrid, Logger::INFO ,"Constructing global grid...");
         String metaFilePath;
         metaFilePath+=GLOBAL_DIRECTORY;
		 metaFilePath+='/';
         metaFilePath+=GLOBAL_MAP_METADATA_FILE_NAME;
         char metaFilePathName[20];
         metaFilePath.toCharArray(metaFilePathName,20);    
	
	    //Logger::log(Logger::GlobalGrid, Logger::DEBUG,"Checking for file", metaFilePathName); 
        if(SD.exists(metaFilePathName))  // If the meta file we must load data from it. 
        {
           Logger::log(Logger::GlobalGrid, Logger::INFO, "Meta file exists... loading map from file");
        } 
        else // Else we have to create it ourselves 
        {
           Logger::log(Logger::GlobalGrid, Logger::INFO, "Meta file does not exists... creating now");
		   char cGlobalDirectoryName[20];
		   for(unsigned int i = 0 ; i < GLOBAL_DIRECTORY.length() ; i++) {
			   cGlobalDirectoryName[i] = GLOBAL_DIRECTORY.charAt(i);
		   }
		   cGlobalDirectoryName[GLOBAL_DIRECTORY.length()] = '\0';
		   //sGlobalDirectory.toCharArray(cGlobalDirectoryName,20);
		   Logger::log(Logger::GlobalGrid, Logger::DEBUG, "Global Map Directory Path(String):",  String(cGlobalDirectoryName));
           //Logger::log(Logger::GlobalGrid, Logger::DEBUG, "Global Map Directory Path(CharArray):",  cGlobalDirectoryName);


            if(SD.exists(cGlobalDirectoryName)) {
			   /* Logger::log(Logger::GlobalGrid, Logger::DEBUG, "The directory exists");
			   File fGlobalDirectory = SD.open(cGlobalDirectoryName);
               Logger::log(Logger::GlobalGrid, Logger::DEBUG, "Global Map Directory exists");
               if(!fGlobalDirectory.isDirectory()) //If it's not a directory than delete the file
               {
                   fGlobalDirectory.close();
                   Logger::log(Logger::GlobalGrid, Logger::DEBUG, "Global Map Directory is a file... deleting...");
                   SD.remove(cGlobalDirectoryName);
               } */
           } else {
			   Logger::log(Logger::GlobalGrid, Logger::DEBUG, "Directory does not exists...");
		   }  

		    Logger::log(Logger::GlobalGrid, Logger::INFO, "Creating meta Global Map Directory and Meta file");
            
			/* File metaFile = SD.open(metaFilePathName);
            Logger::log(Logger::GlobalGrid, Logger::INFO, "Writing initialization data to meta file");
            metaFile.write("GLOBALMETAFILE\n");
            metaFile.write("MAPFILENAME=GM/GMAP");
            metaFile.flush();
            metaFile.close(); */
               
            Logger::log(Logger::GlobalGrid, Logger::INFO, "Creating Global Map");            
               
            /* if(SD.exists(LogUtil::getCharArray(sGlobalDirectory + GlOBAL_MAP_FILE_NAME))) {
                SD.remove(LogUtil::getCharArray(sGlobalDirectory + GlOBAL_MAP_FILE_NAME));
            }
               
               
            String sGlobalMapFileName;
            sGlobalMapFileName+=sGlobalDirectory;
            sGlobalMapFileName+=GlOBAL_MAP_FILE_NAME;
            char * cGlobalMapFile;
            cGlobalMapFile = LogUtil::getCharArray(sGlobalMapFileName);
               
            //No meta file was associated... delete the cGlobalMapFile
            if(SD.exists(cGlobalMapFile)) {
                SD.remove(cGlobalMapFile);
            }
               
            File grid = SD.open(cGlobalMapFile);
            //Create the first local Grid and write it to the GlobalGrid file
            //to..be continued */
			
        } 
 }
 
 
