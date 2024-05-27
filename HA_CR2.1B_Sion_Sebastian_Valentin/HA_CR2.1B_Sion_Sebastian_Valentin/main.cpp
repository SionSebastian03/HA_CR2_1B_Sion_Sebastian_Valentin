#include "Cities.h"

int main() {
    // Generarea automată a unei matrice de distanțe pentru 15 orașe
    int numCities = 15;
    int maxDistance = 9;
    vector<vector<int>> generatedDist = generateRandomMatrix(numCities, maxDistance);

    cout << "Matricea de distante generate automat:" << endl;
    for (const auto& row : generatedDist) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    auto bfsGeneratedResult = bfsTSP(generatedDist);
    cout << "Folosim BFS pentru matricea generata: " << bfsGeneratedResult.first << endl;
    cout << "Calea: ";
    printPath(bfsGeneratedResult.second);

    auto ucsGeneratedResult = ucsTSP(generatedDist);
    cout << "Folosim UCS pentru matricea generata: " << ucsGeneratedResult.first << endl;
    cout << "Calea: ";
    printPath(ucsGeneratedResult.second);

    auto aStarGeneratedResult = aStarTSP(generatedDist);
    cout << "Folosim A* pentru matricea generata: " << aStarGeneratedResult.first << endl;
    cout << "Calea: ";
    printPath(aStarGeneratedResult.second);

    // Matrice de distanțe prestabilită pentru 15 orașe
    vector<vector<int>> presetDist = {
       {0, 2, 9, 10, 1, 6, 5, 7, 3, 4, 8, 6, 4, 3, 7},
       {2, 0, 4, 3, 5, 9, 6, 2, 8, 7, 5, 3, 4, 6, 8},
       {9, 4, 0, 2, 7, 1, 5, 3, 6, 8, 7, 5, 6, 4, 2},
       {10, 3, 2, 0, 6, 8, 3, 2, 4, 7, 9, 6, 5, 4, 8},
       {1, 5, 7, 6, 0, 2, 4, 8, 3, 5, 4, 2, 3, 6, 7},
       {6, 9, 1, 8, 2, 0, 3, 5, 4, 7, 3, 2, 1, 5, 4},
       {5, 6, 5, 3, 4, 3, 0, 2, 6, 5, 7, 3, 4, 5, 6},
       {7, 2, 3, 2, 8, 5, 2, 0, 4, 6, 5, 3, 2, 4, 5},
       {3, 8, 6, 4, 3, 4, 6, 4, 0, 2, 1, 5, 4, 3, 7},
       {4, 7, 8, 7, 5, 7, 5, 6, 2, 0, 4, 3, 2, 4, 5},
       {8, 5, 7, 9, 4, 3, 7, 5, 1, 4, 0, 2, 3, 4, 6},
       {6, 3, 5, 6, 2, 2, 3, 3, 5, 3, 2, 0, 1, 2, 3},
       {4, 4, 6, 5, 3, 1, 4, 2, 4, 2, 3, 1, 0, 2, 3},
       {3, 6, 4, 4, 6, 5, 5, 4, 3, 4, 4, 2, 2, 0, 1},
       {7, 8, 2, 8, 7, 4, 6, 5, 7, 5, 6, 3, 3, 1, 0}
    };

    cout << "Matricea de distante prestabilita:" << endl;
    for (const auto& row : presetDist) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    auto bfsPresetResult = bfsTSP(presetDist);
    cout << "Folosim BFS pentru matricea prestabilita: " << bfsPresetResult.first << endl;
    cout << "Calea: ";
    printPath(bfsPresetResult.second);


    auto ucsPresetResult = ucsTSP(presetDist);
    cout << "Folosim UCS pentru matricea prestabilita: " << ucsPresetResult.first << endl;
    cout << "Calea: ";
    printPath(ucsPresetResult.second);


    auto aStarPresetResult = aStarTSP(presetDist);
    cout << "Folosim A* pentru matricea prestabilita: " << aStarPresetResult.first << endl;
    cout << "Calea: ";
    printPath(aStarPresetResult.second);


    return 0;
}