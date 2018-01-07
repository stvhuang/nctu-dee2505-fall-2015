/**
 * @filename solve.hpp
 * @author   Yanjia Huang <yanjia.huang.tw@gmail.com>
 */

#ifndef __SOLVE_HPP__
#define __SOLVE_HPP__

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class solve {
  private:
    int limOfNeg;
    int numOfCandidates;
    vector<int> temptry;

  public:
    solve();
    void calculate(int target, int limit, int candidates_num,
                   vector<int> candidates, vector<vector<int>> &solutions);
    void findCombinations(vector<int> &candidates, int startPos, int target,
                          vector<int> &oneAns, vector<vector<int>> &solutions,
                          int useOfNeg = 0);
};

#endif
