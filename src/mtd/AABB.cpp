
#pragma once

void AABB::AddPoint( Vector point )
{
	if( point[0] < min[0] )		min[0] = point[0];
	else if( point[0] > max[0] )		max[0] = point[0];
	
	if( point[1] < min[1] )		min[1] = point[1];
	else if( point[1] > max[1] )		max[1] = point[1];
	
	if( point[2] < min[2] )		min[2] = point[2];
	else if( point[2] > max[2] )		max[2] = point[2];
}

bool AABB::SharedPart( AABB src, AABB & dst )
{
	dst = AABB();
	if( src.min <= max )
	{
		dst = AABB( src.min, max );
		return true;
	}
	return false;
}

Vector AABB::GetMin()
{
	return min;
}

Vector AABB::GetMax()
{
	return max;
}

void AABB::SetMin( Vector min_ )
{
	min = min_;
}

void AABB::SetMax( Vector max_ )
{
	max = max_;
}

void AABB::Set( Vector min_, Vector max_ )
{
	min = min_;
	max = max_;
}

AABB::AABB()
{
	min.Set( 0.0f, 0.0f, 0.0f );
	max.Set( 0.0f, 0.0f, 0.0f );
}

AABB::AABB( Vector min_, Vector max_ )
{
	min = min_;
	max = max_;
}

AABB::~AABB()
{
	min.Set( 0.0f, 0.0f, 0.0f );
	max.Set( 0.0f, 0.0f, 0.0f );
}



