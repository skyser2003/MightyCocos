#include "stdafx.h"
#include "CardFunctionNormal.h"

#include "CardSuit.h"
#include "Card.h"

namespace Mighty
{
	void CardFunctionNormal::OnActivate(bool isFirstCard)
	{

	}

	bool CardFunctionNormal::IsPlayable(CardSuit currentSuit)
	{
		switch (currentSuit)
		{
		case None:
		{
			return true;
		}
		default:
		{
			return currentSuit == card->GetSuit();
		}
		}
	}
}