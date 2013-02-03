#include"LocalGrid.h";

LocalGrid::LocalGrid::LocalGrid() {
  for(int i = 0; i < MAP_SIZE;i++) {
    GridNode * node = new GridNode();
    map_[i] = node; 
  };
}

LocalGrid::GridNode::GridNode(const GridNode &cSource) {
  color_ = cSource.color_;
}

LocalGrid::GridNode& LocalGrid::GridNode::operator=(const GridNode &rhs) {
    // do the copy
    color_ = rhs.color_;
    // return the existing object
    return *this;
}
