#include "stdafx.h"
#include "Card.h"

#include "AbstractRole.h"
#include "CardUtilFunc.h"

namespace Mighty
{
	Card::Card()
	{

	}

	Card::~Card()
	{

	}

	void Card::Init(std::shared_ptr<AbstractPlayer> player, CardType type)
	{
		this->player = player;
		this->type = type;
		role.reset();
	}

	bool Card::WinAgainst(std::shared_ptr<Card> otherCard)
	{
		return true;
	}

	CardSuit Card::GetSuit() const
	{
		return Util::GetSuit(type);
	}

	CardRank Card::GetRank() const
	{
		return Util::GetRank(type);
	}

	std::shared_ptr<AbstractPlayer> Card::GetPlayer() const
	{
		return player;
	}

	CardRole Card::GetRoleType() const
	{
		return role->GetRoleType();
	}

	AbstractRole* Card::GetRole() const
	{
		return role.get();
	}
}