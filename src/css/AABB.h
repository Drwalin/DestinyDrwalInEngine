
#pragma once

class AABB
{
private:
	Vector min;
	Vector max;
	
public:
	
	void DrawDebug() const;
	
	float GetVolume() const;
	
	AABB operator = ( const AABB src );
	AABB operator + ( const AABB src ) const;
	AABB operator + ( const Vector src ) const;
	AABB operator - ( const Vector src ) const;
	
	static bool SharedPart( const AABB srcA, const AABB srcB, AABB & dst );
	bool SharedPart( const AABB src, AABB & dst ) const;
	
	Vector GetMin() const;
	Vector GetMax() const;
	Vector GetSize() const;
	Vector GetCenter() const;
	
	Contact GetContact( const AABB src ) const;
	Contact GetContact( const Triangle src ) const;
	Contact GetContact( const Triangle * src ) const;
	
	void AddPoint( const Vector point );
	
	void SetMin( const Vector min_ );
	void SetMax( const Vector max_ );
	void Set( const Vector min_, const Vector max_ );
	
	AABB();
	AABB( const Vector min_, const Vector max_ );
	~AABB();
};



