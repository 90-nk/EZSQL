// BPlusTree.h
#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <utility>

template <typename key_t, typename value_t>
class BPlusTree {
public:
    BPlusTree(int degree);
    BPlusTree(int degree, std::initializer_list<std::pair<const key_t, value_t>> items);
    ~BPlusTree();

    void insert(key_t key, value_t value);
    void remove(key_t key);
    void removeAll();
    value_t search(const key_t& key);
    void print();

private:
    struct Node {
        explicit Node(bool isLeaf = false);
        bool is_leaf;
        int size;
        std::vector<key_t> keys;
        std::vector<value_t> values;
        std::vector<Node*> children;
        Node* parent;
        Node* next;
        Node* prev;
    };

    Node* root;
    int degree;

    void split(Node* node);
    Node* find_leaf(key_t key);
    void remove_from_leaf(Node* leaf, const key_t& key);
    void borrow_from_left_leaf(Node* leaf, int i);
    void borrow_from_right_leaf(Node* leaf, int i);
    void merge_leaf(Node* left, Node* right, int i);
    void adjust(Node* node);
    void borrow_from_left(Node* node, int i);
    void borrow_from_right(Node* node, int i);
    void merge(Node* left, Node* right, int i);
};

#endif // BPLUSTREE_H
