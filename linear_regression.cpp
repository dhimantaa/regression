#include "linear_regression.h"
#include "matrix.h"


void LinearRegression::optimize(){

    for (int i = 0; i < this->no_of_iteration; i++){
        // yhat = b1 * x + b0
        vector<vector<double>> yhat = sum(dot_product(this->X,this->b1), this->b0);
        // cost = 1/m * np.sum(square(y-yhat))
        vector<vector<double>> change = subtract(this->Y, yhat);

        // before calling vector multiplication both vector has equal length
        //float cost = (1./x[0].size())*sum_matrix(vector_multiply(change,change));
        float cost = (1./this->X.size())*sum_matrix(dot_product(transpose(change),change));

        //dw = np.dot(x_train, 1 / m * (yhat - y_train).T)
        //db = np.sum(1 / m * (yhat - y_train).T)
        vector<vector<double>> sub = subtract(yhat, this->Y);
        vector<vector<double>> db1 = dot_product(scalar_multiply(1./this->X.size(), transpose(sub)), this->X);
        
        float db_value = sum_matrix(scalar_multiply(1./this->X.size(), transpose(sub)));
        vector<vector<double>> db0(this->X.size(), vector<double>(this->Y[0].size(), db_value));
        
        // Updating the weight
        // weight = weight - (learning_rate * dw)
        this->b1 = subtract(this->b1, scalar_multiply(this->alpha, transpose(db1)));
        
        this->b0 = subtract(this->b0, scalar_multiply(this->alpha, db0));
        cout<<"Cost after "<<i<<" iteration: "<<cost<<endl;
    }
}

void LinearRegression::initialization(){
    this->b0 = vector<vector<double>>(this->X.size(), vector<double>(this->Y[0].size(), 0.));
    this->b1 = vector<vector<double>>(this->X[0].size(), vector<double>(this->Y[0].size(), 1.));
}

vector<vector<double>> LinearRegression::predict(vector<vector<double>> x_predict){
    vector<vector<double>> y_predict = sum(dot_product(x_predict, this->b1), this->b0);
    cout<<"predictions are : "<<endl;
    return y_predict;
}

void LinearRegression::fit(){
    
    this->initialization();
    this->optimize();
}

LinearRegression::LinearRegression(vector<vector<double>> X, vector<vector<double>> Y, int no_of_iteration, double alpha)
{
	this->X = X;
	this->Y = Y;
	this->no_of_iteration = no_of_iteration;
    this->alpha = alpha;
}