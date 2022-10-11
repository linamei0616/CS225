/**
 * @file bst.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V BST<K, V>::find(const K& key)
{
    // your code here
    return find(root, key)->value;

}

template <class K, class V>
struct BST<K, V>::Node* & BST<K, V>::find(Node* & subtree, const K& key)
{
    BST<K,V> to_return;
    // Your code here
    if (subtree == NULL || subtree->key == key) {
        return subtree;
    }
    if (key < subtree->key) {
        return find(subtree->left, key);
    } else {
        return find(subtree->right, key);
    }
}

template <class K, class V>
void BST<K, V>::insert(const K & key, const V & value)
{
    return insert(root, key, value);
}

template <class K, class V>
void BST<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if (subtree == NULL) {
        Node* new_root = new Node(key, value);
        subtree = new_root;
        return;
    }
    if (key > subtree->key) {
        insert(subtree->right, key, value);
    } else if (key < subtree->key) {
        insert(subtree->left, key, value);
    }
    return;
}

template <class K, class V>
void BST<K, V>::swap(Node*& first, Node*& second)
{
    // your code here
    K temp_key = first->key;
    V temp_value = first->value;

    first->value = second->value;
    first->key = second->key;

    second->key = temp_key;
    second->value = temp_value;
}

template <class K, class V>
void BST<K, V>::remove(const K& key)
{
    // your code here
    if (!find(root, key)) {
        return;
    }
    remove(root, key);
}

template <class K, class V>
void BST<K, V>::remove(Node*& subtree, const K& key)
{
    // your code here
    if (subtree == NULL) {
        return;
    }
    Node* & to_remove = find(subtree, key);
    if (to_remove->right == NULL && to_remove->left == NULL) {
        delete to_remove;
        to_remove = NULL;
        return;
    }
    if (to_remove->right != NULL && to_remove->left == NULL) {
        Node* right = to_remove->right;
        delete to_remove;
        to_remove = right;
        return;

    }
    if (to_remove->right == NULL && to_remove->left != NULL) {
        Node* left = to_remove->left;
        delete to_remove;
        to_remove = left;
        return;
    } // otherwise
    Node* temp = to_remove->left;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    if (temp->right != NULL) {
        swap(temp, to_remove);
        remove(to_remove->left, temp->key);
    } else {
        swap(temp, to_remove);
        remove(to_remove->left, temp->key);
    } 
}

template <class K, class V>
BST<K, V> listBuild(std::vector<std::pair<K, V>> inList){
    // your code here
    BST<K, V> bst;
    for (std::pair<K,V> pair: inList) {
        bst.insert(pair.first, pair.second);
    }
    return bst;
}

template <class K, class V>
std::vector<int> allBuild(std::vector<std::pair<K, V>> inList){
    // your code here
    std::vector<int> v;
    std::sort (inList.begin(), inList.end());

    do {
        BST<K,V> bst = listBuild(inList);
        unsigned height = bst.height();

        if (v.size() == 0 || height > v.size()) {
            for (unsigned i = v.size(); i <= height; ++i) {
                v.push_back(0);
            }
        }
        v.at(bst.height()) = v.at(bst.height()) + 1;

    }   while (std::next_permutation(inList.begin(), inList.end()));
    return v;
}