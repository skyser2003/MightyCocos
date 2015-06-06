#include "stdafx.h"
#include "Game.h"

#include "HumanPlayer.h"
#include "CardType.h"
#include "Card.h"

#include "JokerRole.h"
#include "JokerCallRole.h"
#include "MightyRole.h"
#include "NormalRole.h"
#include "Round.h"
#include "Rule.h"

namespace Mighty
{
	Game::Game()
	{

	}

	Game::~Game()
	{

	}

	void Game::Init(std::weak_ptr<Game> self)
	{
		this->self = self;

		rule.reset(new Rule());
		rule->SetPlayerCount(5);

		rule->SetCardTypeForRole(CardRole::Mighty, CardType::SA);
		rule->SetCardTypeForRole(CardRole::Joker, CardType::JB);
		rule->SetCardTypeForRole(CardRole::JokerCall, CardType::C3);

		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch());
		gen.seed(ms.count());

		// Test
		for (int i = 0; i < rule->GetPlayerCount(); ++i)
		{
			char name[25];
			sprintf_s(name, "boo%d", i);

			auto* human = new HumanPlayer();
			human->Init(i, name);
			auto player = std::shared_ptr<AbstractPlayer>(human);

			AddPlayer(player);
		}

		DistributeCard();
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

	void Game::PlayCard(std::shared_ptr<Card> card)
	{
		round->PlayNextCard(card);
	}

	void Game::StartNewRound()
	{
		round.reset(new Round());
		round->Init(self);
	}

	bool Game::IsRoundFinished() const
	{
		return round->IsFinished();
	}

	bool Game::IsPlayable(std::shared_ptr<Card> card)
	{
		return round->IsPlayable(card);
	}

	const Game::Players& Game::GetPlayers() const
	{
		return players;
	}

	const Rule& Game::GetRule() const
	{
		return *rule.get();
	}

	const Game::CardList& Game::GetCurrentRoundCardList() const
	{
		return round->GetCurrentRoundCardList();
	}

	int Game::GetCurrentRoundCardCount() const
	{
		return round == nullptr ? 0 : round->GetCurrentRoundCardList().size();
	}

	std::shared_ptr<Card> Game::GetWinningCard() const
	{
		return round->GetCurrentWinningCard();
	}

	void Game::DistributeCard()
	{
		// 53 Cards total : 4 suits * 13 ranks + 1 Joker
		std::deque<CardType> deck;

		for (CardType i = CardType::C2; i <= CardType::JB; i = static_cast<CardType>(static_cast<int>(i)+1))
		{
			deck.push_back(i);
		}

		// Distribute 10 cards to each player, leave 3 cards for latter use.
		for (int i = 0; i < 50; ++i)
		{
			int index = gen() % deck.size();
			CardType type = deck[index];
			deck.erase(deck.begin() + index);

			auto card = std::shared_ptr<Card>(new Card());
			card->Init(players[i % 5], type);
			ApplyRole(card.get());

			players[i % 5]->AddCard(card);
		}

		for (size_t i = 0; i < deck.size(); ++i)
		{
			int index = gen() % deck.size();
			CardType type = deck[index];

			auto card = std::shared_ptr<Card>(new Card());
			card->Init(players[i % 5], type);
			ApplyRole(card.get());

			floorCards.push_back(card);
		}

		deck.clear();
	}

	void Game::ApplyRole(Card* card)
	{
		if (rule->ExistsCardRoleForType(card->GetType()) == false)
		{
			card->SetRole(new NormalRole());
		}
		else
		{
			auto role = rule->GetCardRoleForType(card->GetType());
			switch (role)
			{
			case CardRole::Mighty:
			{
				card->SetRole(new MightyRole());
			}
			break;

			case CardRole::Joker:
			{
				card->SetRole(new JokerRole());
			}
			break;

			case CardRole::JokerCall:
			{
				card->SetRole(new JokerCallRole());
			}
			break;
			}
		}
	}
}