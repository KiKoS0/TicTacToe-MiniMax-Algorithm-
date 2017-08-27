#pragma once
#include<iostream>
#include <string>
#include<vector>
#include<Windows.h>
#include <algorithm>
#include "IA.h"

enum { A1 = 0, A2 = 1, A3 = 2, B1 = 3, B2 = 4, B3 = 5, C1 = 6, C2 = 7, C3 = 8 };
enum Color { Green = 0xA, Aqua = 0xB, Red = 0xC, Purple = 0xD, Yellow = 0xE, White = 0xF };
enum PlayerMark { X = 'X', O = 'O' };
enum IAController { ON = true, OFF = false };

using std::vector;

class GameController;
class Player {
	Player();
public:
	
	Player(IAController AIEnable);
	Color color;
	PlayerMark sym;
	bool AI;
	bool operator==(Player player1)const;
	virtual ~Player() {}
};

class IA : public Player {
	GameController * Controller;
	std::vector<char> GameBoard;
	bool GameIsWon(std::vector<char>& Board, PlayerMark currentSym);
	int Score(std::vector<char> Board, int depth);
	int MiniMax(std::vector<char> Board, bool IsmyTurn, int depth);
	bool GameIsOver(std::vector<char>& Board);
public:
	void Think();
	int choice;
	IA(GameController* gameController);
};

class GameController {

protected :
	vector<char> Board;
private:
	Player* player2;
	// True if game is over
	bool GameOver;
	// True if second player is AI
	bool AIEnabled;
	// Console Render
	void Render();
	void PlayerPlay(Player* whoPlaying);
	const int CheckIfWon(Player whoPlaying);
	const bool CheckIfOver();
	const bool CanPlay(int choice);
public: 
	static int PlayerCount;
	unsigned PlayerTurn;
	Player player1;
	bool PlayerFirst;
	void PlayGame();
	GameController(IAController IAENABLED);
	const vector <char> getBoard();
	void CheckFirst();
	~GameController() {
		PlayerCount = 0;
	}
};





namespace colorN {
	void ChangeColor(Color color);
	void initColor();
}

