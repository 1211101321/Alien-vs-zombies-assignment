#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;
namespace alien
{
    class Alien
    {

    public:
        Alien(int dimX, int dimY)
        {
            dimX_ = dimX;
            dimY_ = dimY;

            centerX_ = dimX_ / 2;
            centerY_ = dimY_ / 2;
            if (dimX_ % 2 == 0)
                centerX_ = centerX_ - 1;
            if (dimY_ % 2 == 0)
                centerY_ = centerY_ - 1;

            x = centerX_;
            y = centerY_;
            direction = 0;
            map_.resize(dimY_, std::vector<char>(dimX_, ' '));
            map_[centerY_][centerX_] = 'A';
        }

        void moveUp()
        {
            y--;
        }
        void moveDown()
        {
            y++;
        }
        void moveLeft()
        {
            x--;
        }
        void moveRight()
        {
            x++;
        }
        void turnLeft()
        {
            direction = (direction + 3) % 4;
        }
        void turnRight()
        {
            direction = (direction + 1) % 4;
        }
        void printMap()
        {
            for (int i = 0; i < dimY_; i++)
            {
                for (int j = 0; j < dimX_; j++)
                {
                    std::cout << setw(2) << map_[i][j];
                }
                std::cout << std::endl;
            }
        }
        void moveForward(int steps)
        {
            switch (direction)
            {
            case 0:
                for (int i = 0; i < steps; i++)
                    moveUp();
                break;
            case 1:
                for (int i = 0; i < steps; i++)
                    moveRight();
                break;
            case 2:
                for (int i = 0; i < steps; i++)
                    moveDown();
                break;
            case 3:
                for (int i = 0; i < steps; i++)
                    moveLeft();
                break;
            }
            map_[y][x] = 'A';
        }

        void teleport(int newX, int newY)
        {
            map_[y][x] = ' ';
            x = newX;
            y = newY;
            map_[y][x] = 'A';
        }

        int getX()
        {
            return x;
        }
        int getY()
        {
            return y;
        }
        int getDirection()
        {
            return direction;
        }

        private:
        int dimX_, dimY_, x, y, direction, centerX_, centerY_;
        std::vector<std::vector<char>> map_;
    };
}


