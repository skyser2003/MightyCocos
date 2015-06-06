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

	void Rule::SetCardType(CardRole role, CardType type)
	{
		cardTypePerRole[role] = type;
	}
	
	int Rule::GetPlayerCount() const
	{
		return playerCount;
	}	

	CardType Rule::GetCardType(CardRole role) const
	{
		auto it = cardTypePerRole.find(role);
		return it->second;
	}
}