


inline void ONEPointParticle::Update( float time )
{
	vel += (accelerate+SetVector(float((rand()%600)-300)*randomization/300.0f,float((rand()%600)-300)*randomization/300.0f,float((rand()%600)-300)*randomization/300.0f)) * time;
	pos += vel * time;
	LifeTime -= time;
}

ONEPointParticle::ONEPointParticle()
{
	pos = SetVector(0.0f,0.0f,0.0f);
	vel = SetVector(0.0f,0.0f,0.0f);
	accelerate = SetVector(0.0f,0.0f,0.0f);
	randomization = 0.1f;
	r = 128;
	g = 128;
	b = 128;
	LifeTime = 1.0f;
}

ONEPointParticle::~ONEPointParticle()
{
	pos = SetVector(0.0f,0.0f,0.0f);
	vel = SetVector(0.0f,0.0f,0.0f);
	accelerate = SetVector(0.0f,0.0f,0.0f);
	randomization = 0.0f;
	r = 0;
	g = 0;
	b = 0;
	LifeTime = 0.0f;
}





inline void PointParticle::Update( float time )
{
	if( particle.size() > 0 )
	{
		int i;
		for( i = 0; i < particle.size(); i++ )
		{
			particle[i].Update( time );
			if( particle[i].LifeTime <= 0.0f )
			{
				particle.erase( particle.begin() + i );
				i--;
				continue;
			}
		}
	}
	--sortAfter;
	if( sortAfter <= 0 )
	{
		sortAfter = 3;
		if( particle.size() > 1 )
			std::sort( particle.begin(), particle.end() );
	}
}

inline void PointParticle::AddParticle( Vector origin, float originrandomization, Vector vel, Vector accelerate, float randomization, unsigned char r,unsigned char g, unsigned char b, unsigned char a, unsigned char rrand,unsigned char grand, unsigned char brand, float lifetime, float randomizationlifetime, int count )
{
	int i;
	int col;
	int pastsize = particle.size();
	particle.resize( pastsize + count );
	for( i = 0; i < count; i++ )
	{
		particle[pastsize+i].pos = origin + SetVector(float((rand()%600)-300)*originrandomization/300.0f,float((rand()%600)-300)*originrandomization/300.0f,float((rand()%600)-300)*originrandomization/300.0f);
		particle[pastsize+i].vel = vel + SetVector(float((rand()%600)-300)*originrandomization/300.0f,float((rand()%600)-300)*originrandomization/300.0f,float((rand()%600)-300)*originrandomization/300.0f);
		particle[pastsize+i].accelerate = accelerate;
		particle[pastsize+i].randomization = randomization;
		
		col = int(r) + ((rand()%(rrand*2))-rrand);
		if( col < 0 ) particle[pastsize+i].r = 0;
		else if( col > 255 ) particle[pastsize+i].r = 255;
		else particle[pastsize+i].r = (unsigned char)(col);
		
		col = int(g) + ((rand()%(grand*2))-grand);
		if( col < 0 ) particle[pastsize+i].g = 0;
		else if( col > 255 ) particle[pastsize+i].g = 255;
		else particle[pastsize+i].g = (unsigned char)(col);
		
		col = int(b) + ((rand()%(brand*2))-brand);
		if( col < 0 ) particle[pastsize+i].b = 0;
		else if( col > 255 ) particle[pastsize+i].b = 255;
		else particle[pastsize+i].b = (unsigned char)(col);
		
		col = int(a) + ((rand()%(brand*2))-brand);
		if( col < 0 ) particle[pastsize+i].a = 0;
		else if( col > 255 ) particle[pastsize+i].a = 255;
		else particle[pastsize+i].a = (unsigned char)(col);
		
		particle[pastsize+i].LifeTime = lifetime + (float((rand()%600)-300)*randomizationlifetime/300.0f);
	}
}

inline void PointParticle::Draw() const
{
	VBO vbo;
	for( int i = 0; i < particle.size(); ++i )
		vbo.AddPoint( particle[i].pos, partice[i].r, partice[i].g, partice[i].b, partice[i].a );
	vbo.GenerateAsPoints( 2.0f /*size*/, VBO::rgba /* |VBO::sth */, GL_BLEND );
	vbo.Draw();
	vbo.Destroy();
	vbo.Clear();
}

PointParticle::PointParticle()
{
	particle.resize( 0 );
}

PointParticle::~PointParticle()
{
	particle.resize( 0 );
}