class Zombie
{
public:
    int numofZombies;
    void zombieInput()
    {
        cout << "Enter The Number of Zombies: " << endl;
        cin >> numofZombies;
    }
    int getNumofZombies() {
        return numofZombies;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////
// code is supposed to randomly positon the zombies on the board after inputting their number,
// some characters will be replaced but the zombies will appear on the board
///////////////////////////////////////////////////////////////////////////////////////////////

 /*void spawnZombies(int numofZombies, int dimX_, int dimY_, vector<vector<char>> &map_)
{
    //srand(time(NULL));

    for (int i = 0; i < numofZombies; i++)
    {
        int x = rand() % dimX_;
        int y = rand() % dimY_;
        if (map_[y][x] == ' ')
        {
        map_[y][x] = 'Z';
        }
        else
        {
            --i;
        }
    }
} 
*/
class Board
{
private:
    std::vector<std::vector<char>> map_; // convention to put trailing underscore
    int dimX_, dimY_;          // to indicate private data
    int numofZombies;

public:
    Board(); 
    void init(int dimX, int dimY);
    void spawnZombies();  //(int numofZombies); //(int numofZombies, int dimX_, int dimY_, vector<vector<char>> &map_);
    void display() const; 

};  


   /*  void init(int x, int y) {
    dimX_ = x;
    dimY_ = y;
    map_ = std::vector<std::vector<char>>(x, std::vector<char>(y, '.'));
  }

  std::vector<std::vector<char>> getMap() {
    return map_;
  }

  void display() {
    for (int i = 0; i < dimX_; i++) {
      for (int j = 0; j < dimY_; j++) {
        std::cout << map_[i][j];
      }
      std::cout << '\n';
    }
  }

    void spawnZombies(int numofZombies, int dimX_, int dimY_, vector<vector<char>> &map_)
{
    //srand(time(NULL));

    for (int i = 0; i < numofZombies; i++)
    {
        int x = rand() % dimX_;
        int y = rand() % dimY_;
        if (map_[y][x] == ' ')
        {
        map_[y][x] = 'Z';
        }
        else
        {
            --i;
        }
    }
} 




};
*/


Board::Board()
{
    dimX_ = 0;
    dimY_ = 0;
    numofZombies = 0;
    //init(dimX_, dimY_);
    //cout << "Enter the number of zombies you want to spawn: " << endl; //request how many zombies you want inputted
   // cin >> dimX_ >> dimY_;
    init(dimX_, dimY_);
     cout << "Enter the number of zombies you want to spawn: " << endl;
    cin >> numofZombies;
    init(dimX_, dimY_);
    spawnZombies();
    //void spawnZombies(int numofZombies, int dimX_,int  dimY_, vector<vector<char>> &map_); //(numofZombies, dimX_, dimY_, map_);
}

void Board::init(int dimX, int dimY)
{
    if (dimX <= 0 || dimY <= 0)
        return;
    dimX_ = dimX;
    dimY_ = dimY;
    map_ = std::vector<std::vector<char>>(dimY_ , std::vector<char>(dimX_, '.'));
    char objects[] = {' ', ' ', ' ', ' ', 'p', 'h', 'r', '^', 'v', '>', '<', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
     vector<char> zombies(numofZombies);
     for (int i = 0; i < numofZombies; ++i) {
        zombies[i] = 'Z';
     }
    int noOfObjects = sizeof(objects) / sizeof(objects[0]); // number of objects in the objects array

    // create dynamic 2D array using vector
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_); // resize each row
    }

    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
    //////////////////////////////////////////////////////////////
    // code that will place the Alien in the center of the board
    //////////////////////////////////////////////////////////////
    int centerX = dimX_ / 2; 
    int centerY = dimY_ / 2;
    if (dimX_ % 2 == 0)
        centerX = centerX - 1;
    if (dimY_ % 2 == 0)
        centerY = centerY - 1;

    if (centerX >= dimX_ || centerY >= dimY_)
        return;
    map_[centerY][centerX] = 'A';
     //spawnZombies(numofZombies, dimX_, dimY_, map_);
}

void Board::spawnZombies() //(int numofZombies, int dimX_, int dimY_, vector<vector<char>> &map_)
{
    srand(time(NULL));
    int x, y;
    int counter = 0;
    while (counter < numofZombies)
    {
        x = rand() % dimX_;
        y = rand() % dimY_;
        if (map_[y][x] == '.')
        {
            map_[y][x] = 'Z';
            counter++;
        }
    }
}


void Board::display() const
{
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << " =      Alien vs Zombie        = " << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << " ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // display row number
        cout << setw(2) << (dimY_ - i);

        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }

    // display lower border of the last row
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;

    // display column
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;

        /* for (const auto &row : map_) {
        for (const auto &col : row) {
            std::cout << col;
        }
        std::cout << '\n';
    } */
}


int main()

{
    int dimX, dimY;
    srand(time(NULL));
    cout << "Enter the dimensions of the board" << endl;
    cout << "Number of columns X:" << endl;
    cin >> dimX; // This allows us to input the number of columns on the board
    cout << "Number of rows Y:" << endl;
    cin >> dimY; // This allows us to input the number of rows on the board
                 //  The board dimension would have to be in odd integers since the alien spawns in the center of the board

    Board board;
    board.init(dimX, dimY);
     Zombie zombie;
     zombie.zombieInput();
     int numofZombies = zombie.getNumofZombies();
     //vector<vector<char>> map_ = board.getMap();
     board.spawnZombies();
    // spawnZombies(numofZombies, dimX, dimY, map_);
    board.display();
    return 0;

    int dimX_, dimY_;
    std::cout << "Enter the board dimensions (X Y): ";
    std::cin >> dimX >> dimY;
    alien::Alien a(dimX, dimY);
    std::string input;
    while (true)
    {
        std::cout << "Enter commands (up, down, left, right): ";
        std::getline(std::cin, input);
        for (char c : input)
        {
            if (c == 'u')
            {
                a.moveUp();
            }
            else if (c == 'd')
            {
                a.moveDown();
            }
            else if (c == 'l')
            {
                a.moveLeft();
            }
            else if (c == 'r')
            {
                a.moveRight();
            }
        }

        a.printMap();
    }
    return 0;
}
