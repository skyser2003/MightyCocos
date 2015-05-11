#include "stdafx.h"
#include "JokerCallRole.h"

namespace Mighty
{
	bool JokerCallRole::WinAgainst(AbstractRole* otherRole) const
	{
		return true;
	}

	void JokerCallRole::SetIsActivated(bool isActivated)
	{
		this->isActivated = isActivated;
	}

	bool JokerCallRole::IsActivated() const
	{
		return isActivated;
	}
}