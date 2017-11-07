
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
	void AddActor( Actor * actor );
	
	void GetActors( AABB aabb, std::map < Actor*, bool > & actors );
	
	Collider();
	~Collider();
};



