#include "ClassInit.h"
//		 ========================================== Console Handler =======================================
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//		 ========================================== GameController Class Definition =======================================
void GameController::Render(){
	using namespace std;
	system("cls");
	int CaseIn = 0;
	for (int i = 0; i < 3; i++)
	{
		printf("\n                 ");
		for (int j = 0; j < 3; j++)
		{
			if (Board[CaseIn] != 0 && j!=2)
			{
				if (Board[CaseIn] == player1.sym)
					colorN::ChangeColor(player1.color);
				else colorN::ChangeColor(player2.color);
				printf("%c", Board[CaseIn]);
				colorN::initColor();
				printf("||");
				CaseIn++;
			}
			else if (j != 2) {
				printf("%d||",CaseIn+1);
				CaseIn++;
			}
			else if (j == 2) {
				if (Board[CaseIn] == player1.sym) {
					colorN::ChangeColor(player1.color);
					printf("%c", Board[CaseIn]);
					CaseIn++;
					colorN::initColor();
				}
				else if (Board[CaseIn] == player2.sym) {
					colorN::ChangeColor(player2.color);
					printf("%c", Board[CaseIn]);
					CaseIn++;
					colorN::initColor();
				}
				else {
					printf("%d", CaseIn + 1);
					CaseIn++;
				}
			}
			
		}
		if (i != 2)
		{
			printf("\n                 -------");
		}

	}
	
}



const bool GameController::CheckIfOver() {
	for (int i = 0; i < 9; i++)
	{
		if (Board[i] == 0)
			return false;
	}
	
	return true;
}

const int GameController::CheckIfWon(Player whoPlaying) {
	colorN::ChangeColor(whoPlaying.color);
	PlayerMark who = whoPlaying.sym;
		if ((Board[A1] == who && Board[A2] == who && Board[A3] == who)
			|| (Board[B1] == who && Board[B2] == who && Board[B3] == who)
			|| (Board[C1] == who && Board[C2] == who && Board[C3] == who))
		{
			std::cout << "  Player " <<(char) who << " Won the game" << std::endl;
			colorN::initColor();
			return 1;
		}
		else if ((Board[A1] == who && Board[B1] == who && Board[C1] == who)
			|| (Board[A2] == who && Board[B2] == who && Board[C2] == who)
			|| (Board[A3] == who && Board[B3] == who && Board[C3] == who))
		{
			std::cout << "  Player " << (char)who << " Won the game" << std::endl;
			colorN::initColor();
			return 1;
		}
		else if ((Board[A1] == who && Board[B2] == who && Board[C3] == who)
			|| (Board[A3] == who && Board[B2] == who && Board[C1] == who))
		{
			std::cout << "  Player " << (char)who << " Won the game" << std::endl;
			colorN::initColor();
			return 1;
		}
		colorN::initColor();
		return 0;
	}
void GameIsOver() {
	colorN::ChangeColor(Purple);
	std::cout << "        TIE " << std::endl;
	colorN::initColor();
	}
void GameController::PlayGame() {
	using namespace std;
	if (PlayerFirst)
	{
		Render();
		PlayerPlay(player1);
		Render();
	}
	do {
		if (IAEnabled) {
			//IA PLAY
		}
		else{ PlayerPlay(player2); }
		Render();
		if (CheckIfOver()) {
			GameIsOver();
			GameOver = true;
			break;
		}
		if (CheckIfWon(player2))
		{
			GameOver = true;
			break;
		}
		PlayerPlay(player1);
		Render();
		if (CheckIfWon(player1))
		{
			GameOver = true;
			break;
		}
		if (CheckIfOver()) {
			GameIsOver();
			GameOver = true;
			break;
		}
	} while (!GameOver);
	cout << endl;
}

const bool GameController::CanPlay(int choice) {
	if (Board[choice - 1] == 0)
		return true;
	return false;
}
void GameController::PlayerPlay(Player whoPlaying) {
	int choice;
	PlayerMark who = whoPlaying.sym;
	do {
		Render();
		colorN::ChangeColor(whoPlaying.color);
		std::cout << "\n\n\n\nPlayer "<<(char)who << " Turn :Case Number ? :";
		std::cin.clear();
		std::cin >> choice;
	} while (choice > 9 || choice < 1 || !CanPlay(choice));
	GameController::Board[choice - 1] = (char)who;
}
//		 ==========================================PLAYER CLASS Definition===========================================
Player::Player() {
	PlayerMark Symbols[] = { X,O };
	Color Colors[] = {Green,Red};
	sym = Symbols[PlayerCount];
	color = Colors[PlayerCount];
	Player::PlayerCount++;
}
bool Player::operator==(Player player1)const {
	if (this->sym == player1.sym && this->color == player1.color)
		return 1;
	return 0;
}
//		 ==========================================Color NAMESPACE Definition=======================================

void colorN::ChangeColor(Color color) {
	SetConsoleTextAttribute(hConsole, color);
}
void colorN::initColor() {
	SetConsoleTextAttribute(hConsole, White);
}