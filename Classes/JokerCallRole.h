#pragma once

#include "AbstractRole.h"

namespace Mighty
{
	class JokerCallRole final : public AbstractRole
	{
	public:
		virtual bool WinAgainst(AbstractRole* otherRole) const;

		void SetIsActivated(bool isActivated);

		bool IsActivated() const;

	private:
		bool isActivated;
	};
}