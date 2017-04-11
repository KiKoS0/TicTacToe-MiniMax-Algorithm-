#pragma once
#include<iostream>
#include <string>
#include<vector>

using std::vector;
class GameController {
	vector<char> Board;
	bool GameOver;
void Render();
void PlayerPlay();
const void CheckIfWon();
const bool CheckIfOver();
const bool CanPlay(int choice);
public: 
	bool PlayerFirst;
	void PlayGame();
	GameController() {
		GameOver = 0;
		for (int i = 0; i < 9; i++)
		{
			Board.push_back(0);
		}
	}

};




class IA {
	enum { A1 = 0, A2 = 1, A3 = 2, B1 = 3, B2 = 4, B3 = 5, B4 = 5 };
};