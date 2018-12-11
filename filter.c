/*
 **********************************************
 *  CS314 Principles of Programming Languages *
 *  Fall 2018                                 *
 *  File: filter.c                            *
 *  Date: 11/25/2018                          *
 **********************************************
 */

#include "filter.h"

void count_unmatched_vertices(int threadId, int threadNum, int nodeNum,
                              int *nodeToProcess, int *res,
                              int *nodeCount)
{
    int numPer = (nodeNum+threadNum-1)/threadNum;
    int lB =  threadId*numPer;
    int uB = lB+numPer;
    int curr_node = 0;
    int i;
	nodeCount[threadId] = 0;
    if(uB>nodeNum)
    {
    	uB= nodeNum;
    } 
    for(i =lB;i<uB;i++){
    	curr_node=nodeToProcess[i];
    	
    	if(res[curr_node] == -1)
    	{
    		nodeCount[threadId]++;
    	}

    }
}

void update_remain_nodes_index(int threadId, int threadNum,
                               int *nodeToProcess, int *startLocations,
                               int *res,
                               int nodeNum, int *newNodeToProcess)
{
    int numPer = (nodeNum+threadNum-1)/threadNum;
    int lB =  threadId*numPer;
    int uB = lB+numPer;
   	int curr_node = 0;
   	int offset = 0;
   	int i;
    if(uB>nodeNum)
    {
    	uB = nodeNum;
    } 
    for(i =lB;i<uB;i++){
    	curr_node=nodeToProcess[i];
    	if(res[curr_node] == -1)
    	{
    		offset = startLocations[threadId]++;
    		newNodeToProcess[offset] = curr_node;
    	}

    }
}
