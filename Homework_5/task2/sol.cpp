#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
  const int INF = 1e9;

  int minCostConnectPoints(std::vector<std::vector<int>>& points) {
    size_t n = points.size();
    std::vector<int> distance_to_tree(n, INF);
    int next_to_add = 0;

    int answer = 0;
    for (int i = 0; i < n - 1; i++) {
      distance_to_tree[next_to_add] = 0;

      int min_distance = INF;
      int last_added = next_to_add;
      for (int i = 0; i < n; i++) {
        if (distance_to_tree[i] == 0) continue;
        distance_to_tree[i] = std::min(distance_to_tree[i], GetDist(points[i], points[last_added]));

        if (distance_to_tree[i] < min_distance) {
          min_distance = distance_to_tree[i];
          next_to_add = i;
        }
      }
      answer += min_distance;

      // std::cout << "last_added=" << last_added
      //           << ", next_to_add=" << next_to_add
      //           << ", min_distance=" << min_distance
      //           << std::endl;
    }

    return answer;
  }

  int GetDist(const std::vector<int>& from, const std::vector<int>& to) {
    int dist = 0;
    for (int i = 0; i < from.size(); i++) {
      dist += std::abs(from[i] - to[i]);
    }
    return dist;
  }
};