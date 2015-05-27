#pragma once

#include "AbstractRole.h"

namespace Mighty
{
	class JokerCallRole final : public CRTPRole<JokerCallRole>
	{
	public:
		void SetIsActivated(bool isActivated);

		bool IsActivated() const;

	private:
		bool isActivated;
	};
}