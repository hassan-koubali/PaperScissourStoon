#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int GetNumberOfRound(string messege) {
	int number = 0;
	do
	{
		cout << messege << endl;
		cin >> number;
	} while (number < 0 || number > 10);
	return number;
}
int GetPlayer1Choice(string messege) {
	int number = 0;
	do
	{
		cout << messege << endl;
		cin >> number;
	} while (number < 1 || number > 3);
	return number;
}
int RandomNumber(int from, int to) {
	int number = rand() % (to - from + 1) + from;
	return number;
}
void ResetScrin() {
	system("cls");
	system("color 0F");
}
string compareFunction(short choice) {
	if (choice == 1)
		return "Stoon";
	else if (choice == 2)
	{
		return "Paper";
	}
	else
	{
		return "scissour";
	}
}
string WhoWinTheRound(string compar_Player1eChoice, string compar_ComputereChoice) {
	if (compar_Player1eChoice == compar_ComputereChoice)
	{
		return "Draw";
	}
	else if (compar_Player1eChoice == "Stoon" && compar_ComputereChoice == "Paper")
	{
		return "Computer win";
	}
	else if (compar_Player1eChoice == "Paper" && compar_ComputereChoice == "scissour")
	{
		return "Computer win";
	}
	else if (compar_Player1eChoice == "scissour" && compar_ComputereChoice == "Stoon")
	{
		return "Computer win";
	}
	else
	{
		return "Player 1 win";
	}
}
void PrintWinTheRound(string Player1WineTimes, string ComputerWineTimes, string  Win, short Round) {
	cout << "----------------Round [" << Round << "]----------------\n";
	cout << "Player 1 Choice is :" << Player1WineTimes << endl;
	cout << "Compiter Choice is :" << ComputerWineTimes << endl;
	cout << "Round Win is :" << Win << endl;
	cout << "----------------------------------------------------------------------------" << endl;
}
string Tabs(short NumberOfTabs) {
	string t = "";
	for (int i = 1; i < NumberOfTabs; i++)
	{
		t = t + '\t';
		cout << t;
	}
	return t;
}
void ShowGameOverScreen()
{
	cout << Tabs(2) << "__________________________________________________________\n\n";
	cout << Tabs(2) << "                 +++ G a m e  O v e r +++\n";
	cout << Tabs(2) << "__________________________________________________________\n\n";
}
void ShowFinalGameResult(short Round, short DrawTimes, short Player1WineTimes, short ComputerWineTimes, string WinTheGame) {
	cout << Tabs(2) << "___________________ [Game Results ]_____________________\n\n";
	cout << Tabs(2) << "Game Rounds        : " << Round << endl;
	cout << Tabs(2) << "Player1 won times  : " << Player1WineTimes << endl;
	cout << Tabs(2) << "Computer won times : " << ComputerWineTimes << endl;
	cout << Tabs(2) << "Draw times         : " << DrawTimes << endl;
	cout << Tabs(2) << "Final Winner       : " << WinTheGame << endl;
	cout << Tabs(2) << "___________________________________________________________\n";

}
string GetWhoWinTheGame(int Player1WineTimes, int ComputerWineTimes, int DrawTimes) {
	if (Player1WineTimes > ComputerWineTimes)
	{
		return "Player 1 win The Game\n";
	}
	else if (Player1WineTimes < ComputerWineTimes)
	{
		return "Computer Win The Game\n";
	}
	else
	{
		return "Draw";
	}
}

void PlayGame() {
	short Player1WineTimes = 0, ComputerWineTimes = 0, DrawTimes = 0;
	short NumberOfRound = GetNumberOfRound("pleas entr how many round\n");
	for (short Round = 1; Round <= NumberOfRound; Round++)
	{
		short Player1Choice = GetPlayer1Choice("pleas entr Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ");
		short ComputerChoice = RandomNumber(1, 3);
		string compar_Player1eChoice = compareFunction(Player1Choice);
		string compar_ComputereChoice = compareFunction(ComputerChoice);
		string WinTheRound = WhoWinTheRound(compar_Player1eChoice, compar_ComputereChoice);

		//Increase win/Draw counters 

		if (WinTheRound == "Draw")
		{
			system("color 6F");
			DrawTimes++;
		}
		else if (WinTheRound == "Computer win")
		{
			system("color 4F");
			cout << "\a";
			ComputerWineTimes++;
		}
		else if (WinTheRound == "Player 1 win")
		{
			system("color 2F");
			Player1WineTimes++;
		}
		PrintWinTheRound(compar_Player1eChoice, compar_ComputereChoice, WinTheRound, Round);
	}
	string WinTheGame = GetWhoWinTheGame(Player1WineTimes, ComputerWineTimes, DrawTimes);
	ShowFinalGameResult(NumberOfRound, DrawTimes, Player1WineTimes, ComputerWineTimes, WinTheGame);
}
void Play() {
	char play = 'Y';
	do
	{
		ResetScrin();
		PlayGame();
		cout << "do you went to game again? [Y]\n";
		cin >> play;
	} while (play == 'Y' || play == 'y');
}
int main() {
	//Seeds the random number generator in C++, called only once  
	srand((unsigned)time(NULL));
	Play();
	return 0;
}