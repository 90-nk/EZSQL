#include <iostream>
#include <vector>

template <typename KeyType>

class BTreeNode {
    public:
        std::vector<KeyType> keys;
        std::vector<BTreeNode*> children;
        bool isLeaf;
        int numKeys;
        BTreeNode(bool isLeaf);
}