#ifndef SETTINGS_H
#define SETTINGS_H

namespace Settings {

struct Settings {
	/** The Arduino moves to fast for it's own good... We are not able to receive proper Serial Communication Output... We must slow it down
	in order to effectively use logs */
	const static bool SLOW_DOWN = false;
};

}
#endif
