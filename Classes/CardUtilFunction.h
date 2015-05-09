#pragma once

namespace Mighty
{
	enum CardSuit;
	enum CardRank;

	bool IsClub(CardRank rank);
	bool IsDiamond(CardRank rank);
	bool IsHeart(CardRank rank);
	bool IsSpade(CardRank rank);

	CardSuit GetSuit(CardRank rank);
}