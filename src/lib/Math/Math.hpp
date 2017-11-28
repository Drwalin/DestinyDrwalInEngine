
#pragma once

#include <cmath>
#include <ctgmath>
#include <ctime>
#include <random>

#ifndef M_PI
#define M_PI 3.141592
#endif

inline float sqrtf( const float src )
{
	return sqrt( src );
}

inline float clamp( const float src, const float min, const float max )
{
	return ( src < min ) ? min : ( ( src > max ) ? max : src );
}

inline int clamp( const int src, const int min, const int max )
{
	return ( src < min ) ? min : ( ( src > max ) ? max : src );
}

namespace randomGeneratorObjects
{
	std::minstd_rand0 generatorLinear( time(NULL) );
	std::default_random_engine generatorNormal;
	std::normal_distribution<float> distributionNormal( 0.0f, 1.0f );
};

inline int rand( int min, int max )
{
	return (randomGeneratorObjects::generatorLinear()%(max-min)) + min;
}

inline float rand( float min, float max )
{
	return 
			((((randomGeneratorObjects::generatorLinear()-randomGeneratorObjects::generatorLinear.min())%
			(randomGeneratorObjects::generatorLinear.max()-randomGeneratorObjects::generatorLinear.min())
			)/(float(randomGeneratorObjects::generatorLinear.max()-randomGeneratorObjects::generatorLinear.min()))
			)
			/(max-min))+min;
}

inline float rand_normal( float min, float max )		// normal distribution
{
	randomGeneratorObjects::distributionNormal = std::normal_distribution<float>( (min+max)*0.5f, ((max-min)*0.5f)/M_PI );
	float fast = randomGeneratorObjects::distributionNormal(randomGeneratorObjects::generatorNormal);
	return ( fast < min || fast > max ) ? (min+max)*0.5f : fast;
}

inline int rand_normal( int min, int max )
{
	int fast = (int)rand_normal( float(min), float(max) );
	return ( fast < min || fast > max ) ? (min+max)>>1 : fast;
}


float safe_acos( float x )
{
	if( x <= -1.0f ) return M_PI;
	if( x >= 1.0f ) return 0.0f;
	return acos( x );
}



