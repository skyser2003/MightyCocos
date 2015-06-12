#pragma once

#include "EnumEnumerator.h"

namespace Mighty
{
	enum class CardType
	{
		// Club
		C2,
		C3,
		C4,
		C5,
		C6,
		C7,
		C8,
		C9,
		C10,
		CJ,
		CQ,
		CK,
		CA,

		// Diamond
		D2,
		D3,
		D4,
		D5,
		D6,
		D7,
		D8,
		D9,
		D10,
		DJ,
		DQ,
		DK,
		DA,

		// Heart
		H2,
		H3,
		H4,
		H5,
		H6,
		H7,
		H8,
		H9,
		H10,
		HJ,
		HQ,
		HK,
		HA,

		// Spade
		S2,
		S3,
		S4,
		S5,
		S6,
		S7,
		S8,
		S9,
		S10,
		SJ,
		SQ,
		SK,
		SA,

		// Joker
		JB, // Black(Monotone)
		JC  // Color
	};

	// Enumerator
	typedef EnumEnumerator<CardType, CardType::C2, CardType::JC> CardTypes;
}