#include "pch.h"
#include "Tile.h"
#include "DDSTextureLoader.h"
#include "Sprite.h"
#include <string>

Tile::Tile(int _index, ID3D11Device * _device, int _tileID, float _posX, float _posY)
{
	m_pos.x = _posX;
	m_pos.y = _posY;

	m_tileID = _tileID;

	CreateSprite(_device);

}


Tile::~Tile()
{
	m_texture.Reset();
	m_sprite = nullptr;
	delete m_sprite;

}

void Tile::CreateSprite(ID3D11Device * _device)
{
	//std::wstring _filepath = (L"Textures/" + std::to_wstring(m_tileID) + L".dds");

	std::wstring _filepath = (L"Textures/" + std::to_wstring(0) + L".dds");
	
	m_sprite = new Sprite(_filepath.c_str(), _device);

}

ID3D11ShaderResourceView * Tile::GetTexture()
{
	return m_sprite->getResourceView();

}
