#include "DisjointSet.h"

DisjointSet::DisjointSet(int setSize)
{
	m_Root.reserve(setSize);

	// Initialize default values.
	for (int x=0; x < setSize; ++x)
	{
		m_Root.push_back(x);
	}
}

DisjointSet::~DisjointSet()
{
}

void DisjointSet::AddUnionSet(int inX, int inY)
{
	int rootX = m_Root[inX];
	int rootY = m_Root[inY];

	if (rootX != rootY)
	{
		for (int x=0; x < m_Root.size(); ++x)
		{
			if (m_Root[x] == rootY)
			{
				m_Root[x] = rootX;
			}
		}
	}
}

bool DisjointSet::VertexConnected(int inX, int inY)
{
	return m_Root[inX] == m_Root[inY];
}
