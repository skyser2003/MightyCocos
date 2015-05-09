#include "stdafx.h"
#include "AbstractCardFunction.h"

namespace Mighty
{
	void AbstractCardFunction::SetCard(Card* card)
	{
		this->card = card;
	}

	Card* AbstractCardFunction::GetCard() const
	{
		return card;
	}
}