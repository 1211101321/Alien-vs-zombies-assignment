// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT11L | TT11L | TT9L
// Names: MUHAMMAD ZAFRAN BIN MOHD ANUAR | AHMAD DANIAL BIN AHMAD FAUZI | NUR ALYA NABILAH BINTI MD.NASER
// IDs: 1211101321 | 1211100824 | 1211101925
// Emails: 1211101321@student.mmu.edu.my | 1211100824@student.mmu.edu.my | 1211101925@student.mmu.edu.my
// Phones: 0183834854 | 0178714669 | 0167859895
// *********************************************************



#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

void helpCommand()
{
    cout << "Commands" << endl;
    cout << "1. up    - Move up." << endl;
    cout << "2. down  - Move down." << endl;
    cout << "3. left  - Move left." << endl;
    cout << "4. right - Move right." << endl;
    cout << "5. arrow - Change the direction of an arrow." << endl;
    cout << "6. help  - Display these user commands." << endl;
    cout << "7. save  - Save the game." << endl;
    cout << "8. load  - Load a game." << endl;
    cout << "9. quit  - Quit the game." << endl;
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
};

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

void spawnZombies(int numofZombies, int dimX_, int dimY_, vector<vector<char>> &map_)
{
    // char zombieplacement[] = {'Z'};
    // int zombiesinChar = 1;
    for (int i = 0; i <= numofZombies; i++)
    {
        // int x = rand() % zombiesinChar;
        // int y = rand() % zombiesinChar;
        // map_[y][x] = zombieplacement[zombiesinChar];

        for (int j = 0; j < dimX_; ++j)
        {
            int zombieNo = rand() % numofZombies;
            map_[i][j] = 'Z';
        }
    }
}

Board::Board()
{
    dimX_ = 0;
    dimY_ = 0;
    numofZombies = 0;
    init(dimX_, dimY_);
    // cout << "Enter the number of zombies you want to spawn: " << endl; //request how many zombies you want inputted
    // cin >> numofZombies;
    spawnZombies(numofZombies, dimX_, dimY_, map_);
}

void Board::init(int dimX, int dimY)
{
    if (dimX <= 0 || dimY <= 0)
        return;
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {' ', ' ', ' ', ' ', 'p', 'h', 'r', '^', 'v', '>', '<', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    // char zombies[];
    int noOfObjects = 18; // number of objects in the objects array

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
    if (dimX_ % 2 == 0) // making sure that the board is odd dimensions
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
    cout << "      = Alien vs Zombies =      " << endl;
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

class Rock
{
private:
    char rock = 'r';

public:
};
class Alien
{

private:
    int dimX_, dimY_, x, y, direction, centerX, centerY;
    // direction facing (0-up, 1 -right, 2-down, 3-left)
    vector<vector<char>> map_;

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

int main()
{

    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    system("pause");
    int dimX, dimY, numofZombies;
    srand(time(NULL));
    cout << "Enter the dimensions of the board" << endl;
    cout << "Number of columns X:" << endl;
    cin >> dimX; // This allows us to input the number of columns on the board
    cout << "Number of rows Y:" << endl;
    cin >> dimY; // This allows us to input the number of rows on the board
                 //  The board dimension would have to be in odd integers since the alien spawns in the center of the board
    cout << "Enter the number of zombies: " << endl;
    cin >> numofZombies;
    Board board;
    board.init(dimX, dimY);
    board.display();
}
int main()
{
    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    string commandinput;
    while (true)
    {
     cout << "Enter a command:\n";
     cin >> commandinput;
     if(commandinput == "help")
     {
        helpCommand(); break;
     }
    else
     {
        cout << "Command is Invalid. Enter 'help' for available commands.\n";
     }
    }
    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    system("pause");
    int dimX, dimY, numofZombies;
    srand(time(NULL));
    cout << "Enter the dimensions of the board" << endl;
    cout << "Number of columns X:" << endl;
    cin >> dimX; // This allows us to input the number of columns on the board
    cout << "Number of rows Y:" << endl;
    cin >> dimY; // This allows us to input the number of rows on the board
                 //  The board dimension would have to be in odd integers since the alien spawns in the center of the board
    cout << "Enter the number of zombies: " << endl;
    cin >> numofZombies;
    Board board;
    board.init(dimX, dimY);
    board.display();
}
