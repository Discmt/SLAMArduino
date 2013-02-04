#ifndef ROBOTPOSE_H
#define ROBOTPOSE_H

namespace RobotPose {

	class RobotPose {
	public:
		/** Constructor for initial robot Pose */
		RobotPose();

		/** Constructor for robot pose */
		RobotPose(double x, double y, double theta);

		double getX() {return x_;};
		double getY() {return y_;};
		double getTheta(){return theta_;};
	private:
	        double x_;
	        double y_;
			double theta_;
	};

}

#endif
