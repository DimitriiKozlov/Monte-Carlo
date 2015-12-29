#include <iostream>
#include <vector>

using namespace std;

const int size = 3;
const int nVangrancy = 1;
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
    cout << endl;
//    srand(time(NULL));
    double sum = 0;
    double p = (double)(rand() % 10 + 1) / k;
    cout << p << endl;

    while (i < size)
        if ((sum <= p) && (p < matrix[newId][i] + sum)){
            newId = i;
            i = 0;
            x += matrix[newId][size];
            p = (double)(rand() % 10 + 1) / k;
            cout << newId << '\t' << p << endl;
        }
        else
            sum += matrix[newId][i++];

    cout << p << endl;
    return x;
//    }
}


int main(){
    vector<int> x = vector<int>(size, 0);

//    srand(time(NULL));
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