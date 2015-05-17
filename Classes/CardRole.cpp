#include "stdafx.h"
#include "CardRole.h"

namespace Mighty
{
	template <>
	CardRole GetRoleType<NormalRole>()
	{
		return CardRole::Normal;
	}

	template <>
	CardRole GetRoleType<MightyRole>()
	{
		return CardRole::Mighty;
	}

	template <>
	CardRole GetRoleType<JokerRole>()
	{
		return CardRole::Joker;
	}

	template <>
	CardRole GetRoleType<JokerCallRole>()
	{
		return CardRole::JokerCall;
	}
}