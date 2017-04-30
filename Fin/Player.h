#pragma once
#include <vector>
class Player
{
private:
	using Items = std::vector<Item*>;
	Items m_items;
	void AddItem(const Item* item) //AddItem is AddHealth
	{
		m_items.push_back(const_cast<Item*>(item));
	}
};