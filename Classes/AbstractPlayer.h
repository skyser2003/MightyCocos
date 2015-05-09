#pragma once

namespace Mighty
{
	class AbstractPlayer
	{
	public:
		virtual void PlayTurn() = 0;

		int GetID() const;
		const std::string& GetName() const;

	protected:
		void SetBasicInfo(int id, const std::string& name);

	private:
		int id;
		std::string name;
	};
}