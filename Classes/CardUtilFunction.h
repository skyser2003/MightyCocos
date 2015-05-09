#pragma once

namespace Mighty
{
	enum CardSuit;
	enum CardRank;

	namespace Util
	{
		bool IsClub(CardRank rank);
		bool IsDiamond(CardRank rank);
		bool IsHeart(CardRank rank);
		bool IsSpade(CardRank rank);

		CardSuit GetSuit(CardRank rank);
	}
}