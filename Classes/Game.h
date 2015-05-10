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

		void BroadcastMsg(CardMessage msg, Card* sender);

		void AddPlayer(std::shared_ptr<AbstractPlayer> player);

		const Players& GetPlayers() const;

	private:
		Players players;
	};
}