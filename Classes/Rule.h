#pragma once

namespace Mighty
{
	#include "enum_class_CardRole.h"
	#include "enum_class_CardType.h"

	class Rule
	{
	public:
		Rule();

		void SetPlayerCount(int count);
		void SetCardType(CardRole role, CardType type);

		int GetPlayerCount() const;
		CardType GetCardType(CardRole role) const;

	private:
		int playerCount;
		std::map<CardRole, CardType> cardTypePerRole;
	};
}