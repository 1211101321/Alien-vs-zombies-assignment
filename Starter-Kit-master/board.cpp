#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

class Zombie
{
public:
    int numofZombies;
    void zombieInput()
    {
        cout << "Enter The Number of Zombies: " << endl;
        cin >> numofZombies;
    }
};

void spawnZombies(int numofZombies, int dimX_, int dimY_, vector<vector<char>> &map_)
{

    for (int i = 0; i <= numofZombies; i++)
    {
        int x = rand() % dimX_;
        int y = rand() % dimY_;
        map_[y][x] = 'Z';
    }
}
class Board
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int dimX_, dimY_;          // to indicate private data
    int numofZombies;

public:
    Board();
    void init(int dimX, int dimY);
    void spawnZombieas(int numofZombies, int dimX_, int dimY_, vector<vector<char>> &map_);
    void display() const;
};



Board::Board()
{
    dimX_ = 0;
    dimY_ = 0;
    numofZombies = 0;
    init(dimX_, dimY_);
    cout << "Enter the number of zombies you want to spawn: " << endl;
    cin >> numofZombies;
    spawnZombies(numofZombies, dimX_, dimY_, map_);
}

void Board::init(int dimX, int dimY)
{
    if (dimX <= 0 || dimY <= 0)
        return;
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {' ', ' ', ' ', ' ', 'p', 'h', 'r', '^', 'v', '>', '<', ' ', ' ', ' '};
    // char zombies[];
    int noOfObjects = 14; // number of objects in the objects array

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

    int centerX = dimX_ / 2; // code that will place the Alien in the center of the board
    int centerY = dimY_ / 2;
    if (dimX_ % 2 == 0)
        centerX = centerX - 1;
    if (dimY_ % 2 == 0)
        centerY = centerY - 1;

    if (centerX >= dimX_ || centerY >= dimY_)
        return;
    map_[centerY][centerX] = 'A';
    spawnZombies(numofZombies, dimX_, dimY_, map_);
}

void Board::display() const
{
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << " = Alien vs Zombie = " << endl;
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
    spawnZombies(zombie.numofZombies, dimX, dimY, board.map_);
    board.display();
    return 0;

   
}
