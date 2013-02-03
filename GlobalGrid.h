#ifndef GLOBALMAP_H
#define GLOBALMAP_H

#include <SD.h>;
#include<Arduino.h>;
#include"LocalGrid.h";
#include"RobotPose.h";
#include"Settings.h";
#include"Logger.h";

namespace GlobalGrid {

	class GlobalGrid {
	public:

                
		/* Constructor for the Global Map. It will create the file structure necessary right from the beginning, or if one is already there it will load that into itself */
		GlobalGrid();

		/** Get the LocalGrid for the specified RobotPose. The robot pose is considered to be the center. */
		LocalGrid::LocalGrid getLocalGrid(RobotPose::RobotPose pose);
      
                



	private:
               /** Write a node at the specified coordinates. If a node is currently there then overwrite. */
               void writeNode(int x,int y);
               
               /** Write a grid node. If a node currently exists than overwrite */ 
               void writeNode(LocalGrid::GridNode gridNode);
              
              
              
	};

      


}
#endif
