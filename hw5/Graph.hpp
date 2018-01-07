/**
 * @filename Graph.cpp
 * @author   Yanjia Huang <yanjia.huang.tw@gmail.com>
 */

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

struct Edge {
    Edge(int F = 0, int S = 0, int W = 0)
        : FirstNode(F), SecondNode(S), weight(W){};
    Edge &operator=(const Edge arg) {
        this->FirstNode = arg.FirstNode;
        this->SecondNode = arg.SecondNode;
        this->weight = arg.weight;
        return *this;
    }

    bool operator==(const Edge arg) {
        if ((this->FirstNode == arg.FirstNode) &&
            (this->SecondNode == arg.SecondNode) &&
            (this->weight == arg.weight))
            return true;
        return false;
    }

    int FirstNode, SecondNode, weight;
};

struct AdjNode {
    AdjNode(int I = 0, int W = 0) : index(I), weight(W){};
    AdjNode &operator=(const AdjNode arg) {
        this->index = arg.index;
        this->weight = arg.weight;
        return *this;
    }
    int index, weight;
};

class Graph {
  private:
    int NumVertex;
    vector<list<AdjNode>> AdjList;
    vector<AdjNode> *myList;
    bool *alreadyATree;

  public:
    void AddNode(int &first, int &second, int &weight);
    void MST(vector<Edge> &Answer);
    bool notYet();
    Graph(int &NumVertex);
    void findNextEdge(vector<Edge> &ans);
};

#endif
