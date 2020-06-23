#pragma once
#include "Stdafx.h"

template <typename DataType, class ContainerType = std::unordered_map<int, DataType>>
struct ComponentVector
{
	ComponentVector()
	{
		Data.reserve( 1000 );
	}

	DataType &Find( int id )
	{
		return Data.find( id )->second;
	}

	ContainerType Data;
};
