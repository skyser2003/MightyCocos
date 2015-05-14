#include "stdafx.h"
#include "Game.h"

#include "HumanPlayer.h"
#include "CardSuit.h"
#include "CardRank.h"
#include "Card.h"

namespace Mighty
{
	enum CardSuit;
	enum CardRank;

	void Game::Init()
	{
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch());
		gen.seed(ms.count());

		// Test
		for (int i = 0; i < 5; ++i)
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

	void Game::DistributeCard()
	{
		// 53 Cards total : 4 suits * 13 ranks + 1 Joker
		std::deque<std::pair<CardSuit, CardRank>> deck;

		// 4 suits * 13 ranks
		for (CardSuit i = Club; i <= Spade; i = static_cast<CardSuit>(i + 1))
		{
			for (CardRank j = Two; j <= Ace; j = static_cast<CardRank>(j + 1))
			{
				deck.push_back(std::make_pair(i, j));
			}
		}

		// Joker
		deck.push_back(std::make_pair(None, JB));

		// Distribute 10 cards to each player, leave 3 cards for latter use.
		for (int i = 0; i < 50; ++i)
		{
			int index = gen() % deck.size();
			CardSuit suit = deck[index].first;
			CardRank rank = deck[index].second;
			deck.erase(deck.begin() + index);

			auto card = std::shared_ptr<Card>(new Card());
			card->Init(players[i % 5], suit, rank);

			players[i % 5]->AddCard(card);
		}
	}
}