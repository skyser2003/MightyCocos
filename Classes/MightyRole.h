#pragma once

#include "AbstractRole.h"

namespace Mighty
{
	class MightyRole final : public AbstractRole
	{
	public:
		virtual bool WinAgainst(AbstractRole* otherRole) const;
	};
}