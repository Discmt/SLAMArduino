#ifndef ROBOTPOSE_H
#define ROBOTPOSE_H

namespace RobotPose {

	class RobotPose {
	public:
                RobotPose();
                RobotPose(double x, double y, double theta);
		int getX();
		int getY();
	private:
	        int x_;
	        int y_;
                int theta_;
	};

}

#endif
