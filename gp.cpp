#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
using namespace std;

bool tBombOn = 0, pcDemoOn = 0;
char blockChar = 'X';
int boardSize = 10;

//Declare function
void blockBoard();
bool exit(char[]);
void credit();
void blockCharC(char);
void startGame();


class Block
{
public:
	//Construtor to create block for player to pick(block type, index) 
	Block(char block[5][5],int x){
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				blockS[i][j] = block[i][j];
		blockIndex = x;
	}

	void print(){

		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				cout << blockS[i][j];
			}
			cout << endl;
		}

	}

private:
	char blockS[5][5];
	int placeScore, blockIndex;
};


int main()
{
	int choice;
	char mainmenuExit[40] = "You really want to exit : ???";
	/*
	 * Plz copy zero's work to here
	 * Please name h for horizontal block
	 * v for vectical block e.t.c
	 */
	char h1[5][5] = {blockChar};
	char h2[5][5] = {blockChar,blockChar};

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
		cout << "Option (1-5): ";
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
		//Ask User for input
		cout << msg << endl;
		cout << "(y/n)" << endl;
		cin >> isexit;
		//Check the input
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

//Show the credit page
void credit(){

}

//Change the char of the blocks
void blockCharC(char x){
	blockChar = x;
}

//Start the Game
void startGame(){

}
