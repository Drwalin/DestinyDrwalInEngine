
#pragma once

class Collider
{
private:
	
	Octtree < Actor * > octtree;
	Vector pos;
	Vector size;
	std::vector < Actor * > outsideActors;
	
public:
	
	void Clear();
	
	void Add( Actor * actor );
	
	void Get( AABB aabb, std::map < Actor*, bool > & actors ) const;		// std::map actors - must be empty
	
	Collider();
	~Collider();
};



