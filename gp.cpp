#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <ctime>
using namespace std;

bool tBombOn = 0, pcDemoOn = 0;
char blockChar = 'X';
int boardSize = 10, tBombCount = 9;

//Declare function
void blockBoard();
bool exit(char[]);
void credit();
void blockCharC();
void startGame();
void settingsMenu();

class Block
{
public:
	//Construtor to create block for player to pick(block type, index, blockCount) 
	Block(char block[5][5],int x,int b){
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				blockS[i][j] = block[i][j];
		blockIndex = x;
		placeScore = b*10;
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

class Board{

public:

	//print the big chessboard
	void print(){
		for(int i=0;i<13;i++){
				for(int j=0;j<13;j++){
					cout << boardSpace[i][j];
				}
				cout << endl;
			}
	}

	//Update the chessboard from Real Game Board to Show Board
	void update(){
		for(int i=3;i<boardSize+3-2;i++){
			for(int j=3;j<boardSize+3-2;j++){
				boardSpace[i][j] = realboard[i][j];
			}
		}
	}

	//Construtor
	Board(){
		//Create a clean 13*13 board
		for (int i = 0; i < 13; i++){
				for (int j = 0; j < 13; j++){
					boardSpace[i][j] = ' ';
				}
			}

		//Create a clean varSize board(Real Game Board)

		for (int i = 0; i < boardSize; i++){
			for (int j = 0; j < boardSize; j++){
				realboard[i][j] = ' ';
			}
		}

		//generate size sensitive top
		for(int i=2;i<boardSize+3-1;i++){
			boardSpace[0][i] = 48+i-2;
		}

		//generate size sensitive side
		for(int i=2;i<boardSize+3-1;i++){
			boardSpace[i][0] = 65+i-2;
		}

		//Generate the outline of the board
		for(int i=0;i<boardSize+3;i++){
			for(int j=0;j<boardSize+3;j++){
				if((i==1||i==boardSize+3-1) && j>=1)
					boardSpace[i][j] = '@';
				if(i!=0){
					if(j==1 || j== boardSize+3-1)
						boardSpace[i][j] = '-';
				}
			}

		}

	}

private:
	char boardSpace[13][13];
	char realboard[10][10];
};


int main()
{
	char choice;
	char mainmenuExit[40] = "Do you really wish to exit?";
	/*
	 * Plz copy zero's work to here
	 * Please name h for horizontal block
	 * v for vectical block e.t.c
	 */
	char h1[4][4] = {blockChar};
	char h2[4][4] = {blockChar,blockChar};
	char h3[4][4] = {blockChar,blockChar,blockChar};
	char h4[4][4] = {blockChar, blockChar, blockChar, blockChar};
	char h5[4][4] = {blockChar, blockChar, blockChar, blockChar, blockChar};
	char v2[4][4] = {{blockChar}, {blockChar}};
	char v3[4][4] = {{blockChar}, {blockChar}, {blockChar}};
	char v4[4][4] = {{blockChar}, {blockChar}, {blockChar}, {blockChar}};
	char v5[5][4] = {{blockChar}, {blockChar}, {blockChar}, {blockChar}, {blockChar}};
	char L11[4][4] = {{blockChar}, {blockChar, blockChar}};
	char L12[4][4] = {{' ', blockChar}, {blockChar, blockChar}};
	char L13[4][4] = {{blockChar, blockChar}, {blockChar}};
	char L14[4][4] = {{blockChar, blockChar}, {' ', blockChar}};
	char L21[4][4] = {{blockChar}, {blockChar}, {blockChar, blockChar, blockChar}};
	char L22[4][4] = {{' ', ' ', blockChar}, {' ', ' ', blockChar}, {blockChar, blockChar, blockChar}};
	char L23[4][4] = {{blockChar, blockChar, blockChar}, {blockChar}, {blockChar}};
	char L24[4][4] = {{blockChar, blockChar, blockChar}, {' ', ' ', blockChar}, {' ', ' ', blockChar}};
	char s1[4][4] = {{blockChar, blockChar}, {blockChar, blockChar}};
	char s2[4][4] = {{blockChar, blockChar, blockChar}, {blockChar, blockChar, blockChar}, {blockChar, blockChar, blockChar}};

	//The main loop of the game, only break out when user want to exit
	while(1){
		cout << endl;
		cout << "Blockblazer - Clear The Blocks!\n" << endl;
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
		case '1': startGame() ; break;
		case '2': system("cls");settingsMenu(); break;
		case '3': /*P3 here*/ ; break;
		case '4': credit() ; break;
		case '5': if(exit(mainmenuExit) == true)
					return 0;
				else continue;
		default:
			cout << "Please enter choice 1 - 5 only." << endl;
			system("pause");
			break;
		}
		//Clear Screen
		system("cls");
	};
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
	//clear the screen first
	system("cls");
	cout << "Leung Ho HIN  16187002A 103A" << endl;
	cout << "Leung Ka MING 16091968A 103A" << endl;
	cout << "MAK HOI KIT   16027276A 103C" << endl;
	cout << "SARKI JOSHAN  1698910AA 103B" << endl;
	
	system("pause");

}

//Change the char of the blocks
void blockCharC(){
	int loopCheck = 0;
	char charChoice;
	
	while(loopCheck == 0){
		cout << "*** Block Character Selection ***" << endl;
		cout << "[1] X" << endl;
		cout << "[2] O" << endl;
		cout << "[3] @" << endl;
		cout << "[4] #" << endl;
		cout << "*****************" << endl;
		cout << "Option (1-4): ";
		cin >> charChoice;
		
		loopCheck = 1;
		switch(charChoice){
			case '1': blockChar = 'X'; break;
			case '2': blockChar = 'O'; break;
			case '3': blockChar = '@'; break;
			case '4': blockChar = '#'; break;
			default: cout << "Please enter choice 1 - 4 only." << endl;
				loopCheck = 0;
		}
		
		if (loopCheck != 0) cout << "Block Character has been changed.";
		
		system("pause");
		system("cls");
	}
}

//Start the Game <-- Will be modified later <--Cosmetics chessboard
void startGame(){
	
	system("cls");

	Board board;
	board.print();

	
	system("pause");
}

void PCdemo(){
	bool Changed = false;
	while (!Changed){
		system("cls");
		cout << "Current: ";
		if (PC_Play){
			cout << "Demo Game By PC" << endl;
		}else{
			cout << "Game By Player" << endl;
		}
		cout << "**************" << endl;
		cout << "Input '1' to change to demo game by pc" << endl;
		cout << "Input '2' to change to game by player" << endl;
		cout << "Input '3' to go back to Setting Menu. " << endl;
		cout << "**************" << endl;
		cout << "Choice: ";
		int option;
		if(!(cin >> option)){
			option = 0;
			cin.clear();
			cin.ignore();
		}
		switch (option){
			case 1:
				PC_Play = true;
				Changed = true;
				break;
			case 2:
				PC_Play = false;
				Changed = true;
				break;
			case 3:
				Changed = true;
				break;
			default:
				cout << "Please enter '1' or '2' or '3'" << endl;
				system("pause");
				break;
		}
	}	
}

	
}


//Load Settings configuration
void settingsMenu(){
	bool setExit = 0;
	int choice;
	char settingsMenuExit[40] = "Do you wish to return to main menu?";
	
	while(setExit == 0){
		cout << "\n*** Settings Menu ***" << endl;
		cout << "[1] PC Game Demo" << endl;
		cout << "[2] Timer Bomb Mode" << endl;
		cout << "[3] Change Board Size" << endl;
		cout << "[4] Change Bomb Timer" << endl;
		cout << "[5] Change Block Character" << endl;
		cout << "[6] Return to Game Menu" << endl;
		cout << "*****************" << endl;
		cout << "Option (1-6): ";
		cin >> choice;

		switch (choice){
		case 1: /*PC Demo toggle*/ ; continue;
		case 2: /*Timer Bomb toggle*/ ; continue;
		case 3: /*Board Size option*/ ; continue;
		case 4: /*Bomb Timer option*/ ; continue;
		case 5: blockCharC(); continue;
		case 6: if(exit(settingsMenuExit) == true) setExit = 1;
			continue;
		default:
			cout << "Please enter choice 1 - 6 only." << endl;
			break;

		}
		//Clear Screen
		system("cls");
	};
}
