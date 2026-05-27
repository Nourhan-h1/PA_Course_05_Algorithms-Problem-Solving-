/*
===========================================================
Project  : Rock Paper Scissors Game
Course   : Algorithms & Problem Solving Level 2
Author   : Nourhan Hany
Date     : 

Description:
A console-based Rock Paper Scissors game built using C++.

Features:
- Random computer choices
- Round tracking system
- Winner detection
- Sound effects using Beep()
- Screen color changes
- Input validation
- Replay option
- Clean and organized code structure

Concepts Used:
- Structs & Enums
- Functions Decomposition
- Randomization
- Windows API
- Data Validation
- Control Flow
===========================================================
*/

#include <windows.h>

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// =========================================
// Enums
// =========================================

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

// =========================================
// Structs
// =========================================

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResults
{
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

// =========================================
// Input Functions
// =========================================

int ReadRoundsNumber()
{
    int Number;

    do
    {
        cout << "How Many Rounds from 1 to 10?: ";
        cin >> Number;

    } while(Number < 1 || Number > 10);

    return Number;
}

enGameChoice ReadPlayer1Choice()
{
    short Choice;

    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> Choice;

    } while (Choice < 1 || Choice > 3);

    return (enGameChoice)Choice;
}

// =========================================
// Randomization Functions
// =========================================

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

// =========================================
// Game Logic Functions
// =========================================

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        return (RoundInfo.ComputerChoice == enGameChoice::Paper)
            ? enWinner::Computer
            : enWinner::Player1;

    case enGameChoice::Paper:
        return (RoundInfo.ComputerChoice == enGameChoice::Scissors)
            ? enWinner::Computer
            : enWinner::Player1;

    case enGameChoice::Scissors:
        return (RoundInfo.ComputerChoice == enGameChoice::Stone)
            ? enWinner::Computer
            : enWinner::Player1;
    }

    return enWinner::Draw;
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes)
        return enWinner::Player1;

    else if (ComputerWinTimes > Player1WinTimes)
        return enWinner::Computer;

    else
        return enWinner::Draw;
}

string ChoiceName(enGameChoice Choice)
{
    string arrGameChoices[3] = { "Stone", "Paper", "Scissors" };

    return arrGameChoices[Choice - 1];
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] =
    {
        "Player1",
        "Computer",
        "No Winner (Draw)"
    };

    return arrWinnerName[Winner - 1];
}

// =========================================
// UI & Effects Functions
// =========================================

void PlayRoundSound(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
        Beep(900, 120);
        Beep(1100, 120);
        break;

    case enWinner::Computer:
        Beep(500, 250);
        break;

    case enWinner::Draw:
        Beep(600, 80);
        break;
    }
}

void SetScreenColor(enWinner Winner)
{
    switch(Winner)
    {
        case enWinner::Player1:
            system("color 2F");
            break;

        case enWinner::Computer:
            system("color 4F");
            break;

        case enWinner::Draw:
            system("color E0");
            break;
    }
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n____________ Round ["
         << RoundInfo.RoundNumber
         << "] ____________\n\n";

    cout << "Player1 Choice : "
         << ChoiceName(RoundInfo.Player1Choice)
         << endl;

    cout << "Computer Choice: "
         << ChoiceName(RoundInfo.ComputerChoice)
         << endl;

    cout << "Round Winner   : ["
         << RoundInfo.WinnerName
         << "]\n";

    cout << "___________________________________\n" << endl;
}

// =========================================
// Main Game Functions
// =========================================

stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;

    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;

    for (short GameRound = 1;
         GameRound <= HowManyRounds;
         GameRound++)
    {
        cout << "\nRound ["
             << GameRound
             << "] begins:\n";

        RoundInfo.RoundNumber = GameRound;

        RoundInfo.Player1Choice = ReadPlayer1Choice();

        RoundInfo.ComputerChoice = GetComputerChoice();

        RoundInfo.Winner = WhoWonTheRound(RoundInfo);

        RoundInfo.WinnerName =
            WinnerName(RoundInfo.Winner);

        switch (RoundInfo.Winner)
        {
        case Player1:
            Player1WinTimes++;
            break;

        case Computer:
            ComputerWinTimes++;
            break;

        case Draw:
            DrawTimes++;
            break;
        }

        SetScreenColor(RoundInfo.Winner);

        PlayRoundSound(RoundInfo.Winner);

        PrintRoundResults(RoundInfo);
    }

    stGameResults FinalResults;

    FinalResults.GameRounds = HowManyRounds;

    FinalResults.Player1WinTimes = Player1WinTimes;

    FinalResults.ComputerWinTimes = ComputerWinTimes;

    FinalResults.DrawTimes = DrawTimes;

    FinalResults.GameWinner =
        WhoWonTheGame(Player1WinTimes,
                      ComputerWinTimes);

    FinalResults.WinnerName =
        WinnerName(FinalResults.GameWinner);

    return FinalResults;
}

void PrintFinalResults(stGameResults GameResults)
{
    SetScreenColor(GameResults.GameWinner);

    cout << "\n\n\t\t_______________________________________________________"
         << endl;

    cout << "\n\t\t              +++ G a m e  O v e r +++                "
         << endl;

    cout << "\n\t\t_______________________________________________________"
         << endl;

    cout << "\n\t\t____________________ [Game Results] ___________________"
         << endl;

    cout << "\n\t\tGame Round        : "
         << GameResults.GameRounds
         << endl;

    cout << "\n\t\tPlayer won times  : "
         << GameResults.Player1WinTimes
         << endl;

    cout << "\n\t\tComputer won times: "
         << GameResults.ComputerWinTimes
         << endl;

    cout << "\n\t\tDraw times        : "
         << GameResults.DrawTimes
         << endl;

    cout << "\n\t\tFinal Winner      : "
         << GameResults.WinnerName
         << endl;

    cout << "\t\t_______________________________________________________"
         << endl;
}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        system("cls");
        system("color 0F");

        stGameResults GameResults =
            PlayGame(ReadRoundsNumber());

        PrintFinalResults(GameResults);

        cout << "\n\t\tDo you want to play again? (Y/N): ";

        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

// =========================================
// Main Function
// =========================================

int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}
