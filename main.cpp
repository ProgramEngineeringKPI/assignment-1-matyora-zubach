#include <string>
#include <iostream>
#include <cstring>

using namespace std;

void insertionSort(int *, string*, int);
void swap(int &, int &);
void resParser(int*, string*, int);


int main() {
    FILE *pFile = fopen("premier_league.csv", "r");
    if(pFile == nullptr) {
        cout << "Error, please, check your file.\n";
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
                if(parsedData[i][j][0] != '-') {
                    if (parsedData[i][j][0] > parsedData[i][j][2]) resultPoints[i] += 3;
                    if (parsedData[i][j][0] == parsedData[i][j][2]) resultPoints[i] += 1;
                } else resultPoints[i] += 1;
            }
        }

        //New Git- commit
        
        for(int i = 0; i < amountOfTeams; i++) {
            resultTeams[i] = parsedData[i][0];
        }

        insertionSort(resultPoints, resultTeams, amountOfTeams); //Sort two result arrays

        resParser( resultPoints, resultTeams, amountOfTeams);
        cout << "Read and write file success.\n" << "The winner is: " << resultTeams[0] << '\n';
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

//Second commit here

//And here

void swap(int &a, int &b) {
    int tmp;
    tmp = a; a = b; b = tmp;
}
//Test comment for git train
void resParser(int* arrResults, string* arrTeams, int arrLength) {
    FILE* pOutput = fopen("results.csv", "w");
    for(int i = 0; i < arrLength; i++ ){
        fprintf( pOutput, "%s%c%d%c",  arrTeams[i].c_str(),':',arrResults[i],'\n');
    }
    fclose(pOutput);
}

//Test comment for git train
//Test comment for git train
//Test comment for git train
//Test comment for git train
