#include"LocalGrid.h";

LocalGrid::LocalGrid::LocalGrid() {
  for(int i = 0; i < MAP_SIZE;i++) {
    GridNode * node = new GridNode();
    map_[i] = node; 
  };
}

LocalGrid::GridNode::GridNode(const GridNode &cSource) {
  isOccupied_ = cSource.isOccupied_;
}

LocalGrid::GridNode& LocalGrid::GridNode::operator=(const GridNode &rhs) {
    // do the copy
    isOccupied_ = rhs.isOccupied_;
 
    // return the existing object
    return *this;
}
