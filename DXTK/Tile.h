#pragma once
#include "GameObject.h"
#include "DDSTextureLoader.h"
#include "Sprite.h"

class Tile :
	public GameObject
{
public:
	Tile(ID3D11Device * _device);
	~Tile();

	ID3D11ShaderResourceView* GetTexture() { return m_texture.Get(); }

private:
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	
	Sprite * m_sprite;

	D3D11_TEXTURE2D_DESC desc;
};

