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
		void SetCardTypeForRole(CardRole role, CardType type);

		int GetPlayerCount() const;
		CardType GetCardTypeForRole(CardRole role) const;
		CardRole GetCardRoleForType(CardType type) const;
		bool ExistsCardRoleForType(CardType type) const;

	private:
		int playerCount;
		std::map<CardRole, CardType> cardTypePerRole;
		std::map<CardType, CardRole> cardRolePerType;
	};
}