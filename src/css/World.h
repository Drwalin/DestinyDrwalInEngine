
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
	
	float timeScale;
	float deltaTime;		// with timeScale
	
public:
	
	void InitWorld( const AABB aabb, const std::string name );
	
	void PlaySound( const std::string name, const float volume );
	void PlaySound( const std::string name, const Vector origin );
	void PlaySound( const std::string name, const Vector origin, const float minDistance );
	
	// void SpawnParticles(...);
	
	Camera * SpawnCamera( const std::string name, const Vector pos, const Vector rotation, const float fov, const float zNear, const float zFar, const int TextureWidth, const int textureHeight );
	Light * SpawnLight( const std::string name, const Vector pos, const Vector rotation, const float fov, const float zNear, const float zFar, const int lightMapWidth, const int lightMapHeight );
	Actor * SpawnStaticActor( const std::string name, const std::string graphicBodyName, const std::string physicsBodyName );
	Actor * SpawnDynamicActor( const std::string name, const std::string graphicBodyName, const Vector size );
	Actor * SpawnTriggerVolumeActor( const std::string name, const Vector pos, const Vector size );
	Actor * SpawnActorByTemplate( const Actor * src, const std::string name );
	
	
	Camera * GetCamera( const std::string name );
	Light * GetLight( const std::string name );
	Actor * GetActor( const std::string name );
	
	void DestroyCamera( const std::string name );
	void DestroyLight( const std::string name );
	void DestroyActor( const std::string name );
	
	void GetActors( const AABB aabb, std::map < Actor *, bool > & actors ) const;
	
	void DrawDebug() const;
	void Draw() const;
	
	void UpdateBinaryCamera( const char * binary, const int len );
	void UpdateBinaryLight( const char * binary, const int len );
	void UpdateBinaryActor( const char * binary, const int len );
	
	void UpdateCollider();
	void UpdateCollisions();
	void Update( const float deltaTime );
	
	World();
	~World();
};



