/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

using namespace std;

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here

    Node * tmp = t -> right;
    t -> right = tmp -> left;
    tmp -> left = t;
    t -> height = 1 + max(heightOrNeg1(t->left), heightOrNeg1(t->right));
    t = tmp;
    t -> height = 1 + max(heightOrNeg1(t->left), heightOrNeg1(t->right));
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight");  // Stores the rotation name (don't remove this)
    
    Node * tmp = t -> left;
    t -> left = tmp -> right;
    tmp -> right = t;
    t->height = 1 + max(heightOrNeg1(t->left), heightOrNeg1(t->right));
    t = tmp;
    t->height = 1 + max(heightOrNeg1(t->left), heightOrNeg1(t->right));

}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here

    rotateRight(t -> right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here

    if (subtree == NULL) {
        return;
    }

    int left_h = heightOrNeg1(subtree->left);
    int right_h = heightOrNeg1(subtree->right);

    int difference = left_h - right_h;

    if (difference < -1){
        int right_balanced = heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left);
        if (right_balanced == 1){
            rotateLeft(subtree);
        } else {
            rotateRightLeft(subtree);
        }
    } 
    
    else if(difference > 1) {
        int left_balanced = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left);
        if(left_balanced == -1){
            rotateRight(subtree);
        } else {
            rotateLeftRight(subtree);
        }
    }

    subtree->height = heightOrNeg1(subtree->left) > heightOrNeg1(subtree->right) ? heightOrNeg1(subtree->left) : heightOrNeg1(subtree->right);
    subtree->height = subtree->height + 1;
}



template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here

    if (subtree == NULL) {
        subtree = new Node(key, value);
    }
    else if (subtree->key < key) {
        insert(subtree->right, key, value);
    }
    else if (subtree->key > key) {
        insert(subtree->left, key, value);
    }
    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here

        remove(subtree -> left, key);
        rebalance(subtree);
    } else if (key > subtree->key) {
        // your code here

        remove(subtree -> right, key);
        rebalance(subtree);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here

            delete subtree;
            subtree = NULL;

        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here

            Node * tmp = subtree -> left;
            while (tmp -> right != NULL) {
                tmp = tmp -> right;
            }
            subtree -> key = tmp -> key;
            subtree -> value = tmp -> value;

            remove(subtree -> left, tmp -> key);
            rebalance(subtree);
            
        } else {
            /* one-child remove */
            // your code here

            Node *tempTree = (subtree->right == NULL) ? subtree->left : subtree->right;
            *subtree = *tempTree;
            delete tempTree;
            tempTree = NULL; 
            
        }
        // your code here
        rebalance(subtree);
    }
}