#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <ctime>
using namespace std;

bool tBombOn = 0, pcDemoOn = 0, PC_Play = 0;
char blockChar = 'X';
int boardSize = 10, tBombCount = 9;

char h1[5][5] = {blockChar};
char h2[5][5] = {blockChar,blockChar};
char h3[5][5] = {blockChar,blockChar,blockChar};
char h4[5][5] = {blockChar, blockChar, blockChar, blockChar};
char h5[5][5] = {blockChar, blockChar, blockChar, blockChar, blockChar};
char v2[5][5] = {{blockChar}, {blockChar}};
char v3[5][5] = {{blockChar}, {blockChar}, {blockChar}};
char v4[5][5] = {{blockChar}, {blockChar}, {blockChar}, {blockChar}};
char v5[5][5] = {{blockChar}, {blockChar}, {blockChar}, {blockChar}, {blockChar}};
char L11[5][5] = {{blockChar}, {blockChar, blockChar}};
char L12[5][5] = {{' ', blockChar}, {blockChar, blockChar}};
char L13[5][5] = {{blockChar, blockChar}, {blockChar}};
char L14[5][5] = {{blockChar, blockChar}, {' ', blockChar}};
char L21[5][5] = {{blockChar}, {blockChar}, {blockChar, blockChar, blockChar}};
char L22[5][5] = {{' ', ' ', blockChar}, {' ', ' ', blockChar}, {blockChar, blockChar, blockChar}};
char L23[5][5] = {{blockChar, blockChar, blockChar}, {blockChar}, {blockChar}};
char L24[5][5] = {{blockChar, blockChar, blockChar}, {' ', ' ', blockChar}, {' ', ' ', blockChar}};
char s1[5][5] = {{blockChar, blockChar}, {blockChar, blockChar}};
char s2[5][5] = {{blockChar, blockChar, blockChar}, {blockChar, blockChar, blockChar}, {blockChar, blockChar, blockChar}};

class Block
{
public:
	//Default construtor
	Block(){

	}

	//Construtor to create block for player to pick(block type, index, blockCount)
	Block(char block[5][5],int x,int b,int num,int width,int height){
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				blockS[i][j] = block[i][j];
		blockIndex = x;
		placeScore = b*10;
		blocknum = num;
		Bwidth = width;
		Bheight = height;
	}

	void print(){

		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				cout << blockS[i][j];
			}
			if(i==0){
				cout << "---" << blocknum;
			}
			cout << endl;
		}

	}

	//check if a block unit at (i, j) exists
	//Return 1 if that block is blockChar, else return 0 <-- Do this first, change when to time bomb mode
	bool blockExist(int i, int j){
		return (blockS[i][j] == blockChar) ? 1 : 0;
	}

	//records the position of the leftmost block
	void blockLeftPos(int * h){
		for (int n; n < 5; n++){
			if (blockExist(0, n) == 1){
				*h = n;
				cout << "left" << *h << endl; //debug
				break;
			}
		}
	}

	int getplaceScore(){
		return placeScore;
	}

	int getblockIndex(){
		return blockIndex;
	}

	int getblockW(){
		return Bwidth;
	}

	int getblockH(){
		return Bheight;
	}

private:
	char blockS[5][5];
	int placeScore, blockIndex,blocknum,Bwidth,Bheight;
};

class Board{

public:

