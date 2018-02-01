#include "pch.h"
#include "Tile.h"
#include "DDSTextureLoader.h"

Tile::Tile(ID3D11Device * _device)
{
	HRESULT hr = DirectX::CreateDDSTextureFromFile(_device, L"../Textures/testimage.dds", nullptr, &m_shaderresource);

	ID3D11Resource* r;
	m_shaderresource->GetResource(&r);
	static_cast<ID3D11Texture2D*>(r)->GetDesc(&desc);

	m_texture
}


Tile::~Tile()
{
	m_texture.Reset();
}
