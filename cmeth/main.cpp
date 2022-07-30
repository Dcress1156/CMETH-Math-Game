#include <iostream>			// need
#include <random>			// for rng
#include <limits>			// error handling
#include <string>
#include <string_view>	

// error handling
void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// most of this is badly written
// this is what happens when a noob (myself) uses everything they have learned to make a simple program :)

namespace prng
{
	// prng::customRange(x, y) //

	std::random_device rd;

	std::seed_seq seed{ rd(), rd(), rd(), rd(),
					   rd(), rd(), rd(), rd() };

	std::mt19937 mt{ seed };

	double customRange(int min, int max)
	{
		std::uniform_int_distribution range{ min, max };
		return range(mt);
	}
}

// stuff for the cmeth game
namespace cmeth
{
	// easy = 1 because we use this with user input and starting a printed list with 0 is odd
	enum Difficulty
	{
		easy = 1,
		medium = 2,
		hard = 3,
		insane = 4,
		impossible = 5,
	};

	enum Operator
	{
		addition,			// 0
		subtraction,		// 1
		multiplication,		// 2
		division,			// 3
	};

	// off/on switch used in isRunning() and main() loop
	enum Gamestate
	{
		notRunning = false,
		running = true,
		error = notRunning,
	};

	// our solution for clearing the console. Will only work on Windows.
	void cc()
	{
		system("cls");
	}
}

// because std::cout can't print a 'difficulty'
std::string_view printDifficulty(cmeth::Difficulty difficulty)
{
	switch (difficulty)
	{
	case cmeth::Difficulty::easy:		return "Easy";
		break;
	case cmeth::Difficulty::medium:		return "Medium";
		break;
	case cmeth::Difficulty::hard:		return "Hard";
		break;
	case cmeth::Difficulty::insane:		return "Insane";
		break;
	case cmeth::Difficulty::impossible:	return "Impossible";
		break;
	default:							return "????";
		break;
	}

}

// used to play again or quit the game
cmeth::Gamestate isRunning()
{
	char runningSel{};
	do {
		std::cout << "Would you like to play again? y/n: ";
		std::cin >> runningSel;

		if ((!std::cin) or (runningSel != 'y') or (runningSel != 'n'))
		{
			std::cin.clear();
			ignoreLine();
		}
		else
		{
			ignoreLine();
		}
	} while ((runningSel != 'y') and (runningSel != 'n'));

	if (runningSel == 'y')
	{
		return cmeth::Gamestate::running;
	}
	else if (runningSel == 'n')
	{
		return cmeth::Gamestate::notRunning;
	}
	else
	{
		std::cout << "An unexpected error has occured.";
		return cmeth::Gamestate::error;
	}
}

// storing random question in a struct
// because each question has multiple pieces of data associated with it
struct cmethexpr
{
	cmeth::Difficulty	diff{};
	cmeth::Operator		op{};

	double fNum{};
	double sNum{};

	double solution{};
};

// an overly long and needlessly complicated series of switch statements
// sets up the random questions for the game loop using the above struct
cmethexpr returnRandQuestion(cmeth::Difficulty difficulty)
{
	using namespace cmeth;
	cmethexpr question{};
	question.diff = difficulty;

	double operand1{};
	double operation{};
	double operand2{};

	switch (difficulty)
	{
	case easy:
		operand1 = prng::customRange(1, 10);
		operation = prng::customRange(0, 2);
		operand2 = prng::customRange(1, 10);
		question.op = static_cast<Operator>(operation);
		question.fNum = operand1;
		question.sNum = operand2;
		switch (static_cast<Operator>(operation))
		{
		case addition:
			question.solution = question.fNum + question.sNum;
			return question;
		case subtraction:
			question.solution = question.fNum - question.sNum;
			return question;
		case multiplication:
			question.solution = question.fNum * question.sNum;
			return question;
		case division:
			question.solution = question.fNum / question.sNum;
			return question;
		}
	case medium:
		operand1 = prng::customRange(1, 99);
		operation = prng::customRange(0, 2);
		operand2 = prng::customRange(1, 99);
		question.op = static_cast<Operator>(operation);
		question.fNum = operand1;
		question.sNum = operand2;
		switch (static_cast<Operator>(operation))
		{
		case addition:
			question.solution = question.fNum + question.sNum;
			return question;
		case subtraction:
			question.solution = question.fNum - question.sNum;
			return question;
		case multiplication:
			question.solution = question.fNum * question.sNum;
			return question;
		case division:
			question.solution = question.fNum / question.sNum;
			return question;
		}
	case hard:
		operand1 = prng::customRange(1, 100);
		operation = prng::customRange(0, 2);
		operand2 = prng::customRange(1, 100);
		question.op = static_cast<Operator>(operation);
		question.fNum = operand1;
		question.sNum = operand2;
		switch (static_cast<Operator>(operation))
		{
		case addition:
			question.solution = question.fNum + question.sNum;
			return question;
		case subtraction:
			question.solution = question.fNum - question.sNum;
			return question;
		case multiplication:
			question.solution = question.fNum * question.sNum;
			return question;
		case division:
			question.solution = question.fNum / question.sNum;
			return question;
		}
	case insane:
		operand1 = prng::customRange(1, 1000);
		operation = prng::customRange(0, 3);
		operand2 = prng::customRange(1, 1000);
		question.op = static_cast<Operator>(operation);
		question.fNum = operand1;
		question.sNum = operand2;
		switch (static_cast<Operator>(operation))
		{
		case addition:
			question.solution = question.fNum + question.sNum;
			return question;
		case subtraction:
			question.solution = question.fNum - question.sNum;
			return question;
		case multiplication:
			question.solution = question.fNum * question.sNum;
			return question;
		case division:
			question.solution = question.fNum / question.sNum;
			return question;
		}
	case impossible:
		operand1 = prng::customRange(1, 10000);
		operation = prng::customRange(0, 3);
		operand2 = prng::customRange(1, 10000);
		question.op = static_cast<Operator>(operation);
		question.fNum = operand1;
		question.sNum = operand2;
		switch (static_cast<Operator>(operation))
		{
		case addition:
			question.solution = question.fNum + question.sNum;
			return question;
		case subtraction:
			question.solution = question.fNum - question.sNum;
			return question;
		case multiplication:
			question.solution = question.fNum * question.sNum;
			return question;
		case division:
			question.solution = question.fNum / question.sNum;
			return question;
		}
	}
	return question;
}

