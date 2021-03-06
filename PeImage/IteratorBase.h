#pragma once
#include <iterator>
#include "CategoryPolicy.h"
template<
	typename TIterator,
	typename TCategory,
	typename TValueType,
	typename TDiff = ptrdiff_t,
	typename TPointer = TValueType *,
	typename TReference = TValueType&>
	struct IteratorBase :
	public CategoryPolicy<TIterator, TCategory, TValueType, TDiff, TPointer, TReference>,
	public _STD iterator<TCategory, TValueType, TDiff, TPointer, TReference>
{
	typedef TIterator TIterator;
/*
	没怎么检查，可能有错

	在子类friend IteratorFriendAccess;

	根据选择的tag实现对应的接口
	隐式接口为：
	bool Equal(const TIterator & val) const
	{
	}
	void Increment()
	{
	}
	void Decrement()
	{
	}
	void Advance(int n)
	{
	}
	difference_type DistanceTo(const TIterator & val) const
	{
	}
	reference Dereference()
	{
	}
	reference Dereference() const
	{
	}
*/
};