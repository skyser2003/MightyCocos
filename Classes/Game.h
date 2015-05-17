#pragma once

namespace Mighty
{
	enum CardMessage;

	class AbstractPlayer;
	class Card;
	class Round;
	class Rule;

	class Game
	{
	private:
		typedef std::map<int, std::shared_ptr<AbstractPlayer>> Players;

	public:
		Game();
		~Game();

		void Init(std::weak_ptr<Game> self);
		void Destroy();

		void AddPlayer(std::shared_ptr<AbstractPlayer> player);
		void PlayCard(std::shared_ptr<Card> card);

		const Players& GetPlayers() const;
		const Rule& GetRule() const;

	private:
		void DistributeCard();
		void ApplyRole(Card* card);
		void StartNewRound();

		std::mt19937 gen;

		std::weak_ptr<Game> self;

		Players players;
		std::vector<std::shared_ptr<Card>> floorCards;
		std::unique_ptr<Round> round;
		std::unique_ptr<Rule> rule;
	};
}