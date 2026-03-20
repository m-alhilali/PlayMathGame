#include <iostream>
#include <cstdlib>
using namespace std;

enum enQuestionLevel { LevelEasy = 1, LevelMed = 2, LevelHard = 3, Mix = 4 };
enum enOpType { OpAdd = 1, OpSub = 2, OpMult = 3, OpDiv = 4, OpMix = 5 };

int RandomNumber(int From, int To)
{
	//function to generate a random number
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

struct stQuestion
{
	short Number1 = 0;
	short Number2 = 0;
	short CorrectAnswer = 0;
	short PlayerAnswer = 0;
	enOpType QuestionOpType;
	enQuestionLevel QuestionLevel;
	bool AnswerResult = false;
};

struct stQuizz
{
	stQuestion QuestionList[100];
	short NumberOfQuestions = 0;
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
	enQuestionLevel QuizzLevel;
	enOpType QuizzOpType;
	bool isPass = false;
};

short ReadHowManyQuestions()
{
	short Number = 0;
	do
	{
		cout << "How many question do you want to answer ? ";
		cin >> Number;

	} while (Number < 1 || Number > 10);

	return Number;
}

void ResetScreenColor()
{
	system("cls");
	system("color 0F");
}

enQuestionLevel ReadQuestionLevel()
{
	short Number = 0;
	do
	{
		cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> Number;

	} while (Number < 1 || Number>4);

	return (enQuestionLevel)Number;
}

enOpType ReadOperationType()
{
	short Number = 0;
	do
	{
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> Number;

	} while (Number < 1 || Number>5);

	return (enOpType)Number;
}

enOpType GetRandomOperationType()
{
	short Number = RandomNumber(1, 4);
	return (enOpType)Number;
}

short SimpleCalculate(enOpType OperationType,short Number1,short Number2)
{
	switch (OperationType)
	{
	case enOpType::OpAdd:
		return Number1 + Number2;
	case enOpType::OpSub:
		return Number1 - Number2;
	case enOpType::OpMult:
		return Number1 * Number2;
	case enOpType::OpDiv:
		return Number1 / Number2;
	default:
		return Number1 + Number2;
	}
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOpType OperationType)
{
	stQuestion Question;

	if (QuestionLevel == enQuestionLevel::Mix)
	{
		QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
	}
	if (OperationType == enOpType::OpMix)
	{
		OperationType = GetRandomOperationType();
	}

	Question.QuestionOpType = OperationType;

	switch (QuestionLevel)
	{
	case enQuestionLevel::LevelEasy:
	{
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCalculate(Question.QuestionOpType, Question.Number1, Question.Number2);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	}
	case enQuestionLevel::LevelMed:
	{
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);
		Question.CorrectAnswer = SimpleCalculate(Question.QuestionOpType, Question.Number1, Question.Number2);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	}
	case enQuestionLevel::LevelHard:
	{
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);
		Question.CorrectAnswer = SimpleCalculate(Question.QuestionOpType, Question.Number1, Question.Number2);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	}

	}

	return Question;
}

string GetTheQuestionLevelText(enQuestionLevel QuestionLevel)
{
	string arrquestionleveltext[4] = { "Easy" ,"Med" , "Hard","Mix" };

	return arrquestionleveltext[QuestionLevel - 1];
}

string SimpleOpTypeText(enOpType OperationType)
{
	switch (OperationType)
	{
	case enOpType::OpAdd:
		return "+";
	case enOpType::OpSub:
		return "-";
	case enOpType::OpMult:
		return "*";
	case enOpType::OpDiv:
		return "/";
	default:
		return "Mix";
	}
}

void GenerateQuizzQuestion(stQuizz& Quizz)
{
	for (short NumberOfQuestion = 0; NumberOfQuestion < Quizz.NumberOfQuestions; NumberOfQuestion++)
	{
		Quizz.QuestionList[NumberOfQuestion] = GenerateQuestion(Quizz.QuizzLevel, Quizz.QuizzOpType);
	}
}

void PrintTheQuestion(stQuizz& Quizz, short NumberOfQuestion)
{
	cout << "\n";
	cout << "Question [" << NumberOfQuestion + 1 << "/" << Quizz.NumberOfQuestions << "]\n";
	cout << Quizz.QuestionList[NumberOfQuestion].Number1 << endl;
	cout << Quizz.QuestionList[NumberOfQuestion].Number2 << " ";
	cout << SimpleOpTypeText(Quizz.QuestionList[NumberOfQuestion].QuestionOpType) << endl;
	cout << "______________________\n";
}

short GetTheQuestionAnswer()
{
	short Number;
	cin >> Number;
	return Number;
}

void SetScreenColor(bool Right)
{
	if (Right)
		system("color 2F");
	else
		system("color 4F");
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short NumberOfQuestion)
{
	if (Quizz.QuestionList[NumberOfQuestion].CorrectAnswer != Quizz.QuestionList[NumberOfQuestion].PlayerAnswer)
	{
		Quizz.NumberOfWrongAnswers++;
		Quizz.QuestionList[NumberOfQuestion].AnswerResult = false;
		cout << "Wrong Answer.\n";
		cout << "The Right Answer " << Quizz.QuestionList[NumberOfQuestion].CorrectAnswer << endl;
	}
	else
	{
		Quizz.NumberOfRightAnswers++;
		Quizz.QuestionList[NumberOfQuestion].AnswerResult = true;
		cout << "Right Answer.\n";
	}
	SetScreenColor(Quizz.QuestionList[NumberOfQuestion].AnswerResult);

}

void AskAndCorrectTheQuestionAnswer(stQuizz& Quizz)
{
	for (short NumberOfQuestion = 0; NumberOfQuestion < Quizz.NumberOfQuestions; NumberOfQuestion++)
	{
		PrintTheQuestion(Quizz, NumberOfQuestion);

		Quizz.QuestionList[NumberOfQuestion].PlayerAnswer = GetTheQuestionAnswer();

		CorrectTheQuestionAnswer(Quizz, NumberOfQuestion);

	}

	Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

string ShowPASSFailText(bool Right)
{
	if (Right)
		return "PASS :-)";
	else
		return "Fail :-(";
}

void PrintQuizzResult(stQuizz Quizz)
{
	cout << "\n\n_____________________________________\n\n";
	cout << "   Final Result is " << ShowPASSFailText(Quizz.isPass) << endl;
	cout << "\n_____________________________________\n\n";
	cout << "Number of Questions : " << Quizz.NumberOfQuestions << endl;
	cout << "Questions Level     : " << GetTheQuestionLevelText(Quizz.QuizzLevel) << endl;
	cout << "OpType              : " << SimpleOpTypeText(Quizz.QuizzOpType) << endl;
	cout << "Number of Right Answer: " << Quizz.NumberOfRightAnswers << endl;
	cout << "Number of Wrong Answer: " << Quizz.NumberOfWrongAnswers << endl;
	cout << "\n_____________________________________\n\n";

	SetScreenColor(Quizz.isPass);
}

void PlayMathGame()
{
	stQuizz Quizz;
	Quizz.NumberOfQuestions = ReadHowManyQuestions();
	Quizz.QuizzLevel = ReadQuestionLevel();
	Quizz.QuizzOpType = ReadOperationType();

	GenerateQuizzQuestion(Quizz);
	AskAndCorrectTheQuestionAnswer(Quizz);
	PrintQuizzResult(Quizz);

}

void StartGame()
{
	char PlayAgain = 'Y';
	do
	{
		ResetScreenColor();

		PlayMathGame();

		cout << "Do you want to play again? Y/N ? : ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();
	   
	return 0;


	
}

