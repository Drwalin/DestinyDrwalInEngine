
#ifndef POINT_PARTICLE_H
#define POINT_PARTICLE_H

class ONEPointParticle
{
public:
	Vector pos;
	Vector vel;
	Vector accelerate;
	float randomization;
	unsigned char r, g, b, a;
	float LifeTime;			// in seconds
	
	//inline bool operator < ( ONEPointParticle src );
	
	inline void Update( float time );
	
	ONEPointParticle();
	~ONEPointParticle();
};

class PointParticle
{
private:
	std::vector < ONEPointParticle > particle;
	int sortAfter;
	
public:
	inline void Update( float time );
	inline void AddParticle( Vector origin, float originrandomization, Vector vel, Vector accelerate, float randomization, unsigned char r,unsigned char g, unsigned char b, unsigned char a, unsigned char rrand,unsigned char grand, unsigned char brand, float lifetime, float randomizationlifetime, int count );
	inline void Draw() const;
	
	PointParticle();
	~PointParticle();
};

#endif
