
#pragma once

class AABB
{
private:
	Vector min;
	Vector max;
	
public:
	
	void DrawDebug() const;
	
	inline float GetVolume() const;
	
	inline AABB operator = ( const AABB src );
	inline AABB operator + ( const AABB src ) const;
	inline AABB operator + ( const Vector src ) const;
	inline AABB operator - ( const Vector src ) const;
	
	inline static bool SharedPart( const AABB a, const AABB b, AABB & dst );
	inline bool SharedPart( const AABB src, AABB & dst ) const;
	
	inline Vector GetMin() const;
	inline Vector GetMax() const;
	inline Vector GetSize() const;
	inline Vector GetCenter() const;
	
	Contact GetContact( const AABB src ) const;
	Contact GetContact( const Triangle src ) const;
	Contact GetContact( const Triangle * src ) const;
	Contact GetContact( const Vector beg, const Vector end ) const;
	
	inline void AddPoint( const Vector point );
	
	inline void SetMin( const Vector min_ );
	inline void SetMax( const Vector max_ );
	inline void Set( const Vector min_, const Vector max_ );
	
	AABB();
	AABB( const Vector min_, const Vector max_ );
	~AABB();
};



