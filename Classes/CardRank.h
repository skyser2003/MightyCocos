#pragma once

namespace Mighty
{
	enum class CardRank
	{
		None,

		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,
		Ace,
	};

	CardRank GetHigherRank(CardRank rank1, CardRank rank2);
}