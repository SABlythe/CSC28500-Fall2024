/***************************************************************************/
/*  FILE: Graph.hpp                                                        */
/*  AUTHOR: S. Blythe                                                      */
/*  DATE: 11/2024                                                          */
/*  PURPOSE: Present a simple graph interface for CSC28500 students        */
/***************************************************************************/
#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_


#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <utility>  // for pair<>

class Graph
{
private:
  /*
     these are private instance variables. The whole point is that you
     do NOT need to undertand these to use the class. So if this
     private section confuses you, just ignore it - you don't need to
     understand it to use the class!
  */
  
  // collection of all vertices in graph. Note that a vertex is
  // identified by a unique string
  std::set<std::string> _verts;

  // adjacency list representation of the edges in the graph. Instead
  // of having this be "regular" array indexed by integers, I use a
  // map, which can be thought of as an associative array indexed by
  // the vertex names (which are just strings). In C++, the closest
  // structure to an associative array is a map.
  //
  // What type is each element in the array (map)? Well, it's an
  // adjacency list representation, so each item in the array is a list
  // of vertexes (and their cost) that are adjacent to the indexed
  // vertex. This combination of a vertex (which is a string in this
  // proect) and cost (which is an int) is a pair of values ... and
  // there is a C++ structure called "pair" to represent this concept.
  //
  // With all of the above in mind, this is a associative array (map)
  // of lists with indexes being of type string. Each list is made up
  // of pairs (representing an adjacent vertex and its cost.)
  std::map< std::string, std::list< std::pair<std::string, int> > > _adj; 



public:

  // default contructor. Resulting Graph would have no vertexes (and no edges)
  Graph(): _verts(), _adj() {}

  // constructor to read a graph from an input (file) stream. The
  // input stream should be a sequence of edges, specified as a source
  // vertex (string) followed by a destination vertex (string)
  // followed by the cost of that edge. This constructor assumes all
  // edges are undirectional, so adding an edge from a to b also shows
  // up as b to a for the same cost.
  Graph(std::istream &is);

  // returns a set of the vertexes (names) in the graph
  std::set<std::string> getVertexes() const;

  // for any one vertex, this returns a set of all other ajacent vertexes
  std::set<std::string> getAdjacencies(const std::string &vertex) const;

  // for the associated two vertexes, returns the cost of an edge between them
  //   * returns INT_MAX if there is no such edge (or vertexes)
  int getEdgeCost(const std::string &src, const std::string &dest) const;



  // ************************************************************
  // NOTE: Although the following methods are public and you are
  // welcome to use them, you will likley not need to do so. I
  // *seriously* thought about making the following private methods!
  
  // adds a single vertex (string) to the graph with no new edges
  void addVertex(const std::string &v);

  // adds a single edge between the two specifed vertexes (strings)
  // with the given cost. By default, the edges are considered
  // undirected.
  void addEdge(const std::string &src, const std::string &dest, int cost, bool undirected=true);

  // two methods that use the above and the context of the parameter
  // to decide whether the add is for a vertex or an edge
  // (polymorphism at work!)
  void add(const std::string &v) {addVertex(v);}
  void add(const std::string &src, const std::string &dest, int cost, bool undirected=true)
  {addEdge(src, dest, cost, undirected);}

  // prints the data regarding this graph to the specified stream. 
  std::ostream& print(std::ostream &os) const; 
};

// overload << so that it prints a grpah's data to the scrren. 
std::ostream& operator<<(std::ostream &os, const Graph &g);

#endif
