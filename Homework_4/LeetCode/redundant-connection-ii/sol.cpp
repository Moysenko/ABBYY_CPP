#include <vector>
#include <queue>
#include <stdexcept>

class Solution {
public:
    std::vector<int> findRedundantDirectedConnection(
        std::vector<std::vector<int>>& edges) {
      int p2 = -1;  // index of vertex with 2 parents

      for (const auto& edge: edges) {
        parents[edge[1]].push_back(edge[0]);
        ++out_count[edge[0]];
        
        if (parents[edge[1]].size() == 2) {
          p2 = edge[1];
        }
      }

      std::queue<int> q;
      for (size_t i = 0; i < MAX_N; i++) {
        if (out_count[i] == 0) {
          q.push(i);
        }
      }

      while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (parents[v].size() > 1) {
          return {parents[v][1], v};
        }

        for (size_t p: parents[v]) {
          --out_count[p];
          if (out_count[p] == 0) {
            q.push(p);
          }
        }

        parents[v].clear();
      }


      if (p2 == -1) {  // it is circle
        for (int e = edges.size() - 1; e >= 0; e--) {
          if (!parents[edges[e][1]].empty()) {
            return edges[e];
          }
        }
      } else {
        int v = parents[p2][0];
        while (!parents[v].empty() && v != p2) {
          v = parents[v][0];
        }
        
        if (v == p2) {
          return {parents[p2][0], p2};
        } else {
          return {parents[p2][1], p2};
        }
      }

      throw std::invalid_argument("There is no rooted directed subtree");
    }

    static const size_t MAX_N = 1001;
    std::vector<int> parents[MAX_N];
    size_t out_count[MAX_N];
};