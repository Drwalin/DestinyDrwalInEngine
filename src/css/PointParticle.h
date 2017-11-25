
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
	unsigned int sortAfter;
	unsigned int updateAfterFrames;
	
public:
	
	void Update( float time );
	void AddParticle( Vector origin, float originrandomization, Vector vel, Vector accelerate, float randomization, unsigned char r,unsigned char g, unsigned char b, unsigned char a, unsigned char rrand,unsigned char grand, unsigned char brand, float lifetime, float randomizationlifetime, int count );
	void Draw() const;
	
	int Init( const unsigned int updateAfterFrames );
	
	PointParticle();
	~PointParticle();
};

#endif
