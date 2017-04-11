#include "Header.h"

int Check() {
	using namespace std;
	cout << "Play First(Y,N)? ";
	char ans;
	cin >> ans;
	if (ans == 'y' || ans == 'Y')
	{
		return 1;

	}
	else if (ans == 'N' || ans == 'n')
		return 0;
	return -1;

}



void main() {
	using namespace std;
	GameController game;
	int PlayerFirst;
	do {
		PlayerFirst = Check();
	} while (PlayerFirst==-1);
	game.PlayerFirst = PlayerFirst;
	game.PlayGame();


}
