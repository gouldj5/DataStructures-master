#pragma once
#include <array>
#include <map>
#include <vector>

class Roomy
{
public:
	enum class Directions
	{
		North = 0,
	};
private:
	using JoiningRooms = std::array<Roomy*, static_cast<size_t>(JoiningDirections::Max)>;
	JoiningRooms m_pJoiningRooms;
	using StaticOptions = std::map<unsigned int, Option*>;
	StaticOptions m_staticOptions;
	unsigned int m_staticOptionStartKey{ 1 };
	using DynamicOptions = std::vector<Option*>;
	DynamicOptions m_dynamicOptions;
};
void Roomy::AddStaticOption(Option* option)
{
	assert(option != nullptr); //what is nullptr
	m_staticOptions[m_staticOptionStartKey++] = option;
}
void Roomy::AddDynamicOption(Option* option)
{
	assert(option != nullptr);
	m_dynamicOptions.push_back(option);
}
void Roomy::PrintOptions() const
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
			<< option->GetOutputText() << std::endl << std::endl;
	}
}
Option* Roomy::EvaluateInput(unsigned int playerInput)
{
	Option* option = nullptr;
	const unsigned int numDynamicOptions = m_dynamicOptions.size();
	if (playerInput <= numDynamicOptions)
	{
		unsigned int dynamicIndex = playerInput - 1;
		option = m_dynamicOptions[dynamicIndex];
		m_dynamicOptions.erase(m_dynamicOptions.begin() + dynamicIndex);
	}
	else
	{
		option = m_staticOptions.at(playerInput - numDynamicOptions);
	}
	return option;
}