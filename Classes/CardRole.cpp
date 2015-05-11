#include "stdafx.h"
#include "CardRole.h"

namespace Mighty
{
	template <>
	CardRole GetRoleType<NormalRole>()
	{
		return Normal;
	}

	template <>
	CardRole GetRoleType<MightyRole>()
	{
		return Mighty;
	}

	template <>
	CardRole GetRoleType<JokerRole>()
	{
		return Joker;
	}

	template <>
	CardRole GetRoleType<JokerCallRole>()
	{
		return JokerCall;
	}
}