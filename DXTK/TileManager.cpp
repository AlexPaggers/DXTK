#include "pch.h"
#include "TileManager.h"
#include <stdlib.h>
#include <time.h>
#include "Tile.h"


TileManager::TileManager(ID3D11Device * _device, int _height, int _width)
{
	srand(time(NULL));
	
	m_boardHeight	= _height;
	m_boardWidth	= _width;

	m_tiles.reserve(m_boardHeight*m_boardWidth);

	CreateTiles(_device);


}


TileManager::~TileManager()
{
}

void TileManager::CreateTiles(ID3D11Device * _device)
{
	int _index = 0;

	for (int y = 0; y < m_boardHeight; y++)
	{
		for (int x = 0; x < m_boardWidth; x++)
		{

			float _tempRand = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

			if (_tempRand > 0.5)
			{
				m_tiles.push_back(new Tile(_index , _device, 0.0f, x * m_tileSize, y * m_tileSize));
				_index++;
			}
			
		}
	}
}

void TileManager::smoothen(int _factor)
{
	for (auto& tile : m_tiles)
	{
		delete tile;
		tile = nullptr;
	}
}
