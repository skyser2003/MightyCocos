#pragma once

namespace Mighty
{
	enum CardMessage;

	class AbstractPlayer;
	class Card;
	class Round;

	class Game
	{
	private:
		typedef std::map<int, std::shared_ptr<AbstractPlayer>> Players;

	public:
		Game();
		~Game();

		void Init();
		void Destroy();

		void AddPlayer(std::shared_ptr<AbstractPlayer> player);
		void PlayCard(std::shared_ptr<Card> card);

		const Players& GetPlayers() const;

	private:
		void DistributeCard();
		void ApplyRole(Card* card);
		void StartNewRound();

		std::mt19937 gen;

		Players players;
		std::vector<std::shared_ptr<Card>> floorCards;
		std::unique_ptr<Round> round;
	};
}