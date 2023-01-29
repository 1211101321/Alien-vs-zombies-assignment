#include <iostream>
#include <vector>
#include "alienmovement.h"
namespace alien
{
  class Alien
  {

  private:
    int dimX_, dimY_, x, y, direction, centerX, centerY;
    // direction facing (0-up, 1 -right, 2-down, 3-left)
    vector<vector<char>> map_

  public:
    Alien(int dimX, int dimY, char map_)
    {
      dimX_ = dimX;
      dimY_ = dimY;

      int centerX = dimX_ / 2; // code that will place the Alien in the center of the board
      int centerY = dimY_ / 2;
      if (dimX_ % 2 == 0)
        centerX = centerX - 1;
      if (dimY_ % 2 == 0)
        centerY = centerY - 1;

      if (centerX >= dimX_ || centerY >= dimY_)
        return;
        map_[centerY][centerX] = 'A';
    }
    // position on the board
    int direction; // direction facing (0-up, 1-right, 2-down, 3-left)
    bool operator==(const char &c)
    {
      return c == 'A';
    }
    void moveUp()
    {
      y--; // move one step up
    }
    void moveDown()
    {
      y++; // move one step down
    }
    void moveLeft()
    {
      x--; // move left
    }
    void moveRight()
    {
      x++; // move right
    }
    void turnLeft()
    {
      direction = (direction + 3) % 4; // turn left
    }
    void turnRight()
    {
      direction = (direction + 1) % 4; // turn right
    }
  };
}

