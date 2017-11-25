
#pragma once

class Actor
{
protected:
	
	World * world;
	std::string name;
	
	Vector pos;		// barycenter
	Vector bpos;
	
	GraphicBodyInstance graphicBodyInfo;
	
	bool queueToDestroy;
	
	std::string customString;		// this can use gameDeveloper
	void * customData;				// this can use gameDeveloper, he must constract and destruct it on his own
	
public:
	
	inline std::string & GetCustomString();
	inline void ** GetCustomData();
	
	inline World * GetWorld() const;
	inline std::string GetName() const;
	
	virtual void SetByTemplate( const Actor * src )=0;
	
	virtual void DrawDebug() const=0;
	virtual void Draw() const=0;
	
	virtual AABB GetAABB() const=0;
	virtual float GetHeight() const=0;
	
	virtual Vector GetForwardVector() const=0;
	virtual Vector GetRightVector() const =0;
	virtual Vector GetUpVector() const=0;
	
	virtual void Update( const float deltaTime )=0;
	
	virtual void AddForce( const Vector src )=0;
	virtual void AddVelocity( const Vector src )=0;
	virtual void AddPos( const Vector src )=0;
	virtual void Resize( const Vector src )=0;				// full size
	virtual void Rotatate( const Vector src )=0;
	
	virtual void SetForce( const Vector src )=0;
	virtual void SetVelocity( const Vector src )=0;
	virtual void SetPos( const Vector src )=0;
	virtual void SetRotation( const Vector src )=0;
	
	virtual Vector GetForce() const=0;
	virtual Vector GetVelocity() const=0;
	virtual Vector GetPos() const=0;
	virtual Vector GetSize() const=0;			// full size
	virtual Vector GetRotation() const=0;
	
	
	virtual void UpdateBinary( const char * binary, const int len )=0;	// includes name and type (class)
	virtual int GetBinary( char * binary ) const=0;		// includes name and type (class), paste binary data at this pointer
	virtual int GetBinaryLength() const=0;				// includes name, type (class),
	
	virtual bool GetRayTrace( const Vector beg, const Vector end, Vector & point, Vector & normal )=0;
	
	
	static bool IsBinaryTriggerVolumeActor( const char * binary, const int len );
	static bool IsBinaryDynamicActor( const char * binary, const int len );
	static bool IsBinaryStaticActor( const char * binary, const int len );
	
	static Actor * GetNewActorByBinaryTemplate( const char * binary, const int len );
	static Actor * GetNewActorByBinaryType( const char * binary, const int len );
	
	static Actor * GetNewActorByTemplate( const Actor * src );
	static Actor * GetNewActorByType( const Actor * src );
	
	inline static void Destroy( Actor * src );
	virtual void Destroy()=0;
	inline void QueueToDestroy();
	
	Actor();
	virtual ~Actor()=0;
};



