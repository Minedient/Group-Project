#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
using namespace std;

bool tBombOn = 0, pcDemoOn = 0;
char blockChar = 'X';
int boardSize = 10;

class Block
{
public:
	//create block for player to pick with blockTemplate(block type, index number)
	void blockTemplate(int x, int y)
	{
		blockIndex = y;
		switch(x){
			//block types
			case 1: blockS = {blockChar}; placeScore = 10; 
				break;
			case 2: blockS = {blockChar, blockChar}; placeScore = 20; 
				break;
			case 3: blockS = {blockChar, blockChar, blockChar}; placeScore = 30; 
				break;
			case 4: blockS = {blockChar, blockChar, blockChar, blockChar}; placeScore = 40; 
				break;
			case 5: blockS = {blockChar, blockChar, blockChar, blockChar, blockChar}; placeScore = 0; 
				break;
			case 6: blockS = {{blockChar}, {blockChar}}; placeScore = 20; 
				break;
			case 7: blockS = {{blockChar}, {blockChar}, {blockChar}}; placeScore = 30; 
				break;
			case 8: blockS = {{blockChar}, {blockChar}, {blockChar}, {blockChar}}; placeScore = 40; 
				break;
			case 9: blockS = {{blockChar}, {blockChar}, {blockChar}, {blockChar}, {blockChar}}; placeScore = 0; 
				break;
			case 10: blockS = {{blockChar}, {blockChar, blockChar}}; placeScore = 30;
				break;
			case 11: blockS = {{' ', blockChar}, {blockChar, blockChar}}; placeScore = 30;
				break;
			case 12: blockS = {{blockChar, blockChar}, {blockChar}}; placeScore = 30;
				break;
			case 13: blockS = {{blockChar, blockChar}, {' ', blockChar}}; placeScore = 30;
				break;
			case 14: blockS = {{blockChar}, {blockChar}, {blockChar, blockChar, blockChar}}; placeScore = 50;
				break;
			case 15: blockS = {{' ', ' ', blockChar}, {' ', ' ', blockChar}, {blockChar, blockChar, blockChar}}; placeScore = 50; 
				break;
			case 16: blockS = {{blockChar, blockChar, blockChar}, {blockChar}, {blockChar}}; placeScore = 50;
				break;
			case 17: blockS = {{blockChar, blockChar, blockChar}, {' ', ' ', blockChar}, {' ', ' ', blockChar}}; placeScore = 50;
				break;
			case 18: blockS = {{blockChar, blockChar}, {blockChar, blockChar}}; placeScore = 40;
				break;
			case 19: blockS = {{blockChar, blockChar, blockChar}, {blockChar, blockChar, blockChar}, {blockChar, blockChar, blockChar}}; placeScore = 90; 
				            break;
	}
	}
private:
	char blockS[5][5] = {{' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' '}};
	int placeScore, blockIndex;
}

void blockBoard();

bool exit(char[]);

void credit();

int main()
{
	int choice;
	char mainmenuExit[40] = "You really want to exit : |???";

	//The main loop of the game, only break out when user want to exit
	while(1){
		cout << endl;
		cout << "Welcome Message designed by your group\n" << endl;
		cout << "*** Game Menu ***" << endl;
		cout << "[1] Start Game" << endl;
		cout << "[2] Settings" << endl;
		cout << "[3] Instructions" << endl;
		cout << "[4] Credits" << endl;
		cout << "[5] Exit" << endl;
		cout << "*****************" << endl;
		cin >> choice;

		switch (choice){
		case 1: /*P1 here*/ ; break;
		case 2: /*P2 here*/ ; break;
		case 3: /*P3 here*/ ; break;
		case 4: credit() ; break;
		case 5: if(exit(mainmenuExit) == true)
					return 0;
				else continue;
		default:
			cout << "Please enter choice 1 - 5 only." << endl;
			break;

		}
		//Clear Screen
		system("cls");
	};
}
	
void blockBoard(){
	char boardSpace[10][10];
	
	//store empty space into board
	for (int i = 0; i < boardSize; i++){
		for (int j = 0; j < boardSize; j++){
			boardSpace[i][j] = ' ';
		}
	}
	
}

//Macro exit function (with y/n) for returning to upper level of the program, terminate the program when execute in main menu
bool exit(char msg[]){
	char isexit;
	while(1){
		cout << msg << endl;
		cout << "(y/n)" << endl;
		cin >> isexit;
		if(isexit == 'y'|| isexit == 'Y')
			return true;
		else if(isexit == 'n'|| isexit == 'N'){
			system("cls");
			return false;
		}else{
			system("cls");
			cout << "Only y/n is accepted" << endl;
		}
	}

}

void credit(){

}
