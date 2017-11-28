
#pragma once

#include "a5\init.cpp"

ALLEGRO_DISPLAY* D3DWrapper::AllegroDisplay()
{
	return display;
}

ALLEGRO_BITMAP* D3DWrapper::AllegroBackbuffer()
{
	return al_get_backbuffer( display );
}

IDirect3DDevice9* D3DWrapper::D3DDev()
{
	return al_get_d3d_device( display );
}

bool D3DWrapper::CreateDisplay( int w, int h, int bpp, int refresh, int fullscreen )
{
	switch( fullscreen )
	{
	case ALLEGRO_WINDOWED:
	case ALLEGRO_FULLSCREEN:
	case ALLEGRO_FULLSCREEN_WINDOW:
		al_set_new_display_flags( fullscreen );
		break;
	default:
		al_set_new_display_flags( ALLEGRO_WINDOWED );
	}
	al_set_new_display_refresh_rate( refresh );
	al_set_new_display_option( ALLEGRO_COLOR_SIZE, bpp, ALLEGRO_SUGGEST );
	display = al_create_display( w, h );
	
	return display;
}

bool D3DWrapper::CreateDisplay( int w, int h, int bpp, int fullscreen )
{
	return CreateDisplay( w, h, bpp, al_get_new_display_refresh_rate(), fullscreen );
}

bool D3DWrapper::CreateDisplay( int w, int h, int fullscreen )
{
	return CreateDisplay(w, h, 32, fullscreen);
}

bool D3DWrapper::SetWindowPos( int x, int y )
{
	if( !display )
		return false;
	al_set_window_position( display, x, y );
	return true;
}

bool D3DWrapper::SetWindowIcon( ALLEGRO_BITMAP* bitmap )
{
	if( !bitmap )
		return false;
	al_set_display_icon( display, bitmap );
	return true;
}

bool D3DWrapper::SetWindowIcon(const char* bmpPath)
{
	c_icon = al_load_bitmap( bmpPath );
	return SetWindowIcon( c_icon );
}

bool D3DWrapper::SetWindowTitle( const char* title )
{
	al_set_window_title( display, title );
}

void D3DWrapper::GetNativeVideoMode( int & x, int & y, int & bpp, int & refreshRate )
{
	ALLEGRO_MONITOR_INFO info;
	al_get_monitor_info( 0, &info );
	x = info.x2-info.x1;
	y = info.y2-info.y1;
	bpp = 32;
	refreshRate = al_get_new_display_refresh_rate();
}

void D3DWrapper::Init( int w, int h, int fullscreen )
{
	display = NULL;
	c_icon = NULL;
	
	allegro_full_init();
	al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 32, ALLEGRO_SUGGEST);
	
	CreateDisplay( w, h, fullscreen );
	
	D3DDev()->SetRenderState( D3DRS_LIGHTING, false );    					// turn off the 3D lighting
    D3DDev()->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );				// both sides of the triangles
    D3DDev()->SetRenderState( D3DRS_ZENABLE,  true );						// turn on the z-buffer
	D3DDev()->SetRenderState( D3DRS_ALPHABLENDENABLE, true );
	D3DDev()->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	D3DDev()->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	D3DDev()->SetTextureStageState( 0, D3DTSS_ALPHAOP, D3DTOP_MODULATE );
}

static void D3DWrapper::Destroy()
{
	if( c_icon )
		al_destroy_bitmap( c_icon );
	if( display )
		al_destroy_display( display );
}



