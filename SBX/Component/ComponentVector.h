#pragma once
#include "Stdafx.h"

template <typename KeyType, typename DataType, typename ContainerType>
struct ComponentVector
{
	virtual DataType &Find( KeyType id ) = 0;
	virtual ContainerType &GetContainer() = 0;
	virtual void Emplace( KeyType id, DataType &&data ) = 0;
	virtual void Erase( KeyType id ) = 0;
};
