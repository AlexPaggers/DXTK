//
// Game.h
//

#pragma once

#include "StepTimer.h"
#include "GameData.h"
#include "GameObject.h"
#include "Camera.h"
#include "SpriteBatch.h"

#include <vector>
#include <AntTweakBar.h>
#include <String>

class Tile;
class TileManager;

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

	// Callbacks
	void TileManagerSmoothen();
	void TileManagerRecreate();
	void TileManagerSaveLevel();
	void TileManagerLoadLevel();

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext;

    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;

	std::vector<Tile*> m_GameObjects;

	Camera * m_cam;
	TileManager * m_tileManager;

	Tile * t_tile;
	TwBar * m_tweakBar;

	std::unique_ptr<SpriteBatch> m_spriteBatch;

	int m_smoothnessFactor = 1;

	std::string m_loadpath;
	std::string m_savepath = "Level";
};