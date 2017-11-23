
#pragma once

void Engine::InitOpenGL( int argc, char ** argv );

World * Engine::GetWorld() const
{
	return world;
}

SoundEngine * Engine::GetSoundEngine() const
{
	return soundEngine;
}

int Engine::LoadPhysicsBody( const std::string fileName, const std::string name );
int Engine::LoadGraphicBody( const std::string fileName, const std::string name );
int Engine::LoadTexture( const std::string fileName, const std::string name );
int Engine::LoadSound( const std::string fileName, const std::string name );
int Engine::LoadOBJ( const std::string fileName, const std::string name );

StaticActor * Engine::GetPhysicsBody( const std::string name ) const
{
	auto it = physicsBody.find( name );
	if( it != physicsBody.end() )
		return it->second;
	return NULL;
}

GraphicBody * Engine::GetGraphicBody( const std::string name ) const
{
	auto it = graphicBody.find( name );
	if( it != graphicBody.end() )
		return it->second;
	return NULL;
}

Texture * Engine::GetTexture( const std::string name ) const
{
	auto it = texture.find( name );
	if( it != texture.end() )
		return it->second;
	return NULL;
}

ObjectOBJ * Engine::GetOBJ( const std::string name ) const
{
	auto it = obj.find( name );
	if( it != obj.end() )
		return it->second;
	return NULL;
}


void Engine::SetFunctionCustomDrawGUI( FunctionVoidFloat * src )
{
	FunctionCustomDrawGUI = src;
}

void Engine::SetFunctionCustomInput( FunctionVoidFloat * src )
{
	FunctionCustomInput = src;
}

void Engine::MainLoop();

void Engine::Init( int argc, char ** argv, int hostMode );

Engine::Engine()
{
	server = NULL;
	client = NULL;
	
	world = NULL;
	soundEngine = NULL;
	
	name = "";
	
	threadsData = NULL;
	threadsNumber = 0;
	
	framesPerSecond = 0.01f;
	framesCounter = 0;
	lastFramesWereReset = 0;
	
	timeScale = 1.0f;
	deltaTime = 0.01f;		// with timeScale
	
	FunctionCustomDrawGUI = NULL;
	FunctionCustomInput = NULL;
}

Engine::~Engine()
{
	if( server )
	{
		server->Destroy();
		delete server;
		server = NULL;
	}
	if( client )
	{
		client->Destroy();
		delete client;
		client = NULL;
	}
	
	if( world )
	{
		world->Destroy();
		delete world;
		world = NULL;
	}
	
	if( soundEngine )
	{
		soundEngine->Destroy();
		delete soundEngine;
		soundEngine = NULL;
	}
	
	name = "";
	
	for( auto it = physicsBody.begin(); it != physicsBody.end(); *it++ )
	{
		if( it->second )
		{
			it->second->Destroy();
			delete it->second;
			it->second = NULL;
		}
	}
	
	for( auto it = graphicBody.begin(); it != graphicBody.end(); *it++ )
	{
		if( it->second )
		{
			it->second->Destroy();
			delete it->second;
			it->second = NULL;
		}
	}
	
	for( auto it = texture.begin(); it != texture.end(); *it++ )
	{
		if( it->second )
		{
			it->second->Destroy();
			delete it->second;
			it->second = NULL;
		}
	}
	
	for( auto it = obj.begin(); it != obj.end(); *it++ )
	{
		if( it->second )
		{
			it->second->Destroy();
			delete it->second;
			it->second = NULL;
		}
	}
	
	if( threadsData )
	{
		delete[] threadsData;
		threadsData = NULL;
	}
	threadsNumber = 0;
	
	framesPerSecond = 0.0f;
	framesCounter = 0;
	lastFramesWereReset = 0;
	
	timeScale = 0.0f;
	deltaTime = 0.0f;		// with timeScale
	
	FunctionVoidFloat * FunctionCustomDrawGUI;
	FunctionVoidFloat * FunctionCustomInput;
}



