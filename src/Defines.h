
#pragma once

#ifndef	DEVELOPMENT_DEBUG_ENABLE
#define		DEBUG(debugArgument)	{	printf( "\n Debug: %s", debugArgument );	getch();	}
#elif
#define		DEBUG(debugArgument)
#endif

enum WebEngine
{
	ENGINE_SERFVER_NONE,
	ENGINE_SERVER_HOST,
	ENGINE_SERVER_CLIENT
};



