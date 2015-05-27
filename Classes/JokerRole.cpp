#include "stdafx.h"
#include "JokerRole.h"

#include "CardSuit.h"

namespace Mighty
{
	JokerRole::JokerRole()
	{
		SelectSuit(CardSuit::None);
	}

	void JokerRole::SelectSuit(CardSuit suit)
	{
		selectedSuit = suit;
	}

	CardSuit JokerRole::GetSelectedSuit() const
	{
		return selectedSuit;
	}
}