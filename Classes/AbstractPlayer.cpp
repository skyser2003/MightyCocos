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
		handCardList.push_back(card);
	}

	void AbstractPlayer::AddAcquiredCard(const CardList& acquiredCardList)
	{
		this->acquiredCardList.insert(this->acquiredCardList.begin(), acquiredCardList.begin(), acquiredCardList.end());
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
		return handCardList;
	}

	void AbstractPlayer::SetBasicInfo(int id, const std::string& name)
	{
		this->id = id;
		this->name = name;
	}
}