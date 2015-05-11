#pragma once

namespace Mighty
{
	class NormalRole;
	class MightyRole;
	class JokerRole;
	class JokerCallRole;

	enum CardRole
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
	class GetRoleClass < Normal >
	{
	public:
		typedef NormalRole Class;
	};

	template <>
	class GetRoleClass < Mighty >
	{
	public:
		typedef MightyRole Class;
	};

	template <>
	class GetRoleClass < Joker >
	{
	public:
		typedef JokerRole Class;
	};

	template <>
	class GetRoleClass < JokerCall >
	{
	public:
		typedef JokerCallRole Class;
	};
}