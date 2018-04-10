#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    FILE *pFile = fopen("premier_league.csv", "r");
    if(pFile == nullptr) {
        cout << "Error";
    } else {
        auto *number = new char;
        fgets(number, sizeof(number), pFile);
        int amountOfTeams = atoi(number);
        auto* results = new int[amountOfTeams];

        char unparsedData[amountOfTeams][100];
        for(int i = 0; i < amountOfTeams; i++) {
            fgets(unparsedData[i], 100, pFile);
            //printf("%s", unparsedData[i]);
        }

        string parsedData[amountOfTeams][11];

        for(int i = 0; i < amountOfTeams; i++) {
            char *pch = strtok(unparsedData[i], ",");
            for(int j = 0; j < 11; j++) {
                parsedData[i][j] = pch;
                pch = strtok(nullptr, ",");
                //cout << parsedData[i][j];
            }
        }

        for(int i = 0; i < amountOfTeams; i++) {
            for(int j = 1; j < 11; j++) {
                if(parsedData[i][j][0] > parsedData[i][j][2]) results[i] += 3;
                if(parsedData[i][j][0] == parsedData[i][j][2]) results[i] += 1;
            }
            cout << results[i] << ',';
        }
        cout << '\n';
    }
}