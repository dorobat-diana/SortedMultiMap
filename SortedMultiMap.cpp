#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

SortedMultiMap::SortedMultiMap(Relation relation_) {
	root = nullptr;
    relation = relation_;
    nrPairs = 0;
}

void SortedMultiMap::add(TKey key, TValue value) {
    // Find the correct position for the new node
    TreeNode* currentNode = root;
    TreeNode* parentNode = nullptr;
    while (currentNode != nullptr && currentNode->key != key) {
        parentNode = currentNode;
        if (relation(key, currentNode->key)) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    if (currentNode != nullptr) { // The key already exists
        currentNode->values.push_back(value);
    } else {
        auto* newNode = new TreeNode;
        newNode->key = key;
        newNode->values.push_back(value);
        if (parentNode == nullptr) {
            root = newNode;
        } else if (relation(key, parentNode->key)) {
            parentNode->left = newNode;
            newNode->parent = parentNode;
        } else {
            parentNode->right = newNode;
            newNode->parent = parentNode;
        }
    }
    nrPairs++;
}

vector<TValue> SortedMultiMap::search(TKey key) const {
    vector<TValue> values;
    TreeNode* currentNode = root;
    while (currentNode != nullptr && currentNode->key != key) {
        if (relation(key, currentNode->key)) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    if (currentNode != nullptr) {
        values = currentNode->values;
    }
    return values;
}

// TODO: there may be a problem with the parent pointer
bool SortedMultiMap::remove(TKey c, TValue v) {
    TreeNode* currentNode = root;
    TreeNode* parentNode = nullptr;
    while (currentNode != nullptr && currentNode->key != c) {
        parentNode = currentNode;
        if (relation(c, currentNode->key)) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    if (currentNode == nullptr) { /// The key doesn't exist
        return false;
    }
    for (int i = 0; i < currentNode->values.size(); i++) {
        if (currentNode->values[i] == v) { /// The value exists
            currentNode->values.erase(currentNode->values.begin() + i);
            if (currentNode->values.empty()) { /// The node has no values left => delete it
                if (currentNode->left == nullptr && currentNode->right == nullptr) { /// The node is a leaf => delete it
                    if (parentNode == nullptr) {    /// The node is the root
                        root = nullptr;
                    } else if (parentNode->left == currentNode) {   /// The node is the left child of its parent
                        parentNode->left = nullptr;
                    } else {    /// The node is the right child of its parent
                        parentNode->right = nullptr;
                    }
                    delete currentNode;
                } else if (currentNode->left == nullptr) {      /// The node has only a right child
                    if (parentNode == nullptr) {    /// The node is the root => make its right child the new root
                        root = currentNode->right;
                        currentNode->right->parent = nullptr;
                    } else if (parentNode->left == currentNode) {   /// The node is the left child of its parent
                        parentNode->left = currentNode->right;
                        currentNode->right->parent = parentNode;
                    } else {
                        parentNode->right = currentNode->right;
                        currentNode->right->parent = parentNode;
                    }
                    delete currentNode;
                } else if (currentNode->right == nullptr) {     /// The node has only a left child
                    if (parentNode == nullptr) {
                        root = currentNode->left;
                        currentNode->left->parent = nullptr;
                    } else if (parentNode->left == currentNode) {
                        parentNode->left = currentNode->left;
                        currentNode->left->parent = parentNode;
                    } else {
                        parentNode->right = currentNode->left;
                        currentNode->left->parent = parentNode;
                    }
                    delete currentNode;
                } else {   /// The node has both children
                    TreeNode* successor = currentNode->right;  /// Find the successor of the node
                    TreeNode* successorParent = currentNode;
                    while (successor->left != nullptr) {  /// The successor is the leftmost node in the right subtree
                        successorParent = successor;
                        successor = successor->left;
                    }
                    currentNode->key = successor->key;  /// Replace the key and values of the node with the key and values of the successor
                    currentNode->values = successor->values;
                    if (successorParent->left == successor) {   /// if the successor is the left child of its parent
                        successorParent->left = successor->right;
                        successor->right->parent = successorParent;
                    } else {
                        successorParent->right = successor->right;
                        successor->right->parent = successorParent;
                    }
                    delete successor;
                }
            }
            nrPairs--;
            return true;
        }
    }
    return false;
}


int SortedMultiMap::size() const {
	return nrPairs;
}

bool SortedMultiMap::isEmpty() const {
	return nrPairs == 0;
}

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap() {
    deleteAllNodes(root);
}

void SortedMultiMap::deleteAllNodes(TreeNode *node) {
    if (node != nullptr) {
        deleteAllNodes(node->left);
        deleteAllNodes(node->right);
        delete node;
    }
}

void SortedMultiMap::replace(TKey key, TValue oldValue, TValue newValue) {
    TreeNode* currentNode = root;
    while (currentNode != nullptr && currentNode->key != key) {
        if (relation(key, currentNode->key)) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    if (currentNode != nullptr) {
        for (int & value : currentNode->values) {
            if (value == oldValue) {
                value = newValue;
            }
        }
    }

}

int SortedMultiMap::trimValues(int k) {
    vector<TValue> values2 = vector<TValue>();
    int total = 0;
    for(int j=0;j<size();j++){
        values2=search(j);
        if (values2.size() > k){
            int maxim= values2.size()-k;
            for(int i=0;i<maxim;i++) {
                remove(k, values2[i]);
                total++;
            }
        }
    }
    return total;
}