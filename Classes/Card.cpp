#include "stdafx.h"
#include "Card.h"

#include "CardUtilFunction.h"
#include "AbstractCardFunction.h"

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

	bool Card::IsPlayable(CardSuit currentSuit) const
	{
		bool isPlayable = true;

		for (auto cardFunc : cardFuncList)
		{
			if (cardFunc->IsPlayable(currentSuit) == false)
			{
				isPlayable = false;
				break;
			}
		}

		return isPlayable;
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
}