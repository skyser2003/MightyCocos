#pragma once

namespace Mighty
{
	enum CardMessage;

	class AbstractPlayer;
	class Card;

	class Game
	{
	private:
		typedef std::map<int, std::shared_ptr<AbstractPlayer>> Players;

	public:
		void Init();
		void Destroy();

		void AddPlayer(std::shared_ptr<AbstractPlayer> player);

		const Players& GetPlayers() const;

	private:
		void DistributeCard();

		std::mt19937 gen;

		Players players;
	};
}