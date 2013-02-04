#ifndef GLOBALMAP_H
#define GLOBALMAP_H

#include <SD.h>;
#include<Arduino.h>;
#include"LocalGrid.h";
#include"RobotPose.h";
#include"Settings.h";
#include"Logger.h";

namespace GlobalGrid {

	class GlobalGridNode;

	class GlobalGrid {
	public:

                
		/* Constructor for the Global Map. It will create the file structure necessary right from the beginning, or if one is already there it will load that into itself */
		GlobalGrid();

		/** Get the LocalGrid for the specified RobotPose. The robot pose is considered to be the center. */
		LocalGrid::LocalGrid getLocalGrid(RobotPose::RobotPose pose);
      
	    /** Update the GlobalGrid using data from the localGrid */
        void update(LocalGrid::LocalGrid localGrid);      



	private:
		

		/** Return the position of the opening brace of the Grid node at specified coordinates, return "-1" if not found */
		int findLinePositionOfGridNode(int x, int y);

		int numberOfNodes;

        /** Write a node at the specified coordinates. If a node is currently there then overwrite. */
        void writeNode(int x,int y);
               
        /** Write a grid node. If a node currently exists than overwrite */ 
        void writeNode(LocalGrid::LocalGridNode gridNode);
       


	};

	class GlobalGridNode {
	public:
		/* Instantiate a Global Grid Node from local Grid node */
		GlobalGridNode(LocalGrid::LocalGridNode localGridNode);
		/* Instantiate a Global Grid Node based on the liner it should be on within a file */
		GlobalGridNode(int lineNumber);
	private:
		int lineNumber_;
		bool isRecorded_;
	};

      


}
#endif
