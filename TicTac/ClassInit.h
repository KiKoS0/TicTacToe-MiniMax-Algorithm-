#pragma once
#include<iostream>
#include <string>
#include<vector>
#include<Windows.h>
enum { A1 = 0, A2 = 1, A3 = 2, B1 = 3, B2 = 4, B3 = 5, C1 = 6 , C2=7 , C3=8 };
enum Color{Green=0xA,Aqua=0xB,Red=0xC,Purple=0xD,Yellow=0xE,White=0xF};
enum PlayerMark { X = 'X', O = 'O' };

enum IAController{ON=true,OFF=false};
using std::vector;

class Player {

	
public:
	static int PlayerCount;
	Player();
	Color color;
	PlayerMark sym;
	bool operator==(Player player1)const;
};



class GameController {
protected :
	vector<char> Board;
private:
	Player player1, player2;
	bool GameOver;
	bool IAEnabled;
	void Render();
	void PlayerPlay(Player whoPlaying);
	const int CheckIfWon(Player whoPlaying);
	const bool CheckIfOver();
	const bool CanPlay(int choice);
public: 
	bool PlayerFirst;
	void PlayGame();
	GameController(IAController IA)  {
		Player::PlayerCount = 0;
		if (IA == OFF)
			IAEnabled = false;
		else
			IAEnabled = true;
		GameOver = false;
		for (int i = 0; i < 9; i++)
		{
			Board.push_back(0);
		}
	}
	int CheckFirst() {
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

};




class IA {
	
};


namespace colorN {
	void ChangeColor(Color color);
	
	void initColor();
}

