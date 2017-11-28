
#pragma once


bool Engine::GetDebug() const
{
	return debug;
}

void Engine::SetDebug( const bool debug )
{
	this->debug = debug;
}

World * Engine::GetWorld() const
{
	return world;
}

SoundEngine * Engine::GetSoundEngine() const
{
	return soundEngine;
}

void Engine::CallFunctionCustomDrawGUI()
{
	if( FunctionCustomDrawGUI )
		FunctionCustomDrawGUI( deltaTime );
}

void Engine::CallFunctionCustomInput( const float deltaTime )
{
	if( FunctionCustomInput )
		FunctionCustomInput( deltaTime );
}

int Engine::LoadPhysicsBody( const std::string fileName, const std::string name );///////////////////////////////////////////////////////////////////////////////////////////////////////
int Engine::LoadGraphicBody( const std::string fileName, const std::string name );///////////////////////////////////////////////////////////////////////////////////////////////////////
int Engine::LoadOBJ( const std::string fileName, const std::string name );///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Engine::LoadTexture( const std::string fileName, const std::string name )
{
	Texture ** texture = &(this->texture[name]);
	if( texture )
	{
		if( *texture == NULL )
			*texture = new Texture;
		if( (*texture)->Load( fileName, name, Texture::Linear, 1 ) )
		{
			return 1;
		}
		else
		{
			delete *texture;
			this->texture.erase( "name" );
			return 0;
		}
	}
	else
	{
		this->texture.erase( "name" );
	}
	return 0;
}

int Engine::LoadSound( const std::string fileName, const std::string name )
{
	AddSound( fileName, name );
}

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

void Engine::DestroyPhysicsBody( const std::string name )
{
	auto it = physicsBody.find( name );
	if( it != physicsBody.end() )
	{
		it->second->Destroy();
		delete it->second;
		physicsBody.erase( it );
	}
}

void Engine::DestroyGraphicBody( const std::string name )
{
	auto it = graphicBody.find( name );
	if( it != graphicBody.end() )
	{
		it->second->Destroy();
		delete it->second;
		graphicBody.erase( it );
	}
}

void Engine::DestroyTexture( const std::string name )
{
	auto it = texture.find( name );
	if( it != texture.end() )
	{
		it->second->Destroy();
		delete it->second;
		texture.erase( it );
	}
}

void Engine::DestroyOBJ( const std::string name )
{
	auto it = obj.find( name );
	if( it != obj.end() )
	{
		it->second->Destroy();
		delete it->second;
		obj.erase( it );
	}
}
void Engine::DestroySound( const std::string name );/////////////////////////////////////////////////////////////////////

void Engine::SetFunctionCustomDrawGUI( FunctionVoidFloat * src )
{
	FunctionCustomDrawGUI = src;
}

void Engine::SetFunctionCustomInput( FunctionVoidFloat * src )
{
	FunctionCustomInput = src;
}

void Engine::Iteration( const float deltaTime )/////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	if( !world )
		return;
	
	this->deltaTime = deltaTime;
	
	world->Update( deltaTime );
	
	Render();
	
	if( soundEngine && world->GetMainCamera() )
		soundEngine->Update( world->GetMainCamera()->GetPos(), world->GetMainCamera()->GetForwardVector(), world->GetMainCamera()->GetUpVector() );
	
	//////////////////////
	// Update by server //
	//  Update clients  //
	//////////////////////
	switch( hostMode )
	{
	case HostClient:
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		break;
	case HostServer:
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		break;
	}
}

void Engine::Render()
{
	if( world && D3DWrapper::D3DDev() )
	{
		D3DWrapper::D3DDev()->Clear( 0, NULL, D3DCLEAR_TARGET,  D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0 );
		D3DWrapper::D3DDev()->Clear( 0, NULL, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0 );
		D3DWrapper::D3DDev()->BeginScene();
		
		if( world->GetMainCamera() )
			world->GetMainCamera()->SetView();
		
		world->Draw();
		
		CallFunctionCustomDrawGUI();
		
		D3DWrapper::D3DDev()->EndScene();
		D3DWrapper::D3DDev()->Present( NULL, NULL, NULL, NULL );
	}
}

int Engine::Init( int argc, char ** argv, int hostMode, const AABB aabbWorld = AABB(Vector(-10000,-10000,-10000), Vector(10000,10000,10000)), const std::string name, const std:string worldName, const unsigned int frequencyParticleUpdate = 3 )///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	Graphic::Init( argc, argv );
	Graphic::SetEngine( this );
	Destroy();
	
	switch( hostMode )
	{
	case HostClient:
		///////////////////////////////////////////////////////////////////////////////////////////////////////
		break;
	case HostServer:
		///////////////////////////////////////////////////////////////////////////////////////////////////////
		break;
	case HostNone:
	default:
		//server = NULL;
		//client = NULL;
	}
	
	this->name = name;
	
	world = new World();
	world->Init( aabbWorld, worldName, this, frequencyParticleUpdate );
}

void Engine::Destroy()
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
	physicsBody.clear();
	
	for( auto it = graphicBody.begin(); it != graphicBody.end(); *it++ )
	{
		if( it->second )
		{
			it->second->Destroy();
			delete it->second;
			it->second = NULL;
		}
	}
	graphicBody.clear();
	
	for( auto it = texture.begin(); it != texture.end(); *it++ )
	{
		if( it->second )
		{
			it->second->Destroy();
			delete it->second;
			it->second = NULL;
		}
	}
	texture.clear();
	
	for( auto it = obj.begin(); it != obj.end(); *it++ )
	{
		if( it->second )
		{
			it->second->Destroy();
			delete it->second;
			it->second = NULL;
		}
	}
	obj.clear();
	
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
	deltaTime = 0.0f;
}

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
	Destroy();
	FunctionCustomDrawGUI = NULL;
	FunctionCustomInput = NULL;
}



