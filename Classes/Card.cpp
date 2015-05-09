#include "stdafx.h"
#include "Card.h"

namespace Mighty
{
	void Card::Init(AbstractPlayer* player, CardRank rank)
	{
		this->player = player;
		this->rank = rank;
	}

	void Card::AddCardFunction(std::shared_ptr<AbstractCardFunction> cardFunc)
	{
		cardFuncList.push_back(cardFunc);
	}

	CardRank Card::GetRank() const
	{
		return rank;
	}

	AbstractPlayer* Card::GetPlayer() const
	{
		return player;
	}
}