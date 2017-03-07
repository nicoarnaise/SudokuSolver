#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include "Node.h"
#include "Utilities.h"
#include "BackTracking.h"
#include "Main.h"

using namespace std;

int main() {
	// Read the file 'input.csv'
	vector < vector<string>> grid_s = readFile();
	// -------- Make the csp from what you've read -------------
	queue<Node*> nodes;
	set<int> areasKeys;
	map<int, vector<Node*>> areas;
	int index;
	for (int i = 0; i < grid_s.size(); i++)
	{
		for (int j = 0; j < grid_s.at(i).size(); j++)
		{
			// create a node
			Node* node = new Node(grid_s.at(i).at(j));
			// search for its neighbors
			for (int k = 0; k < 3; k++)
			{
				switch (k)
				{
				case 0:
					//Squares
					index = i / 3 + (j / 3) * 10 + k * 100;
					break;
				case 1:
					//Horizontals
					index = i + k * 100;
					break;
				case 2:
					//Verticals
					index = j * 10 + k * 100;
					break;
				}
				if (areas.find(index) == areas.end()) {
					vector<Node*> tmp;
					tmp.push_back(node);
					areasKeys.insert(index);
					areas.emplace(index, tmp);
				}
				else
				{
					areas.at(index).push_back(node);
				}
			}
			// add the node to the csp
			nodes.push(node);
		}
	}
	// add the neighbors to each node
	for each (int key in areasKeys)
	{
		for each (Node* node in areas.at(key))
		{
			node->AddNeighbors(areas.at(key));
		}
	}
	// -----------------------------------------------------------
	// do the backtracking search on our csp
	nodes = BacktrackingSearch(nodes);
	// write the solution in 'output.csv'
	writeFile(nodes);
	// tell the user that its solution is reachable.
	cout << "Le sodoku 'input.csv' a ete resolu dans 'output.csv'." << endl;
	// give him the time to read what you've just wrote.
	system("pause");
	
	// tell the system you've finished properly your execution
	return 0;
}