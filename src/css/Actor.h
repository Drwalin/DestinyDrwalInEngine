
#pragma once

class Actor
{
protected:
	
	World * world;
	std::string name;
	
	Vector pos;
	Vector bpos;
	
	int currentAnimationId;
	float currentAnimationTime;
	GraphicBody * graphicBody;
	
	bool queueToDestroy;
	
public:
	
	virtual void Draw()=0;
	virtual void DrawDebug()=0;
	
	virtual void Set( Actor * src )=0;
	
	virtual Vector GetPhysicsAABB()=0;
	virtual Vector GetGraphicAABB()=0;
	
	virtual Vector GetForwardVector()=0;
	virtual Vector GetRightVector()=0;
	virtual Vector GetUpVector()=0;
	
	virtual void Update( float deltaTime )=0;
	
	virtual void AddForce( Vector src )=0;
	virtual void AddVelocity( Vector src )=0;
	virtual void AddPos( Vector src )=0;
	virtual void AddSize( Vector src )=0;
	
	virtual void SetForce( Vector src )=0;
	virtual void SetVelocity( Vector src )=0;
	virtual void SetPos( Vector src )=0;
	virtual void SetSize( Vector src )=0;
	
	virtual void GetForce( Vector src )=0;
	virtual void GetVelocity( Vector src )=0;
	virtual void GetPos( Vector src )=0;
	virtual void GetSize( Vector src )=0;
	
	virtual int GetBinaryLength()=0;				// includes name, type (class),
	virtual int GetBinary( char * binary )=0;		// includes name and type (class), paste binary data in this pointer
	virtual void SetBinary( const char * binary, int len )=0;	// includes name and type (class)
	
	static void IsBinaryTriggerVolumeActor( const char * binary, int len );
	static void IsBinaryDynamicActor( const char * binary, int len );
	static void IsBinaryStaticActor( const char * binary, int len );
	
	virtual void QueueToDestroy()=0;
	virtual void Destroy()=0;
	
	Actor();
	~Actor();
};



