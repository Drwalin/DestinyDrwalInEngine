
#pragma once

class StaticActor : public Actor
{
private:
	
	std::vector < std::string > hitSoundName;
	std::vector < Triangle* > triangle;
	Octtree < Triangle* > octtree;
	
	float frictionFactor;
	
public:
	
	void FromOBJData( const ObjectOBJ * src );
	
	void FromPhysicsBody( const PhysicsBody * src );
	
	
	virtual void SetByTemplate( const Actor * src ) override;
	
	virtual void DrawDebug() const override;
	virtual void Draw() const override;
	
	virtual AABB GetPhysicsAABB() const override;
	virtual AABB GetGraphicAABB() const override;
	virtual float GetHeight() const override;
	
	virtual Vector GetForwardVector() const override;
	virtual Vector GetRightVector() const override;
	virtual Vector GetUpVector() const override;
	
	virtual void Update( const float deltaTime ) override;
	
	virtual void AddForce( const Vector src ) override;
	virtual void AddVelocity( const Vector src ) override;
	virtual void AddPos( const Vector src ) override;
	virtual void Resize( const Vector src ) override;				// fulle size
	virtual void Rotatate( const Vector src ) override;
	
	virtual void SetForce( const Vector src ) override;				// none
	virtual void SetVelocity( const Vector src ) override;			// none
	virtual void SetPos( const Vector src ) override;				// none
	virtual void SetRotation( const Vector src ) override;			// none
	
	virtual Vector GetForce() const override;
	virtual Vector GetVelocity() const override;
	virtual Vector GetPos() const override;
	virtual Vector GetSize() const override;			// full size
	virtual Vector GetRotation() const override;
	
	
	virtual void UpdateBinary( const char * binary, const int len ) override;	// includes name and type (class)
	virtual int GetBinary( char * binary ) const override;		// includes name and type (class), paste binary data in this pointer
	virtual int GetBinaryLength() const override;				// includes name, type (class),
	
	
	StaticActor();
	virtual ~StaticActor() override;
};



