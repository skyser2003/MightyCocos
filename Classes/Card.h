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
		void Init(AbstractPlayer* player, CardSuit suit, CardRank rank);

		bool WinAgainst(std::shared_ptr<Card> otherCard);

		CardSuit GetSuit() const;
		CardRank GetRank() const;
		AbstractPlayer* GetPlayer() const;
		CardRole GetRoleType() const;

	private:
		CardSuit suit;
		CardRank rank;
		std::unique_ptr<AbstractRole> role;

		AbstractPlayer* player = nullptr;
	};
}