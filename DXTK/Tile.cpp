#include "pch.h"
#include "Tile.h"
#include "DDSTextureLoader.h"
#include "Sprite.h"

Tile::Tile(ID3D11Device * _device)
{
	
}


Tile::~Tile()
{
	m_texture.Reset();
	m_sprite = nullptr;
	delete m_sprite;
}

void Tile::CreateSprite(ID3D11Device * _device)
{
	m_sprite = new Sprite((L"D:/DXTK/DXTK/Textures/testimage.dds"), _device);
}

ID3D11ShaderResourceView * Tile::GetTexture()
{
	return m_sprite->getResourceView();
}
