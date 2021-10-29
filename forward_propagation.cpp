#include <iostream>

using namespace std;

void fill_my_matrix(int size_row, int size_col, float *marix){
    for(int row=0; row<size_row; ++row){
        for(int col=0; col<size_col; ++col){
            marix[row*size_col+col] = rand()%100 +1;
        }
    }
}
void fill_weights(int size_col, float *vektor){
    for (int idx=0; idx<size_col; idx++){
        vektor[idx] = rand()%100 +1 *0.02; 
    }
}
float *neuron(int rows, int cols, float *input_data, float *bias, float *weights, float *result){
    for(int row=0; row<rows; row++){
        for(int col=0; col<cols; col++){
            result[row] += input_data[row*cols+col]*weights[col];
        }
        result[row] += bias[row];
    }
    return result;
}

void ReLu(int rows, float *result){
    for(int i=0; i<rows; i++){
        if(result[i]<0){
            result[i]=0;
        }
    }
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;
    float *input_data = new float[rows*cols];
    float *weights = new float[cols];
    fill_my_matrix(rows, cols, input_data);
    fill_weights(cols, weights);
    float *result = new float[rows];
    float *bias = new float[rows];
    fill_weights(rows, bias);
    for(int i=0; i<rows; i++){
        result[i]=0;
    }
    
    ReLu(rows, neuron(rows, cols, input_data, bias, weights, result));
    
    for(int i=0; i<rows; i++){
        cout<<result[i]<<" ";
    }

    return 0;
}
