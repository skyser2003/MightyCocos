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

	void Rule::SetCardTypeForRole(CardRole role, CardType type)
	{
		cardTypePerRole[role] = type;
		cardRolePerType[type] = role;
	}
	
	int Rule::GetPlayerCount() const
	{
		return playerCount;
	}	

	CardType Rule::GetCardTypeForRole(CardRole role) const
	{
		auto it = cardTypePerRole.find(role);
		return it->second;
	}

	CardRole Rule::GetCardRoleForType(CardType type) const
	{
		auto it = cardRolePerType.find(type);
		return it->second;
	}

	bool Rule::ExistsCardRoleForType(CardType type) const
	{
		return cardRolePerType.count(type) != 0;
	}
}