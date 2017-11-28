
#pragma once

class World
{
public:
	
	static constexpr float MinimumTimeScale = 0.001f;
	
private:
	
	Engine * engine;
	
	std::string name;
	
	std::map < std::string, Actor* > actor;
	std::map < std::string, Camera* > camera;
	std::map < std::string, Light* > light;
	std::map < std::string, NavMesh* > navMesh;		// instances of navMeshParent
	NavMeshParent * navMeshParent;
	
	Collider * collider;
	
	PointParticle * pointParticle;
	
	Camera * mainCamera;
	
	float timeScale;
	float deltaTime;		// with timeScale
	
	bool physicsPaused;
	bool graphicPaused;
	
	void UpdateCollider();
	void UpdateCollision();
	void ReactCollision( const float deltaTime );
	
public:
	
	Contact RayTrace( const Vector beg, const Vector end, std::map < Actor*, bool > & ignoreActors, bool returnAllIntersection = false );
	
	int Init( const AABB aabb, const std::string name, Engine * engine, const unsigned int frequencyParticleUpdate );
	
	void PlaySound( const std::string name, const float volume );
	void PlaySound( const std::string name, const Vector origin );
	void PlaySound( const std::string name, const Vector origin, const float minDistance );
	
	PointParticle * ParticleSpawner();
	
	
	Camera * SpawnCamera( const std::string name, const Vector pos, const Vector rotation, const float fov, const float zNear, const float zFar, const int TextureWidth, const int textureHeight );
	Light * SpawnLight( const std::string name, const Vector pos, const Vector rotation, const float fov, const float zNear, const float zFar, const int lightMapWidth, const int lightMapHeight );
	Actor * SpawnStaticActor( const std::string name, const std::string graphicBodyName, const std::string physicsBodyName );
	Actor * SpawnDynamicActor( const std::string name, const std::string graphicBodyName, const Vector size );
	Actor * SpawnTriggerVolumeActor( const std::string name, const Vector pos, const Vector size );
	Actor * SpawnActorByTemplate( const Actor * src, const std::string name );
	NavMesh * SpawnNavMesh( const std::string name );
	
	NavMeshParent * GetNavMeshParent() const;
	NavMesh * GetNavMesh( const std::string name ) const;
	Camera * GetCamera( const std::string name ) const;
	Light * GetLight( const std::string name ) const;
	Actor * GetActor( const std::string name ) const;
	
	void GetActors( const AABB aabb, std::map < Actor*, bool > & actors ) const;
	void GetActors( const AABB aabb, std::map < Actor*, AABB > & actors ) const;
	
	void SetMainCamera( const Camera * camera );
	Camera * GetMainCamera() const;
	
	float GetDeltaTime() const;
	float GetTimeScale() const;
	void SetTimeScale( const float val );
	
	void DestroyNavMesh( const std::string name );
	void DestroyCamera( const std::string name );
	void DestroyLight( const std::string name );
	void DestroyActor( const std::string name );
	
	void Draw() const;
	
	void UpdateBinaryCamera( const char * binary, const int len );
	void UpdateBinaryLight( const char * binary, const int len );
	void UpdateBinaryActor( const char * binary, const int len );
	
	void Update( const float deltaTime );
	
	void PausePhysics();
	void StartPhysics();
	void PauseGraphic();
	void StartGraphic();
	
	void Destroy();
	
	World();
	~World();
};



