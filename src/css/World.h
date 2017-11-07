
#pragma once

class World
{
private:
	
	Engine * engine;
	
	std::string name;
	
	std::map < std::string, Actor * > actor;
	std::map < std::string, Camera * > camera;
	std::map < std::string, Light * > light;
	
	Collider collider;
	
public:
	
	void InitWorld( 
	
	void PlaySound( std::string name, float volume );
	void PlaySound( std::string name, Vector origin );
	void PlaySound( std::string name, Vector origin, float minDistance );
	
	void SpawnParticles(...);
	
	Light * SpawnLight( std::string name );
	
	Camera * SpawnCamera( std::string name, Vector pos, Vector rotation, float fov, float zNear, float zFar );
	Actor * SpawnStaticActor( std::string name, std::string graphicBodyName, std::string physicsBodyName );
	Actor * SpawnDynamicActor( std::string name, std::string graphicBodyName, Vector size );
	Actor * SpawnTriggerVolumeActor( std::string name, Vector pos, Vector size );
	
	
	Camera * GetCamera( std::string name );
	Light * GetLight( std::string name );
	Actor * GetActor( std::string name );
	
	void GetActors( Vector beg, Vector end, std::map < Actor *, bool > & actors );
	
	void Draw();
	void DrawDebug();
	
	void UpdateCollider( float deltaTime );
	
	World();
	~World();
};



