#include "stdafx.h"
#include "Game.h"

#include "HumanPlayer.h"

namespace Mighty
{
	void Game::Init()
	{
		// Test
		for (int i = 0; i < 4; ++i)
		{
			auto* human = new HumanPlayer();
			human->Init(i, "boo" + i);
			auto player = std::shared_ptr<AbstractPlayer>(human);

			AddPlayer(player);
		}
	}

	void Game::Destroy()
	{
		players.clear();
	}

	void Game::BroadcastMsg(CardMessage msg, Card* sender)
	{
		for (auto pair : players)
		{
			auto player = pair.second;
			player->ReceiveMsg(msg, sender);
		}
	}

	void Game::AddPlayer(std::shared_ptr<AbstractPlayer> player)
	{
		if (players.count(player->GetID()) != 0)
		{
			return;
		}

		players[player->GetID()] = player;
	}

	const Game::Players& Game::GetPlayers() const
	{
		return players;
	}
}