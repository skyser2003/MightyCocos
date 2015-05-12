#pragma once

namespace Mighty
{
	enum CardRank
	{
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

		JB, // Black(Monotone)
		JC = JB // Color
	};

	CardRank GetHigherRank(CardRank rank1, CardRank rank2);
}