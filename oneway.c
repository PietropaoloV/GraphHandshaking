/*
 **********************************************
 *  CS314 Principles of Programming Languages *
 *  Fall 2018                                 *
 *  File: oneway.c                            *
 *  Date: 11/25/2018                          *
 **********************************************
 */
#include "oneway.h"
#include "utils.h"

void extend_one_hand(int threadId, int threadNum, GraphData graph,
                     int nodeNum, int *nodeToProcess,
                     int *res, int *strongNeighbor)
{
	int curr_node = 0;
    
    int numPer = (nodeNum+threadNum-1)/threadNum;
    int lB =  threadId*numPer;
    int uB = lB+numPer;
    if(uB>nodeNum)
    {
    	uB= nodeNum;
    } 
    int i;
    int j;
	int* n;
    for(i =lB;i<uB;i++){
   		curr_node=nodeToProcess[i];
		int degree = graph.degree[curr_node];
		int offset = graph.offset[curr_node];
		n = graph.index+offset;
		strongNeighbor[curr_node] = -1;
		for(j = 0; j<degree;j++){
			if(res[n[j]] == -1){
				strongNeighbor[curr_node] = n[j];
				break;
			}
		}
	}
}

void check_handshaking(int threadId, int threadNum,
                       int nodeNum, int *nodeToProcess,
                       int *strongNeighbor, int *res)
{
	int numPer = (nodeNum+threadNum-1)/threadNum;
    int lB =  threadId*numPer;
    int uB = lB+numPer;
    int curr_node = 0;
    int i;
    if(uB>nodeNum)
    {
    	uB= nodeNum;
    } 
   for( i =lB;i<uB;i++){
   		curr_node=nodeToProcess[i];
   		int s = strongNeighbor[curr_node];
   		if(s==-1){
   			res[curr_node] = -2;
   		}
   		else if(curr_node == strongNeighbor[s]){
   				res[curr_node] = s;
   			}

   		}
}


