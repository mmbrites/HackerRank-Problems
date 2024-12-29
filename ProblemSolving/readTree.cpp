// This is not a HackerRank problem, but I did not know where to store it, so...

#include <iostream>
#include <queue>
#include <vector>

struct treeNode
{

    int number;
    treeNode * left;
    treeNode * right;

};

typedef treeNode * tree;

tree buildBinaryTreeRoot() 
{

    tree root = new treeNode;
    root->number = 1;
    root->left = NULL;
    root->right = NULL;
    return root;

}

int binaryTreeNodeChildren(treeNode * node) 
{

    int left = node->left == NULL;
    int right = node->right == NULL;

    if (left && right)
        return 0;
    else if (left || right)
        return 1;
    return 2;

}

void addBinaryTreeNode(int value, treeNode * node) 
{

    int children = binaryTreeNodeChildren(node);

    if (children == 0)
    {

        treeNode * newNode = new treeNode;
        newNode->number = value;
        node->left = newNode;
    
    }
    else if (children == 1)
    {

        treeNode * newNode = new treeNode;
        newNode->number = value;
        node->right = newNode;
    
    }
    else 
    {

        if (value % 2 == 0)
            addBinaryTreeNode(value, node->left);
        else
            addBinaryTreeNode(value, node->right);

    }

}

void printTreeNodesByLevel(treeNode * node) 
{

    // ROOT
    if (node)
        std::cout << node->number << std::endl;
    else
        return;

    std::queue<treeNode *> level;
    level.push(node);

    std::vector<treeNode *> currentLevel;

    do 
    {

        while(!level.empty()) 
        {

            treeNode * currentNode = level.front();
            if (currentNode->left)
                currentLevel.emplace_back(currentNode->left);
            if (currentNode->right)
                currentLevel.emplace_back(currentNode->right);
            level.pop();

        }

        for (treeNode * nodeInCurrentLevel : currentLevel)
        {
            std::cout << nodeInCurrentLevel->number << " ";
            level.push(nodeInCurrentLevel);
        }

        // Adding this condition removes a 'new line' from the output
        if (!currentLevel.empty())
            std::cout << std::endl;

        currentLevel.clear();
        
    } while (!level.empty());
    
}

int main() 
{

    tree root = buildBinaryTreeRoot();

    addBinaryTreeNode(2, root);
    addBinaryTreeNode(3, root);
    addBinaryTreeNode(4, root);
    addBinaryTreeNode(5, root);
    addBinaryTreeNode(6, root);

    printTreeNodesByLevel(root);

}