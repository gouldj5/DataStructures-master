#include "room.h"
#include <iostream>

room::room() {
	RoomEnemy = enemy();
	NumDoors = 0;
}

room::room(int doors, enemy en) {
	RoomEnemy = en;
	NumDoors = doors;
}

void room::enterRoom(int &doors, enemy &en) {
	doors = NumDoors;
	en = RoomEnemy;
}
