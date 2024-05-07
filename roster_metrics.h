#ifndef ROSTER_METRICS_H
#define ROSTER_METRICS_H
#include "AVL_Tree.h"
class roster_metrics {
    private:
        AVL_Tree playerTree;
        AVL_Tree performanceTree;
        AVL_Tree gameTree;
    public:
        // constructor
        roster_metrics();

        // mutator functions
        void record(int game, int player, int points);
        void clear(int game, int player);

        // accessor functions
        int ranked_receiver(int rank);
};

#endif
