#pragma once
#include "GameObject.h"
#include "DDSTextureLoader.h"
#include <memory>


class Sprite;

enum TileID
{
	GRASS = 0,
	ROCK = 1,
	WATER = 2,
	TREE = 3,

};

class Tile :
	public GameObject
{
public:
	Tile(int _index, ID3D11Device * _device, int _tileID, float _posX, float _posY);
	~Tile();

	void CreateSprite(ID3D11Device * _device);

	int getTileID() { return m_tileID; }

	ID3D11ShaderResourceView* GetTexture();

private:
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	
	Sprite * m_sprite;


	int m_tileID, m_index;

	D3D11_TEXTURE2D_DESC desc;
};

