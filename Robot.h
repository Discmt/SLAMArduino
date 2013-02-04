#ifndef ROBOT_H
#define ROBOT_H
#include"Robot.h";
#include"RobotPose.h";
#include"GlobalGrid.h";
#include"LocalGrid.h";


namespace Robot {

	class Robot {
	public:
		Robot();
	private:
		RobotPose::RobotPose * pose_;
		GlobalGrid::GlobalGrid globalGrid_;
		LocalGrid::LocalGrid * localGrid_;
	};


}


#endif