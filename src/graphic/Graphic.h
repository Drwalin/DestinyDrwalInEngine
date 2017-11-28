
#pragma once

class Graphic
{
private:
	
	static Engine * engine = NULL;
	static float maxFps = 60.0f;
	
public:
	
	static void Init( int argc, char ** argv );
	static void MainLoop();
	
	static void SetEngine( const Engine * engine );
	static void SetMaxFps( const float val );
	
};



