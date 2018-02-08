#include "Sprite.h"
#include <DDSTextureLoader.h>

Sprite::Sprite(const wchar_t* _file_name, ID3D11Device* _d3d_device)
{
	HRESULT hr = DirectX::CreateDDSTextureFromFile(_d3d_device, _file_name, nullptr, &m_sprite_rv);

	// Find size of image.
	ID3D11Resource *pResource;
	m_sprite_rv->GetResource(&pResource);
	static_cast<ID3D11Texture2D*>(pResource)->GetDesc(&m_desc);
}


Sprite::~Sprite()
{
	if (m_sprite_rv)
	{
		m_sprite_rv->Release();
		m_sprite_rv = nullptr;
	}
}


ID3D11ShaderResourceView* Sprite::getResourceView() const
{
	return m_sprite_rv;
}


int Sprite::getWidth() const
{
	return m_desc.Width;
}


int Sprite::getHeight() const
{
	return m_desc.Height;
}