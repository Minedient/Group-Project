#include <iostream>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <cstring>

using namespace std;
int  platform[10][10]; // 10*10 platform
int  block[19][5][5] = {  // [type][row][column]
			{
				 {1,0,0,0,0},//0
				 {0,0,0,0,0},
				 {0,0,0,0,0},
				 {0,0,0,0,0},
				 {0,0,0,0,0}
			},
			{ 
				{ 1,0,0,0,0 },//1
				{ 1,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 1,1,0,0,0 },//2
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},		
			{
				{ 1,0,0,0,0 },//3
				{ 1,0,0,0,0 },
				{ 1,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 1,1,1,0,0 },//4
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 1,1,0,0,0 },//5
				{ 1,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 1,1,0,0,0 },//6
				{ 0,1,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 0,1,0,0,0 },//7
				{ 1,1,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 1,0,0,0,0 },//8
				{ 1,1,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 1,1,1,1,0 },//9
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 1,0,0,0,0 },//10
				{ 1,0,0,0,0 },
				{ 1,0,0,0,0 },
				{ 1,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 1,1,0,0,0 },//11
				{ 1,1,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 1,0,0,0,0 },//12
				{ 1,0,0,0,0 },
				{ 1,0,0,0,0 },
				{ 1,0,0,0,0 },
				{ 1,0,0,0,0 }
			},
			{
				{ 1,1,1,1,1 },//13
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 1,1,1,0,0 },//14
				{ 1,0,0,0,0 },
				{ 1,0,0,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 0,0,1,0,0 },//15
				{ 0,0,1,0,0 },
				{ 1,1,1,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 1,1,1,0,0 },//16
				{ 0,0,1,0,0 },
				{ 0,0,1,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 1,0,0,0,0 },//17
				{ 1,0,0,0,0 },
				{ 1,1,1,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			},
			{
				{ 1,1,1,0,0 },//18
				{ 1,1,1,0,0 },
				{ 1,1,1,0,0 },
				{ 0,0,0,0,0 },
				{ 0,0,0,0,0 }
			}
			};
char DisplayBlock[5][5];  
int integer_coor[2]; //the input coordinate e.g. : [0 ,1]


