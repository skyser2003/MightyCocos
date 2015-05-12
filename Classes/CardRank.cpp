#include "stdafx.h"
#include "CardRank.h"

namespace Mighty
{
	CardRank GetHigherRank(CardRank rank1, CardRank rank2)
	{
		if (rank1 > rank2)
		{
			return rank1;
		}
		else
		{
			return rank2;
		}
	}
}