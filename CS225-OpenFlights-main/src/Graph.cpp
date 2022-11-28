#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>


#include "Graph.h"
#include "utils.h"
#include <algorithm>


Graph::Graph(string routes, string airports) {
    
    // Making adjList
    vector<string> lines;
    vector<vector<string>> fields;
    string str =  file_to_string(routes);
    int count = SplitString(str, '\n', lines);
    fields.resize(count - 1);
    for (int i = 0; i < count - 1; i++) {
        SplitString(lines[i], ',', fields[i]);
    }
    for (unsigned i = 0; i < fields.size(); i++) {
        adjList[stoi(fields[i][0])].push_back(make_pair(stoi(fields[i][1]), stod(fields[i][2])));
    }

    // Mapping airport name to node and vice versa
    vector<string> otherlines;
    vector<vector<string>> otherfields;
    string otherstr = file_to_string(airports);
    int othercount = SplitString(otherstr, '\n', otherlines);
    otherfields.resize(othercount - 1);
    for (int i = 0; i < othercount - 1; i++) {
        SplitString(otherlines[i], ',', otherfields[i]);
    }
    for (unsigned i = 0; i < otherfields.size(); i++) {
        nodeToAirportName[stoi(otherfields[i][0])] = otherfields[i][1];
        airportNameToNode[otherfields[i][1]] = stoi(otherfields[i][0]);
    }
}

void Graph::Dijkstra(int source, int dest) {
    /*
    Dijkstra(Graph, source, destination):

  initialize distances  // initialize tentative distance value
  initialize previous   // initialize a map that maps current node -> its previous node
  initialize priority_queue   // initialize the priority queue
  initialize visited

  while the top of priority_queue is not destination:
      get the current_node from priority_queue
      for neighbor in current_node's neighbors and not in visited:
          if update its neighbor's distances:
              previous[neighbor] = current_node
      save current_node into visited

  extract path from previous
  return path and distance
    */
set<int> visited;
    unordered_map<int, int> prev;
    unordered_map<int, int> dist;
    for (auto p : nodeToAirportName) {
        if (p.first == source) {
            dist[p.first] = 0;
        } else {
            dist[p.first] = INT32_MAX;
        }
        prev[p.first] == NULL;
    }
    struct Compare //used for priority queue to compare distances in pairs
    {
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };
    priority_queue <pair<int, int>, vector<pair<int,int>>, Compare>  q; //replace greater probably
    pair<int, int> start(source, 0);
    q.push(start);
    
    while (q.top().first != dest) {
        pair<int, int> curr = q.top();
        q.pop();
        for (auto p : adjList[curr.first]) { //first is neighbor node, second is distance from curr node
            if (visited.count(p.first) == 1) {
                continue;
            }
            if (p.second + dist[curr.first] < dist[p.first]) {
                dist[p.first] = p.second + dist[curr.first];
                prev[p.first] = curr.first;
            }
        }
        visited.insert(curr.first);
    }
}
