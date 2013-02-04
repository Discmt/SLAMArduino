#ifndef SENSOR_H
#define SENSOR_H

namespace Sensor {

	/** Return whether the space in front of the robot's current position is occupied */
	bool isNextSpaceOccupied(RobotPose pose);

	class Sensor {



	};

	class SonarSensor : Sensor {
		
	};

	/** Dummy sensor always senses an object a couple feet away */
	class DummySensor : Sensor {
		
	};

}
#endif