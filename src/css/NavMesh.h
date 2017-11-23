
#pragma once

class Node
{
private:
	
	long long int x, y, z;
	
	std::vector < Node * > walkConnections;
	std::vector < Node * > swimConnections;
	std::vector < Node * > flyConnections;
	std::vector < Node * > climbConnections;
	std::vector < Node * > fallConnections;
	std::map < Node *, bool > cameFrom;
	
public:
	
	friend class NavMesh;
	
	void DestroyFromConnected();
	
	Node();
	Node( const Vector pos, const float scale );
	Node( const Node * src );
	Node( const Node & src );
	~Node();
};

class BaseNode
{
private:
	
	long long int x, y, z;
	
public:
	
	friend class NavMesh;
	
	bool operator < ( BaseNode src );
	bool operator > ( BaseNode src );
	bool operator == ( BaseNode src );
	
	BaseNode();
	BaseNode( const Vector pos, const float scale );
	BaseNode( const BaseNode src );
};

class NavMeshPath
{
private:
	
	std::vector < Vector > path;
	int currentNode;
	
public:
	
	inline Vector GetNextNode();		// return path[currentNode++];
	inline bool GetExist() const;
	
	NavMeshPath();
	~NavMeshPath();
};

class NavMeshPathFinderVetrtex
{
private:
	long long int pathLength;
	Node * cameFrom;
	
public:
	
	friend NavMesh;
	
	NavMeshPathFinderVetrtex();
	~NavMeshPathFinderVetrtex();
};

class NavMeshVertexToCheck
{
private:
	
	long long int distanceToDestiny;	// linear
	long long int pathLength;
	Node * node;
	Node * cameFrom;
	
public:
	
	friend NavMesh;
	
	bool operator < ( const NavMeshVertexToCheck src ) const;		// compare distanceToDestiny (if equal compare node pointer as int)
	
	VertexToCheck();
	~VertexToCheck();
};

class NavMeshParent
{
private:
	
	std::string name;
	World * world;
	
	std::map < BaseNode, Node * > nodes;								// only in parent
	
	float scale;
	float maximumDistanceNodeConnection;
	
	inline Node * GetNode( const BaseNode pos ) const;
	inline Node * GetNode( const Vector pos ) const;
	
public:
	
	void AddNode( const Vector point );
	void Update( const int count );
	
	void Init( const float acceptableDistanceAsOneNode, const float maximumDistanceNodeConnection );
	void Destroy();
	
	NavMeshParent();
	~NavMeshParent();
};

class NavMesh
{
private:
	
	std::string name;
	World * world;
	NavMeshParent * parent;
	
	std::vector < AABB > excludeSpace;
	//std::vector < AABB > lastResortSpace;									// can use graph node from these space only if there are no other path
	//std::vector < NavMeshVertexToCheck > lastResortVerticesToCheck;		// must be sorted before taking vertex, use only: if( verticesToCheck.size() == 0 ){...}
	std::vector < NavMeshVertexToCheck > verticesToCheck;					// must be sorted before taking vertex
	std::map < Node *, NavMeshPathFinderVetrtex > checkedVertices;			// on the path
	
	Vector begin, end;
	Node * beginNode, * endNode;
	
	NavMeshPath path;
	
	inline void AddVertexToCheck( const Node * node );
	inline Node * GetNextNodeToCheck();
	
	inline Node * GetNode( const BaseNode pos ) const;					// get from parent, create if exist
	inline Node * GetNode( const Vector pos ) const;					// returns: GetNode( BaseNode )
	inline int IsNodeEnable( const Node * node ) const;					// returns diferent: is in [ excludedSpace ? lastResortSpace ]
	
public:
	
	inline Node * GetClosestAvailableNode( const Vector pos ) const;
	inline Node * GetClosestLastResortNode( const Vector pos ) const;
	inline Node * GetClosestExcludedNode( const Vector pos ) const;
	
	void ExcludeSpace( const AABB aabb );
	void IncludeSpace( const AABB aabb );
	
	void BeginNewPath( const Vector a, const Vector b );
	int UpdatePath( const int count );
	
	void Init( const float acceptableDistanceAsOneNode, const float maximumDistanceNodeConnection, const NavMeshParent * parent );
	
	void Destroy();
	
	NavMeshPath GetPath( bool & exist = false ) const;		// argument - setted on true if path does exist
	
	NavMesh();
	~NavMesh();
};