void Display_platform(int S_Score, int & S_counter, int &L_Score){	//show the platform with all 0 | S_score = Selected_Score ;  S_counter = counter;  L_Score = line_score
	S_counter += S_Score + L_Score;		// add the total score
	cout<< "                             Score: " << S_counter << endl; 
	cout << "    0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "  +---------------------+" << endl;
	for (char i = 'A' ; i <='J'; i++) //from A to J
	{
		cout << i << " | ";
		for (int j = 0; j < 10; j++) 
		{
			cout << ((platform[i-'A'][j]!=0) ? "* ":"  ");  // transfer the [i] to integer| if [i][j] != 0 cout "* " , [i][j]==0 cout "  ";

		}
		cout << "|"<< endl;

	}
	cout << "  +---------------------+" << endl;
	
}
void memCopy(char SaveBlock[5][5], int & index){ // save the displayblok according the type| SaveBlock[5][5] = DisplayBlock[5][5]; index =  BlockNumber
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			
			SaveBlock[i][j] = block[index][i][j];
			};
		};
				
}
void GenerateBlock(int &BlockScore, int & Number){ // BlockScore, BlockNumber
	int BlockList = 1 + rand() % 19; // get the type number
	
	switch (BlockList)
	{
	case 1: BlockScore = 10;		// save the score
			break;
	case 2: BlockScore = 20;
			break;
	case 3: BlockScore = 20;
			break;
	case 4: BlockScore = 30;
			break;
	case 5: BlockScore = 30;
			break;
	case 6: BlockScore = 30;
			break;
	case 7: BlockScore = 30;
			break;
	case 8: BlockScore = 30;
			break;
	case 9: BlockScore = 30;
			break;
	case 10: BlockScore = 40;
			break;
	case 11: BlockScore = 40;
			break;
	case 12: BlockScore = 40;
			break;
	case 13: BlockScore = 50;
			break;
	case 14: BlockScore = 50;
			break;
	case 15: BlockScore = 50;
			break;
	case 16: BlockScore = 50;
			break;
	case 17: BlockScore = 50;
			break;
	case 18: BlockScore = 50;
			break;
	case 19: BlockScore = 90;
			break;
	}
	Number = BlockList - 1;			//the type  = the random number - 1  (as array start from 0)
	memCopy(DisplayBlock,Number);	// save it to the Displayblock

}
void BlockImage(int a, int b, int c){		// display the blocks| a = BlockNumber1, b = BlockNumber2, c =BlockNumber3
	cout<< "No.1:     No.2:     No.3:\n";
	cout<< setw(6);
		for (int k = 0; k < 5; k++){
			for (int h = 0; h < 5; h++){
				if (block[a][k][h] == 0)
					cout<< " ";
				else 
					cout<< "*";
					}
					cout << setw(6);
				

			for (int h = 0; h < 5; h++){
				if (block[b][k][h] == 0)
					cout<< " ";
				else 
					cout<< "*";
					}
					cout<< setw(6);
				
			for (int h = 0; h < 5; h++){
				if (block[c][k][h] == 0)
					cout<< " ";
				else 
					cout<< "*";
					}
				cout<< endl << setw(6);	
			}	
}
void Input_Choice_And_Checking(int &a, int &b){ // a = selected (the block type selected), b = choice| enter the block you would choose and check input type
bool valid = false; 	// the input type = false
string Selected;		//your input
	while (!valid)
	{
		valid = true; 

		cout << "Enter your choice( 1 - 3 ):  ";
		cin >> Selected;

		if( cin.fail())  //if data type = wrong
		{
			cin.clear(); 
			cin.ignore(); 
			cout << "Please enter integer only." ;
			valid = false; 
		}

	}
    while (Selected < "1"  || Selected > "3" ) //if the input is not in 1-3
	{
    	cout << "Incorrect choice! Please enter choice( 1 - 3 ) only :" ;
   		cin >> Selected;
	}
	if (Selected == "1")// change the string to intger
	{
		a = 1;
		b = 1;
	}
	else if (Selected == "2")
	{
		a = 2;
		b = 2;
	}
	else if (Selected == "3")
	{
		a = 3;
		b = 3;
	}
		 
}		 
void Save_Selection(int &Choice , int &Choice_Score, int B1, int B2, int B3, int BS1, int BS2, int BS3){ //  save the block type 's informantion to the choice
		switch (Choice)	//Choice = selected, Choice_Score = Selected_Score, B1 =BlockNumber1, B2 =BlockNumber2, B3 =BlockNumber3, BS1 = BlockScore1, BS2 = BlockScore2, BS3 = BlockScore3
		{
			case 1: Choice = B1;
					Choice_Score= BS1;
					break;
			case 2: Choice = B2;
					Choice_Score= BS2;
					break;
			case 3: Choice = B3;
					Choice_Score= BS3;
					break;
		}
}
void Block_Eliminate(int & l_score){ // Eliminate  the line when full of 1| l_score = linescore
	int line_counter = 0;
	for (int i = 0; i < 10; i++)
	{	
		int counter = 0; //mark the number of 1 appear in one line
		
		if (platform[0][i]==1)	// for  first row
		{
			for (int j = 0 ; j < 10 ; j++) // for other rows
			{
				if (platform[j][i]==1)
				{
					counter += 1 ;
					
				 
				}
	    	}
			if (counter == 10){  // the maximum of 1 is 10
				line_counter +=1; // mark how many line can be eliminated
				for (int j = 0; j < 10; j++)
				{
					platform[j][i] = 0; // eliminate the lines
				}
			}		
		}
		else 
		{
			continue; // go to next line if the row != 1
		}
		}
	for (int i = 0; i < 10; i++) // for column
	{	
		int counter2 = 0; //count the number of 1
		
		if (platform[i][0]==1)
		{
			for (int j = 0 ; j < 10 ; j++)
			{
				if (platform[i][j]==1)
				{
					counter2 += 1 ;
					
				 
				}
	    	}
			if (counter2 == 10){
				line_counter +=1;  // count the line that can be eliminated
				for (int j = 0; j < 10; j++)
				{
					platform[i][j] = 0;
				}
			}		
		}
		else 
		{
			continue;
		} //pass if there are 0
	}
	switch (line_counter)
		{
			case 0: l_score = 0;	//the score of the eliminated lines number
					break;
			case 1: l_score = 100;
					break;
			case 2: l_score = 300;
					break;
			case 3: l_score = 600;
					break;
			case 4: l_score = 1000;
					break;
			case 5: l_score = 1500;
					break;		
}
}

