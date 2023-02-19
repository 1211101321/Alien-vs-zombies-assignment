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
#include <fstream>
using namespace std;

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

///////////////////////////////////////////////////////////////////////////////////////////////
// code is supposed to randomly positon the zombies on the board after inputting their number,
// some characters will be replaced but the zombies will appear on the board
///////////////////////////////////////////////////////////////////////////////////////////////

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
    void spawnZombies(int numofZombies, int dimX_, int dimY_, vector<vector<char>> &map_);
    void display() const;
};

Board::Board()
{
    dimX_ = 0;
    dimY_ = 0;
    numofZombies = 0;
    init(dimX_, dimY_);
    // spawnZombies(numofZombies, dimX_, dimY_, map_);
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
    if (dimX_ % 2 == 0)
        centerX = centerX - 1;
    if (dimY_ % 2 == 0)
        centerY = centerY - 1;

    if (centerX >= dimX_ || centerY >= dimY_)
        return;
    map_[centerY][centerX] = 'A';
    // spawnZombies(numofZombies, dimX_, dimY_, map_);
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

void saveCommand() 
{
    ofstream outputFile("alienvszombiedata.txt");
    if (outputFile.is_open()) 
    {
        outputFile << "Current board data" << endl;
        outputFile.close();
        cout << "Data saved successfully" << endl;
    }

    else 
    {
        cout << "Error: Unable to open file for writing" << endl;
    }
}

void loadCommand() 
{
    ifstream inputFile("alienvszombiedata.txt");

    if (inputFile.is_open()) 
    {
        string data;
        while (getline(inputFile, data)) {
            cout << data << endl;
        }
        inputFile.close();
    }
    
    else 
    {
        cout << "Error: Unable to open file for reading" << endl;
    }
}

void quitCommand()
{
   while (true)
   {
    string escape;
    cout << "Are you sure you want to quit? (y/n)?: ";
    cin >> escape;
    if (escape == "y" || escape == "Y")
           {
            cout << "Thank you for playing! Goodbye!";
            exit (0);
           }

    else if (escape == "n" || escape == "N")
            {
              break;
            }

    else
        {
            cout << "Invalid Input" << endl;  
        }
   }    
}

int main()
{
    cout << "Assignment" << endl;
    cout << "Let's Get Started!" << endl;
    int dimY = 11, dimX = 9;
    int numofZombies = 1;
    srand(time(NULL));

    char settings;
    cout << "Default Game Settings" << endl;
    cout << "-----------------------" << endl;
    cout << "Board Rows     : " << dimY << endl;
    cout << "Board Columns  : " << dimX << endl;
    cout << "Zombie Count   : " << numofZombies << endl
         << endl;

    while (true)
    {
        cout << "Do you wish to change the game settings? (y/n)?: ";
        cin >> settings;

        if (settings == 'Y' || settings == 'y')
        {
            cout << "Settings" << endl;
            cout << "------------" << endl;
            cout << "Number of Rows: ";
            cin >> dimY;;

            while (dimY% 2 == 0)
           {
                cout << "Error, value must be an odd number: ";
                cin >> dimY;
           }
            cout << "Number of Columns: ";
            cin >> dimX;

            while (dimX % 2 == 0)
           { 
            cout << "Error, value must be an odd number: ";
            cin >> dimX;
           }

            cout << "Enter the number of zombies you want to spawn: " << endl; //request how many zombies you want inputted
            cin >> numofZombies;
            break;
        }

        else if (settings == 'n' || settings == 'N')
        {
            //continue to default board values
            break;
        }

        else
        {
            cout << "Invalid Input" << endl; //back to loop and ask user to re-enter y/n
        }
    } 
   
    Board board;
    board.init(dimX, dimY);
    cout << "Settings updated." << endl << endl;
    board.display();

    string commandinput;
    while (true)
    {   
     cout << "Enter a command:\n";
     cin >> commandinput;
     if(commandinput == "help")
     {
        helpCommand();
     }

     else if(commandinput == "save")
     {
        saveCommand();
     }

     else if(commandinput == "load")
     {
        loadCommand();
     }

     else if(commandinput == "quit")
     {
        quitCommand();
     }

     else
     {
        cout << "Command is Invalid. Enter 'help' for available commands.\n";
     }
    } 
}
