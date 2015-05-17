#pragma once

namespace Mighty
{
	class Rule
	{
	public:
		Rule();

		void SetPlayerCount(int count);

		int GetPlayerCount() const;
	private:
		int playerCount;
	};
}