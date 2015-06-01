#pragma once

namespace Mighty
{
	#include "enum_class_CardType.h"
	#include "enum_class_CardSuit.h"
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