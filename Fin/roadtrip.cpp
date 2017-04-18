#include "stdafx.h"
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <string>
#include "bag3.h"       // probably going to use sorted lists from the bag
#include "node1.h"
using namespace std;
using namespace link;

void add_to_sorted_list(node*& head, string s); //I like sorted lists better than normal lists. As all of us should

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

	cout << "Enter destination names, pressing Enter/Return after each.\nEnter 'Done' to finish your list\n"; \
		cin >> dest;
	while (dest != "Done") {
		add_to_sorted_list(head, dest); //send to the bag and the linked list with node
		cin >> dest;
	}
	cout << "\nSize of list: " << list_length(head) << endl;		//DISPLAY LIST
	cout << "\nFull destination list: \n";
	for (int i = 1; i <= list_length(head); ++i) {

		cout << list_locate(head, i)->data() << "    Destination #" << i << endl;
		cout << "\nDistance between last stop = " << i * (i - 1)*11.75 << " miles\n" << endl;
		max = i;

	}
	//_________________________________________________________________________________________________FORCE TO SELECT XTH STOP 

	cout << "\nWould you like to look at any of your destinations? (y/n)\n";

	cin >> y;
	if (y == "n") {
		cout << "O.K. too bad you have to look at one of them for this assignment" << endl;
		cout << "\nWhich destination number would you like to see? (enter digit) \n";
		cin >> step;
	}
	else if (y == "y") {
		cout << "\nWhich destination number would you like to see? (enter digit) \n";
		cin >> step;
	}
	else {
		cout << "Would you please type this correctly you nut." << endl;
		cout << "\nType 'crash' to crash this program. This is your fault\n";
		cin >> crash;
	}

	//_________________________________________________________________________________________________DISPLAY STOP THEY SELECTED

	if (step > list_length(head)) {
		cout << "That's not on the list!" << endl;
		cout << "\nWhich destination number would you like to see? \n";
		cin >> step;
	}
	else if (step <= 0) {
		cout << "That's not on the list!" << endl;
		cout << "\nWhich destination number would you like to see? \n";
		cin >> step;
	}
	else {
		node* temp = list_locate(head, step);
		cout << "\nHere's the name of the stop you selected: \n";
		cout << temp->data() << "\n" << endl;
	}

	cout << "What would you like to do with it? \n" << endl;
	cout << "Enter 'Delete' to remove it or type 'Go' to calculate your total trip." << endl;
	cin >> del;

	//_______________________________________________________________________________________________________________DELETE STATEMENTS

	if (del == "Delete") {

		list_remove(head);

		cout << "Yes, I've got that destination and have removed it.\n" << endl;
		cout << "Displaying your new trip....\n" << endl;

		for (int i = 1; i <= list_length(head); ++i) {
			cout << list_locate(head, i)->data() << "    Destination #" << i << endl; //Display list again

			cout << "\nDistance between last stop = " << i * (i - 1)*11.75 + (i - 1)*11.75 << " miles\n" << endl; //DOES NOT ADJUST I AM SORRY
		}
	
	cout << "\nTotal distance travelled = " << max*(max - 1)*11.75 << endl;

	}
	
//____________________________________________________________________________________________________________________IF THEY DONT WANT TO DELETE
	else {
		cout << "\nOK, Enjoy here's your trip\n" << endl;
		for (int i = 1; i <= list_length(head); ++i) {
			cout << list_locate(head, i)->data() << "    Destination #" << i << endl; //Display list again

			cout << "\nDistance between last stop = " << i * (i - 1)*11.75 << " miles\n" << endl;
		}
		cout << "\nTotal distance travelled = " << max*(max - 1)*11.75 << endl;
	}
//________________________________________________________________________________________________________________//
	
	//POSSIBLE RELIST

	system("pause");
	return EXIT_SUCCESS;
};

void add_to_sorted_list(node*& head, string str)
{
	if (list_length(head) == 0 || str < head->data()) // SEND STRING TO DATA
		list_head_insert(head, str);
	else
	{
		node* temp = head;
		while (temp->link() != NULL) //WHEN NODE ISNT NOTHING
		{
			if (str < temp->link()->data())
			{
				list_insert(temp, str); //return the string
				return;
			}
			temp = temp->link();
		}
		list_insert(temp, str);
	}
}
