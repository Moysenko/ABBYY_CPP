#include <vector>
#include <set>

class Solution {
public:
  const int INF = 1e7;

  struct Edge {
    Edge(int to, int weight) : to(to), weight(weight) {}
    int to;
    int weight;
  };

  std::vector<std::vector<int>> findCriticalAndPseudoCriticalEdges(int n, std::vector<std::vector<int>>& edges) {
    int full_spantree_weight = Prim(n, edges);
    std::vector<int> critical, pseudo_critical;
    for (int i = 0; i < edges.size(); i++) {
      int save_weight = edges[i][2];

      edges[i][2] = INF;  // same as delete
      if (full_spantree_weight < Prim(n, edges)) {
        critical.push_back(i);
      } else {
        edges[i][2] = 0;  // same as merge
        if (full_spantree_weight == Prim(n, edges) + save_weight){
          pseudo_critical.push_back(i);
        }
      }

      edges[i][2] = save_weight;
    }
    return {critical, pseudo_critical};
  }

  int Prim(int n, const std::vector<std::vector<int>>& edges) {  
    std::vector<bool> in_spanning_tree(n, false);
    std::vector<Edge> parsed_edges[n];
    int answer = 0;

    for (const auto& edge: edges) {
      parsed_edges[edge[0]].emplace_back(edge[1], edge[2]);
      parsed_edges[edge[1]].emplace_back(edge[0], edge[2]);
    }

    std::set<std::pair<int, int>> edges_queue;  // {edge.weight, edge.to}
    edges_queue.emplace(0, 0);

    for (int i = 0; i < n; i++) {
      while (!edges_queue.empty() && in_spanning_tree[edges_queue.begin()->second]) {
        edges_queue.erase(edges_queue.begin());
      }

      if (edges_queue.empty()) {
        answer = INF;
        break;
      }

      auto& [weight, to_add] = *edges_queue.begin();
      answer += weight;

      in_spanning_tree[to_add] = true;
      for (const auto& edge: parsed_edges[to_add]) {
        if (!in_spanning_tree[edge.to]) {
          edges_queue.emplace(edge.weight, edge.to);
        }
      }
    }

    return answer;
  }
};