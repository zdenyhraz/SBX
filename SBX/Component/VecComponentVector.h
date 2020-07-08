#pragma once
#include "ComponentVector.h"

template <typename KeyType, typename DataType>
struct VecComponentVector : ComponentVector<KeyType, DataType>
{
public:
	VecComponentVector()
	{
		Data.reserve( 1000 );
	}

	DataType &Find( KeyType id ) override
	{

	}

	void Emplace( KeyType id, DataType &&data ) override
	{
		Data.emplace( std::pair<KeyType, DataType>( id, data ) );
	}

	void Erase( KeyType id ) override
	{

	}

private:
	std::vector<std::pair<KeyType, DataType>> Data;

	int FindIdx( KeyType id )
	{
		for ( int i = 0; i < Data.size(); i++ )
		{
			if ( Data[i].first == id )
			{
				return i;
			}
		}
		return -1;
	}
};