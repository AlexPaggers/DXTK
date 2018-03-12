#include "pch.h"
#include "TileManager.h"
#include <stdlib.h>
#include <time.h>
#include "Tile.h"
#include <fstream>


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

void TileManager::SaveLevel(std::string _savepath)
{
	std::ofstream _saveFile;
	_saveFile.open(_savepath);

	for (int _index = 0; _index < m_tiles.size(); _index++)
	{
		int _tempWidth = m_boardWidth;
		_saveFile << std::to_string(m_tiles[_index]->getTileID());

		if ((_index + 1) % _tempWidth == 0)
		{
			_saveFile << std::endl;
		}
	}

	_saveFile.close();



}

void TileManager::LoadLevel(std::string _loadpath)
{
	std::ifstream _loadFile;
	_loadFile.open("Levels/" + _loadpath + ".txt");
	if (!_loadFile)
	{

	}
	else
	{
		char _ID;
		int i = 0;
		while (_loadFile >> _ID)
		{
			int _IDI = _ID;
			m_tiles[i]->SetTempID(_IDI - 48);
			i++;
		}

		_loadFile.close();

		for (int _index = 0; _index < m_tiles.size(); _index++)
		{
			m_tiles[_index]->UpdateTile();
		}
	}

}

void TileManager::CreateTiles(ID3D11Device * _device)
{
	int _index = 0;

	for (int y = 0; y < m_boardHeight; y++)
	{
		for (int x = 0; x < m_boardWidth; x++)
		{

			float _tempRand = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

			if (_tempRand > 0.3)
			{
				m_tiles.push_back(new Tile(_index , _device, 0.0f, x * m_tileSize, y * m_tileSize));
				_index++;
			}
			else
			{
				m_tiles.push_back(new Tile(_index, _device, 2.0f, x * m_tileSize, y * m_tileSize));
				_index++;
			}
			
		}
	}

	smoothen(10);

}

void TileManager::ReCreateTiles(ID3D11Device * _device)
{
	for (int _index = 0; _index < m_tiles.size(); _index++)
	{
		float _tempRand = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		if (_tempRand < 0.5f)
		{
			m_tiles[_index]->SetTempID(2);
		}
		else
		{
			m_tiles[_index]->SetTempID(0);
		}
		
	}

	for (int _index = 0; _index < m_tiles.size(); _index++)
	{
		m_tiles[_index]->UpdateTile();
	}

	

}

void TileManager::smoothen(int _factor)
{
	for (int _loops = 0; _loops < _factor; _loops++)
	{
		for (int _index = 0; _index < m_tiles.size(); _index++)
		{
			if (_index > m_boardWidth &&
				_index < (m_boardHeight * m_boardWidth) - m_boardWidth 
				&& _index % m_boardWidth != 0 
				&&	_index % m_boardWidth != m_boardWidth - 1
				)
			{
				int _activeSurroundingTiles = 0;

				if (m_tiles[_index - m_boardWidth]->getTileID() != 2) //Checking up
				{
					_activeSurroundingTiles++;
				}

				if (m_tiles[_index - m_boardWidth - 1]->getTileID() != 2) //Checking up - Left
				{
					_activeSurroundingTiles++;
				}

				if (m_tiles[_index - m_boardWidth + 1]->getTileID() != 2) //Checking up - Right
				{
					_activeSurroundingTiles++;
				}

				if (m_tiles[_index + m_boardWidth]->getTileID() != 2) //Checking down
				{
					_activeSurroundingTiles++;
				}

				if (m_tiles[_index + m_boardWidth - 1]->getTileID() != 2) //Checking down - Left
				{
					_activeSurroundingTiles++;
				}

				if (m_tiles[_index + m_boardWidth + 1]->getTileID() != 2) //Checking down - Right
				{
					_activeSurroundingTiles++;
				}

				if (m_tiles[_index - 1]->getTileID() != 2) //Checking left
				{
					_activeSurroundingTiles++;
				}

				if (m_tiles[_index + 1]->getTileID() != 2) //Checking right
				{
					_activeSurroundingTiles++;
				}



				float _tempRand = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

				switch (_activeSurroundingTiles)
				{
				case 0: if (_tempRand < 0.00f)
				{
					m_tiles[_index]->SetTempID(0);
				}
						else
						{
							m_tiles[_index]->SetTempID(2);
						}
						break;
				case 1: if (_tempRand < 0.175f)
				{
					m_tiles[_index]->SetTempID(0);
				}
						else
						{
							m_tiles[_index]->SetTempID(2);
						}
						break;
				case 2: if (_tempRand < 0.25f)
				{
					m_tiles[_index]->SetTempID(0);
				}
						else
						{
							m_tiles[_index]->SetTempID(2);
						}
						break;
				case 3: if (_tempRand < 0.375f)
				{
					m_tiles[_index]->SetTempID(0);
				}
						else
						{
							m_tiles[_index]->SetTempID(2);
						}
						break;
				case 4: if (_tempRand < 0.5f)
				{
					m_tiles[_index]->SetTempID(0);
				}
						else
						{
							m_tiles[_index]->SetTempID(2);
						}
						break;
				case 5: if (_tempRand < 0.675f)
				{
					m_tiles[_index]->SetTempID(0);
				}
						else
						{
							m_tiles[_index]->SetTempID(2);
						}
						break;
				case 6: if (_tempRand < 0.75f)
				{
					m_tiles[_index]->SetTempID(0);
				}
						else
						{
							m_tiles[_index]->SetTempID(2);
						}
						break;
				case 7: if (_tempRand < 0.825f)
				{
					m_tiles[_index]->SetTempID(0);
				}
						else
						{
							m_tiles[_index]->SetTempID(2);
						}
						break;
				case 8: if (_tempRand < 1.0f)
				{
					m_tiles[_index]->SetTempID(0);
				}
						else
						{
							m_tiles[_index]->SetTempID(2);
						}
						break;

				}
			}

		}
	}

	for (int _index = 0; _index < m_tiles.size(); _index++)
	{
		m_tiles[_index]->UpdateTile();
	}

}
