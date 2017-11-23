
#pragm once

#include <map>
#include <vector>

class Contact
{
private:
	
	class Pair
	{
	public:
		Vector normal;
		Vector point;
		Pair( const Vector norm, const Vector pnt ){ normal = norm; point = pnt; }
		Pair(){}
	};
	
	std::map < Actor *, std::vector < Pair > > contact;
	Vector normal;
	Vector barycenter;
	float deviation;
	
public:
	
	void Add( const Actor * actor, const Vector point, const Vector normal );
	void operator += ( Contact src );
	void operator  = ( Contact src );
	
	void CalcNormal();
	inline Vector GetNormal() const;
	
	void Clear();
	
	Contact();
	~Contact();
};



