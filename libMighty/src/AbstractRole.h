#pragma once

#include "CardRole.h"

namespace Mighty
{
	class Card;

	class AbstractRole
	{
	protected:
		AbstractRole();
		
	public:
		virtual ~AbstractRole();

		void SetCard(std::shared_ptr<Card> card);

		CardRole GetRoleType() const;

	protected:
		CardRole roleType;
		std::shared_ptr<Card> card;

		void SetRole(CardRole roleType);
	};

	template <class ChildClass>
	class CRTPRole : public AbstractRole
	{
	protected:
		CRTPRole()
		{
			SetRole(Mighty::GetRoleType<ChildClass>());
		}

		virtual ~CRTPRole()
		{
		}
	};
}