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
	char name[50];
	cout << "What is your name?" << endl;
	cin.getline(name, 50);
	cout << "You better move fast, " << name << ". The dungeon awaits." << endl;
	cout << "\n----------------------Press any key to continue----------------------" << endl;
	return 0;
}
