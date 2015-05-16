#include "stdafx.h"
#include "CardUtilFunc.h"

#include "CardType.h"
#include "CardSuit.h"
#include "CardRank.h"

namespace Mighty
{
	namespace Util
	{
		CardSuit GetSuit(CardType type)
		{
			switch (type)
			{
			case CardType::C2:
			case CardType::C3:
			case CardType::C4:
			case CardType::C5:
			case CardType::C6:
			case CardType::C7:
			case CardType::C8:
			case CardType::C9:
			case CardType::C10:
			case CardType::CJ:
			case CardType::CQ:
			case CardType::CK:
			case CardType::CA:
			{
				return CardSuit::Club;
			}
			break;

			case CardType::D2:
			case CardType::D3:
			case CardType::D4:
			case CardType::D5:
			case CardType::D6:
			case CardType::D7:
			case CardType::D8:
			case CardType::D9:
			case CardType::D10:
			case CardType::DJ:
			case CardType::DQ:
			case CardType::DK:
			case CardType::DA:
			{
				return CardSuit::Diamond;
			}
			break;

			case CardType::H2:
			case CardType::H3:
			case CardType::H4:
			case CardType::H5:
			case CardType::H6:
			case CardType::H7:
			case CardType::H8:
			case CardType::H9:
			case CardType::H10:
			case CardType::HJ:
			case CardType::HQ:
			case CardType::HK:
			case CardType::HA:
			{
				return CardSuit::Heart;
			}
			break;

			case CardType::S2:
			case CardType::S3:
			case CardType::S4:
			case CardType::S5:
			case CardType::S6:
			case CardType::S7:
			case CardType::S8:
			case CardType::S9:
			case CardType::S10:
			case CardType::SJ:
			case CardType::SQ:
			case CardType::SK:
			case CardType::SA:
			{
				return CardSuit::Spade;
			}
			break;

			case CardType::JB:
			case CardType::JC:
			default:
			{
				return CardSuit::None;
			}
			break;
			}
		}

		CardRank GetRank(CardType type)
		{
			switch (type)
			{
			case CardType::C2:
			case CardType::D2:
			case CardType::H2:
			case CardType::S2:
			{
				return CardRank::Two;
			}
			break;

			case CardType::C3:
			case CardType::D3:
			case CardType::H3:
			case CardType::S3:
			{
				return CardRank::Three;
			}
			break;

			case CardType::C4:
			case CardType::D4:
			case CardType::H4:
			case CardType::S4:
			{
				return CardRank::Four;
			}
			break;

			case CardType::C5:
			case CardType::D5:
			case CardType::H5:
			case CardType::S5:
			{
				return CardRank::Five;
			}
			break;

			case CardType::C6:
			case CardType::D6:
			case CardType::H6:
			case CardType::S6:
			{
				return CardRank::Six;
			}
			break;

			case CardType::C7:
			case CardType::D7:
			case CardType::H7:
			case CardType::S7:
			{
				return CardRank::Seven;
			}
			break;

			case CardType::C8:
			case CardType::D8:
			case CardType::H8:
			case CardType::S8:
			{
				return CardRank::Eight;
			}
			break;

			case CardType::C9:
			case CardType::D9:
			case CardType::H9:
			case CardType::S9:
			{
				return CardRank::Nine;
			}
			break;

			case CardType::C10:
			case CardType::D10:
			case CardType::H10:
			case CardType::S10:
			{
				return CardRank::Ten;
			}
			break;

			case CardType::CJ:
			case CardType::DJ:
			case CardType::HJ:
			case CardType::SJ:
			{
				return CardRank::Jack;
			}
			break;

			case CardType::CQ:
			case CardType::DQ:
			case CardType::HQ:
			case CardType::SQ:
			{
				return CardRank::Queen;
			}
			break;

			case CardType::CK:
			case CardType::DK:
			case CardType::HK:
			case CardType::SK:
			{
				return CardRank::King;
			}
			break;

			case CardType::CA:
			case CardType::DA:
			case CardType::HA:
			case CardType::SA:
			{
				return CardRank::Ace;
			}
			break;

			case CardType::JB:
			case CardType::JC:
			default:
			{
				return CardRank::None;
			}
			}
		}

		std::string GetCardResourceName(CardType type)
		{
			switch (type)
			{
			case CardType::JB:
			{
				return "jb";
			}
			break;

			case CardType::JC:
			{
				return "jr";
			}
			break;
			}

			CardSuit suit = GetSuit(type);
			CardRank rank = GetRank(type);

			std::string ret;

			// Suit
			switch (suit)
			{
			case CardSuit::Club:
			{
				ret = "c";
			}
			break;

			case CardSuit::Diamond:
			{
				ret = "d";
			}
			break;

			case CardSuit::Heart:
			{
				ret = "h";
			}
			break;

			case CardSuit::Spade:
			{
				ret = "s";
			}
			break;
			}

			// Rank
			switch (rank)
			{
			case CardRank::Ace:
			{
				ret += "1";
			}
			break;

			case CardRank::Two:
			{
				ret += "2";
			}
			break;

			case CardRank::Three:
			{
				ret += "3";
			}
			break;

			case CardRank::Four:
			{
				ret += "4";
			}
			break;

			case CardRank::Five:
			{
				ret += "5";
			}
			break;

			case CardRank::Six:
			{
				ret += "6";
			}
			break;

			case CardRank::Seven:
			{
				ret += "7";
			}
			break;

			case CardRank::Eight:
			{
				ret += "8";
			}
			break;

			case CardRank::Nine:
			{
				ret += "9";
			}
			break;

			case CardRank::Ten:
			{
				ret += "10";
			}
			break;

			case CardRank::Jack:
			{
				ret += "j";
			}
			break;

			case CardRank::Queen:
			{
				ret += "q";
			}
			break;

			case CardRank::King:
			{
				ret += "k";
			}
			break;
			}

			return ret;
		}
	}
}