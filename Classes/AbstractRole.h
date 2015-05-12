#pragma once

#include "CardRole.h"

namespace Mighty
{
	class Card;

	class AbstractRole
	{
	public:
		template <class RoleClass>
		static std::shared_ptr<AbstractRole> Create()
		{
			AbstractRole* role = new RoleClass();
			role->SetRole(GetRoleType<RoleClass>());
		}

	protected:
		AbstractRole();
		
	public:
		virtual ~AbstractRole() {}

		virtual bool WinAgainst(AbstractRole* otherRole) const = 0;

		void SetCard(std::shared_ptr<Card> card);

		CardRole GetRoleType() const;

	protected:
		CardRole roleType;

		std::shared_ptr<Card> card;

	private:
		void SetRole(CardRole roleType);
	};
}