#include "bst.h"
#include <algorithm>
#include <iostream>

namespace DI {
    BST::BST() {}
    BST::~BST() { DeleteTree(); }

    void BST::Insert(int value) {
        if (root_ == nullptr) {
            root_= new BSTNode(value);
            return;
        }

        if (value < root_->data) {
            root_->left = Insert_Internal(value, root_->left);
            return;
        }

        if (value > root_->data) {
            root_->right = Insert_Internal(value, root_->right);
            return;
        }
    }

    int BST::GetMin() {
        if (root_ == nullptr) {
            return -1;
        }

        return GetMinNode(root_)->data;
    }

    int BST::GetMax() {
        if (root_ == nullptr) {
            return -1;
        }

        return GetMaxNode(root_)->data;
    }

    void BST::DeleteTree() {
        DeleteTree_Internal(root_);
        return;
    }

    void BST::DeleteValue(int value) {
        if (root_ != nullptr)
        {
            DeleteNode(value, root_);
        }
    }

    unsigned int BST::GetHeight() {
        if (root_ == nullptr) { return 0; }

        return 1 + std::max(GetHeight_Internal(root_->left), GetHeight_Internal(root_->right));
    }

    bool BST::Exist(int value) {
        BSTNode* node = SearchNode(value, root_);

        if (node != nullptr) {
            return true;
        }

        return false;
    }

    void BST::PrintInOrder() {
        if (root_ == nullptr) {
            return;
        }

        PrintNodeInOrder(root_);
        
    }

    BSTNode* BST::Insert_Internal(int value, BSTNode* node) {
        if (node == nullptr) {
            node = new BSTNode(value);
            return node;
        }
        
        if (value < node->data) {
            node->left = Insert_Internal(value, node->left);
            return node;
        }

        if (value > node->data) {
            node->right = Insert_Internal(value, node->right);
            return node;
        }

        return node;
    }

    BSTNode* BST::GetMinNode(BSTNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->left == nullptr) {
            return node;
        }

        return GetMinNode(node);
    }

    BSTNode* BST::GetMaxNode(BSTNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->right == nullptr) {
            return node;
        }

        return GetMaxNode(node);
    }

    unsigned int BST::GetHeight_Internal(BSTNode* node) {
        if (node == nullptr) { return 0; }
        
        return 1 + std::max(GetHeight_Internal(node->left), GetHeight_Internal(node->right));
    }

    void BST::DeleteTree_Internal(BSTNode* node) {
        if (node == nullptr) {
            return;
        }

        if (node->left != nullptr) DeleteTree_Internal(node->left);
        if (node->right != nullptr) DeleteTree_Internal(node->right);
        
        delete node;
    }

    BSTNode* BST::SearchNode(int value, BSTNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value == node->data) {
            return node;
        }

        if (value > node->data) return SearchNode(value, node->right);
        if (value < node->data) return SearchNode(value, node->left);
        
        return nullptr;
    }

    void BST::PrintNodeInOrder(BSTNode* node) {
        if (node == nullptr)
        {
            return;
        }

        if (node->left != nullptr)
        {
            PrintNodeInOrder(node->left);
        }

        std::cout << node->data << " ";

        if (node->right != nullptr)
        {
            PrintNodeInOrder(node->right);
        } 
    }
    // need to refactor this method. Wrong recursion
    BSTNode* BST::DeleteNode(int value, BSTNode* node) {
        if (node == nullptr) { return nullptr; }

        if (value > node->data) {
            node->right = DeleteNode(value, node->right);
            return node;
        }

        if (value < node->data) {
            node->left = DeleteNode(value, node->left);
            return node;
        }

        if (node->left == nullptr && node->right == nullptr) {//leaf node, easy to delete
            delete node;
            node = nullptr;
            return node;
        }

        if (node->left == nullptr) {
            BSTNode* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            BSTNode* temp = node;
            node = node->left;
            delete temp;
        } else {
            BSTNode* min_node = FindMinNode(node->right);
            node->data = min_node->data;//swap data
            node->right = DeleteNode(node->data, node->right);
        }

        return node;
    }

    BSTNode* BST::FindMinNode(BSTNode* node) {
        if (node->left != nullptr)
        {
            return FindMinNode(node->left);
        }

        return node;
    }
}