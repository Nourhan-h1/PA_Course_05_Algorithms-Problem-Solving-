/*
===========================================================
Project  : Math Quiz Game
Course   : Algorithms & Problem Solving Level 2
Author   : Nourhan Hany
Date     : 28/5/2026

Description:
A console-based Math Quiz game built using C++.

Features:
- Adjustable difficulty levels (Easy, Medium, Hard, Mix)
- Various operation types (Add, Sub, Mult, Div, Mix)
- Score tracking and success rate calculation
- Screen color feedback based on answer correctness
- Input validation
- Replay option
- Clean and organized code structure

Concepts Used:
- Structs & Enums
- Functions Decomposition
- Randomization
- System commands (Screen colors/Clear)
- Data Validation
- Control Flow
===========================================================
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// =========================================
// Enums
// =========================================

enum enQuestionsLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };

// =========================================
// Structs
// =========================================

struct stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enOperationType OperationType;
    enQuestionsLevel QuestionLevel;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};

struct stQuizz
{
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enQuestionsLevel QuestionsLevel;
    enOperationType OpType;
    short NumberOfWrongAnswers = 0;
    short NumberOfRightAnswers = 0;
    bool isPass = false;
    float SuccessRate = 0;
};

// =========================================
// Input/Helper Functions
// =========================================

string GetOpTypeSymbol(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add: return "+";
    case enOperationType::Sub: return "-";
    case enOperationType::Mult: return "x";
    case enOperationType::Div: return "/";
    default: return "Mix";
    }
}

string GetQuestionLevelText(enQuestionsLevel QuestionLevel)
{
    string arrQuestionLevelText[4] = { "Easy","Medium","Hard","Mixed" };
    return arrQuestionLevelText[QuestionLevel - 1];
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

short ReadHowManyQuestions()
{
    short NumberOfQuestions;
    do
    {
        cout << "How Many Questions do you want to answer ? ";
        cin >> NumberOfQuestions;
    } while(NumberOfQuestions < 1 || NumberOfQuestions > 10);

    return NumberOfQuestions;
}

enQuestionsLevel ReadQuestionsLevel()
{
    short QuestionsLevel;
    do
    {
        cout << "\nEnter Questions Level: [1]:Easy, [2]:Med, [3]:Hard, [4]:Mix ? ";
        cin >> QuestionsLevel;
    } while(QuestionsLevel < 1 || QuestionsLevel > 4);

    return (enQuestionsLevel)QuestionsLevel;
}

enOperationType ReadOpType()
{
    short OpType;
    do
    {
        cout << "\nEnter Operation Type: [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:Mix ? ";
        cin >> OpType;
    } while(OpType < 1 || OpType > 5);

    return (enOperationType)OpType;
}

// =========================================
// Game Logic Functions
// =========================================

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add: return Number1 + Number2;
    case enOperationType::Sub: return Number1 - Number2;
    case enOperationType::Mult: return Number1 * Number2;
    case enOperationType::Div: return (Number2 != 0) ? (Number1 / Number2) : 0;
    default: return Number1 + Number2;
    }
}

enOperationType GetRandomOperationType()
{
    return (enOperationType)RandomNumber(1, 4);
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationType OpType)
{
    stQuestion Question;

    if (QuestionLevel == enQuestionsLevel::Mix)
        QuestionLevel = (enQuestionsLevel)RandomNumber(1, 3);

    if (OpType == enOperationType::MixOp)
        OpType = GetRandomOperationType();

    Question.OperationType = OpType;

    switch (QuestionLevel)
    {
    case enQuestionsLevel::EasyLevel:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        break;
    case enQuestionsLevel::MedLevel:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        break;
    case enQuestionsLevel::HardLevel:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        break;
    }

    if (Question.OperationType == enOperationType::Div)
    {
        Question.Number2 = RandomNumber(1, 10);
        Question.Number1 = Question.Number2 * RandomNumber(1, 10);
    }

    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
    Question.QuestionLevel = QuestionLevel;

    return Question;
}

void GenerateQuizzQuestions(stQuizz& Quizz)
{
    for(short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);
    }
}

// =========================================
// UI & Effects Functions
// =========================================

void SetScreenColor(bool Right)
{
    if (Right)
        system("color 2F");
    else
    {
        system("color 4F");
        cout << "\a";
    }
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void PrintTheQuestion(const stQuizz& Quizz, short QuestionNumber)
{
    cout << "\n";
    cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n";

    cout << Quizz.QuestionList[QuestionNumber].Number1 << " "
         << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType) << " "
         << Quizz.QuestionList[QuestionNumber].Number2 << " = ?\n"; 

    cout << "_____________\n";
}

void PrintQuizzResults(const stQuizz& Quizz)
{
    cout << "\n\t\t_______________________________________________________\n" ;
    cout << "\n\t\t              Final Result " << (Quizz.isPass ? "Pass :-)" : "Fail :-(");
    cout << "\n\t\t_______________________________________________________" << endl;

    cout << "\n\t\tNumber Of Questions   : " << Quizz.NumberOfQuestions << endl;
    cout << "\t\tQuestions Level       : " << GetQuestionLevelText(Quizz.QuestionsLevel)<< endl;
    cout << "\t\tOperation Type        : " << GetOpTypeSymbol(Quizz.OpType)<< endl;
    cout << "\t\tNumber of Right Answer: " << Quizz.NumberOfRightAnswers << endl;
    cout << "\t\tNumber of Wrong Answer: " << Quizz.NumberOfWrongAnswers << endl;
    cout << "\t\tSuccess Rate          : " << Quizz.SuccessRate << "%\n";
    cout << "\n\t\t_______________________________________________________" << endl;
}

// =========================================
// Main Game Loop Functions
// =========================================

int ReadQuestionsAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
    if(Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = false;
        Quizz.NumberOfWrongAnswers++;
        cout << "Wrong Answer :-( \n";
        cout << "The right answer is: " << Quizz.QuestionList[QuestionNumber].CorrectAnswer << "\n";
    }
    else
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = true;
        Quizz.NumberOfRightAnswers++;
        cout << "Right Answer :-) \n";
    }
    cout << endl;
    SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
    for(short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
    {
        PrintTheQuestion(Quizz, QuestionNumber);
        Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionsAnswer();
        CorrectTheQuestionAnswer(Quizz, QuestionNumber);
    }

    Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
    Quizz.SuccessRate = (float)Quizz.NumberOfRightAnswers * 100 / Quizz.NumberOfQuestions;
}

void PlayMathGame()
{
    stQuizz Quizz;
    Quizz.NumberOfQuestions = ReadHowManyQuestions();
    Quizz.QuestionsLevel = ReadQuestionsLevel();
    Quizz.OpType = ReadOpType();

    GenerateQuizzQuestions(Quizz);
    AskAndCorrectQuestionListAnswers(Quizz);
    PrintQuizzResults(Quizz);
}

void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        PlayMathGame();
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

