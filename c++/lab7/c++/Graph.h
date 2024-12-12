
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include "Queue.h"

class Graph {
public:
    std::unordered_map<std::string, std::vector<std::string>> graph;
    std::unordered_map<std::string, int> count;

    bool InGraph(const std::string& node) {
        return graph.find(node) != graph.end();
    }

    void addNode(const std::string& node, int cnt) {
        if (!InGraph(node)) {
            graph[node] = std::vector<std::string>();
            count[node] = cnt;
        }
    }

    void addEdges(const std::string& from_node, const std::string& to_node) {
        graph[from_node].push_back(to_node);
    }

    std::vector<std::string> dfs(const std::string& start_node, std::set<std::string>& visited) {
        visited.insert(start_node);
        std::vector<std::string> result{ start_node };

        for (const auto& n : graph[start_node]) {
            if (visited.find(n) == visited.end()) {
                std::vector<std::string> dfs_result = dfs(n, visited);
                result.insert(result.end(), dfs_result.begin(), dfs_result.end());
            }
        }
        return result;
    }

    std::vector<std::string> bfs(const std::string& start_node) {
        std::set<std::string> visited;
        Queue queue;
        queue.enqueue(start_node);
        std::vector<std::string> result;

        while (!queue.is_empty()) {
            std::string node = queue.dequeue();
            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                result.push_back(node);
                for (const auto& n : graph[node]) {
                    if (visited.find(n) == visited.end()) {
                        queue.enqueue(n);
                    }
                }
            }
        }
        return result;
    }

    void printGraph() {
        for (const auto& [node, neighbors] : graph) {
            std::cout << node << " (" << count[node] << "): ";
            for (const auto& neighbor : neighbors) {
                std::cout << neighbor << ",";
            }
            std::cout << std::endl;
        }
    }

    Graph restructurePlan() {
        Graph graph2;

        for (const auto& action1 : graph) {
            graph2.addNode(action1.first, count[action1.first]);
            for (const auto& action2 : graph) {
                if (action1.first != action2.first && count[action1.first] < count[action2.first]) {
                    graph2.addEdges(action1.first, action2.first);
                }
            }
        }

        return graph2;
    }

};

#endif // GRAPH_H