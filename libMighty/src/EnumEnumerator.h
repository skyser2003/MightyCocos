#pragma once

template <class Enum>
class EnumIterator
{
public:
	EnumIterator()
	{

	}

	EnumIterator(Enum val)
	{
		this->val = val;
	}

	bool operator !=(const EnumIterator& rhs)
	{
		return val != rhs.val;
	}

	Enum operator++()
	{
		return val = static_cast<Enum>(std::underlying_type<Enum>::type(val) + 1);
	}

	Enum operator*()
	{
		return val;
	}

private:
	Enum val;
};

template <class Enum, Enum first, Enum last>
class EnumEnumerator
{
public:
	EnumIterator<Enum> begin() const
	{
		return first;
	}

	EnumIterator<Enum> end() const
	{
		return static_cast<Enum>(std::underlying_type<Enum>::type(last) + 1);
	}
};