#pragma once
#include "Stdafx.h"

template <typename T>
class ComponentVector
{
public:
	ComponentVector()
	{
		Data.reserve( 1000 );
	}

	T &Find( int id )
	{
		return Data.find( id )->second;
	}

	std::unordered_map<int, T> Data;

private:

};