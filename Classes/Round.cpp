#include "stdafx.h"
#include "Round.h"

#include "CardSuit.h"
#include "Card.h"

namespace Mighty
{
	std::shared_ptr<Card> Round::CalculateWinningCard(CardSuit mainSuit, const CardList& cardList)
	{
		if (cardList.size() == 0)
		{
			return nullptr;
		}
		else if (cardList.size() == 1)
		{
			return cardList.front();
		}

		// Mighty card ALWAYS wins
		auto mightyCard = GetCard(cardList, Mighty);
		if (mightyCard != nullptr)
		{
			return mightyCard;
		}

		auto jokerCard = GetCard(cardList, Joker);
		if (jokerCard != nullptr)
		{
			auto jokerCallCard = GetCard(cardList, JokerCall);
			if (jokerCallCard == nullptr)
			{
				return jokerCard;
			}
			else
			{
			}
		}
	}

	std::shared_ptr<Card> Round::GetCard(const CardList& cardList, CardRole roleType)
	{
		for (const auto& card : cardList)
		{
			if (roleType == card->GetRoleType())
			{
				return card;
			}
		}

		return nullptr;
	}

	void Round::Init()
	{
		Destroy();
	}

	void Round::Destroy()
	{
		mainSuit = None;
		currentWinningCard = nullptr;
		cardList.clear();
	}

	void Round::PlayNextCard(std::shared_ptr<Card> nextCard)
	{
		if (mainSuit == None)
		{
			// TODO : Joker can decide wanted suit
			mainSuit = nextCard->GetSuit();
		}

		cardList.push_back(nextCard);
		currentWinningCard = CalculateWinningCard(mainSuit, cardList);
	}
}