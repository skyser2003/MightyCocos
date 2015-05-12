#pragma once

#include "CardRole.h"

namespace Mighty
{
	enum CardSuit;

	class Card;

	class Round final
	{
	private:
		typedef std::vector<std::shared_ptr<Card>> CardList;

	public:
		static std::shared_ptr<Card> CalculateWinningCard(CardSuit mainSuit, const CardList& cardList);
		static std::shared_ptr<Card> GetCard(const CardList& cardList, CardRole roleType);
		static std::shared_ptr<Card> GetHighestRankCard(const CardList& cardList, CardSuit suit);

	public:
		void Init();
		void Destroy();

		void PlayNextCard(std::shared_ptr<Card> nextCard);
	private:
		CardSuit mainSuit;

		std::shared_ptr<Card> currentWinningCard;
		CardList cardList;
	};
}