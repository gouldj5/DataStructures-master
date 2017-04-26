#pragma once
#include "stdafx.h"
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <string>
#include <ctime>
#include <algorithm>

class enemy {

private:

	bool eLife{ true };

public:

	int ehealth = 1 + rand() % (6 - 1 + 1);
	bool eAlive() const {
		return eLife;
	}
	void Kill() {
		eLife = false;
	}

};