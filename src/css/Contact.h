
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
		Pair( Vector norm, Vector pnt ){ normal = norm; point = pnt; }
		Pair(){}
	};
	
	Actor * parent;
	std::map < Actor*, std::vector < Pair > > contact;
	Vector normal;
	
public:
	
	void Add( Actor * actor, Vector point, Vector normal );
	void operator += ( Contact src );
	void operator  = ( Contact src );
	
	void CalcNormal();
	inline Vector GetNormal();
	
	void Clear();
	
	Contact();
	Contact( Actor * srcParent );
	~Contact();
};



