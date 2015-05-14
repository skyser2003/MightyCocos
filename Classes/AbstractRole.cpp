#include "stdafx.h"
#include "AbstractRole.h"

namespace Mighty
{
	AbstractRole::AbstractRole()
	{

	}

	AbstractRole::~AbstractRole()
	{

	}

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