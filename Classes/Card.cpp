#include "stdafx.h"
#include "Card.h"

#include "CardUtilFunction.h"
#include "AbstractRole.h"

namespace Mighty
{
	void Card::Init(AbstractPlayer* player, CardRank rank)
	{
		this->player = player;
		this->rank = rank;
		role.reset();
	}

	bool Card::WinAgainst(std::shared_ptr<Card> otherCard)
	{
		return true;
	}

	CardSuit Card::GetSuit() const
	{
		return Util::GetSuit(rank);
	}

	CardRank Card::GetRank() const
	{
		return rank;
	}

	AbstractPlayer* Card::GetPlayer() const
	{
		return player;
	}

	CardRole Card::GetRoleType() const
	{
		return role->GetRoleType();
	}
}