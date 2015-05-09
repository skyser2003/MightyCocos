#pragma once

namespace Mighty
{
	class AbstractPlayer;

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
		Players players;
	};
}