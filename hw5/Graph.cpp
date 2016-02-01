/**
 * @filename Graph.hpp
 * @author   Yanjia Huang <yanjia.huang.tw@gmail.com>
 */

#include <list>
#include <iostream>
#include <climits>
#include "Graph.hpp"

using namespace std;

Graph::Graph( int& NVertex ) {
    NumVertex = NVertex;

    for( int i = 0; i < NVertex; i++ ) {
        list<AdjNode> NodeList;
        AdjList.push_back( NodeList );
    }

    alreadyATree = new bool[NumVertex];
    for( int i = 0; i < NumVertex; ++i ) alreadyATree[i] = false;
    alreadyATree[0] = true;

    myList = new vector<AdjNode>[NumVertex];

}

void Graph::AddNode( int& first, int& second, int& weight ) {

    AdjNode NewNode;
    NewNode.index = second;
    NewNode.weight = weight;
    AdjList[first].push_back( NewNode );

    NewNode.index = first;
    NewNode.weight = weight;
    AdjList[second].push_back( NewNode );


}

void Graph::MST( vector<Edge>& Answer ) {

    for(int i = 0; i < NumVertex; ++i ) {
        while ( !AdjList[i].empty() ) {
            myList[i].push_back( AdjList[i].front() );
            AdjList[i].pop_front();
        }
    }
    while ( notYet() ) {
        findNextEdge( Answer );
    }
}

bool Graph::notYet() {
    for( int i = 0; i < NumVertex; ++i)
        if ( alreadyATree[i] == false ) return true;
    return false;
}

void Graph::findNextEdge( vector<Edge>& ans ) {
    Edge temp_min(0, 0, INT_MAX);
    for( int i = 0; i < NumVertex; ++i ) {
        if ( alreadyATree[i] ) {
            for( int j = 0; j < static_cast<int>(myList[i].size()); ++j ) {
                if ( myList[i][j].weight <= temp_min.weight ) {
                    temp_min = Edge( i, myList[i][j].index, myList[i][j].weight );
                }
            }
        }
    }

    if ( alreadyATree[temp_min.SecondNode] == false ) {

        int push_F, push_S, push_W = temp_min.weight;

        if ( temp_min.FirstNode > temp_min.SecondNode) {
            push_F = temp_min.SecondNode, push_S = temp_min.FirstNode;
        }else {
            push_S = temp_min.SecondNode, push_F = temp_min.FirstNode;
        }

        ans.push_back( Edge( push_F, push_S, push_W) );
    }

    for( int i = 0; i < static_cast<int>(myList[temp_min.FirstNode].size()); ++i ) {
        if ( myList[temp_min.FirstNode][i].index == temp_min.SecondNode ) {
            myList[temp_min.FirstNode].erase(myList[temp_min.FirstNode].begin() + i);
            break;
        }
    }

    for( int i = 0; i < static_cast<int>(myList[temp_min.SecondNode].size()); ++i ) {
        if ( myList[temp_min.SecondNode][i].index == temp_min.FirstNode ) {
            myList[temp_min.SecondNode].erase(myList[temp_min.SecondNode].begin() + i);
            break;
        }
    }

    alreadyATree[temp_min.SecondNode] = true;
}