void Input_Coordinate_And_Checking(){ 
	
	bool Valid;
	char coordinate[2];
	cout << "Enter a coordinate to place the block (A0 - J9) :" ;
	cin >> coordinate;	
	do{
	if ((coordinate[0] >='A' && coordinate[0] <= 'J') && (coordinate[1] >= '0' && coordinate[1] <= '9') && (sizeof(coordinate) ==2 )) // make sure if first letter in A-J and second letter in 0-9 and it is only 2 letter
	{
		Valid = true;
		integer_coor[0] =  (int)(coordinate[0]-'A');	// trun the char to int
		integer_coor[1] = (int)(coordinate[1]-'0');	// trun the char to int
	}
	else { 
		Valid = false;
		cout << "Incorrect coordinate! Enter coordinate (A0 - J9) again: " ;	
		cin >> coordinate;
	};
	}while(Valid == false);
}

void CheckInside(int sss, int Sel_Score, int Sel_counter, int &lineScore){ // check will it outside the platform and collise with the other block
	int counter = 0; // counter length for not type 7 && 15 
	bool inside = true;
	bool canput = true;
	int D_x = integer_coor[0]; // the first letter of input coordinate
	int D_y = integer_coor[1]; // the second letter of input coordinate
	int counter_L;				// measure the length
	int counter_A ;				// othe measurment
	
		if (sss == 15 || sss ==7) // for type 7 and 15 (the reflected L shape block)
		{
			if (sss == 15 )
			{
				counter_L = 2; //array start at 0 ,so 0,1,2 = 2
			} 
			else if (sss == 7 )
			{
				counter_L = 1;
			} 
			if ( D_x - counter_L  < 0 ) // check column will it go outside
			{
				inside = false;
			};
			if (D_y + counter_L > 9) // check row will it go outside
			{
				inside = false;
			};	
			
			for (int i = 0; i < counter_L; i++) // check collision
			{	
				if (sss == 7)
				{
					counter_A = 1;	////array start at 0 ,so 0,1 = 1
				}
				else if (sss == 15)
				{
					counter_A = 2;	
				};
				
				for (int j = 0; j <  counter_L; j++)
				{
					if (block[sss][ counter_A - i ][j] == 0)  // dont check the 0 sign
					{
						continue;
					};
					if (platform[ integer_coor[0] - i ][ j + integer_coor[1] ] == block[sss][ counter_A - i ][j]) //check collision
					{
						canput = false;
						break;
					};
		
				}
			counter_A = counter_A - 1 ; // used same as i++ in every loop to control the platform[i][j] be the same as block
			}
			if ((inside) && (canput)) // if no error
			{
				
				for (int i = 0; i < 5 ; i++)
				{
					if (sss == 7)
					{
						counter_A = 1;	// used same as i++ in every loop to control the platform[i][j] be the same as block
					}
					else if (sss == 15)
					{
						counter_A = 2;	// used same as i++ in every loop to control the platform[i][j] be the same as block
					};
					
					for (int j = 0 ; j < 5; j++)
					{
							if (block[sss][ counter_A - i ][j] == 0 )
							{
								continue;
							}
						platform[ integer_coor[0] - i ][ j + integer_coor[1] ] = block[sss][ counter_A - i ][j]; //platform become block
					}
						
				}
		Block_Eliminate(lineScore); //check line
		Display_platform(Sel_Score, Sel_counter,lineScore); //show platform
		
		}
		if ((!inside)||(!canput)) //if error
		{
		cout << "Cannot Put!! ";
		Input_Coordinate_And_Checking(); //input again
		CheckInside(sss, Sel_Score,Sel_counter,lineScore);	
		};
			
		}
		else{ 
		for (int i = 0; i < 5; i++) // for the normal blocks
		{
					if (block[sss][i][0]== 1)
					{
					    counter +=1;
					}
		}
		int counter2 = 0; // other counter to check length of 1 in the block
		for (int i = 0; i < 5; i++)
		{
					if (block[sss][0][i]== 1)
					{
					    counter2 +=1;
					    
					}
		}
		int D_x = integer_coor[0];
		if ( D_x + counter - 1 > 9 ) // check column outside
			{
				inside = false;
			};
		int D_y = integer_coor[1]; // check row outside
			if (D_y + counter2 - 1> 9)
			{
				inside = false;
			};	
		for (int i = 0; i < counter; i++)
		{
			for (int j = 0; j <  counter2; j++)
			{
				if (block[sss][i][j] == 0)
				{
				continue;
				};
				if (platform[i+integer_coor[0]][j+integer_coor[1]] == block[sss][i][j]) //check can put
				{
					canput = false;
					break;
				};
	
			}
		}
		if ((inside) && (canput)){
	
				for (int i = 0; i < 5 ; i++)
				{
					for (int j = 0 ; j < 5; j++)
					{
							if (block[sss][i][j] ==0)
							{
								continue;
							}
						platform[i+integer_coor[0]][j+integer_coor[1]]= block[sss][i][j];
					}
						
		}
		Block_Eliminate(lineScore);
		Display_platform(Sel_Score, Sel_counter,lineScore);
		
		}
		if ((!inside)||(!canput))
		{
		cout << "Cannot Put!! ";
		Input_Coordinate_And_Checking();
		CheckInside(sss, Sel_Score,Sel_counter,lineScore);	
		};
	}
	}
	
