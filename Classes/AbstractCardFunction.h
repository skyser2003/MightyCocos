#pragma once

namespace Mighty
{
	class Card;
	class Game;

	class AbstractCardFunction
	{
	public:
		virtual void OnActivate(bool isFirstCard) = 0;

		void SetCard(Card* card);
		Card* GetCard() const;

	protected:
		Card* card = nullptr;
		Game* game = nullptr;
	};
}