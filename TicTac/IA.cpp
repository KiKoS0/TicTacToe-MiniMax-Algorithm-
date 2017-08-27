#include "ClassInit.h"

IA::IA(GameController* gameController) :Player(ON), choice(-1), Controller(gameController) {
	GameBoard = Controller->getBoard();
}


bool IA::GameIsWon(std::vector<char>& Board,PlayerMark currentSym)
{
		if ((Board[A1] == currentSym && Board[A2] == currentSym && Board[A3] == currentSym)
			|| (Board[B1] == currentSym && Board[B2] == currentSym && Board[B3] == currentSym)
			|| (Board[C1] == currentSym && Board[C2] == currentSym && Board[C3] == currentSym))
		{
			return 1;
		}
		else if ((Board[A1] == currentSym && Board[B1] == currentSym && Board[C1] == currentSym)
			|| (Board[A2] == currentSym && Board[B2] == currentSym && Board[C2] == currentSym)
			|| (Board[A3] == currentSym && Board[B3] == currentSym && Board[C3] == currentSym))
		{
			return 1;
		}
		else if ((Board[A1] == currentSym && Board[B2] == currentSym && Board[C3] == currentSym)
			|| (Board[A3] == currentSym && Board[B2] == currentSym && Board[C1] == currentSym))
		{
			return 1;
		}
		return 0;
}

int IA::Score(std::vector<char> Board,int depth)
{
	if (GameIsWon(Board,this->sym))
	{
		return 10- depth;
	}
	else if (GameIsWon(Board,this->Controller->player1.sym)) 
	{
		return depth-10;
	}
	return 0;
}

bool IA::GameIsOver(std::vector<char>& Board)
{
	PlayerMark Symbols[] = { X,O };
	for (auto currenSym : Symbols)
		if (GameIsWon(Board, currenSym))
			return 1;
	for (auto Position : Board) 
		if (Position==0)
			return 0;
	return 1;
	}

void IA::Think()
{
	GameBoard=Controller->getBoard();
	bool helper = true;
	MiniMax(GameBoard, true,0);
	printf("\n%d\n", choice);
}

int IA::MiniMax(std::vector<char> Board, bool IsmyTurn,int depth)
{
	if (GameIsOver(Board))
	{
		return Score(Board, depth);
	}
	depth += 1;
	std::vector<int> Scores;
	std::vector<int> Moves;
	for (SIZE_T it = 0; it < Board.size();it++) {
		if (Board[it] == 0) {
			// Position Can be played
			// Add Play to Board
			if (IsmyTurn)
			{
				Board[it] = this->sym;
			}
			else
			{
				Board[it] = Controller->player1.sym;
			}
			Scores.push_back(MiniMax(Board,!IsmyTurn,depth));
			Moves.push_back(it);
			Board[it] = 0; // Removing This will make the AI dump as fuck xD
		}
	}
	
	if (IsmyTurn) {
		auto result = std::max_element(Scores.begin(), Scores.end());
		int max_score_index = std::distance(Scores.begin(), result);
		this->choice = Moves[max_score_index];
		return Scores[max_score_index];
	}
	else {
		auto result = std::min_element(Scores.begin(), Scores.end());
		int min_score_index = std::distance(Scores.begin(), result);
		this->choice = Moves[min_score_index];
		return Scores[min_score_index];
	}
}

