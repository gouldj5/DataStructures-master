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
	using Rooms = std::array<Room, m_numberOfRooms>;
	room m_rooms;
	Player m_player;
	AttackEnemyOption m_attack;
	MoveOption m_moveNorthOption; //Change these later if we wish
	MoveOption m_moveEastOption;
	MoveOption m_moveSouthOption;
	MoveOption m_moveWestOption;
	PickupItem m_openSwordChest;
	QuitOption m_quitOption;
	Item m_swordChest;
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