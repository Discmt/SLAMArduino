#ifndef LOCALGRID_H
#define LOCALGRID_H

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

        class GridNode;

	/** The localGrid is simply an abstraction of the larger GlobalGrid */
	class LocalGrid {
	public:
                //Instantiate a basic local grid with all nodes "unoccupied"
                LocalGrid();

		/* The size of the map array */
		const static int MAP_SIZE = 9;

	private:
		/* Map of nodes */
		GridNode * map_[MAP_SIZE];
	};

	/** A Grid node that keeps track of whether or not is occupied and possibly other information as necessary */
	class GridNode {
	public:
              friend class LocalGrid;
              GridNode() { isOccupied_ = false; };
              GridNode(const GridNode &gSource);
              bool isOccupied() { return isOccupied_; };
              GridNode& operator=(const GridNode &rhs);
	private:
        protected:
		bool isOccupied_;
	};

}

#endif
