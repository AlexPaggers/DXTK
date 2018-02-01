#pragma once
#include "GameObject.h"
#include "DDSTextureLoader.h"

class Tile :
	public GameObject
{
public:
	Tile(ID3D11Device * _device);
	~Tile();

	ID3D11ShaderResourceView* GetTexture() { return m_texture.Get(); }

private:
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	ID3D11ShaderResourceView* m_shaderresource;
	D3D11_TEXTURE2D_DESC desc;
};

