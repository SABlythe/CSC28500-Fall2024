#include <iostream>
#include <fstream>
#include <set>
#include <string>

#include "Graph.hpp"

using namespace std;

int main()
{
	cout << "Enter a filename for graph data: ";
	string fname;
	cin >> fname;

	ifstream ifile;
	ifile.open(fname);

	Graph g(ifile);

	set<string> verts = g.getVertexes();

	for (string v : verts)
		cout << v << endl;

	cout << "Which vertex do you want to see adjacencies for?";

	string start;
	cin >> start;

	verts = g.getAdjacencies(start);

	for (string v : verts)
		cout << v << endl;


	string v1, v2;
	do
	{
		cout << "Give me two vertex names: (use quit as first vertex to stop)";
		cin >> v1 >> v2;

		if (v1!="quit")
			cout << "cost between those two is :"
			     << g.getEdgeCost(v1, v2) << endl;
	}
	while (v1!="quit");

	return 0;
}

