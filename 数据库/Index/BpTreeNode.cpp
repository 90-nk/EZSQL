#include <iostream>
#include <vector>

template <typename KeyType>
/*
@Author:Guo Yu
*/
class BTreeNode {
    
public:
    std::vector<KeyType> keys;
    std::vector<BTreeNode*> children;
    bool isLeaf;
    int t;  // B树的最小度数（每个节点的最小孩子数）
    int numKeys;  //当前节点的键数

    BTreeNode(bool isLeaf);




    BTreeNode(int _t, bool _isLeaf) : t(_t), isLeaf(_isLeaf) {
        keys.resize(2*t-1); //最大键数
        children.resize(2*t); //最大孩子数
    }

    // 插入非满节点
    /*
    @brief:插入非满节点
    */
    void insertNonFull(KeyType key) {
    // 初始化i为最右边的键的索引
    int i = numKeys - 1;

    if (isLeaf) {
        // 当前节点是叶节点，找到合适的位置插入新键
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        numKeys++;  // 增加键的数量
    } else {
        // 当前节点不是叶节点，找到合适的子节点插入新键
        // 找到第一个小于等于key的子节点
        while (i >= 0 && keys[i] > key) {
            i--;
        }

        // 检查找到的子节点是否已满
        if (children[i + 1]->numKeys == 2*t - 1) {
            // 如果子节点已满，则先分裂该节点
            splitChild(i + 1, children[i + 1]);

            // 确定要插入的子节点
            if (keys[i + 1] < key) {
                i++;
            }
        }
        children[i + 1]->insertNonFull(key);
    }
}


// 分裂子节点
/*
@brief:分裂子节点
*/
    void splitChild(int i, BTreeNode *y) {
        // 创建一个新节点，它将存储(t-1)个键
        BTreeNode *z = new BTreeNode(y->t, y->isLeaf);
        z->numKeys = t - 1;

        // 将y的最后(t-1)个键复制到z
        for (int j = 0; j < t - 1; j++) {
            z->keys[j] = y->keys[j + t];
        }

        // 如果y不是叶节点，将y的最后t个子节点复制到z
        if (!y->isLeaf) {
            for (int j = 0; j < t; j++) {
                z->children[j] = y->children[j + t];
            }
        }

        // 减少y的键的数量
        y->numKeys = t - 1;

        // 由于这个节点将有一个新的子节点，所以为子节点腾出空间
        for (int j = numKeys; j >= i + 1; j--) {
            children[j + 1] = children[j];
        }

        // 将新的子节点链接到这个节点
        children[i + 1] = z;

        // 一个键将从y移动到这个节点。找到这个键的位置，并将所有更大的键向右移动一个位置
        for (int j = numKeys - 1; j >= i; j--) {
            keys[j + 1] = keys[j];
        }

        // 将y的中间键复制到这个节点
        keys[i] = y->keys[t - 1];

        // 增加这个节点的键计数
        numKeys = numKeys + 1;
    }


// 查找键
    BTreeNode<KeyType>* search(KeyType key) {
    // 找到第一个大于等于key的键的索引
    int i = 0;
    while (i < keys.size() && key > keys[i]) {
        i++;
    }

    // 如果找到了精确的键，则返回这个节点
    if (i < keys.size() && keys[i] == key) {
        return this;
    }

    // 如果这是一个叶节点，则键不在树中
    if (isLeaf) {
        return nullptr;
    }

    // 否则，在合适的子树中递归查找
    return children[i]->search(key);
}

//删除节点
    // void BTreeNode<KeyType>::remove(KeyType key) {







    //不知道会不会用到，先写着
    // 序列化节点
    void serializeNode(std::string filename) {

        // 将节点信息写入文件
    }

    // 反序列化节点
    BTreeNode* deserializeNode(std::string filename) {
        // 从文件中读取节点信息
        return nullptr;
    }

    friend class BTree;
};




int main () {
    BTreeNode<int> node(3, false);
    node.insertNonFull(1);
    node.insertNonFull(2);
    node.insertNonFull(3);
    node.insertNonFull(4);
    node.insertNonFull(5);
    node.insertNonFull(6);
    node.insertNonFull(7);
    node.insertNonFull(8);
    printf("%d\n", node.keys[0]);
    printf("%d\n", node.keys[1]);  
    printf("%d\n", node.keys[2]); 
    printf("%d\n", node.keys[5]); 
    printf("%d\n", node.keys[7]); 
    printf("%d\n", node.keys[11]); 

    return 0;
}