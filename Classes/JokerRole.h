#pragma once

#include "AbstractRole.h"

namespace Mighty
{
	class JokerRole final : public AbstractRole
	{
	public:
		virtual bool WinAgainst(AbstractRole* otherRole) const;
	};
}