#include "stdafx.h"
#include "AbstractPlayer.h"

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
		cardList.push_back(card);
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

	const AbstractPlayer::CardList& AbstractPlayer::GetCardList() const
	{
		return cardList;
	}

	void AbstractPlayer::SetBasicInfo(int id, const std::string& name)
	{
		this->id = id;
		this->name = name;
	}
}