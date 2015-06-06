#pragma once

namespace Mighty
{
	class NormalRole;
	class MightyRole;
	class JokerRole;
	class JokerCallRole;

	enum class CardRole
	{
		Normal,
		Mighty,
		Joker,
		JokerCall
	};

	template <class RoleClass>
	CardRole GetRoleType();

	// Declaration only
	template <CardRole type>
	class GetRoleClass;

	template <>
	class GetRoleClass < CardRole::Normal >
	{
	public:
		typedef NormalRole Class;
	};

	template <>
	class GetRoleClass < CardRole::Mighty >
	{
	public:
		typedef MightyRole Class;
	};

	template <>
	class GetRoleClass < CardRole::Joker >
	{
	public:
		typedef JokerRole Class;
	};

	template <>
	class GetRoleClass < CardRole::JokerCall >
	{
	public:
		typedef JokerCallRole Class;
	};
}