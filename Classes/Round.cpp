#include "stdafx.h"
#include "Round.h"

namespace Mighty
{
	void Round::Init()
	{

	}

	void Round::Destroy()
	{
		currentWinningCard = nullptr;
		cardList.clear();
	}

	void Round::PlayNextCard(std::shared_ptr<Card> nextCard)
	{
		if (cardList.size() == 0)
		{
			currentWinningCard = nextCard;
		}
		else
		{
			// TODO - Check conditions and find out the winning card
		}

		cardList.push_back(nextCard);
	}
}