#pragma once
#include "enemy.h"
#include "item.h"

class room {
	public :
		room();
		room(int doors, enemy en);
		void enterRoom(int &doors, enemy &en);
	private:
		int NumDoors;
		enemy RoomEnemy;
};
