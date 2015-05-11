#include "stdafx.h"
#include "AbstractRole.h"

namespace Mighty
{
	void AbstractRole::SetCard(std::shared_ptr<Card> card)
	{
		this->card = card;
	}

	CardRole AbstractRole::GetRoleType() const
	{
		return roleType;
	}

	void AbstractRole::SetRole(CardRole roleType)
	{
		this->roleType = roleType;
	}
}