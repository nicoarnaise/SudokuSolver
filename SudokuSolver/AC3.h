#pragma once
#include <queue>
#include <set>

#include "Node.h"

void AC3(std::queue<Node*> csp);
bool RemoveInconsistentValues(std::pair<Node*, Node*> arc);
std::deque<std::pair<Node*, Node*>> GenerateQueue(std::queue<Node*> csp);