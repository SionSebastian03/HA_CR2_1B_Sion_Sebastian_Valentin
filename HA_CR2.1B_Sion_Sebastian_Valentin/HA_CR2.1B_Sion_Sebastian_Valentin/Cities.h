#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct State {
    int mask; // reprezinta orasele vizitate
    int city; // orasul curent
    int cost; // costul curent
    int heuristic; // Valoarea heuristica
    vector<int> path; // path-ul care a fost parcurs


    bool operator>(const State& other) const {
        return (cost + heuristic) > (other.cost + other.heuristic);
    }
};
pair<int, vector<int>> bfsTSP(const vector<vector<int>>& dist);
pair<int, vector<int>> ucsTSP(const vector<vector<int>>& dist);
int calculateHeuristic(int mask, int currentCity, const vector<vector<int>>& dist);
pair<int, vector<int>> aStarTSP(const vector<vector<int>>& dist);
void printPath(const vector<int>& path);
vector<vector<int>> generateRandomMatrix(int n, int maxDistance);
