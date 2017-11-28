
#pragma once

#include "full.hpp"

bool allegro_full_init();

class D3DWrapper
{
	static ALLEGRO_BITMAP * c_icon;
	static ALLEGRO_DISPLAY * display;
public:
	
	static ALLEGRO_BITMAP * AllegroBackbuffer();
	static ALLEGRO_DISPLAY * AllegroDisplay();
	static IDirect3DDevice9 * D3DDev();
	
	static void Init( int w, int h, int fullscreen );
	
	static bool CreateDisplay( int w, int h, int fullscreen );
	static bool CreateDisplay( int w, int h, int bpp, int fullscreen );
	static bool CreateDisplay( int w, int h, int bpp, int refresh, int fullscreen );
	
	static bool SetWindowPos( int x, int y );
	static bool SetWindowIcon( ALLEGRO_BITMAP * bmp );
	static bool SetWindowIcon( const char * bmpPath );
	static bool SetWindowTitle( const char * title );
	
	static void GetNativeVideoMode( int & x, int & y, int & bpp, int & refreshRate );
	
	static void Destroy();
};

#pragma once

