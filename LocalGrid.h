#ifndef LOCALGRID_H
#define LOCALGRID_H
#include"GridNode.h";

namespace LocalGrid {
	const int CENTER = 4;
	const int TOP_LEFT = 0;
	const int TOP_RIGHT = 2;
	const int TOP = 1;
	const int LEFT = 3;
	const int RIGHT = 5;
	const int BOTTOM_LEFT = 6;
	const int BOTTOM = 7;
	const int BOTTOM_RIGHT = 8;

	/** The localGrid is simply an abstraction of the larger GlobalGrid */
	class LocalGrid {
	public:
                //Instantiate a basic local grid with all nodes "unoccupied"
                LocalGrid();
                LocalGrid(int x, int y);
	        ~LocalGrid();

		/* The size of the map array */
		const static int MAP_SIZE = 9;

	private:
                int x_,y_;
		/* Map of nodes */
	};
}

#endif
