#include "roster_metrics.h"
using namespace std;

roster_metrics::roster_metrics() {
    gameTree = AVL_Tree();
    performanceTree = AVL_Tree();
}

// mutator functions

//record(g, r, p) | record p points for jersey r in game g
void roster_metrics::record(int game, int player, int points) {
    //record tree by game
    
    //check if game exists
    AVLTreeNode* gameNode = gameTree.search(game);
    if (gameNode == nullptr) {
        // If the game node doesn't exist, create a new one
        gameNode = new AVLTreeNode();
        gameNode->key = game;
        gameNode->secondValue = 0;
        gameNode->left = nullptr;
        gameNode->right = nullptr;
        gameNode->parent = nullptr;
        gameNode->balanceFactor = '=';
        gameNode->nextTree = new AVL_Tree(); //avl tree for players/jerseys this game
        gameTree.Insert(gameNode);
    }

    //record tree by jersey
    AVLTreeNode *playerNode = new AVLTreeNode();
    playerNode->key = player;
    playerNode->secondValue = points;
    playerNode->left = nullptr;
    playerNode->right = nullptr;
    playerNode->parent = nullptr;
    playerNode->balanceFactor = '=';
    gameNode->nextTree->Insert(playerNode);

    //record tree by performance
    AVLTreeNode *performanceNode = new AVLTreeNode();
    performanceNode->key = points;
    performanceNode->secondValue = player;
    performanceNode->left = nullptr;
    performanceNode->right = nullptr;
    performanceNode->parent = nullptr;
    performanceTree.Insert(performanceNode);

}

//clear(g, r) | remove any record that jersey r played in game g
void roster_metrics::clear(int game, int player) {
    //find game node g in game tree
    //go to player tree
    //ClearTree (AVLTreeNode *n)
    AVLTreeNode *gameNode = gameTree.search(game);
    if (gameNode != nullptr) {
        
        //delete player from game if player exists and played
        AVLTreeNode *playerNode = gameNode->nextTree->search(player);
        if (playerNode != nullptr) {
            gameNode->nextTree->Delete(player);
        }
    
        //delete points from that game from performance tree
        AVLTreeNode *performanceNode = performanceTree.search(playerNode->secondValue);
        if (performanceNode != nullptr) {

        }


    }
}

// accessor functions
//ranked receiver(k) | return the jersey with the kth highest performance
    //look at performance tree
    // Traverse to rightmost node
    //go back k-1 steps and return the player at that node
    //recursively call successor until end, then recrusively call predecessor k-1 times

int roster_metrics::ranked_receiver(int rank) {
    // go to rightmost point
    AVLTreeNode* current = performanceTree.getRoot();
    while (current != nullptr && current->right != nullptr) {
        current = current->right;
    }

    // go back k-1 positions
    for (int i = 0; i < rank - 1 && current != nullptr; ++i) {
        int predecessorKey = performanceTree.Predecessor(current->key);
        if (predecessorKey == -1) {
            return -1; // rank not found
        }
        current = performanceTree.search(predecessorKey);
    }

    // return player
    if (current != nullptr) {
        return current->secondValue;
    } else {
        return -1; // rank not found
    }
}
