
#pragma once

class Collider
{
private:
	
	Octtree < std::vector < Actor* > > octtree;
	std::vector < Actor* > outsideActors;
	
	Vector pos;
	Vector size;
	
public:
	
	void Clear();
	
	void AddActor( Actor * actor );
	
	void GetActor( AABB aabb, std::map < Actor*, bool > & actors ) const;		// std::map actors - must be empty
	
	Collider();
	~Collider();
};



