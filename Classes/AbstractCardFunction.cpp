#include "stdafx.h"
#include "AbstractCardFunction.h"

#include "Card.h"
#include "AbstractPlayer.h"

namespace Mighty
{
	void AbstractCardFunction::SendMsg(CardMessage msg, Card* sender)
	{
		card->GetPlayer()->GetGame();
	}

	void AbstractCardFunction::SetCard(Card* card)
	{
		this->card = card;
	}

	Card* AbstractCardFunction::GetCard() const
	{
		return card;
	}
}