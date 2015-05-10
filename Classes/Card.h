#pragma once

namespace Mighty
{
	enum CardSuit;
	enum CardRank;
	enum CardRole;

	class AbstractPlayer;
	class AbstractCardFunction;

	class Card
	{
	public:
		void Init(AbstractPlayer* player, CardRank rank);

		void AddCardFunction(std::shared_ptr<AbstractCardFunction> cardFunc);
		bool IsPlayable(CardSuit currentSuit) const;

		CardSuit GetSuit() const;
		CardRank GetRank() const;
		AbstractPlayer* GetPlayer() const;

	private:
		CardRank rank;
		CardRole role;

		AbstractPlayer* player = nullptr;
		std::vector<std::shared_ptr<AbstractCardFunction>> cardFuncList;
	};
}