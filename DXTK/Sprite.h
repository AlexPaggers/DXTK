#pragma once
#include <d3d11_1.h>

class Sprite
{
public:
	Sprite(const wchar_t* _filename, ID3D11Device* _device);
	~Sprite();

	ID3D11ShaderResourceView* getResourceView() const;
	int getWidth() const;
	int getHeight() const;

private:
	ID3D11ShaderResourceView* m_sprite_rv;
	D3D11_TEXTURE2D_DESC m_desc;

};