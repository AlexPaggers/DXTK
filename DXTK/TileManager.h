#pragma once

#include <vector>
#include <memory>

class Tile;
class GameData;


class TileManager
{
public:
	TileManager(ID3D11Device * _device, int _height, int _width);
	~TileManager();

	void Tick(GameData* _GD);

	void CreateTiles(ID3D11Device * _device);

	std::vector<Tile*> returnTiles() { return m_tiles; }


private:
	
	std::vector<Tile*> m_tiles;

	int m_boardWidth, m_boardHeight, m_tileSize;

};

