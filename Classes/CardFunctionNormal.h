#pragma once

#include "AbstractCardFunction.h"

namespace Mighty
{
	class CardFunctionNormal final : public AbstractCardFunction
	{
	public:
		virtual void OnActivate(bool isFirstCard) override;
		virtual bool IsPlayable(CardSuit currentSuit) override;
	};
}