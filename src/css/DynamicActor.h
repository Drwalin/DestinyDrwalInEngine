
#pragma once

class DynamicActor : public Actor
{
private:
	
	Vector size;		// half size
	Vector bsize;
	Vector vel;
	Vector force;
	
	Vector mass;
	
public:
	
	
	
	DynamicActor();
	~DynamicActor();
}
