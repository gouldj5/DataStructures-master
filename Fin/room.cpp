#include "room.h"
#include <iostream>

room(int doors, Enemy en, Item it) {
	RoomEnemy = en;
	RoomItem = it;
	NumDoors = doors;
}

void enterRoom(int &doors, Enemy &en, Item &it) {
	doors = NumDoors;
	en = RoomEnemy;
	it = RoomItem;
}
