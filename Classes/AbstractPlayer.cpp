#include "stdafx.h"
#include "AbstractPlayer.h"

namespace Mighty
{
	int AbstractPlayer::GetID() const
	{
		return id;
	}

	const std::string& AbstractPlayer::GetName() const
	{
		return name;
	}

	void AbstractPlayer::SetBasicInfo(int id, const std::string& name)
	{
		this->id = id;
		this->name = name;
	}
}