#pragma once
#include "ComponentVector.h"

template <typename KeyType, typename DataType>
struct MapComponentVector: ComponentVector<KeyType, DataType, std::unordered_map<KeyType, DataType>>
{
	MapComponentVector()
	{
		Data.reserve( 1000 );
	}

	DataType &Find( KeyType id ) override
	{
		return Data.find( id )->second;
	}

	void Add( KeyType id ) override
	{
		Data.emplace( std::pair<KeyType, DataType>( id, DataType() ) );
	}

	void Remove( KeyType id ) override
	{
		Data.erase( id );
	}

	std::unordered_map<KeyType, DataType> &GetContainer() override
	{
		return Data;
	}

private:
	std::unordered_map<KeyType, DataType> Data;
};