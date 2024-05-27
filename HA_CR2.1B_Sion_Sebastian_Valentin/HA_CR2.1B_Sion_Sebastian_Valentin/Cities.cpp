#include "Cities.h"

pair<int, vector<int>> bfsTSP(const vector<vector<int>>& dist) {
    clock_t start = clock();

    int n = dist.size();
    int finalMask = (1 << n) - 1;
    queue<State> q;
    vector<vector<int>> minCost(1 << n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; ++i) {
        q.push({ 1 << i, i, 0, 0, {i} });
        minCost[1 << i][i] = 0;
    }

    int result = INT_MAX;
    vector<int> path;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.mask == finalMask) {
            if (current.cost + dist[current.city][0] < result) {
                result = current.cost + dist[current.city][0];
                path = current.path;
            }
            continue;
        }

        for (int nextCity = 0; nextCity < n; ++nextCity) {
            if (!(current.mask & (1 << nextCity))) {
                int newMask = current.mask | (1 << nextCity);
                int newCost = current.cost + dist[current.city][nextCity];

                if (newCost < minCost[newMask][nextCity]) {
                    minCost[newMask][nextCity] = newCost;
                    vector<int> newPath = current.path;
                    newPath.push_back(nextCity);
                    q.push({ newMask, nextCity, newCost, 0, newPath });
                }
            }
        }
    }

    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    cout << "Timpul de executie pentru BFS" << elapsed_secs << " secunde" << endl;

    return { result, path };
}


pair<int, vector<int>> ucsTSP(const vector<vector<int>>& dist) {
    clock_t start = clock();

    int n = dist.size();
    int finalMask = (1 << n) - 1;
    priority_queue<State, vector<State>, greater<State>> pq;
    vector<vector<int>> minCost(1 << n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; ++i) {
        pq.push({ 1 << i, i, 0, 0, {i} });
        minCost[1 << i][i] = 0;
    }

    int result = INT_MAX;
    vector<int> path;

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (current.mask == finalMask) {
            if (current.cost + dist[current.city][0] < result) {
                result = current.cost + dist[current.city][0];
                path = current.path;
            }
            continue;
        }

        for (int nextCity = 0; nextCity < n; ++nextCity) {
            if (!(current.mask & (1 << nextCity))) {
                int newMask = current.mask | (1 << nextCity);
                int newCost = current.cost + dist[current.city][nextCity];

                if (newCost < minCost[newMask][nextCity]) {
                    minCost[newMask][nextCity] = newCost;
                    vector<int> newPath = current.path;
                    newPath.push_back(nextCity);
                    pq.push({ newMask, nextCity, newCost, 0, newPath });
                }
            }
        }
    }

    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    cout << "Timpul de executie pentru UCS: " << elapsed_secs << " secunde" << endl;

    return { result, path };
}
int calculateHeuristic(int mask, int currentCity, const vector<vector<int>>& dist) {
    int n = dist.size();
    int heuristic = 0;

    for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i))) {
            heuristic += dist[currentCity][i];
        }
    }

    return heuristic;
}
pair<int, vector<int>> aStarTSP(const vector<vector<int>>& dist) {
    clock_t start = clock();

    int n = dist.size();
    int finalMask = (1 << n) - 1;
    priority_queue<State, vector<State>, greater<State>> pq;
    vector<vector<int>> minCost(1 << n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; ++i) {
        int heuristic = calculateHeuristic(1 << i, i, dist);
        pq.push({ 1 << i, i, 0, heuristic, {i} });
        minCost[1 << i][i] = 0;
    }

    int result = INT_MAX;
    vector<int> path;

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (current.mask == finalMask) {
            if (current.cost + dist[current.city][0] < result) {
                result = current.cost + dist[current.city][0];
                path = current.path;
            }
            continue;
        }

        for (int nextCity = 0; nextCity < n; ++nextCity) {
            if (!(current.mask & (1 << nextCity))) {
                int newMask = current.mask | (1 << nextCity);
                int newCost = current.cost + dist[current.city][nextCity];
                int heuristic = calculateHeuristic(newMask, nextCity, dist);

                if (newCost < minCost[newMask][nextCity]) {
                    minCost[newMask][nextCity] = newCost;
                    vector<int> newPath = current.path;
                    newPath.push_back(nextCity);
                    pq.push({ newMask, nextCity, newCost, heuristic, newPath });
                }
            }
        }
    }

    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    cout << "Timpul de executie pentru A*: " << elapsed_secs << " secunde" << endl;

    return { result, path };
}
void printPath(const vector<int>& path) {
    for (int city : path) {
        cout << city << " ";
    }
    cout << endl;
}
vector<vector<int>> generateRandomMatrix(int n, int maxDistance) {
    vector<vector<int>> dist(n, vector<int>(n));
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                dist[i][j] = 1 + rand() % maxDistance;
            }
            else {
                dist[i][j] = 0;
            }
        }
    }
    return dist;
}