
#pragma once

class AABB
{
private:
	Vector min;
	Vector max;
	
public:
	
	void DrawDebug();
	
	inline AABB & operator = ( AABB src );
	
	static inline bool SharedPart( AABB src, AABB & dst );
	
	inline Vector GetMin();
	inline Vector GetMax();
	inline Vector GetSize();
	
	inline Contact GetContact( AABB src );
	inline Contact GetContact( Triangle src );
	
	inline void AddPoint( Vector point );
	
	inline void SetMin( Vector min_ );
	inline void SetMax( Vector max_ );
	inline void Set( Vector min_, Vector max_ );
	
	AABB();
	AABB( Vector min_, Vector max_ );
	~AABB();
};



