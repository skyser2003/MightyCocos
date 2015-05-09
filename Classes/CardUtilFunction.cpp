#include "stdafx.h"
#include "CardUtilFunction.h"

#include "CardSuit.h"
#include "CardRank.h"

namespace Mighty
{
	bool IsClub(CardRank rank)
	{
		switch (rank)
		{
		case CA:
		case C2:
		case C3:
		case C4:
		case C5:
		case C6:
		case C7:
		case C8:
		case C9:
		case C10:
		case CJ:
		case CQ:
		case CK:
		{
			return true;
		}
		default:
		{
			return false;
		}
		}
	}

	bool IsDiamond(CardRank rank)
	{
		switch (rank)
		{
		case DA:
		case D2:
		case D3:
		case D4:
		case D5:
		case D6:
		case D7:
		case D8:
		case D9:
		case D10:
		case DJ:
		case DQ:
		case DK:
		{
			return true;
		}
		default:
		{
			return false;
		}
		}

	}

	bool IsHeart(CardRank rank)
	{
		switch (rank)
		{
		case HA:
		case H2:
		case H3:
		case H4:
		case H5:
		case H6:
		case H7:
		case H8:
		case H9:
		case H10:
		case HJ:
		case HQ:
		case HK:
		{
			return true;
		}
		default:
		{
			return false;
		}
		}

	}

	bool IsSpade(CardRank rank)
	{
		switch (rank)
		{
		case SA:
		case S2:
		case S3:
		case S4:
		case S5:
		case S6:
		case S7:
		case S8:
		case S9:
		case S10:
		case SJ:
		case SQ:
		case SK:
		{
			return true;
		}
		default:
		{
			return false;
		}
		}

	}

	CardSuit GetSuit(CardRank rank)
	{
		if (IsClub(rank) == true)
		{
			return Club;
		}
		else if (IsDiamond(rank) == true)
		{
			return Diamond;
		}
		else if (IsHeart(rank) == true)
		{
			return Heart;
		}
		else if (IsSpade(rank) == true)
		{
			return Spade;
		}
		else
		{
			return None;
		}
	}
}