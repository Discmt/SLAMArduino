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
	
	class LocalGridNode;

	/** The localGrid is simply an abstraction of the larger GlobalGrid */
	class LocalGrid {
	public:
        //Instantiate a basic local grid with all nodes "unoccupied", and center at (0,0)
        LocalGrid();

		//Instaniate a local grid with all nodes " unoccupied, and center at (x,y) 
		LocalGrid(int x, int y);

		/* return the center X of the local grid */
		int getX() { return x_;};

		/* return the center Y of the local grid */
		int getY() { return y_;};

		///* Return the nodes */
		//LocalGridNode* getMap() {return map_;};

		/* The size of the map array */
		const static int MAP_SIZE = 9;

	private:
		//Center coordinates of the LocalGrid
		int x_,y_;


		/* Map of nodes */
		LocalGridNode * map_[MAP_SIZE];
	};

	/** A Grid node that keeps track of whether or not is occupied and possibly other information as necessary */
	class LocalGridNode {
	public:
              friend class LocalGrid;
			  LocalGridNode() { color_ = Gray; };
              LocalGridNode(const LocalGridNode &gSource);
              Color getColor() { return color_; };
              LocalGridNode& operator=(const LocalGridNode &rhs);
	private:
	protected:
		Color color_;
	};

}

#endif
