#include "Header.h"

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
				printf("%c||", Board[CaseIn]);
				CaseIn++;
			}
			else if (j != 2) {
				printf(" ||");
				CaseIn++;
			}
			else if (j == 2) {
				printf("%c", Board[CaseIn]);
				CaseIn++;
			}
			else {
				printf(" ");
				CaseIn++;
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

const void GameController::CheckIfWon() {

}
void GameController::PlayGame() {
	using namespace std;
	if (PlayerFirst)
	{
		Render();
		PlayerPlay();
		Render();
	}
	do {
		//IA Play;
		PlayerPlay();
		Render();
	/*	if (CheckIfWon())
		{
			break;
		}  */
		if (CheckIfOver()) {
			GameOver = true;
			break;
		}
		;
	} while (1);
	cout << endl;
}

const bool GameController::CanPlay(int choice) {
	if (Board[choice - 1] == 0)
		return true;
	return false;
}
void GameController::PlayerPlay() {
	int choice;
	do {
		std::cout << "\nCase # ? ";
		std::cin >> choice;
	} while (choice > 9 || choice < 1 || !CanPlay(choice));
	GameController::Board[choice - 1] = 'X';
}