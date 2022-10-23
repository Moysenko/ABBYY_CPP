#include <vector>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print_dfs(TreeNode* node) {
  std::cout << node->val << ' ';
  if (node->left) {
    print_dfs(node->left);
  } else {
    std::cout << "NONE ";
  }
  if (node->right) {
    print_dfs(node->right);;
  } else {
    std::cout << "NONE ";
  }
}

class Solution {
public:
  std::vector<TreeNode*> generateTrees(int n) {
    std::vector<TreeNode*> trees[n + 1][n + 1];
    for (int i = 0; i < n; i++) {
      trees[i][i] = { nullptr };
      trees[i][i + 1] = { new TreeNode(i + 1, nullptr, nullptr) };
    }
    trees[n][n] = { nullptr };

    for (int len = 2; len <= n; len++) {
      for (int left = 0; left + len <= n; left++) {
        int right = left + len;
        for (int root = left; root < right; root++) {
          for (auto left_child: trees[left][root]) {
            for (auto right_child: trees[root + 1][right]) {
              trees[left][right].push_back(new TreeNode(root + 1, left_child, right_child));
            }
          }
        }
      }
    }

    return trees[0][n];
  }
};