#include <algorithm>
#include <iterator>
#include <list>


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) { return {}; }
        
        // Iterators for node-based containers such as list are not invalidated upon insertion/deletion unlike those for sequence-based containers such as vector, deque, default queue (which uses a deque), etc
        list<list<TreeNode*>> levelQueue {{root}};
        
        // Modified Breadth-First Search
        for (auto levelIter = levelQueue.begin(); levelIter != levelQueue.end(); ++levelIter) {
            for (auto node : *levelIter) {
                auto addChildNode = [&levelQueue, levelIter](TreeNode* child){
                    if (child == nullptr) {
                        return;
                    }
                    
                    if (std::next(levelIter) == levelQueue.end()) {
                        levelQueue.push_back({});
                    }
                    
                    levelQueue.back().push_back(child);
                };
                
                addChildNode(node->left);
                addChildNode(node->right);
            }
        }
        
        // Transfer data from list to required vector format
        vector<vector<int>> out(levelQueue.size());
        auto levelIter = levelQueue.cbegin();
        for (auto outIter = out.begin(); outIter != out.end(); ++outIter, ++levelIter) {
            outIter->resize(levelIter->size());
            std::transform(levelIter->cbegin(), levelIter->cend(), outIter->begin(),
                           [](auto* node){ return node->val; });
        }
        return out;
    }
};