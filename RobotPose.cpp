#include"RobotPose.h";

RobotPose::RobotPose::RobotPose() {
	x_ = 0;
	y_ = 0;
	theta_ = 0;
}

RobotPose::RobotPose::RobotPose(double x, double y, double theta) {
	 x_ = x; 
	 y_ = y; 
	 theta_  = theta;
}