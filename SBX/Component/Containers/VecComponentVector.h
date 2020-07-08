#pragma once
#include "ComponentVector.h"

template <typename KeyType, typename DataType>
struct VecComponentVector : ComponentVector<KeyType, DataType, std::vector<std::pair<KeyType, DataType>>>
{
	VecComponentVector()
	{
		Data.reserve( 1000 );
	}

	DataType &Find( KeyType id ) override
	{
		return Data[FindIdx( id )].second;
	}

	void Add( KeyType id, DataType &&data ) override
	{
		Data.emplace_back( std::pair<KeyType, DataType>( id, std::move( data ) ) );
	}

	void Remove( KeyType id ) override
	{
		int idx = FindIdx( id );
		if ( idx >= 0 )
		{
			Data.erase( Data.begin() + idx );
		}
	}

	std::vector<std::pair<KeyType, DataType>> &GetContainer() override
	{
		return Data;
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