#pragma once

#include "AbstractRole.h"

namespace Mighty
{
	class NormalRole final : public AbstractRole
	{
	public:
		virtual bool WinAgainst(AbstractRole* otherRole) const;
	};
}