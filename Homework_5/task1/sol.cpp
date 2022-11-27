#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

class Solution {
public:
    struct Edge {
      Edge(int to, int weight) : to(to), weight(weight) {}
      int to;
      int weight;
    };

    const long long INF = 1e12;

    std::vector<long long> GetDistances(int n, std::vector<Edge> *graph, int root) {
      std::vector<long long> distances(n, INF);
      std::set<std::pair<long long, int>> distances_heap;
      distances[root] = 0;

      for (int i = 0; i < n; i++) {
        distances_heap.emplace(distances[i], i);
      }

      while (!distances_heap.empty()) {
        auto [distance, top] = *distances_heap.begin();
        distances_heap.erase(distances_heap.begin());

        if (distances[top] == INF) break;

        for (auto& edge: graph[top]) {
          if (!distances_heap.count({distances[edge.to], edge.to})) continue;

          distances_heap.erase(distances_heap.find({distances[edge.to], edge.to}));
          distances[edge.to] = std::min(distances[edge.to], distances[top] + edge.weight);
          distances_heap.insert({distances[edge.to], edge.to});
        }
      }

      return distances;
    }

    long long minimumWeight(int n, std::vector<std::vector<int>>& edges, int src1, int src2, int dest) {
      std::vector<Edge> graph[n];
      std::vector<Edge> reversed_graph[n];

      for (auto& edge: edges) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
        reversed_graph[edge[1]].emplace_back(edge[0], edge[2]);
      }        

      auto src1_distances = GetDistances(n, graph, src1);
      auto src2_distances = GetDistances(n, graph, src2);
      auto dest_distances = GetDistances(n, reversed_graph, dest);

      long long answer = INF;
      for (int first_common_vertex = 0; first_common_vertex < n; ++first_common_vertex) {
        answer = std::min(answer, 
          src1_distances[first_common_vertex] + 
          src2_distances[first_common_vertex] + 
          dest_distances[first_common_vertex]);
      }

      return answer == INF ? -1 : answer;
    }
};