
#pragma once

class AABB
{
private:
	Vector min;
	Vector max;
	
public:
	
	void DrawDebug() const;
	
	float GetVolume() const;
	
	AABB & operator = ( const AABB src );
	
	static bool SharedPart( const AABB srcA, const AABB srcB, AABB & dst );
	bool SharedPart( const AABB src, AABB & dst ) const;
	
	Vector GetMin() const;
	Vector GetMax() const;
	Vector GetSize() const;
	
	Contact GetContact( AABB src ) const;
	Contact GetContact( Triangle src ) const;
	
	void AddPoint( Vector point );
	
	void SetMin( Vector min_ );
	void SetMax( Vector max_ );
	void Set( Vector min_, Vector max_ );
	
	AABB();
	AABB( Vector min_, Vector max_ );
	~AABB();
};