	//clear lines and register score addition by lineClear(playerScore)
	    void lineClear(int * score){
	        int lineTotal = 0;
	        int colCheck[boardSize] = {}, rowCheck[boardSize] = {};

	        //First loop
	        for(int i=0;i<boardSize;i++){

	        	//check if rol full
	        	for(int j=0;j<boardSize;j++){

	        		//immediately breaks if there are empty spaces in row
	        		if(realboard[i][j] != blockChar)
	        			break;

	        		if(j == boardSize-1){
	        			rowCheck[i] = 1;
	        			lineTotal++;
	        		}

	        	}

	        	for(int k=0;k<boardSize;k++){

	        		//immediately breaks if there are empty spaces in col
	        		if(realboard[k][i] != blockChar)
	        			break;

	        		if(k == boardSize-1){
	        			colCheck[i] = 1;
	        			lineTotal++;
	        		}

	        	}

	        }

	        //clear out full columns/rows
	        for (int q = 0; q < boardSize; q++){

	        	cout << rowCheck[q] << " " << colCheck[q] << endl;

	        	if (rowCheck[q] == 1){
	        	    for (int i = 0; i < boardSize; i++){
	        	        realboard[q][i] = ' ';
	        	    }
	        	}
	        	if (colCheck[q] == 1){
	        	    for (int i = 0; i < boardSize; i++){
	        	         realboard[i][q] = ' ';
	        	    }
	        	}
	        }

	        //add score from line clears
	        for (int s = 1; s <= lineTotal; s++){
	        	            *score += s*100;
	        	        }

	    }

	//Problematic
	bool gameOver(Block x){
		for (int i = 0; i < boardSize-1; i++){
			for (int j = 0; j < boardSize-1; j++){
				if (blockLocCheck(x, i, j) == 1){
					return 0;
				}
			}
		}
		return 1;
	}

