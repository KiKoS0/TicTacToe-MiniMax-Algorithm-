#include "ClassInit.h"
#include "IA.h"
int GameController::PlayerCount=0;
bool vsAI() {
	 using namespace std;
	 char ans;
	 do
	 {
		 cout << "Play VS AI(Y,N)? ";
		 cin >> ans;
		 if (ans == 'y' || ans == 'Y')
		 {
			 return true;
		 }
		 else if (ans == 'N' || ans == 'n')
			 return false;
	 } while (ans != 'N' && ans != 'n' && ans != 'y' && ans != 'Y');
}
void main() {
	using namespace std;
	GameController* game;
	int PlayerFirst;
	int Again;
	do {
		bool isVsAI = vsAI();
		game = new GameController((IAController)isVsAI);
		game->PlayGame();
		delete(game);
		cout << "Play Again(Y,N)? ";
		char ans;
		do {
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
