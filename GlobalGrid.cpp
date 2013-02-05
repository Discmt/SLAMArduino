#include"GlobalGrid.h";



/** Get the LocalGrid for the specified RobotPose. The robot pose is considered to be the center. */
LocalGrid::LocalGrid GlobalGrid::GlobalGrid::getLocalGrid(RobotPose::RobotPose pose) {
	int x = pose.getX();
	int y = pose.getY();
}

GlobalGrid::GlobalGrid::GlobalGrid() {
         numberOfNodes_ = 0;
	 Logger::log(Logger::GlobalGrid, Logger::DEBUG,"Checking for file", "GMMETA.txt"); 
         if(SD.exists("GMMETA.TXT")) {
	      SD.remove("GMMETA.TXT");
         }
         if(SD.exists("GMAP.TXT")) {
	      SD.remove("GMAP.TXT");
         }

        if(SD.exists("GMMETA.TXT"))  // If the meta file exists we load data from it. 
        {
            Logger::log(Logger::GlobalGrid, Logger::INFO, "Meta file exists... loading map from file");
        } 
        else // Else we have to create it ourselves 
        {
  	  File metaFile = SD.open("GMMETA.TXT", FILE_WRITE);
	  if(metaFile) {
	    metaFile.write("+++GLOBALMETAFILE+++\n");
	    metaFile.write("MAPFILENAME=GMAP.TXT");
	  } else {
  	      return;
	  }
          metaFile.flush();
          metaFile.close();

          Logger::log(Logger::GlobalGrid, Logger::INFO, "Creating Global Map");
          File globalGrid = SD.open("GMAP.TXT", FILE_WRITE);     
          for(int i = 0; i < 1; i++) {
            //int x = (nodes[i])->getX();
            //int y = (nodes[i])->getY();
            //delay(100);
          }
          GridNode::writeNode(0,0,GridNode::Gray,0,globalGrid);
          globalGrid.flush();
          globalGrid.close();
          //writeNode(0,0,LocalGrid::Gray);
          //LocalGrid::GridNode secondNode(0,0);
          //gridNode.print();
          //writeNode(secondNode);
       } 
 }

void GlobalGrid::GlobalGrid::update(LocalGrid::LocalGrid localGrid) {
		File map = SD.open("GMAP.TXT", FILE_WRITE);
		map.flush();
		map.close();
}


void GlobalGrid::GlobalGrid::writeNode(GridNode::GridNode * node) {
    int x = node->getX();
    int y = node->getY();
    GridNode::Color color = node->getColor();
    File gridMap = SD.open("GMAP.TXT", FILE_WRITE);
    GridNode::writeNode(x, y, color,numberOfNodes_, gridMap);
    numberOfNodes_++;
    gridMap.flush();
    gridMap.close();
}




