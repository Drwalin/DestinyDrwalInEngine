
#pragma once

#include "Sounds.cpp"

void World::Init( const AABB aabb, const std::string name, Engine * engine, const unsigned int frequencyParticleUpdate )
{
	this->name = name;
	if( collider == NULL )
		collider = new Collider;
	collider->Init( aabb, Math::Log( (unsigned long long int)2, (unsigned long long int)((aabb.GetMin()-aabb.GetMax()).Length()) ), this );
	this->engine = engine;
	if( pointParticle == NULL )
		pointParticle = new PointParticle;
	pointParticle->Init( frequencyParticleUpdate );
	if( navMeshParent == NULL )
		navMeshParent = new NavMeshParent;
	navMeshParent->Init( 0.4f, 20.0f );
}

PointParticle * World::ParticleSpawner()
{
	return pointParticle;
}

Camera * World::SpawnCamera( const std::string name, const Vector pos, const Vector rotation, const float fov, const float zNear, const float zFar, const int TextureWidth, const int textureHeight )/////////////////////////////////////////////
{
	Camera ** camera = &(this->camera[name]);
	if( camera )
	{
		if( *camera == NULL )
			*camera = new Camera;
		(*camera)->Init( name, pos, rotation, fov, zFar, zNear, TextureWidth, textureHeight );
		return *camera;
	}
	else
	{
		this->camera.erase( "name" );
	}
	return NULL;
}

Light * World::SpawnLight( const std::string name, const Vector pos, const Vector rotation, const float fov, const float zNear, const float zFar, const int lightMapWidth, const int lightMapHeight );/////////////////////////////////////////////
Actor * World::SpawnStaticActor( const std::string name, const std::string graphicBodyName, const std::string physicsBodyName );///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Actor * World::SpawnDynamicActor( const std::string name, const std::string graphicBodyName )
{
	if( engine )
	{
		Actor ** actor = &(this->camera[name]);
		if( actor )
		{
			if( *actor == NULL )
				*actor = new DynamicActor;
			(*actor)->Init( name, engine->GetGraphicBody( graphicBodyName ) );
			return *actor;
		}
		else
		{
			this->actor.erase( "name" );
		}
	}
	return NULL;
}

Actor * World::SpawnTriggerVolumeActor( const std::string name, const Vector pos, const Vector size );/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Actor * World::SpawnActorByTemplate( const Actor * src, const std::string name );//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
NavMesh * World::SpawnNavMesh( const std::string name );///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

NavMesh * World::GetNavMesh( const std::string name ) const
{
	auto it = navMesh.find( name );
	if( it != navMesh.end() )
		return it->second;
	return NULL;
}

Camera * World::GetCamera( const std::string name ) const
{
	auto it = camera.find( name );
	if( it != camera.end() )
		return it->second;
	return NULL;
}

Light * World::GetLight( const std::string name ) const
{
	auto it = light.find( name );
	if( it != light.end() )
		return it->second;
	return NULL;
}

Actor * World::GetActor( const std::string name ) const
{
	auto it = actor.find( name );
	if( it != actor.end() )
		return it->second;
	return NULL;
}

NavMeshParent * World::GetNavMeshParent() const
{
	return navMeshParent;
}

void World::GetActors( const AABB aabb, std::map < Actor*, bool > & actors ) const
{
	if( collider )
		collider->GetActor( aabb, actors );
}

void World::GetActors( const AABB aabb, std::map < Actor*, AABB > & actors ) const
{
	if( collider )
		collider->GetActor( aabb, actors );
}

void World::SetMainCamera( const Camera * camera )
{
	this->mainCamera = camera;
}

Camera * World::GetMainCamera() const
{
	return this->mainCamera;
}

float World::GetDeltaTime() const
{
	return deltaTime;
}

float World::GetTimeScale() const
{
	return timeScale;
}

void World::SetTimeScale( const float val )
{
	if( val > World::MinimumTimeScale )
		timeScale = val;
}

void World::DestroyNavMesh( const std::string name )
{
	auto it = navMesh.find( name );
	if( it != navMesh.end() )
	{
		it->second->Destroy();
		delete it->second;
		navMesh.erase( it );
	}
}

void World::DestroyCamera( const std::string name )
{
	auto it = camera.find( name );
	if( it != camera.end() )
	{
		it->second->Destroy();
		delete it->second;
		camera.erase( it );
	}
}

void World::DestroyLight( const std::string name )
{
	auto it = light.find( name );
	if( it != light.end() )
	{
		it->second->Destroy();
		delete it->second;
		light.erase( it );
	}
}

void World::DestroyActor( const std::string name )
{
	auto it = actor.find( name );
	if( it != actor.end() )
	{
		if( collider )
			collider->DeleteActor( it->second );
		it->second->Destroy();
		delete it->second;
		actor.erase( it );
	}
}





















void World::PausePhysics()
{
	physicsPaused = true;
}

void World::StartPhysics()
{
	physicsPaused = false;
}

void World::PauseGraphic()
{
	graphicPaused = true;
}

void World::StartGraphic()
{
	graphicPaused = false;
}

void World::Destroy()
{
	mainCamera = NULL;
	
	engine = NULL;
	
	name = "";
	
	for( auto it = actor.begin(); it != actor.end(); *it++ )
	{
		if( it->second )
		{
			it->second->Destroy();
			delete it->second;
			it->second = NULL;
		}
	}
	actor.clear();
	
	for( auto it = camera.begin(); it != camera.end(); *it++ )
	{
		if( it->second )
		{
			it->second->Destroy();
			delete it->second;
			it->second = NULL;
		}
	}
	camera.clear();
	
	for( auto it = light.begin(); it != light.end(); *it++ )
	{
		if( it->second )
		{
			it->second->Destroy();
			delete it->second;
			it->second = NULL;
		}
	}
	light.clear();
	
	for( auto it = navMesh.begin(); it != navMesh.end(); *it++ )
	{
		if( it->second )
		{
			it->second->Destroy();
			delete it->second;
			it->second = NULL;
		}
	}
	navMesh.clear();
	
	if( navMeshParent )
	{
		navMeshParent->Destroy();
		delete navMeshParent;
		navMeshParent = NULL;
	}
	
	if( collider )
	{
		collider->Destroy();
		delete collider;
		collider = NULL;
	}
	
	if( pointParticle )
	{
		delete pointParticle;
		pointParticle = NULL;
	}
	
	timeScale = 0.0f;
	deltaTime = 0.0f;
	
	physicsPaused = false;
	graphicPaused = false;
}

World::World()
{
	engine = NULL;
	
	name = "";
	navMeshParent = NULL;
	
	collider = NULL;
	pointParticle = NULL;
	
	timeScale = 1.0f;
	deltaTime = 0.01f;
	
	physicsPaused = false;
	graphicPaused = false;
	
	mainCamera = NULL;
}

World::~World()
{
	Destroy();
}



