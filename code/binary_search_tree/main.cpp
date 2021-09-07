#include "bst.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    DI::BST Tree;

    Tree.Insert(5);
    Tree.Insert(6);
    Tree.Insert(4);
    Tree.Insert(10);
    Tree.Insert(11);
    Tree.Insert(1);

    if (Tree.Exist(6)) {
        std::cout << "Exist" << std::endl;
    } else {
        std::cout << "Do not Exist" << std::endl;
    }

    Tree.PrintInOrder();

    Tree.DeleteValue(6);

    if (Tree.Exist(6)) {
        std::cout << "Exist" << std::endl;
    } else {
        std::cout << "Do not Exist" << std::endl;
    }

    Tree.PrintInOrder();

    return 0;
}
