#include <iostream>
#include <vector>

using namespace std;

const int size = 2;
const int nVangrancy = 10000;
int k;


vector<vector<double>> getMatrixForVangrancy(vector<int> x){

    int maxSum = 0;
    vector<vector<double>> matrix = vector<vector<double>>();

//    srand(time(NULL));
    for (int i = 0; i < size; i++){
        int rowSum = 0;
        vector<double> row = vector<double>(size + 1, 0);

        for (int j = 0; j < size; j++){
            row[j] = rand() % 10;
            rowSum += row[j];
        }
        maxSum = max(maxSum, rowSum);
        matrix.push_back(row);
    }

    for (int i = 0; i < size; i++){
        int colSum = 0;
        for (int j = 0; j < size; j++){
            colSum += matrix[i][j];
        }
        maxSum = max(maxSum, colSum);
    }

//    int k = (int)ceil((double)maxSum / 100) * 100;
    k = maxSum + 1;
    for (int i = 0; i < size; i++) {
        double p = x[i];
        for (int j = 0; j < size; j++) {
            matrix[i][j] /= k;
            p -= matrix[i][j] * x[j];
        }
        matrix[i][size] = p;
    }
//    matrix[x.size()][x.size()] = 1;
    return matrix;
}


double vangrancy(int id, vector<vector<double>> matrix){
    double x = 0;

//    while (true)/============/

    x += matrix[id][size];
    int newId = id;

    int i = 0;
//    cout << endl;
//    srand(time(NULL));
    double sum = 0;
    double p = (double)(rand() % 10000 + 1) / 10000;
//    cout << p << '\t' << x << endl;

    while (i < size)
        if ((sum <= p) && (p < matrix[i][newId] + sum)){
            newId = i;
            x += matrix[newId][size];
            i = 0;
            sum = 0;
//            cout << newId << '\t' << p << '\t' << x << endl;
            p = (double)(rand() % 10000 + 1) / 10000;
        }
        else
            sum += matrix[i++][newId];

//    cout << p << '\t' << x << endl;
    return x;
//    }
}


int main(){
    vector<int> x = vector<int>(size, 0);

    srand((unsigned int) time(NULL));
    for (int i = 0; i < size; i++){
        x[i] = rand() % 10;
        cout << x[i] << ' ';
    }

    cout << endl << endl;
    vector<vector<double>> matrix = vector<vector<double>>();
    matrix = getMatrixForVangrancy(x);

    for (int i = 0; i < size; i++){
        cout << 'x' << i << " = ";
        for (int j = 0; j < size + 1; j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }

    cout << endl << endl;
    for (int i = 0; i < size; i++){
        double x = 0;
        for (int j = 0; j < nVangrancy; j++)
            x += vangrancy(i, matrix);
        cout << 'x' << i << " = " << (double)x / nVangrancy << endl;
    }


}