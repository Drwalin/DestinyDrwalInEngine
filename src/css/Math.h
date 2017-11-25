
#pragma once

class Math
{
	static float Min( const float a, const float b );
	static float Max( const float a, const float b );
	static Vector Min( const Vector a, const Vector b );
	static Vector Max( const Vector a, const Vector b );
	static float Abs( const float a );
	static unsigned long long int Log( const unsigned long long int base, const unsigned long long int a );
	static float Log( const float base, const float a );		// returns not the best approximation: abs(log(base,a) - Math::Log(base,a)) <~ 0.2
};