void Any_Space(bool & b_ok, int type){ //b_ok = b1ok/b2ok/b3ok, type = the block type| ¥¼¸Õdebug 
	b_ok = false;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 ; j++)
		{
			if (platform[i][j] == 1)// only find 0 in platform
			{
				continue;	
			}
			for (int a = 0 ; a < 5 ; a++ ) 
			{
				for (int b = 0 ; b < 5 ; b++ )
				{
					if (block[b_ok][a][b] == 0) //check is it match the block
					{
						continue;
					}
				
					if (platform[i+a][j+b] != block[type][a][b]) // check whether the next step match the block 
					{
						b_ok = true;
					}
					
					
				
				}
			}
			if (b_ok = true)
			{
				break;
			}
			}
		}
	}

	





int main()
{	
	srand(time(0)); // seed acoording the time
	int BlockScore1, BlockScore2 , BlockScore3 ; //used to store the score of the 3 diaplayed block
	int choice = 0; // your block choice in 1 - 3
	int BlockNumber1, BlockNumber2, BlockNumber3; //used to store the type of the 3 diaplayed block
	int selected , Selected_Score = 0, counter = 0, line_score = 0; // used to store the selected block type, selected block type score, counter for total score, line eliminated score
	bool b1ok,b2ok,b3ok; // is the block 1 block 2 block 3 can put in the platform;
	bool NotEnd = true;	//not gameover
	while (NotEnd = true)
	{	
		Display_platform(Selected_Score, counter, line_score);
		if ((choice == 1)||(choice == 0)){  //if your choice = 1, only generate the choosen block, 0 for the first generate;
		GenerateBlock(BlockScore1, BlockNumber1);
		};
		if ((choice == 2)||(choice == 0)){
	    GenerateBlock(BlockScore2, BlockNumber2);
		};
		if ((choice == 3)||(choice == 0)){
		GenerateBlock(BlockScore3, BlockNumber3);
		};
		BlockImage(BlockNumber1,BlockNumber2,BlockNumber3);
		Input_Choice_And_Checking(selected, choice);
		Save_Selection(selected, Selected_Score, BlockNumber1, BlockNumber2, BlockNumber3, BlockScore1, BlockScore2, BlockScore3);
		Input_Coordinate_And_Checking();
		CheckInside(selected, Selected_Score, counter, line_score);
		Any_Space(b1ok, BlockNumber1);
		Any_Space(b2ok, BlockNumber2);
		Any_Space(b3ok, BlockNumber3);
		if ((b1ok = false) && (b2ok = false) && (b3ok = false))
		{
			NotEnd = false;
			system("cls");
			cout << "GameOver!!!  Your score is :" << counter;
		}
		system("cls");
	}
	return 0 ;
	
	
}
