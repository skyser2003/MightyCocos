#include "stdafx.h"
#include "Rule.h"

namespace Mighty
{
	Rule::Rule()
	{
		playerCount = 0;
	}

	void Rule::SetPlayerCount(int count)
	{
		this->playerCount = count;
	}

	int Rule::GetPlayerCount() const
	{
		return playerCount;
	}
}