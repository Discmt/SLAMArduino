#include"LocalGrid.h";

LocalGrid::LocalGrid::LocalGrid() {
  x_ = 0; 
  y_ = 0;
  for(int i = 0; i < MAP_SIZE;i++) {
    LocalGridNode * node = new LocalGridNode();
    map_[i] = node; 
  }
}

LocalGrid::LocalGrid::LocalGrid(int x, int y) {
  x_ = x; 
  y_ = y;
  for(int i = 0; i < MAP_SIZE;i++) {
    LocalGridNode * node = new LocalGridNode();
    map_[i] = node; 
  }
}

LocalGrid::LocalGridNode::LocalGridNode(const LocalGridNode &cSource) {
  color_ = cSource.color_;
}

LocalGrid::LocalGridNode& LocalGrid::LocalGridNode::operator=(const LocalGridNode &rhs) {
    // do the copy
    color_ = rhs.color_;
    // return the existing object
    return *this;
}
