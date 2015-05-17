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

namespace Mighty
{
	enum class CardSuit;
	enum class CardRank;

	Game::Game()
	{

	}

	Game::~Game()
	{

	}

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
		if (round == nullptr)
		{
			StartNewRound();
		}

		round->PlayNextCard(card);

		if (round->IsFinished() == true)
		{
			auto winCard = round->GetCurrentWinningCard();
			auto player = winCard->GetPlayer();

			auto cardList = round->GetCurrentRoundCardList();
			for (const auto& card : cardList)
			{

			}

			// Destroy round
			round = nullptr;
		}
	}

	const Game::Players& Game::GetPlayers() const
	{
		return players;
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

		for (int i = 0; i < deck.size(); ++i)
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
		switch (card->GetType())
		{
		case CardType::SA:
		{
			card->SetRole(new MightyRole());
		}
		break;

		case CardType::JC:
		case CardType::JB:
		{
			card->SetRole(new JokerRole());
		}
		break;

		case CardType::C3:
		{
			card->SetRole(new JokerCallRole());
		}
		break;

		default:
		{
			card->SetRole(new NormalRole());
		}
		break;
		}
	}

	void Game::StartNewRound()
	{
		round.reset(new Round());
		round->Init();
	}
}