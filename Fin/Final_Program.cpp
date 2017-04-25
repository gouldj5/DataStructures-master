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
	int step;
	string dest;
	string del;
	string y;
	int max;
	string crash;
	char name[50];
	cout << "What is your name?" << endl;
	cin.getline(name, 50);
	cout << "You better move fast, " << name << ". The dungeon awaits." << endl;
	cout << "\n----------------------Press any key to continue----------------------" << endl;
	cout << "Did you ever hear the tragedy of Darth Plagueis the Wise?\nI thought not. It's not a story the Jedi would tell you.\nIt's a Sith legend. Darth Plagueis was a Dark Lord of the Sith,\n so powerful and so wise he could use the Force to influence the midichlorians to create life... \nHe had such a knowledge of the dark side that he could even keep the ones he cared about from dying.\n\n The dark side of the Force is a pathway to many abilities some consider to be unnatural.\n He became so powerful... the only thing he was afraid of was losing his power, which eventually, of course, he did.\n Unfortunately, he taught his apprentice everything he knew, then his apprentice killed him in his sleep.\n\nIronic,\n he could save others from death,...\nbut not himself.\n\n\n";
	system("pause");
	return EXIT_SUCCESS;
}
