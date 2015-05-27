#include "stdafx.h"
#include "JokerCallRole.h"

namespace Mighty
{
	void JokerCallRole::SetIsActivated(bool isActivated)
	{
		this->isActivated = isActivated;
	}

	bool JokerCallRole::IsActivated() const
	{
		return isActivated;
	}
}