
#pragma once

float Math::Min( const float a, const float b )
{
	return ( a < b ) ? a : b;
}

float Math::Max( const float a, const float b )
{
	return ( a > b ) ? a : b;
}

Vector Math::Min( const Vector a, const Vector b )
{
	return Vector( Math::Min(a[0],b[0]), Math::Min(a[1],b[1]), Math::Min(a[2],b[2]) );
}

Vector Math::Max( const Vector a, const Vector b )
{
	return Vector( Math::Max(a[0],b[0]), Math::Max(a[1],b[1]), Math::Max(a[2],b[2]) );
}

float Math::Abs( const float a )
{
	return ( a < 0.0f ) ? -a : a;
}



