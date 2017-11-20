#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>;
using namespace std;

bool exit();

void credit();

int main()
{
	int choice;

	start:
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
		case 5: if(exit() == true)
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

//This is the function for calling exit (R5)---Can be also used to RETURN the main menu
bool exit(){
	char isexit;
	cout << "You really want to exit : |???" << endl;
	cin >> isexit;
	if(isexit == 'y'|| isexit == 'Y')
		return true;
	else{
		system("cls");
		return false;
	}

}

void credit(){

}
