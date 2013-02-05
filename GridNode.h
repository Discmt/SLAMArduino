#ifndef GRIDNODE_H
#define GRIDNODE_H
#include<Arduino.h>
#include<SD.h>

namespace GridNode {
       enum Color {
		/** The node is unoccupied */
		White,
		/** The node is occupied */
		Black,
		/** It is unkown the whether or not the node is occupied */
		Gray
	};
  	/* Find the position of the node on the grid */
	int findPositionOfGridNode(int x, int y, File grid);
        void writeNumber(File file, int i);
        void writeColor(File file, Color i, bool addComma);
        void writeInt(File file, int i, bool isNegative);
        int countPowerOfTen(int i);

        /** Write a node at the specified coordinates. If a node is currently there then overwrite. */
        void writeNode(int x,int y, Color color, int numberOfNodes, File grid);
	
        /** A Grid node that keeps track of whether or not is occupied and possibly other information as necessary */
        class GridNode {
	public:
              friend class GlobalGrid;
              friend class LocalGrid;
              GridNode();
              GridNode(int x, int y);
              GridNode(int x, int y, Color color);
              void setColor(Color color) { color_ = color; };
              void setX(int x) { *x_ = x; };
              void setY(int y) { *y_ = y; };
              void print();
              int getX() { return *x_; };
              int getY() { return *y_; }; 
              Color getColor() { return color_; };
	private:
                int * x_;
                int * y_;
		Color color_;
	protected:
	};
}


#endif
