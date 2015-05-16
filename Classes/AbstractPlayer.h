#pragma once

namespace Mighty
{
	enum CardMessage;

	class Game;
	class Card;

	class AbstractPlayer
	{
	private:
		typedef std::vector<std::shared_ptr<Card>> CardList;

	public:
		~AbstractPlayer();

		virtual void PlayTurn() = 0;

		void SetGame(std::shared_ptr<Game> game);

		void AddCard(std::shared_ptr<Card> card);

		std::shared_ptr<Game> GetGame() const;
		int GetID() const;
		const std::string& GetName() const;
		const CardList& GetCardList() const;

	protected:
		void SetBasicInfo(int id, const std::string& name);

	private:
		std::shared_ptr<Game> game = nullptr;

		int id;
		std::string name;

		CardList cardList;
	};
}