#pragma once
#include "enemy.h"
#include "item.h"

class room {
	public :
		room(int doors, enemy en, Item it);
		void enterRoom(int &doors, enemy &en, Item &it);
	private:
		int NumDoors;
		enemy RoomEnemy;
		Item RoomItem;
	
};
