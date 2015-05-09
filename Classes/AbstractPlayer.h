#pragma once

namespace Mighty
{
	class Game;

	class AbstractPlayer
	{
	public:
		virtual void PlayTurn() = 0;

		void SetGame(std::shared_ptr<Game> game);

		std::shared_ptr<Game> GetGame() const;
		int GetID() const;
		const std::string& GetName() const;

	protected:
		void SetBasicInfo(int id, const std::string& name);

	private:
		std::shared_ptr<Game> game = nullptr;

		int id;
		std::string name;
	};
}