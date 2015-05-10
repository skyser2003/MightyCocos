#include "stdafx.h"
#include "AbstractPlayer.h"

namespace Mighty
{
	void AbstractPlayer::ReceiveMsg(CardMessage msg, Card* sender)
	{
		for (auto card : cardList)
		{
		}
	}

	void AbstractPlayer::SetGame(std::shared_ptr<Game> game)
	{
		this->game = game;
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

	void AbstractPlayer::SetBasicInfo(int id, const std::string& name)
	{
		this->id = id;
		this->name = name;
	}
}