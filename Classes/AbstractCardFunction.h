#pragma once

namespace Mighty
{
	enum CardSuit;
	enum CardMessage;

	class Card;
	class Game;

	class AbstractCardFunction
	{
	public:
		virtual void OnActivate(bool isFirstCard) = 0;
		virtual bool IsPlayable(CardSuit currentSuit) = 0;

		void SendMsg(CardMessage msg, Card* sender);

		void SetCard(Card* card);
		
		Card* GetCard() const;

	protected:
		Card* card = nullptr;
		Game* game = nullptr;
	};
}