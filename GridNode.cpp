#include"GridNode.h";

GridNode::GridNode::GridNode()
{ 
  x_ = new int;
  y_ = new int;
  *x_ = 0;
  *y_ = 0;
  color_ = Gray; 
}

GridNode::GridNode::GridNode(int x, int y)
{ 
  x_ = new int;
  y_ = new int;
  *x_ = x;
  *y_ = y;
  color_ = Gray; 
}

GridNode::GridNode::GridNode(int x, int y, Color color)
{ 
  x_ = new int;
  y_ = new int;
  *x_ = x;
  *y_ = y;
  color_ = color; 
}


/** Write a node at the specified coordinates. If a node is currently there then overwrite. */
void GridNode::writeNode(int x,int y, Color color, int numberOfNodes, File grid) {
	int pos = findPositionOfGridNode(x,y,grid);
	if(grid) {
                if(pos == -1) {
                if(numberOfNodes > 0) {
	           grid.write(',');
                   grid.write('\n');
		} 
		  grid.write('\"');
		  writeNumber(grid,x);
		  grid.write(',');
		  writeNumber(grid,y);
		  grid.write('\"');
		  grid.write('{');
		  grid.write('\n');
		  writeColor(grid,color, false);
		  grid.write('\n');
		  grid.write('}');
                } else {
                  grid.seek(pos);
                  grid.write('\n');
                  writeColor(grid,color, false);
                }
	} else {
               //Serial.println("Map file was not avaliable for writing");
        }
        grid.flush();
        grid.close();
}

int GridNode::countPowerOfTen(int i) {
    int count = 0;   
    while(i / 10 > 0) {
        i = i / 10;
        count++;
    }
    return count;
}

void GridNode::writeNumber(File file, int i) {
      bool isNegative = false;
      if( i < 0 ) {
         isNegative = true;
         i = i * -1;
      }
      int powersOfTen = countPowerOfTen(i);
      int cycle = powersOfTen + 1;
      while(cycle > 0) {
         int powerOfTen = (powersOfTen * 10);
         if(powerOfTen > 0) {
           int divisor = i / powerOfTen;
           int remainder = i % powerOfTen;
           if(isNegative) {
             writeInt(file,divisor,isNegative);
             isNegative = false; 
           } else {
             writeInt(file,divisor,false);
           }
           i = remainder;
         } else {
           if(isNegative) {
             writeInt(file,i,isNegative);
             isNegative = false; 
           } else {
             writeInt(file,i,false);
           }
         }
         powersOfTen--;
         cycle--;
      }
      
      
}

void GridNode::writeInt(File file, int i, bool isNegative) {
        switch(i) {
		case 0:
			file.write("0");
                        break;
		case 1: 
                        if(isNegative) {
                          file.write("-");
                        } 
		        file.write("1");
			break;
		case 2:
                        if(isNegative) {
                          file.write("-2");
                        } else {
		          file.write("2");
                        }
			break;
		case 3:
                        if(isNegative) {
                          file.write("-3");
                        } else {
		          file.write("3");
                        }
			break;
		case 4:
                        if(isNegative) {
                          file.write("-4");
                        } else {
		          file.write("4");
                        }
			break;
		case 5:
                        if(isNegative) {
                          file.write("-5");
                        } else {
		          file.write("5");
                        }
			break;
		case 6:
                        if(isNegative) {
                          file.write("-6");
                        } else {
		          file.write("6");
                        }
			break;
		case 7:
                        if(isNegative) {
                          file.write("-7");
                        } else {
		          file.write("7");
                        }
			break;
		case 8:
                        if(isNegative) {
                          file.write("-8");
                        } else {
		          file.write("8");
                        }
			break;
		case 9:
                        if(isNegative) {
                          file.write("-9");
                        } else {
		          file.write("9");
                        }
			break;
		case 10:
                        if(isNegative) {
                          file.write("-10");
                        } else {
		          file.write("10");
                        }
			break;
	}
}
 
void GridNode::writeColor(File file, Color i, bool addComma) {
	switch(i) {
		case White:
			file.write("White");
                        break;
		case Black:
		        file.write("Black");
			break;
		case Gray:
                        //It's one extra space as a work around
			file.write("Gray ");
			break;
	}
        if(addComma) {
            file.write(",");
        }
}

int GridNode::findPositionOfGridNode(int x, int y, File grid) {
	int tempX,tempY;
        bool isXNegative = false;
        if(x < 0) {
          isXNegative = true;
        }
        bool isYNegative = false;
        if(y < 0) {
          isYNegative = true;
        }
	if(grid) {
		while(grid.available()) {
			//Find the first quotation
			grid.find("\"");
                          
                        if(isXNegative) {
                           if(char(grid.peek()) == '-') {
                             grid.read();
                           }
                        }  
			//Read in the x value
			tempX = grid.parseInt();
                        if(isXNegative) {
                           tempX = tempX * -1;
                        }  

			grid.read();

                        if(isYNegative) {
                           if(char(grid.peek()) == '-') {
                             grid.read();
                           }
                        }  
			//Read in the y value
			tempY = grid.parseInt();
			if(isYNegative) {
                           tempY = tempY * -1;
                        }  

			if(tempX == x && tempY == y) {
				grid.find("{");
				int pos = grid.position();
				return pos;
			}
			grid.find("}");
		}
	} else {
		return -1;
	}
	return -1;
}

void GridNode::GridNode::print() {
  Serial.print("X: ");
  Serial.println(*x_, DEC);
  Serial.print("Y: ");
  Serial.println(*y_, DEC);
  Serial.print("Color: ");
  Serial.println(color_, DEC);
}
