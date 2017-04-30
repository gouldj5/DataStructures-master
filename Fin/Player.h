#pragma once
#include <vector>
class Player
{
private:
	bool pLife{ true };
public:
	int phealth = 20;
	bool eAlive() const {
		return pLife;
	}
	void playerDeath() {
		pLife = false;
	}
};