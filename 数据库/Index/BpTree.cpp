#include <vector>
#include "BpTreeNode.h"


template <typename KeyType>
class BTree {
    BTreeNode<KeyType>* root;
    int t;  // B树的最小度数（每个节点的最小孩子数）

public:
    BTree(int _t) {
        root = nullptr;
        t = _t;
    }

    void insert(KeyType key);
    BTreeNode<KeyType>* search(KeyType key);
    // 其他成员函数，如搜索键等。
};


//B树的插入操作
template <typename KeyType>
void BTree<KeyType>::insert(KeyType key) {
    // 如果根是空的，创建一个新的根
    if (root == nullptr) {
        root = new BTreeNode<KeyType>(true);
        root->keys.push_back(key);
        root->numKeys = 1;
    } else {
        // 如果根已满，树增长高度
        if (root->numKeys == 2*t - 1) {
            BTreeNode<KeyType>* newRoot = new BTreeNode<KeyType>(false);
            newRoot->children.push_back(root);
            // 分裂根节点
            // ...

            root = newRoot;
        }
        // 在合适的叶子节点中插入键
        // ...
    }
}

//B树的搜索操作
template <typename KeyType>
BTreeNode<KeyType>* BTree<KeyType>::search(KeyType key) {
    BTreeNode<KeyType>* current = root;
    while (current != nullptr) {
        // 找到合适的子节点
        // ...
    }
    return nullptr;  // 如果找不到
}


//B树的序列化和反序列化
template <typename KeyType>
BTreeNode<KeyType>* deserializeNode(std::string filename) {
    // 从文件中读取节点信息
    BTreeNode<KeyType>* node = new BTreeNode<KeyType>();
    // ...
    return node;
}

