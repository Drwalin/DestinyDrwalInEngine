
#pragma once

class Collider
{
private:
	
	Octtree < std::vector < Actor* > > octtree;
	std::vector < Actor* > outsideActors;
	
	AABB aabb;
	
public:
	
	void AddActor( Actor * actor );
	void GetActor( AABB aabb, std::map < Actor*, bool > & actors ) const;		// std::map actors - must be empty
	
	void Clear();
	
	AABB GetAABB() const;
	Vector GetSize() const;
	void Init( const AABB aabb, const int levels );
	
	Collider();
	~Collider();
};



