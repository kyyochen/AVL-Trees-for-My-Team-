#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
using namespace std;

struct AVLTreeNode
{
   int key;
   int secondValue;
   AVLTreeNode *left;
   AVLTreeNode *right;
   AVLTreeNode *parent;
   AVL_Tree *nextTree;
   char balanceFactor;
};

class AVL_Tree
{
   private:
      AVLTreeNode* root;
      void ClearTree(AVLTreeNode *n);
      void Print(AVLTreeNode *n);
   public:
      AVL_Tree();            // Constructor
      ~AVL_Tree();           // Destructor
      void Insert(AVLTreeNode *n);
      void restoreAVL(AVLTreeNode *ancestor, AVLTreeNode *newNode);
      void adjustBalanceFactors(AVLTreeNode *end, AVLTreeNode *start);
      void rotateLeft(AVLTreeNode *n);
      void rotateRight(AVLTreeNode *n);
      void adjustLeftRight(AVLTreeNode *end, AVLTreeNode *start);
      void adjustRightLeft(AVLTreeNode *end, AVLTreeNode *start);
      void PrintTree();

      // NOT YET IMPLEMENTED
      int Predecessor(int key);
      int Successor(int key);
      void Delete(int key);
      AVLTreeNode* search(int key);
      AVLTreeNode* getRoot() const;
      AVLTreeNode* findMax(AVLTreeNode* node);


};

#endif
