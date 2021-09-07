#pragma once

namespace DI {
    struct BSTNode {
        BSTNode() {
            BSTNode* left = nullptr;
            BSTNode* right = nullptr;
        }

        BSTNode(int value) {
            data = value;
            BSTNode* left = nullptr;
            BSTNode* right = nullptr;
        }

        int data;
        BSTNode* left;
        BSTNode* right;
    };
    
    class BST {

    public:
        BST(/* args */);
        ~BST();
        void Insert(int value);
        int GetMin();
        int GetMax();
        void DeleteTree();
        void DeleteValue(int value);
        unsigned int GetHeight();
        bool Exist(int value);
        void PrintInOrder();

    private:
        BSTNode* root_ = nullptr;
        BSTNode* Insert_Internal (int value, BSTNode* node);
        BSTNode* GetMinNode(BSTNode* node);
        BSTNode* GetMaxNode(BSTNode* node);
        unsigned int GetHeight_Internal(BSTNode* node);
        void DeleteTree_Internal(BSTNode* node);
        BSTNode* SearchNode(int value, BSTNode* node);
        void PrintNodeInOrder(BSTNode* node);
        BSTNode* DeleteNode(int value, BSTNode* node);
        BSTNode* FindMinNode(BSTNode* node);
    };
}