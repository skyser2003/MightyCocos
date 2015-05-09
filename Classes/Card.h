#pragma once

namespace Mighty
{
	enum CardRank;

	class AbstractPlayer;
	class AbstractCardFunction;

	class Card
	{
	public:
		void Init(AbstractPlayer* player, CardRank rank);

		void AddCardFunction(std::shared_ptr<AbstractCardFunction> cardFunc);

		CardRank GetRank() const;
		AbstractPlayer* GetPlayer() const;

	private:
		CardRank rank;

		AbstractPlayer* player = nullptr;
		std::vector<std::shared_ptr<AbstractCardFunction>> cardFuncList;
	};
}