#ifndef GLOBALMAP_H
#define GLOBALMAP_H

#include"LocalGrid.h";
#include"RobotPose.h";

namespace GlobalGrid {

	const String GLOBAL_MAP_FILE_NAME = "GM";

	class GlobalGrid {
	public:
		/* Constructor for the Global Map. It will create the file structure necessary right from the beginning, or if one is already there it will load that into itself */
		GlobalGrid();

		/** Get the LocalGrid for the specified RobotPose. The robot pose is considered to be the center. */
		LocalGrid::LocalGrid getLocalGrid(RobotPose::RobotPose pose);



	private:
	};


}
#endif