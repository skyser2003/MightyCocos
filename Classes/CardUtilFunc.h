#pragma once

namespace Mighty
{
	enum class CardType;
	enum class CardSuit;
	enum class CardRank;

	namespace Util
	{
		CardSuit GetSuit(CardType type);
		CardRank GetRank(CardType type);

		std::string GetCardResourceName(CardType type);
	}
}