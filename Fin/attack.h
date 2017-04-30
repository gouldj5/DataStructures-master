#pragma once
#include "enemy.h"
#include <string>
#include <iostream>
#include "Player.h"
#include <cmath>
using namespace std;

class attack
{
private:
	enemy* m_enemy;
public:
	attack(enemy* enemy, const string& outputText);
	virtual void Evaluate(Player& player);
};
void attack::Evaluate(Player& player)
{
	cout << endl << "You have chosen to " << m_outputText //attack or defend
		<< endl << endl;
	if (m_ouputText = "A") //A for Attack, D for defend... this may change to numbers
	{
		if (enemy* ehealth = 0)
		{
			m_enemy->Kill();
			cout << "You killed...younglings!" << endl << endl;
		}
		else if (enemy* ehealth != 0) {
			ehealth--;
			cout << "Good swing!" << endl << endl;
		}
			
			
	}
	else if (m_output = "D")
	{
		cout << "You've defended yourself!" << endl << std::endl;
	}
}