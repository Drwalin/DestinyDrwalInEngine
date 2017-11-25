
#pragma once

void DrawDebug() const
{
	
}

inline float GetVolume() const
{
	Vector a = max-min;
	return abs( a[0] * a[1] * a[2] );
}

inline AABB AABB::operator = ( const AABB src )
{
	min = src.min;
	max = src.max;
}

inline AABB AABB::operator + ( const AABB src ) const
{
	return AABB( Math::Min(min,src.min), Math::Max(max,src.max) );
}

inline AABB AABB::operator + ( const Vector src ) const
{
	return AABB( min+src, max+src );
}

inline AABB AABB::operator - ( const Vector src ) const
{
	return AABB( min-src, max-src );
}

inline bool AABB::SharedPart( const AABB a, const AABB b, AABB & dst )
{
	if( a.max > b.min )
	{
		if( a.min < b.max )
		{
			dst.min = Math::Max( a.min, b.min );
			dst.max = Math::Min( a.max, b.max );
			return true;
		}
	}
	return false;
}

inline bool AABB::SharedPart( const AABB src, AABB & dst ) const
{
	if( max > src.min )
	{
		if( min < src.max )
		{
			dst.min = Math::Max( min, src.min );
			dst.max = Math::Min( max, src.max );
			return true;
		}
	}
	return false;
}

inline Vector AABB::GetMin() const
{
	return min;
}

inline Vector AABB::GetMax() const
{
	return max;
}

inline Vector AABB::GetSize() const
{
	return max-min;
}

inline Vector AABB::GetCenter() const
{
	return (min+max) * 0.5f;
}


inline void AABB::AddPoint( const Vector point )
{
	if( point[0] < min[0] )				min[0] = point[0];
	else if( point[0] > max[0] )		max[0] = point[0];
	if( point[1] < min[1] )				min[1] = point[1];
	else if( point[1] > max[1] )		max[1] = point[1];
	if( point[2] < min[2] )				min[2] = point[2];
	else if( point[2] > max[2] )		max[2] = point[2];
}

inline void AABB::SetMin( const Vector min_ )
{
	min = min_;
}

inline void AABB::SetMax( const Vector max_ )
{
	max = max_;
}

inline void AABB::Set( const Vector min_, const Vector max_ )
{
	min = min_;
	max = max_;
}

AABB::AABB()
{
	min.Set( 0.0f, 0.0f, 0.0f );
	max.Set( 0.0f, 0.0f, 0.0f );
}

AABB::AABB( const Vector min_, const Vector max_ )
{
	min = min_;
	max = max_;
}

AABB::~AABB()
{
	min.Set( 0.0f, 0.0f, 0.0f );
	max.Set( 0.0f, 0.0f, 0.0f );
}



