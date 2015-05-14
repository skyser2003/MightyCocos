#include "stdafx.h"
#include "Round.h"

#include "CardSuit.h"
#include "CardRank.h"
#include "Card.h"
#include "JokerRole.h"
#include "JokerCallRole.h"

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

		// Joker card wins most of the times, except when joker call is activated.
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
				auto* jokerCallRole = static_cast<JokerCallRole*>(jokerCallCard->GetRole());
				if (jokerCallRole->IsActivated() == false)
				{
					return jokerCard;
				}
			}
		}

		// Highest rank card in main suit wins.
		auto highestMainCard = GetHighestRankCard(cardList, mainSuit);

		if (highestMainCard != nullptr)
		{
			return highestMainCard;
		}

		// If there is no card with main suit, first card's main suit will be temporary main suit for this turn.
		auto tempMainSuit = CardSuit::None;
		if (jokerCard == cardList[0])
		{
			auto* jokerRole = static_cast<JokerRole*>(jokerCard->GetRole());
			tempMainSuit = jokerRole->GetSelectedSuit();
		}
		else
		{
			tempMainSuit = cardList[0]->GetSuit();
		}

		auto highestTempCard = GetHighestRankCard(cardList, tempMainSuit);

		return highestTempCard;
	}

	std::shared_ptr<Card> Round::GetHighestRankCard(const CardList& cardList, CardSuit suit)
	{
		std::shared_ptr<Card> highestCard = nullptr;

		for (const auto& card : cardList)
		{
			if (card->GetSuit() != suit)
			{
				continue;
			}

			if (highestCard == nullptr)
			{
				highestCard = card;
			}
			else
			{
				auto higherRank = GetHigherRank(highestCard->GetRank(), card->GetRank());
				if (higherRank == card->GetRank())
				{
					highestCard = card;
				}
			}
		}

		return highestCard;
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
		mainSuit = CardSuit::None;
		currentWinningCard = nullptr;
		cardList.clear();
	}

	void Round::PlayNextCard(std::shared_ptr<Card> nextCard)
	{
		if (mainSuit == CardSuit::None)
		{
			// TODO : Joker can decide wanted suit
			mainSuit = nextCard->GetSuit();
		}

		cardList.push_back(nextCard);
		currentWinningCard = CalculateWinningCard(mainSuit, cardList);
	}
}