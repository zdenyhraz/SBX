#pragma once
#include "Stdafx.h"

template <typename KeyType, typename DataType, typename ContainerType>
struct ComponentVector
{
	virtual DataType &Find( KeyType id ) = 0;
	virtual ContainerType &GetContainer() = 0;
	virtual void Add( KeyType id ) = 0;
	virtual void Remove( KeyType id ) = 0;
};
