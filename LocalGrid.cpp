#include"LocalGrid.h";

LocalGrid::LocalGrid::LocalGrid() {
  x_ = 0;
  y_ = 0;
}

LocalGrid::LocalGrid::LocalGrid(int x, int y) {
  x_ = x;
  y_ = y;
  GridNode::GridNode * node;
  for(int i = 0; i < MAP_SIZE;i++) {
    switch(i) {
    	case CENTER:
            node = new GridNode::GridNode(x,y);
            break;
	case TOP_LEFT:
            node = new GridNode::GridNode(x - 1, y + 1);
            break;
	case TOP_RIGHT:
            node = new GridNode::GridNode(x + 1, y + 1);
            break;
	case TOP:
            node = new GridNode::GridNode(x , y + 1);
            break;
	case LEFT:
            node = new GridNode::GridNode(x - 1, y);
            break;
	case RIGHT:
            node = new GridNode::GridNode(x + 1, y);
            break;
	case BOTTOM_LEFT:
            node = new GridNode::GridNode(x - 1, y - 1);
            break;
	case BOTTOM:
            node = new GridNode::GridNode(x, y - 1);
            break;
	case BOTTOM_RIGHT:
            node = new GridNode::GridNode(x + 1, y - 1);
            break;
    }
  }
}



LocalGrid::LocalGrid::~LocalGrid() {
	for(int i = 0; i < MAP_SIZE;i++) {
  };
}
