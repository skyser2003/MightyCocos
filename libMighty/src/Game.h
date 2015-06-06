#pragma once

namespace Mighty
{
	class AbstractPlayer;
	class Card;
	class Round;
	class Rule;

	class Game
	{
	private:
		typedef std::map<int, std::shared_ptr<AbstractPlayer>> Players;
		typedef std::vector<std::shared_ptr<Card>> CardList;

	public:
		Game();
		~Game();

		void Init(std::weak_ptr<Game> self);
		void Destroy();

		void AddPlayer(std::shared_ptr<AbstractPlayer> player);
		void PlayCard(std::shared_ptr<Card> card);
		void StartNewRound();
		bool IsRoundFinished() const;
		bool IsPlayable(std::shared_ptr<Card> card);

		const Players& GetPlayers() const;
		const Rule& GetRule() const;
		const CardList& GetCurrentRoundCardList() const;
		int GetCurrentRoundCardCount() const;
		std::shared_ptr<Card> GetWinningCard() const;

	private:
		void DistributeCard();
		void ApplyRole(Card* card);

		std::mt19937 gen;

		std::weak_ptr<Game> self;

		Players players;
		CardList floorCards;
		std::unique_ptr<Round> round;
		std::unique_ptr<Rule> rule;
	};
}