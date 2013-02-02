#include"GlobalGrid.h";


/** Get the LocalGrid for the specified RobotPose. The robot pose is considered to be the center. */
LocalGrid::LocalGrid GlobalGrid::GlobalGrid::getLocalGrid(RobotPose::RobotPose pose) {
	int x = pose.getX();
	int y = pose.getY();
}

GlobalGrid::GlobalGrid::GlobalGrid() {
         Logger::pushMethodStack("GlobalGridConstructor");
         Logger::log(Logger::GlobalGrid, "Instantiating global grid...");
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
           //Load what I need into it here.
        } 
        else // Else we have to create it ourselves 
        {
           String sGlobalDirectory;
           sGlobalDirectory+=Settings::ROOT;
           sGlobalDirectory+='/';
           sGlobalDirectory+=GLOBAL_DIRECTORY;
           char cGlobalDirectoryName[sGlobalDirectory.length()];
           sGlobalDirectory.toCharArray(cGlobalDirectoryName,sGlobalDirectory.length());
           
           if(SD.exists(cGlobalDirectoryName)) {
               File fGlobalDirectory = SD.open(cGlobalDirectoryName);
               if(!fGlobalDirectory.isDirectory()) //If it's not a directory than delete the file
               {
                   SD.remove(cGlobalDirectoryName);
               }
               //Create the meta file :D
               File metaFile = SD.open(metaFileName);
               //Write what I need to write to the file
               
               String sGlobalMapFileName;
               sGlobalMapFileName+=sGlobalDirectory;
               sGlobalMapFileName+=GlOBAL_MAP_FILE_NAME;
               char * cGlobalMapFile;
               cGlobalMapFile = LogUtil::getCharArray(sGlobalMapFileName);
               
               File grid = SD.open(cGlobalMapFile);
               //Create the first local Grid and write it to the GlobalGrid file
               
           }
        
        }
 }
 
 
