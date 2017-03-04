#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include "Node.h"
#include "Utilities.h"
#include "Main.h"

using namespace std;

int main() {
	vector < vector<string>> grid_s = readFile();
	queue<Node*> nodes;
	set<int> areasKeys;
	map<int, vector<Node*>> areas;

	for (int i = 0; i < grid_s.size(); i++)
	{
		for (int j = 0; j < grid_s.at(i).size(); j++)
		{
			Node* node = new Node(grid_s.at(i).at(j));
			areasKeys.emplace(i + j * 10);
			//Squares
			int k(0);
			if (areas.find(i + j * 10 + k * 100) == areas.end()) {
				vector<Node*> tmp;
				tmp.push_back(node);
				areas.emplace(i + j * 10 + k * 100, tmp);
			}
			else
			{
				areas.at(i + j * 10 + k * 100).push_back(node);
			}
			//Horizontals
			k++;
			if (areas.find(i + k * 100) == areas.end()) {
				vector<Node*> tmp;
				tmp.push_back(node);
				areas.emplace(i + k * 100, tmp);
			}
			else
			{
				areas.at(i + k * 100).push_back(node);
			}
			//Verticals
			k++;
			if (areas.find(j * 10 + k * 100) == areas.end()) {
				vector<Node*> tmp;
				tmp.push_back(node);
				areas.emplace(j * 10 + k * 100, tmp);
			}
			else
			{
				areas.at(j * 10 + k * 100).push_back(node);
			}
			nodes.emplace(node);
		}
	}
	for each (int key in areasKeys)
	{
		for each (Node* node in areas.at(key))
		{
			node->AddNeighbors(areas.at(key));
		}
	}
	writeFile(nodes);
	cout << "Hello" << endl;
	system("pause");

	return 0;
}