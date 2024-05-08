#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char tab[31][27];
    int i=0, j;
    int linhas, colunas;
    fstream file;


    file.open("input.txt", ios::in);

    while (i<31){
        file.getline(tab[i], 256);
        i++;
    }
    i = 0;
    while(i<31) {
        cout << tab[i] << endl;
        i++;
    }
    return 0;
}

