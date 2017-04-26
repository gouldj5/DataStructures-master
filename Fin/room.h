#pragma once

class room {
	public :
		room(int doors, Enemy en, Item it);
		void enterRoom(int &doors, Enemy &en, Item &it);
	private:
		int NumDoors;
		Enemy RoomEnemy;
		Item RoomItem;
};