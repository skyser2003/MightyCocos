#pragma once

#include "AbstractPlayer.h"

namespace Mighty
{
	class HumanPlayer : public AbstractPlayer
	{
	public:
		virtual void PlayTurn() override;

		void Init(int id, const std::string& name);
	};
}