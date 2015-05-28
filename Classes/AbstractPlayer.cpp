#include "stdafx.h"
#include "AbstractPlayer.h"

#include "Card.h"

namespace Mighty
{
	AbstractPlayer::~AbstractPlayer()
	{

	}

	void AbstractPlayer::SetGame(std::shared_ptr<Game> game)
	{
		this->game = game;
	}

	void AbstractPlayer::AddCard(std::shared_ptr<Card> card)
	{
		handCardList.push_back(card);
	}

	void AbstractPlayer::AddAcquiredCard(const CardList& acquiredCardList)
	{
		this->acquiredCardList.insert(this->acquiredCardList.begin(), acquiredCardList.begin(), acquiredCardList.end());
	}

	void AbstractPlayer::RemoveFromHand(std::shared_ptr<Card> card)
	{
		handCardList.erase(std::remove(handCardList.begin(), handCardList.end(), card));
	}

	std::shared_ptr<Game> AbstractPlayer::GetGame() const
	{
		return game;
	}

	int AbstractPlayer::GetID() const
	{
		return id;
	}

	const std::string& AbstractPlayer::GetName() const
	{
		return name;
	}

	const AbstractPlayer::CardList& AbstractPlayer::GetHandCardList() const
	{
		return handCardList;
	}


	AbstractPlayer::CardList AbstractPlayer::GetMatchingCardList(CardSuit suit) const
	{
		CardList cardList;

		for (auto card : handCardList)
		{
			if (card->GetSuit() == suit)
			{
				cardList.push_back(card);
			}
		}

		return cardList;
	}

	AbstractPlayer::CardList AbstractPlayer::GetMatchingCardList(CardRole role) const
	{
		CardList list;

		for (auto card : handCardList)
		{
			if (card->GetRoleType() == role)
			{
				list.push_back(card);
			}
		}

		return list;
	}

	void AbstractPlayer::SetBasicInfo(int id, const std::string& name)
	{
		this->id = id;
		this->name = name;
	}
}