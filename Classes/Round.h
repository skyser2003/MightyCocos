#pragma once

namespace Mighty
{
	class Card;

	class Round final
	{
	public:
		void Init();
		void Destroy();

		void PlayNextCard(std::shared_ptr<Card> nextCard);

	private:
		std::shared_ptr<Card> currentWinningCard;
		std::vector<std::shared_ptr<Card>> cardList;
	};
}