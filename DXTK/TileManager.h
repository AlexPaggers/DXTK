#pragma once

#include <vector>
#include <memory>
#include <fstream>
#include <string>


class Tile;
class GameData;


class TileManager
{
public:
	TileManager(ID3D11Device * _device, int _height, int _width);
	~TileManager();

	void Tick(GameData* _GD);


	void SaveLevel(std::string _savepath);
	void LoadLevel(std::string _loadpath);
	void CreateTiles(ID3D11Device * _device);
	void ReCreateTiles(ID3D11Device * _device);

	std::vector<Tile*> returnTiles() { return m_tiles; }

	void smoothen(int _factor);


private:

	std::vector<Tile*> m_tiles;

	int m_boardWidth, m_boardHeight, m_tileSize = 8;

};

