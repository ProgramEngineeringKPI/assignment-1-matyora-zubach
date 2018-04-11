#include <string>
#include <iostream>
#include <cstring>

using namespace std;

void insertionSort(int *, string*, int);
void swap(int &, int &);
void resParser(int*, string*, int, FILE*);


int main() {
    FILE *pFile = fopen("premier_league.csv", "r");
    if(pFile == nullptr) {
        cout << "Error, please, check your file.";
    } else {
        auto number = new char;             //
        fgets(number, sizeof(number), pFile);// Take the first number from file
        int amountOfTeams = atoi(number);    //

        auto resultPoints = new int[amountOfTeams];//
        string resultTeams[amountOfTeams];          //Arrays of results

        char unparsedData[amountOfTeams][100];        //Read from file
        for(int i = 0; i < amountOfTeams; i++) {      //
            fgets(unparsedData[i], 100, pFile);       //
        }
        fclose(pFile);

        string parsedData[amountOfTeams][11];         //Changing to convenient format
        for(int i = 0; i < amountOfTeams; i++) {      //with splitting by delimiter ","
            char *pch = strtok(unparsedData[i], ",");
            for(int j = 0; j < 11; j++) {
                parsedData[i][j] = pch;
                pch = strtok(nullptr, ",");
            }
        }
        //Counting final results
        for(int i = 0; i < amountOfTeams; i++) {
            for(int j = 1; j < 11; j++) {
                if(parsedData[i][j][0] > parsedData[i][j][2]) resultPoints[i] += 3;
                if(parsedData[i][j][0] == parsedData[i][j][2]) resultPoints[i] += 1;
            }
        }
        for(int i = 0; i < amountOfTeams; i++) {
            resultTeams[i] = parsedData[i][0];
        }

        insertionSort(resultPoints, resultTeams, amountOfTeams); //Sort two result arrays

        //Checkout for arr
        for(int i = 0; i < amountOfTeams; i++) {
            cout << resultTeams[i] << ':' << resultPoints[i] << '\n';
        }

        FILE* pOutput = fopen("results.csv", "w");
        resParser( resultPoints, resultTeams, amountOfTeams, pOutput );
        //
    }
}

void insertionSort(int* arrResults, string* arrTeams, int arrLength) {
    int i, j, k;
    k = 0;
    for(i = 0; i < arrLength; i++) {
        j = i;
        while(j > k && arrResults[j] > arrResults[j - 1]) {
            swap(arrResults[j], arrResults[j - 1]);
            swap(arrTeams[j], arrTeams[j - 1]);
            j--;
        }
    }
}

void swap(int &a, int &b) {
    int tmp;
    tmp = a; a = b; b = tmp;
}

void resParser(int* arrResults, string* arrTeams, int arrLength, FILE* pFile) {
    for(int i = 0; i < arrLength; i++ ){
        fprintf( pFile, "%s %c %d %c",  arrTeams[i].c_str(),':',arrResults[i],'\n');
    }
}