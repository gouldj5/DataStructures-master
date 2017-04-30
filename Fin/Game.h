#pragma once
#include "Player.h"
#include "room.h"
#include "Item.h"
#include "enemy.h"
#include <iostream>

using namespace std;

class Game
{
private:
	static const unsigned int m_numberOfRooms = 4;
	using room = std::array<room, m_numberOfRooms>;
	room m_room;
	Player m_player;
	AttackEnemyOption m_attack;
	MoveOption m_moveNorthOption; //Change these later if we wish
	QuitOption m_quitOption;
	enemy m_monster;
	void InitializeRooms();
	void WelcomePlayer();
	void GivePlayerOptions() const;
	void GetPlayerInput(std::stringstream& playerInput) const;
	PlayerOptions EvaluateInput(std::stringstream& playerInput);
public:
	Game();
	void RunGame();
};
void Game::GivePlayerOptions() const
{
	cout << "What would you like to do? (Enter a corresponding number)" << endl << endl;
	// Print the options for the room
	m_player.GetCurrentRoom()->PrintOptions(); //Get room options like monsters and items
}
Game::EvaluateInput(stringstream& playerInputStream)
{
	PlayerOptions chosenOption = PlayerOptions::None;
	unsigned int playerInputChoice{ 0 };
	playerInputStream >> playerInputChoice;
	try
	{
		Option* option = m_player.GetCurrentRoom()->EvaluateInput(playerInputChoice);
		option->Evaluate(m_player);
		chosenOption = option->GetChosenOption();
	}
	catch (const std::out_of_range&)
	{
		cout << "I do not recognize that option, try again!" << endl << endl;
	}
	return chosenOption;
}
void Game::RunGame()
{
	InitializeRooms();
	WelcomePlayer();
	bool playerWon = false;
	bool playerQuit = false;
	while (playerQuit == false && playerWon == false)
	{
		GivePlayerOptions();
		stringstream playerInputStream;
		GetPlayerInput(playerInputStream);
		PlayerOptions selectedOption = EvaluateInput(playerInputStream);
		playerQuit = selectedOption == PlayerOptions::Quit;
		playerWon = m_clearpass.IsAlive() == false;
	}
	if (playerWon == true)
	{
		cout << "Congratulations, you rid the dungeon of younglings and beat clearpass!" << endl;
		cout << "Type goodbye to end" << endl;
		std::string input;
		cin >> input;
	}
}
//Room FUNCTIONS

void room::AddStaticOption(Option* option)
{
	assert(option != nullptr);
	m_staticOptions[m_staticOptionStartKey++] = option;
}
void room::AddDynamicOption(Option* option)
{
	assert(option != nullptr);
	m_dynamicOptions.push_back(option);
}
void room::PrintOptions() const
{
	for (unsigned int i = 0; i < m_dynamicOptions.size(); ++i)
	{
		const Option* option = m_dynamicOptions[i];
		std::cout << i + 1 << ": " << option->GetOutputText() << std::endl << std::endl;
	}
	for (StaticOptions::const_iterator iter = m_staticOptions.cbegin();
		iter != m_staticOptions.cend();
		++iter)
	{
		const Option* option = iter->second;
		const unsigned int chosenOption = iter->first + m_dynamicOptions.size();
		std::cout << chosenOption << ": "
			<< option->GetOutputText() << endl << endl;
	}
}
