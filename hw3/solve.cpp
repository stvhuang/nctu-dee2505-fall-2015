/**
 * @filename solve.cpp
 * @author   Yanjia Huang <yanjia.huang.tw@gmail.com>
 */

#include "solve.hpp"

solve::solve() : limOfNeg(0), numOfCandidates(0) {}

void solve::calculate(int target, int limit, int candidates_num,
                      vector<int> candidates, vector<vector<int>> &solutions) {
    limOfNeg = limit;
    numOfCandidates = candidates_num;
    findCombinations(candidates, 0, target, temptry, solutions);
}

void solve::findCombinations(vector<int> &candidates, int startPos, int target,
                             vector<int> &oneAns,
                             vector<vector<int>> &solutions, int useOfNeg) {
    if (target == 0) {
        solutions.push_back(oneAns);
        return;
    }

    for (int i(startPos); i < numOfCandidates; ++i) {
        if (candidates[i] > target && useOfNeg == limOfNeg) {
            return;
        }

        if (candidates[i] <= target && useOfNeg <= limOfNeg) {
            if (candidates[i] >= 0) {
                oneAns.push_back(candidates[i]);
                findCombinations(candidates, i, target - candidates[i], oneAns,
                                 solutions, useOfNeg);
                oneAns.pop_back();
            } else if (candidates[i] < 0 && useOfNeg < limOfNeg) {
                oneAns.push_back(candidates[i]);
                ++useOfNeg;
                findCombinations(candidates, i, target - candidates[i], oneAns,
                                 solutions, useOfNeg);
                oneAns.pop_back();
                --useOfNeg;
            }
        }
    }
}
