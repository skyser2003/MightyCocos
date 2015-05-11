#include "stdafx.h"
#include "MightyRole.h"

namespace Mighty
{
	bool MightyRole::WinAgainst(AbstractRole* otherRole) const
	{
		// Mighty always wins
		return true;
	}
}