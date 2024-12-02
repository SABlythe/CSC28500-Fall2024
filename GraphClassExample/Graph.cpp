/***************************************************************************/
/*  FILE: Graph.cpp                                                        */
/*  AUTHOR: S. Blythe                                                      */
/*  DATE: 11/2024                                                          */
/*  PURPOSE: Implements the simple Graph class CSC28500 students           */
/***************************************************************************/
#include "Graph.hpp"

#include <climits>

using namespace std;

// input stream (file) based constructor ...
Graph::Graph(std::istream &is)
{
  // read in first edge (source, destination, and cost
  string src, dest;
  int cost;
  is >> src >> dest >> cost;

  // did last read succeed? If so, add the corresponding edge to this graph. 
  while (is)
    {
      add(src, dest, cost); 

      // read in next (potential) edge. 
      is >> src >> dest >> cost;
    }
}

// adding a vertex to graph
void
Graph::addVertex(const std::string &name)
{
  // pretty easy - just insert the vertex into the underlying set. 
  _verts.insert(name);
}

// adding an edge to the graph
void
Graph::addEdge(const std::string &src, const std::string &dest, int cost, bool undirected)
{
  // ass both vertexes (endpoints) of edge to graph
  addVertex(src);  
  addVertex(dest);

  // add "forward" edge to back of adjacency list for the source vertex. 
  _adj[src].push_back(pair<string, int>(dest, cost));

  // if this is an undirected graph (it probably is) ... 
  if (undirected)
    // ... add "backward" edge to back of adjacency list for the sourcedestination vertex. 
    _adj[dest].push_back(pair<string, int>(src, cost));
}

// dump graph data to stream
std::ostream&
Graph::print(std::ostream &os) const
{
  // go through every vertex v:
  for (string v: _verts)
    {
      // print out the vertex name 
      cout << v << " :";

      // print out all edges incident to v
      for (pair<string, int> incidence: _adj.at(v))
	cout << incidence.first << "(" << incidence.second << ") ";
      cout << endl;
    }
  return os;
}

// gets the cost of an edge between the two specified veretxes (strings)
int 
Graph::getEdgeCost(const std::string &src, const std::string &dest) const
{
  // if either vertex does not exist, there can't be an edge!
  if (_verts.find(src) == _verts.end())
  {
    cerr << "WARNING: vertex not found: " << src << endl;
    return INT_MAX;
  }
  if (_verts.find(dest) == _verts.end())
  {
    cerr << "WARNING: vertex not found: " << dest << endl;
    return INT_MAX;
  }

  // go through adjacency list for the source vertex
  for (pair<string, int> adj: _adj.at(src))
    {
      // if an adjacent vertex matches, then you found the edge,
      // return its cost.
      // NOTE that the "first" part of the pair is the adjavent vertex
      // name and the "second" part of the pair would be the cost.
      if (adj.first==dest)
	return adj.second;
    }

  // if we get here, we didn't find a matching edge ...
  cerr << "WARNING: No edge found between " << src << " and " << dest << endl;
  return INT_MAX;
}

// get a set of the vertex names in the graph. This is so easy, I
// thought about inline-ing it within the .hpp file.
std::set<std::string> 
Graph::getVertexes() const
{
  return _verts;
}

// get a set of the names of vertexes adjacent to the specifed vertex
// (vertName)
std::set<std::string> 
Graph::getAdjacencies(const string &vertName) const
{
  set<string> ans; // initially, we have not found any such vertexes. 

  // if you can't find th requested vertex in the associateive array (map),
  // then it does ot exist. 
  if (_verts.find(vertName) == _verts.end())
    {
      cerr << "WARNING: vertex not found: " << vertName << endl;
      return ans;
    }

  // for each vertex in the corresponding adjacency list, add it to the answer
  for (pair<string, int> adj: _adj.at(vertName))
    ans.insert(adj.first);
  
  return ans;
}

// overload the << operator by using print method (see above) 
std::ostream& operator<<(std::ostream &os, const Graph &g)
{
  return g.print(os);
}
