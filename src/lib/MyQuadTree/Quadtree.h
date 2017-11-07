
#ifndef QUADTREE_H
#define QUADTREE_H

#include <cstring>
#include <cstdio>

template < class T >
class QuadtreeNode
{
public:
	QuadtreeNode<T> * node[2][2];
	T * data;
	
	void Destroy();
	
	int GetNodeNumber();
	void Print( const int i );
	
	QuadtreeNode();
	~QuadtreeNode();
};

template < class T >
class Quadtree
{
public:
	QuadtreeNode<T> node;
	T defaultValue;
	int lvl;
	
	inline bool Exist( const int _x, const int _y );
	inline void Set( const int _x, const int _y, const T src );
	inline T& Get( const int _x, const int _y );
	inline void Erase( const int _x, const int _y );
	
	inline int GetNumberOfNodes();
	inline void Print();
	
	inline void Clear();
	
	inline void Init( const int levels_, const T defaultValue_ );
	
	Quadtree();
	~Quadtree();
};

#endif



