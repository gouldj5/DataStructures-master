#include "stdafx.h"
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <string>
#include "bag3.h"       // probably going to use sorted lists from the bag
#include "node1.h"
using namespace std;
using namespace link;

int main()
{
	node* head = NULL;
	bag remover;
	int room; //room number
	string y;
	int i;
	
	char name[50];
	cout << "What is your name?" << endl;
	cin.getline(name, 50);
	cout << "You better move fast, " << name << ". The dungeon awaits." << endl;
	cout << "\n----------------------Press any key to continue----------------------" << endl;
	cout << "Did you ever hear the tragedy of Darth Plagueis the Wise?\n" << endl;
		cin >> y;
		if (y == "no" | y == "No") {
			cout << "I thought not. It's not a story the Jedi would tell you.\nIt's a Sith legend.Darth Plagueis was a Dark Lord of the Sith, \n so powerful and so wise he could use the Force to influence the midichlorians to create life... \nHe had such a knowledge of the dark side that he could even keep the ones he cared about from dying.\n\n The dark side of the Force is a pathway to many abilities some consider to be unnatural.\n He became so powerful... the only thing he was afraid of was losing his power, which eventually, of course, he did.\n Unfortunately, he taught his apprentice everything he knew, then his apprentice killed him in his sleep.\n\nIronic, \nhe could save others from death,...\nbut not himself.\n\n\n" << endl;
		}
		else {
			cout << "It's not a story the Jedi would tell you.\nAs you know, he was a Sith legend and a Dark Lord of the Sith, \nso powerful and so wise he could use the Force to influence the midichlorians to create life... \nHe had such a knowledge of the dark side that he could even keep the ones he cared about from dying.\n\n The dark side of the Force is a pathway to many abilities some consider to be unnatural.\n He became so powerful... the only thing he was afraid of was losing his power, which eventually, of course, he did.\n Unfortunately, he taught his apprentice everything he knew, then his apprentice killed him in his sleep.\n\nIronic, \nhe could save others from death,...\nbut not himself.\n\n\n" << endl; 
		}
	if (room = 1)
	
	for (i = 1; i <= 20; i++) {
			/* pick random number from 1 to 6 and output it */
			printf("%d ", 1 + (rand() % 6));
			/* if counter is divisible by 5, begin new line of output */
			if (i % 5 == 0) {
				printf("\n");
			} /* end if */
		} /* end for */

		
		
	
	
	
	system("pause");
	return EXIT_SUCCESS;
}
