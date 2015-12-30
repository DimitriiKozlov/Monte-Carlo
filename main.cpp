#include <iostream>
#include <vector>

using namespace std;

const int matrixSize = 5;
const int maxXValue = 10;
const int maxElemMatrixValue = 10;
const int nVangrancy = 100000;
int k;


int getMaxSumInMatrixByCol(vector<vector<double>> matrix){
    int maxSum = 0;
    for (int i = 0; i < matrixSize; i++){
        int colSum = 0;
        for (int j = 0; j < matrixSize; j++){
            colSum += matrix[j][i];
        }
        maxSum = max(maxSum, colSum);
    }
    return maxSum;
}


int getMaxSumInMatrixByRow(vector<vector<double>> matrix){
    int maxSum = 0;
    for (int i = 0; i < matrixSize; i++){
        int rowSum = 0;
        for (int j = 0; j < matrixSize; j++){
            rowSum += matrix[i][j];
        }
        maxSum = max(maxSum, rowSum);
    }
    return maxSum;
}


vector<vector<double>> generateMatrixForVangrancy(vector<int> x){
    vector<vector<double>> matrix = vector<vector<double>>();

    for (int i = 0; i < matrixSize; i++){
        vector<double> row = vector<double>(matrixSize + 1, 0);

        for (int j = 0; j < matrixSize; j++)
            row[j] = rand() % maxElemMatrixValue;
        matrix.push_back(row);
    }
    return matrix;
}


vector<vector<double>> getMatrixForVangrancy(vector<int> x){
    vector<vector<double>> matrix = vector<vector<double>>();
    matrix = generateMatrixForVangrancy(x);

    k = max(getMaxSumInMatrixByCol(matrix), getMaxSumInMatrixByRow(matrix)) + 1;
    for (int i = 0; i < matrixSize; i++) {
        double p = x[i];
        for (int j = 0; j < matrixSize; j++) {
            matrix[i][j] /= k;
            p -= matrix[i][j] * x[j];
        }
        matrix[i][matrixSize] = p;
    }
    return matrix;
}


vector<int> generateXVector(){
    vector<int> x = vector<int>(matrixSize, 0);

    for (int i = 0; i < matrixSize; i++)
        x[i] = rand() % maxXValue;
    return x;
}


double vangrancy(int id, vector<vector<double>> matrix){
    double x = 0;

//    while (true)/============/

    x += matrix[id][matrixSize];
    int newId = id;

    int i = 0;
//    cout << endl;
//    srand(time(NULL));
    double sum = 0;
    double p = (double)(rand() % 10000 + 1) / 10000;
//    cout << p << '\t' << x << endl;

    while (i < matrixSize)
        if ((sum <= p) && (p < matrix[i][newId] + sum)){
            newId = i;
            x += matrix[newId][matrixSize];
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


void printMatrixInConsole(vector<vector<double>> matrix){
    cout << endl;
    for (int i = 0; i < matrixSize; i++){
        cout << 'x' << i << " = ";
        for (int j = 0; j < matrixSize + 1; j++)
            cout << matrix[i][j] << '\t';
        cout << endl;
    }
}

void printXInConsole(vector<int> x){
    cout << endl;
    for (int i = 0; i < matrixSize; i++)
        cout << 'x' << i << " = " << x[i] << endl;
}

void printXMCInConsole(vector<double> x){
    cout << endl << endl << "By Monte-Carlo Method:" << endl;
    for (int i = 0; i < matrixSize; i++)
        cout << 'x' << i << " = " << x[i] << endl;
}


vector<double> getXVectorMC(vector<vector<double>> matrix){
    vector<double> xMC = vector<double>(matrixSize, 0);

    for (int i = 0; i < matrixSize; i++){
        double xi = 0;
        for (int j = 0; j < nVangrancy; j++)
            xi += vangrancy(i, matrix);
        xMC[i] = xi / nVangrancy;
    }
    return xMC;
}


int main(){
    srand((unsigned int) time(NULL));

    vector<int> x = vector<int>(matrixSize, 0);
    vector<double> xMC = vector<double>(matrixSize, 0);
    x = generateXVector();

    vector<vector<double>> matrix = vector<vector<double>>();
    matrix = getMatrixForVangrancy(x);

    printXInConsole(x);
    printMatrixInConsole(matrix);

    xMC = getXVectorMC(matrix);
    printXMCInConsole(xMC);

}