#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

const string dirtyString = "Dirty";
const string cleanString = "Clean";

enum Status
{
    Clean,
    Dirty
};

enum Actions
{
    Nothing,
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_CENTER,
    SUCK
};

enum Location
{
    A,
    B,
    C
};

class Environment
{
private:
    int size[3];

public:
    Environment()
    {
        SetEnvr();
    }

    void SetEnvr()
    {
        int ran = rand() % 10;
        (ran < 5) ? size[A] = Clean : size[A] = Dirty;

        ran = rand() % 10;
        (ran < 5)? size[B] = Clean : size[B] = Dirty;

        ran = rand() % 10;
        (ran < 5)? size[C] = Clean : size[C] = Dirty;
    }

    int GetStatus(int location)
    {
        return size[location];
    }

    void SetStatus(int location, int status)
    {
        size[location] = status;
    }

    void PrintEnvr(int agentLocation)
    {

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);

        cout << "+-----------+-----------+-----------+" << endl;

        SetConsoleTextAttribute(hConsole, 11);
        cout << "| a         | b         | c         |" << endl;

        cout << "+-----------+-----------+-----------+" << endl;

        for (int i = 0; i < 2; i++)
        {
            SetConsoleTextAttribute(hConsole, 14);
            cout << "|   ";
            if (GetStatus(i) == Dirty)
                SetConsoleTextAttribute(hConsole, 12);
            else
                SetConsoleTextAttribute(hConsole, 10);
            cout << ((GetStatus(i) == Dirty) ? dirtyString : cleanString) << "   ";
        }

        SetConsoleTextAttribute(hConsole, 14);
        cout << "|   ";
        if (GetStatus(2) == Dirty)
            SetConsoleTextAttribute(hConsole, 12);
        else
            SetConsoleTextAttribute(hConsole, 10);
        cout << ((GetStatus(2) == Dirty) ? dirtyString : cleanString) << "   ";
        SetConsoleTextAttribute(hConsole, 14);
        cout << "|" << endl;

        cout << "+-----------+-----------+-----------+" << endl;

        SetConsoleTextAttribute(hConsole, 8);
        if (agentLocation == A)
            cout << "  [VACUUM]" << endl;
        else if (agentLocation == B)
            cout << "              [VACUUM]" << endl;
        else
            cout << "                          [VACUUM]  " << endl;



        cout << endl;
    }
};

class Agent
{
public:
    int ReflexiveVacuum(int location, int status)
    {
        return (status == Dirty) ? SUCK :
               (location == A) ? MOVE_RIGHT :
               (location == B) ? MOVE_CENTER :
               MOVE_LEFT;
    }

};
int main()
{
    SetConsoleTitle("Yehia AL");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);
    cout << "=========================================" << endl;
    cout << "  Vacuum Cleaner Agent Simulation\t" << ""<< endl;
    cout << "=========================================" << endl << endl;

    Environment e;
    Agent a;
    int currentLocation = A;

    for (int counter = 0; counter < 250; counter++)
    {
        getch();
        e.PrintEnvr(currentLocation);
        bool allClean = true;

        for (int i = A; i <= C; i++)
        {
            if (e.GetStatus(i) == Dirty)
            {
                allClean = false;
                break;
            }
        }
        int agentAction = a.ReflexiveVacuum(currentLocation, e.GetStatus(currentLocation));

        currentLocation = (agentAction == SUCK) ? currentLocation :
                          (agentAction == MOVE_RIGHT) ? B :
                          (agentAction == MOVE_CENTER) ? C :
                          A;

        if (agentAction == SUCK)
            e.SetStatus(currentLocation, Clean);

        _sleep(500);
        getch();

        if (allClean)
        {
            e.SetEnvr();
            _sleep(1500);
            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "========================================" << endl;
            cout << "  Vacuum Cleaner Agent Simulation" << endl;
            cout << "========================================" << endl << endl;

        }
    }
}
