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

    enum Color {
		/** The node is unoccupied */
		White,
		/** The node is occupied */
		Black,
		/** It is unkown the whether or not the node is occupied */
		Gray
	};
	
	class GridNode;

	/** The localGrid is simply an abstraction of the larger GlobalGrid */
	class LocalGrid {
	public:
                //Instantiate a basic local grid with all nodes "unoccupied"
                LocalGrid();
				~LocalGrid();
				//Return the nodes for this map
				GridNode ** getNodes() { return map_; };

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
			  GridNode() { color_ = Gray; };
              GridNode(const GridNode &gSource);
              Color getColor() { return color_; };
              GridNode& operator=(const GridNode &rhs);
			  ~GridNode() {};
	private:
	protected:
		Color color_;
	};

}

#endif
