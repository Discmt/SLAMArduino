#include"Robot.h"


Robot::Robot::Robot() {
	Logger::pushMethodStack("Robot Constructor");

	pose_ = new RobotPose::RobotPose();
	int x = pose_->getX();
	int y = pose_->getY();
		
	Logger::log(Logger::Robot, Logger::INFO, "Initial Pose created");
	String details;
	Serial.print("x: ");
	Serial.print(x, DEC);
	Serial.print("\ny: ");
	Serial.print(y, DEC);

	localGrid_ = new LocalGrid::LocalGrid(0,0);

	globalGrid_.update((*localGrid_));


	Logger::popMethodStack();
}
