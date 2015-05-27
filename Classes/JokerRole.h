#pragma once

#include "AbstractRole.h"

namespace Mighty
{
	enum class CardSuit;

	class JokerRole final : public CRTPRole<JokerRole>
	{
	public:
		JokerRole();

		void SelectSuit(CardSuit suit);

		CardSuit GetSelectedSuit() const;
	private:
		CardSuit selectedSuit;
	};
}