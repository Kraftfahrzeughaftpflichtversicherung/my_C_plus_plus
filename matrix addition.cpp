

#include <iostream>

using namespace std;

void fill_my_matrix(int size_row, int size_col, float *marix){
    for(int row=0; row<size_row; ++row){
        for(int col=0; col<size_col; ++col){
            marix[row*size_col+col] = rand()%100 +1;
        }
    }
}

void sum_matrix(int size_row, int size_col, float *marix_to_sum, float *matrix){
    for(int row=0; row<size_row; ++row){
        for(int col=0; col<size_col; ++col){
            marix_to_sum[row*size_col+col] = marix_to_sum[row*size_col+col]+matrix[row*size_col+col];
        }
    }
}
void printi(int size_row, int size_col, float *matrix){
    for(int row=0; row<size_row; ++row){
        for(int col=0; col<size_col; ++col){
            cout << matrix[row*size_col+col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main()
{
    int rows, cols;
    cin>> rows >> cols;
    float *matrix1 = new float[rows*cols];
    float *matrix2 = new float[rows*cols];
    
    fill_my_matrix(rows, cols, matrix1);
    printi(rows, cols, matrix1);
    fill_my_matrix(rows, cols, matrix2);
    printi(rows, cols, matrix2);
    sum_matrix(rows, cols, matrix1, matrix2);
    printi(rows, cols, matrix1);

    return 0;
}