// returns the questions operation as a character
std::string_view operatorToChar(cmeth::Operator op)
{
	using namespace cmeth;

	switch (op)
	{
	case addition:
		return " + ";
	case subtraction:
		return " - ";
	case multiplication:
		return " * ";
	case division:
		return " / ";
	}
	return " ? ";
}

// used during gameplay to get users answer for the question
double getUserAnswer()
{
	double userInput{};

	do
	{
		std::cout << "> ";
		std::cin >> userInput;

		if (!std::cin)
		{
			std::cin.clear();
			ignoreLine();
		}
		else
		{
			ignoreLine();
		}

	} while (!std::cin);

	return userInput;
}

// determines lives count depending on difficulty choice
int getLives(cmeth::Difficulty difficulty)
{
	using namespace cmeth;

	switch (difficulty)
	{
	case easy:			return 10;
	case medium:		return 8;
	case hard:			return 6;
	case insane:		return 4;
	case impossible:	return 0;
	}
	return -1;
}

// technically there are two "game" loops, this one is for the actual gameplay
// and yes we are stretching the definition of the word "game"
void gameLoop(cmeth::Difficulty difficulty)
{
	// returns our difficulty via string
	std::string_view difficultyText{ printDifficulty(difficulty) };
	using namespace cmeth;

	// uses difficulty to determine lives count
	int lives{ getLives(difficulty) };
	std::string lastQuestion{};

	// i is only used to determine the question number
	// thus you cannot answer more than 10,000 questions (Not that you would want to anyway)
	for (int i{ 1 }; i < 10000; ++i)
	{
		if (lives < 0)
		{
			std::cout << "You are out of lives! Game Over.\n";
			break;
		}
		cmeth::cc();
		cmethexpr cQuestion = returnRandQuestion(difficulty);
		std::cout << "Difficulty: " << difficultyText << '\n';
		std::cout << "Lives Remaining: " << lives << '\n';
		std::cout << "Last Question: " << lastQuestion << '\n';
		std::cout << '\n';
		std::cout << "#" << i << ": ";
		std::cout << cQuestion.fNum << operatorToChar(cQuestion.op) << cQuestion.sNum;
		std::cout << '\n' << '\n';

		double userAnswer{ getUserAnswer() };

		if (userAnswer == cQuestion.solution)
		{
			lastQuestion = "Correct!";
			std::cout << '\n';
			continue;
		}
		else if (userAnswer != cQuestion.solution)
		{
			--lives;
			lastQuestion = "Incorrect!";
			std::cout << '\n';
		}

		// would never actually be called, but just in case.
		// In retrospect, it would be better to omit the above else if and delagate to an else statement
		else
		{
			std::cout << "This isn't even possible!\n";
		}
	}
}

cmeth::Difficulty difficultySelection()
{
	int mSel{};

	do
	{
		std::cout << "> ";
		std::cin >> mSel;

		if (!std::cin || mSel < cmeth::easy || mSel > cmeth::impossible)
		{
			std::cin.clear();
			ignoreLine();
			std::cerr << "That is not a valid input. Please try again.\n";
		}
		else
		{
			ignoreLine();
		}

	} while (mSel < cmeth::easy || mSel > cmeth::impossible);


	return static_cast<cmeth::Difficulty>(mSel);
}

// it probably isn't the best choice to put the "menu" in the main function
// but I really don't want to continue working on this program
// it is too badly written and it would be better to just rewrite this with more features later
int main()
{
	do
	{
		cmeth::cc();
		std::cout << "     +-------------------+" << '\n';
		std::cout << "     | Welcome To cMeth! |" << '\n';
		std::cout << "     |  A Fun Math Game  |" << '\n';
		std::cout << "     +-------------------+" << '\n' << '\n';

		std::cout << "1: Easy \t(For children)" << '\n';

		std::cout << "2: Medium \t(You know a little...)" << '\n';
		std::cout << "3: Hard \t(You graduated.)" << '\n';
		std::cout << "4: Insane \t(You enjoy punishment)" << '\n';
		std::cout << "5: Impossible \t(Trust me, your parents aren't proud)" << '\n' << '\n';

		//	difficultySelection();
		gameLoop(difficultySelection());
	} while (isRunning());

	return 0;
}
