#include "ClassInit.h"

int CheckFirst() {
	using namespace std;
	cout << "Play First(Y,N)? ";
	char ans;
	std::cin.clear();
	cin >> ans;
	if (ans == 'y' || ans == 'Y')
	{
		return 1;
	}
	else if (ans == 'N' || ans == 'n')
		return 0;
	return -1;

}
int Player::PlayerCount;

void main() {

	using namespace std;
	GameController* game;
	int PlayerFirst;
	int Again;
	/*do {
		PlayerFirst = CheckFirst();
		system("cls");
	} while (PlayerFirst==-1);
	game.PlayerFirst = PlayerFirst;*/
	do {
		game = new GameController(OFF);
		game->PlayGame();
		delete(game);
		cout << "Play Again(Y,N)? ";
		char ans;
		do {
			cin.clear();
			cin >> ans;
			if (ans == 'y' || ans == 'Y')
			{
				Again = 1;
			}
			else if (ans == 'N' || ans == 'n')
				Again = 0;
			else Again = -1;
		} while (Again == -1);
	} while (Again != 0);
	system("cls");
	colorN::ChangeColor(Red);
	cout << "Thanks For Playing" << endl;
	colorN::initColor();
}
