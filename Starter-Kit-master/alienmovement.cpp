#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

class Alien
{

private:
    int dimX_, dimY_, x, y, direction, centerX, centerY;
    // direction facing (0-up, 1 -right, 2-down, 3-left)

public:
    Alien(int dimX, int dimY, vector<vector<char>> &map_)
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

int main ()
{
    while (true)
    {
        string userInput;
        std::cout << "command > ";
        std::cin >> userInput;
        if (userInput == "help")
        {
            std::cout << "\nList of commands: " << '\n'
                      << std::endl;
            std::cout << "1. up - move up." << std::endl;
            std::cout << "2. down - move down." << std::endl;
            std::cout << "3. left - move left." << std::endl;
            std::cout << "4. right - move right." << std::endl;
            std::cout << "5. arrow - change the direction of an arrow." << std::endl;
            std::cout << "6. help - display the user commands." << std::endl;
            std::cout << "7. save - save the game." << std::endl;
            std::cout << "8. load - load a game." << std::endl;
            std::cout << "9. quit - quit the game." << std::endl;
        }
        else
        {
            if (userInput == "up")
            {
            }

            else if (userInput == "down")
            {
            }
        }
    }
    return 0;

    Alien alien;
    char c = 'A';
    string input;
    while (true)
    {
        getline(cin, input);
        for (char c : input)
        {
            if (c == 'up')
            {
                alien.moveUp();
            }
            else if (c == 'down')
            {
                alien.moveDown();
            }
            else if (c == 'left')
            {
                alien.moveLeft();
            }
            else if (c == 'right')
            {
                alien.moveRight();
            }
        }

        for (int i = 0; i < dimY; i++)
        {
            for (int j = 0; j < dimX; j++)
            {
                cout << Board::map_[i][j] = '|';
            }
        }
        
        Board_[Y][X] = 'A';
    }

}