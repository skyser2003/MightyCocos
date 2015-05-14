#pragma once

namespace Mighty
{
	enum CardSuit;
	enum CardRank;
	enum CardRole;

	class AbstractPlayer;
	class AbstractRole;

	class Card final
	{
	public:
		Card();
		~Card();

		void Init(std::shared_ptr<AbstractPlayer> player, CardSuit suit, CardRank rank);

		bool WinAgainst(std::shared_ptr<Card> otherCard);

		CardSuit GetSuit() const;
		CardRank GetRank() const;
		std::shared_ptr<AbstractPlayer> GetPlayer() const;
		CardRole GetRoleType() const;
		AbstractRole* GetRole() const;

	private:
		CardSuit suit;
		CardRank rank;
		std::unique_ptr<AbstractRole> role;

		std::shared_ptr<AbstractPlayer> player;
	};
}