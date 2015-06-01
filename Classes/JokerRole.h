#pragma once

#include "AbstractRole.h"

namespace Mighty
{
	#include "enum_class_CardSuit.h"

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