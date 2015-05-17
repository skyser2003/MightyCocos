#pragma once

namespace Mighty
{
	enum class CardType;
	enum class CardSuit;
	enum class CardRank;
	enum class CardRole;

	class AbstractPlayer;
	class AbstractRole;

	class Card final
	{
	public:
		Card();
		~Card();

		void Init(std::shared_ptr<AbstractPlayer> player, CardType type);

		bool WinAgainst(std::shared_ptr<Card> otherCard);

		void SetRole(AbstractRole* role);

		CardType GetType() const;
		CardSuit GetSuit() const;
		CardRank GetRank() const;
		std::shared_ptr<AbstractPlayer> GetPlayer() const;
		CardRole GetRoleType() const;
		AbstractRole* GetRole() const;

	private:
		CardType type;
		std::unique_ptr<AbstractRole> role;

		std::shared_ptr<AbstractPlayer> player;
	};
}