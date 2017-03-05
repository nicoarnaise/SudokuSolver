#pragma once
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <fstream>
#include "Node.h"

std::vector<std::string> split(std::string input, char delim);
std::vector<std::vector<std::string>> readFile();
bool writeFile(std::queue<Node*> input);
std::queue<Node*> copyCsp(std::queue<Node*> csp);