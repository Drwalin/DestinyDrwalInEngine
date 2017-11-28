
#pragma once

#include "directx\D3DWrapper\d3d_wrapper.h"

void Graphic::Init( int argc, char ** argv )
{
	int width = 800, height = 600, bpp, refreshRate;
	D3DWrapper::GetNativeVideoMode( width, height, bpp, refreshRate );
	D3DWrapper::Init( width, height, ALLEGRO_FULLSCREEN );
}

void Graphic::MainLoop()
{
	if( Graphic::engine = NULL )
		return;
	
	float begTime = 0.0f, currentTime = 0.0f, deltaTime = 0.0f;
	
	while( true )
	{
		currentTime = al_get_time();
		
		if( currentTime - begTime < 1.0f / Graphic::maxFps )
			al_rest( (1.0f/Graphic::maxFps) - (currentTime-begTime) );
		currentTime = al_get_time();
		deltaTime = currentTime - begTime;
		begTime = currentTime;
		
		if( deltaTime < 0.001f)
			deltaTime = 0.001f;
		else if( deltaTime > 0.05f )
			deltaTime = 0.05f;
		
		engine->Iteration( deltaTime );	// must includes draw
	}
}

void Graphic::SetEngine( const Engine * engine )
{
	Graphic::engine = engine;
}

void Graphic::SetMaxFps( const float val )
{
	Graphic::maxFps = val;
}



