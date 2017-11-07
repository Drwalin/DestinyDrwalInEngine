
#ifndef OCTTREE_H
#define OCTTREE_H

#include<cstring>

template < class T >
struct OcttreeNode
{
public:
	OcttreeNode<T> * node[2][2][2];
	T * data;
	
	inline void Destroy();
	
	inline int GetNodeNumber();
	inline void Print( const int i );
	inline void AddToVboEdges( std::vector < Vector > & points, Vector offset, Vector size );
	
	OcttreeNode();
	~OcttreeNode();
};

template < class T >
struct Octtree
{
public:
	OcttreeNode<T> node;
	T defaultValue;
	int lvl;
	
	inline bool Exist( const int _x, const int _y, const int _z );
	inline void Set( const int _x, const int _y, const int _z, const T src );
	inline T& Get( const int _x, const int _y, const int _z );
	inline void Erase( const int _x, const int _y, const int _z );
	
	inline int GetNumberOfNodes();
	inline void Print();
	
	inline void Clear();
	
	inline void Init( const int levels_, const T defaultValue_ );
	
	Octtree();
	~Octtree();
};

#endif



