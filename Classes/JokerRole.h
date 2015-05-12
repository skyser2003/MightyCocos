#pragma once

#include "AbstractRole.h"

namespace Mighty
{
	enum CardSuit;

	class JokerRole final : public AbstractRole
	{
	public:
		JokerRole();

		virtual bool WinAgainst(AbstractRole* otherRole) const;

		void SelectSuit(CardSuit suit);

		CardSuit GetSelectedSuit() const;
	private:
		CardSuit selectedSuit;
	};
}