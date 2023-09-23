#include "SMMIterator.h"
#include "SortedMultiMap.h"

SMMIterator::SMMIterator( const SortedMultiMap& d) : map(d){
    // Find the leftmost node
    currentNode = map.root;
    while(currentNode != nullptr && currentNode->left != nullptr)
        currentNode = currentNode->left;

    currentElementIndex = 0;
}

void SMMIterator::first(){
    // Find the leftmost node
    currentNode = map.root;
    while(currentNode != nullptr && currentNode->left != nullptr)
        currentNode = currentNode->left;

    currentElementIndex = 0;
}

void SMMIterator::next(){
	if(currentNode == nullptr)
        throw exception();
    if(currentElementIndex < currentNode->values.size() - 1)    /// if there are more values for the current key
        currentElementIndex++;                            /// go to the next value for the current key
    else{                                              /// if there are no more values for the current key => go to the next key
        if(currentNode->right != nullptr){
            currentNode = currentNode->right;
            while(currentNode->left != nullptr)
                currentNode = currentNode->left;
        }
        else{
            while(currentNode->parent != nullptr && currentNode->parent->left != currentNode)
                currentNode = currentNode->parent;
            if(currentNode->parent == nullptr)
                currentNode = nullptr;
            else
                currentNode = currentNode->parent;
        }
        currentElementIndex = 0;
    }
}

bool SMMIterator::valid() const{
	if(currentNode == nullptr)
        return false;
    return true;
}

TElem SMMIterator::getCurrent() const{
	if(currentNode == nullptr)
        throw exception();
    return make_pair(currentNode->key, currentNode->values[currentElementIndex]);
}


