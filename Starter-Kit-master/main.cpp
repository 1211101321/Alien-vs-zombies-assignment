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

int main()
{
    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    string helpinput;
    while (true)
    {
     cout << "Enter a command:\n";
     cin >> helpinput;
     if(helpinput == "help")
     {
        helpCommand(); break;
     }
    else
     {
        cout << "Command is Invalid. Enter 'help' for available commands.\n";
     }
    }
}
