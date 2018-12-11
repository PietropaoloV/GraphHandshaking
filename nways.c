/*
 **********************************************
 *  CS314 Principles of Programming Languages *
 *  Fall 2018                                 *
 *  File: nways.c                             *
 *  Date: 11/25/2018                          *
 **********************************************
 */

#include "nways.h"
#include "utils.h"

void generate_n_way_graph(int threadId, int threadNum,
                          GraphData graph, int nWays,
                          int nodeNum, int *nodeToProcess,
                          int *res,
                          int *nWayGraphDegree, int *nWayGraph)
{
   	int curr_node = 0;
    int numPer = (nodeNum+threadNum-1)/threadNum;
    int lB =  threadId*numPer;
    int uB = lB+numPer;
    if(uB>nodeNum)
    {
    	uB= nodeNum;
    }
     
}


void prune_n_way_graph(int threadId, int threadNum, int nWays,
                                  int nodeNum, int *nodeToProcess,
                                  int *nWayGraphDegree, int *nWayGraph,
                                  int *strongNeighbor)
{
    /* Your Code Goes Here */
}

