#include "stdafx.h"
#include "JokerRole.h"

#include "CardSuit.h"

namespace Mighty
{
	JokerRole::JokerRole()
	{
		SelectSuit(None);
	}

	bool JokerRole::WinAgainst(AbstractRole* otherRole) const
	{
		return true;
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