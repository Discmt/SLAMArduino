#include"GlobalGrid.h";


/** Get the LocalGrid for the specified RobotPose. The robot pose is considered to be the center. */
LocalGrid::LocalGrid GlobalGrid::GlobalGrid::getLocalGrid(RobotPose::RobotPose pose) {
	int x = pose.getX();
	int y = pose.getY();
}

GlobalGrid::GlobalGrid::GlobalGrid() {
         Logger::pushMethodStack("GlobalGridConstructor");
         Logger::log(Logger::GlobalGrid, Logger::INFO ,"Consturcting global grid...");
         String metaFile;
         metaFile+=Settings::ROOT;
         metaFile+='/';
         metaFile+=GLOBAL_DIRECTORY;
         metaFile+='/';
         metaFile+=GLOBAL_MAP_METADATA_FILE_NAME;
         char metaFileName[metaFile.length()];
         metaFile.toCharArray(metaFileName,metaFile.length());    
	
        
        if(SD.exists(metaFileName))  // If the meta file we must load data from it. 
        {
           Logger::log(Logger::GlobalGrid, Logger::INFO, "Meta file exists... loading map from file");
        } 
        else // Else we have to create it ourselves 
        {
           Logger::log(Logger::GlobalGrid, Logger::INFO, "Meta file does not exists... creating now");
           
           String sGlobalDirectory;
           sGlobalDirectory+=Settings::ROOT;
           sGlobalDirectory+='/';
           sGlobalDirectory+=GLOBAL_DIRECTORY;
           
           Logger::log(Logger::GlobalGrid, Logger::DEBUG, "Global Map Directory Path:",  sGlobalDirectory);
           char cGlobalDirectoryName[sGlobalDirectory.length()];
           sGlobalDirectory.toCharArray(cGlobalDirectoryName,sGlobalDirectory.length());
           
           if(SD.exists(cGlobalDirectoryName)) {
               File fGlobalDirectory = SD.open(cGlobalDirectoryName);
               Logger::log(Logger::GlobalGrid, Logger::DEBUG, "Global Map Directory exists");
               if(!fGlobalDirectory.isDirectory()) //If it's not a directory than delete the file
               {
                   fGlobalDirectory.close();
                   Logger::log(Logger::GlobalGrid, Logger::DEBUG, "Global Map Directory is a file... deleting...");
                   SD.remove(cGlobalDirectoryName);
               }
               
               
               Logger::log(Logger::GlobalGrid, Logger::INFO, "Creating meta Global Map Directory and Meta file");
               File metaFile = SD.open(metaFileName);
               
               Logger::log(Logger::GlobalGrid, Logger::INFO, "Writing initialization data to meta file");
               metaFile.write("GLOBALMETAFILE\n");
               metaFile.write("MAPFILENAME=GM/GMAP");
               metaFile.flush();
               metaFile.close();
               
               Logger::log(Logger::GlobalGrid, Logger::INFO, "Creating Global Map");            
               
               if(SD.exists(LogUtil::getCharArray(sGlobalDirectory + GlOBAL_MAP_FILE_NAME))) {
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
               //to..be continued
               
               
           }
        
        }
 }
 
 
