#pragma once

namespace Mighty
{
	#include "enum_class_CardType.h"
	#include "enum_class_CardSuit.h"
	enum class CardRank;

	namespace Util
	{
		CardSuit GetSuit(CardType type);
		CardRank GetRank(CardType type);

		std::string GetCardResourceName(CardType type);
	}
}