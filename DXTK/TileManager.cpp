#include "pch.h"
#include "TileManager.h"
#include <stdlib.h>
#include <time.h>
#include "Tile.h"


TileManager::TileManager(ID3D11Device * _device, int _height, int _width)
{
	srand(time(nullptr));
	
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
	for (int y = 0; y < m_boardHeight; y++)
	{
		for (int x = 0; y < m_boardWidth; x++)
		{
			m_tiles.push_back(new Tile(_device, 1.0f, x * m_tileSize, y * m_tileSize));
		}
	}
}
