#pragma once

#include "CardRole.h"

namespace Mighty
{
	#include "enum_class_CardSuit.h"

	class Game;
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
		void Init(std::weak_ptr<Game> game);
		void Destroy();

		void PlayNextCard(std::shared_ptr<Card> nextCard);
		bool IsFinished() const;
		bool IsPlayable(std::shared_ptr<Card> nextCard) const;

		std::shared_ptr<Card> GetCurrentWinningCard() const;
		const CardList& GetCurrentRoundCardList() const;
		CardSuit GetMainSuit() const;

	private:
		std::weak_ptr<Game> game;
		CardSuit mainSuit;

		std::shared_ptr<Card> currentWinningCard;
		CardList cardList;
	};
}