	//Function to put block on board (col in A-F row in 0-9)
	void putBlock(Block x, int col,int row){
		int blockL = 0;
		x.blockLeftPos(&blockL);
		row -= blockL;
		//cout << "block left " << row << endl; //debug
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				if (x.blockExist(i, j) == 1){
					//cout << (char)(i+col+65) << j+row << endl;
					realboard[i+col][j+row] = blockChar;
				}else continue;
			}
		}
	}

	//Problematic
	bool blockLocCheck(Block x, int col, int row){
		int blockH = 0, blockW = 0, blockL = 0;
		blockH = x.getblockH();
		blockW = x.getblockW();
		x.blockLeftPos(&blockL);
		//cout << blockL << endl;
		row -= blockL;
		for (int i = 0; i < blockH; i++){
			for (int j = 0; j < blockW; j++){
				//cout << (char)(i+col+65) << j+row << "  " << x.blockExist(i,j) << "  " << realboard[i+col][j+row] << endl; //Just don't delete it for now
				//conditions: will a block be placed? is the space already occupied? is the block beyond the board?
				if (x.blockExist(i, j) == 1 && (realboard[i+col][j+row] == blockChar || i+col > boardSize-1 || j+row > boardSize-1 || i+col < 0 || j+row < 0)){
				return 0;
				}
				else continue;
			}
		}
		return 1;
	}


	void update(){
		for(int i=2;i<boardSize+3-1;i++){
			for(int j=2;j<boardSize+3-1;j++){
				boardSpace[i][j] = realboard[i-2][j-2];
			}
		}
	}

	void print(){
		for(int i=0;i<13;i++){
			for(int j=0;j<13;j++){
				cout << boardSpace[i][j];
			}
			cout << endl;
		}
	}

	void printR(){
		for(int i=0;i<10;i++){
					for(int j=0;j<10;j++){
						cout << realboard[i][j];
					}
					cout << endl;
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

//Declare function
bool exit(char[]);
void credit();
void blockCharC();
void startGame();
void settingsMenu();
void instruction();
Block genBlock(int);
bool locationD(char[]);
bool boardsizeChange();
void sizechange();

int main()
{
	srand(time(0)); //Init the RNG
	char choice;
	char mainmenuExit[40] = "Do you really wish to exit?";
	/*
	 * Plz copy zero's work to here
	 * Please name h for horizontal block
	 * v for vectical block e.t.c
	 */

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
		case '3': instruction(); break;
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
	cout << "~~~~~~~~~Credit Page~~~~~~~~~~" << endl;
	cout << "Leung Ho HIN   16187002A 103A" << endl;
	cout << "Leung Ka MING  16091968A 103A" << endl;
	cout << "MAK HOI KIT    16027276A 103C" << endl;
	cout << "SARKI JOSHAN   1698910AA 103B" << endl;
	cout << "Wong Yuen Ting 16120342A 103A" << endl;
	cout << "Lui Siu Man    16182713A 103A" << endl;

	cout << "  _______ _                 _           __                   _             _             " << endl;
	cout << " |__   __| |               | |         / _|                 | |           (_)            " << endl;
	cout << "    | |  | |__   __ _ _ __ | | _____  | |_ ___  _ __   _ __ | | __ _ _   _ _ _ __   __ _ " << endl;
	cout << "    | |  | '_ \\ / _` | '_ \\| |/ / __| |  _/ _ \\| '__| | '_ \\| |/ _` | | | | | '_ \\ / _` |" << endl;
	cout << "    | |  | | | | (_| | | | |   <\\__ \\ | || (_) | |    | |_) | | (_| | |_| | | | | | (_| |" << endl;
	cout << "    |_|  |_| |_|\\__,_|_| |_|_|\\_\\___/ |_| \\___/|_|    | .__/|_|\\__,_|\\__, |_|_| |_|\\__, |" << endl;
	cout << "                                                      | |             __/ |         __/ |" << endl;
	cout << "                                                      |_|            |___/         |___/ " << endl;

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

	int playerScore = 0;
	int blockchoice;
	Block thisBlock;
	char location[3];
	bool ischoice,isdecodable, isValid, isfinishBlock = false;
	bool e;

	srand(time(0));
	system("cls");

	//Generate blocks and board
	Block a = genBlock(0);
	Block b = genBlock(1);
	Block c = genBlock(2);
	Board board;

	while(1){

		//Print score board and blocks

		board.print();
		cout << "---------------" << endl;
		a.print();
		cout << "---------------" << endl;
		b.print();
		cout << "---------------" << endl;
		c.print();
		cout << "---------------" << endl;
		cout << "Your score are " << playerScore << endl;
		cout << "---------------" << endl;
		board.printR();
		cout << "---------------" << endl;

		if (board.gameOver(a) == 1 && board.gameOver(b) == 1 && board.gameOver(c) == 1){
					cout << "Game Over" << endl;
					cout << "Final Score: " << playerScore << endl;
					break;
				}

		isfinishBlock = false;
				while(isfinishBlock == false){
				//Ask user for block choice
					cout << "Which block you want to place? (0,1,2)" << endl;

					ischoice = false;
					while(ischoice == false){
						cin >> blockchoice;
						switch(blockchoice){
						//Also create a new block for player to choose
						case 0: thisBlock = a;ischoice = true;a = genBlock(0);break;
						case 1:	thisBlock = b;ischoice = true;b = genBlock(1);break;
						case 2:	thisBlock = c;ischoice = true;c = genBlock(2);break;
						default:cout << "Please enter a number from 0-2" << endl;break;
						}
					}

					isdecodable = false;
					isValid = 0;
					while(isdecodable == false || isValid == 0){
						cout << "Which location you want to place the block? For example:A0" << endl;
						cout << "You are also deselect block by input NN" << endl;
						cin >> location;
						e = locationD(location);
						if(location[0] == 'N' && location[1] == 'N'){
							switch(blockchoice){
							case 0:a = thisBlock;break;
							case 1:b = thisBlock;break;
							case 2:c = thisBlock;break;
							}
							ischoice = false;
							location[0] = ' ';
							location[1] = ' ';
							break;

						}else if(e==true){
							cout << "Please input a valid command! For example: A0" << endl;
						}
						else if (board.blockLocCheck(thisBlock,location[0]-'0',location[1]-'0') == 0){
							cout << "The block cannot fit into the location! Try again." << endl;
						}
						else{
							isdecodable = true;
							isValid = 1;
							isfinishBlock = true;
						}
					}
				}


		//Time to place block
		board.putBlock(thisBlock,location[0]-'0',location[1]-'0');
		board.lineClear(&playerScore);
		playerScore += thisBlock.getplaceScore();
		board.update();
		//debug use
		system("pause");
		system("cls");
	}

	system("pause");
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
		case 3: boardsizeChange() ; continue;
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

int Changethetimer() {
	int newV;
	cout << "What is the value of the bomb you want to change? (6-9)";
	cin >> newV;
	switch (newV) {
	case 6: return 6;
	case 7: return 7;
	case 8: return 8;
	case 9: return 9;
	default: cout << "Only type in 6-9";
		cin >> newV;
	}
}
//Gmae instruction
void instruction(){
	system("cls");
	cout << "\n";
	cout << "INSTRUCTIONS \n\n";
	cout << "There are three ramdomly-generated block.(select index 0 to 2).You are about to choose to place.  Format should be:\n";
	cout << "Forming with a row letter and a column number togther.\n";
	cout << "Example: A0     It indicates where the \"X\" in the upper left corner of the block is placed. \n\n";
	cout << " For the \"reserved LShape \"block, where the leftmost\" X \"of the input position indicator block is placed.\n\n";
	cout << "Note that the block should be placed inside the board and should not overlap with other blocks and should not overlap with bombs under game mode (2).\n\n";
	system("pause");
}

//Generate block for creating the list for user to choose
Block genBlock(int x){

	int choice = 1 + (rand() % 19);

	switch(choice){
	case 1: return Block(h1,choice,1,x,1,1);
	case 2: return Block(h2,choice,2,x,2,1);
	case 3: return Block(h3,choice,3,x,3,1);
	case 4: return Block(h4,choice,4,x,4,1);
	case 5: return Block(h5,choice,5,x,5,1);
	case 6: return Block(v2,choice,2,x,1,2);
	case 7: return Block(v3,choice,3,x,1,3);
	case 8: return Block(v4,choice,4,x,1,4);
	case 9: return Block(v5,choice,5,x,1,5);
	case 10: return Block(L11,choice,3,x,2,2);
	case 11: return Block(L12,choice,3,x,2,2);
	case 12: return Block(L13,choice,3,x,2,2);
	case 13: return Block(L14,choice,3,x,2,2);
	case 14: return Block(L21,choice,5,x,3,3);
	case 15: return Block(L22,choice,5,x,3,3);
	case 16: return Block(L23,choice,5,x,3,3);
	case 17: return Block(L24,choice,5,x,3,3);
	case 18: return Block(s1,choice,4,x,2,2);
	case 19: return Block(s2,choice,9,x,3,3);
	}

}

//This is the block placement location decoder, which turn A2 to two int like (1,3) and use by putBlock(....)
bool locationD(char *input){

	char first = input[0];
	char second = input[1];

	switch(first){
	case 'A': input[0] = '0';break;
	case 'B': input[0] = '1';break;
	case 'C': input[0] = '2';break;
	case 'D': input[0] = '3';break;
	case 'E': input[0] = '4';break;
	case 'F': input[0] = '5';break;
	case 'G': input[0] = '6';break;
	case 'H': input[0] = '7';break;
	case 'I': input[0] = '8';break;
	case 'J': input[0] = '9';break;
	default: return true;
	}

	switch(second){
	case '0':break;
	case '1':break;
	case '2':break;
	case '3':break;
	case '4':break;
	case '5':break;
	case '6':break;
	case '7':break;
	case '8':break;
	case '9':break;
	default: return true;
		}

	return false;
}

bool boardsizeChange() {

	int choice;

	cout << "What Size do you want to change to?" << endl;
	cout << "1: 5x5          2: 7x7          3: 10x10";
	cin >> choice;
	switch (choice) {
	case 1: return true; cout << "The board size has been changed sucessfully!" << endl; break;
	case 2: return true; cout << "The board size has been changed sucessfully!" << endl; break;
	case 3: return false; break;
	default: cout << "Only type in 1 to 3! Input again: "; cin >> choice;
	}
}
