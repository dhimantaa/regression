#include<bits/stdc++.h>
using namespace std;

vector<vector<double>> one_subtract(vector<vector<double>> y){

    vector<vector<double>> z(1, vector<double>(y[0].size(), 0.0));

    for (int i = 0; i < y[0].size(); i++)
    {
        z[0][i] = 1 - y[0][i];
    }
    return z;
}


vector<vector<double>> sum(vector<vector<double>> a, vector<vector<double>> b){

    vector<vector<double>> z(a.size(), vector<double>(a[0].size(), 0.0));

    for (int i =0; i< a.size(); i++){
        for (int j = 0; j < a[0].size(); j++)
        {
            z[i][j] = a[i][j] + b[i][j];
        }
    }
    return z;
}


vector<vector<double>> subtract(vector<vector<double>> a, vector<vector<double>> b){

    vector<vector<double>> z(a.size(), vector<double>(a[0].size(), 0.0));

    for (int i =0; i< a.size(); i++){
        for (int j = 0; j < a[0].size(); j++)
        {
            z[i][j] = a[i][j] - b[i][j];
        }
    }
    return z;
}

vector<vector<double>> dot_product(vector<vector<double>> x, vector<vector<double>> b){

    vector<vector<double>> c(x.size(), vector<double>(b[0].size(), 0.0));

    for (int i = 0; i < x.size(); ++i) {
        for (int j = 0; j < b[0].size(); ++j) {
            for (int k = 0; k < x[0].size(); ++k) {
                c[i][j] += x[i][k] * b[k][j];
            }
        }
    }
    return c;
}

vector<vector<double> > transpose(vector<vector<double> > &b)
{
    if (b.size() == 0)
        return b;

    vector<vector<double> > trans_vec(b[0].size(), vector<double>());

    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            trans_vec[j].push_back(b[i][j]);
        }
    }
    
    return trans_vec;
}

vector<vector<double>> vector_log(vector<vector<double>> y){

    vector<vector<double>> z(1, vector<double>(y[0].size(), 0.0));

    for (int i = 0; i < y[0].size(); i++)
    {
        z[0][i] = log(y[0][i]);
    }
    return z;
}

vector<vector<double>> vector_multiply(vector<vector<double>> a, vector<vector<double>> b){
    vector<vector<double>> z(a.size(), vector<double>(a[0].size(), 0.0));

    for (int i =0; i< a.size(); i++){
        for (int j = 0; j < a[0].size(); j++)
        {
            z[i][j] = a[i][j]*b[i][j];
        }
    }
    return z;
}


vector<vector<double>> scalar_multiply(float a, vector<vector<double>> b){
    vector<vector<double>> z(b.size(), vector<double>(b[0].size(), 0.0));

    for (int i =0; i< b.size(); i++){
        for (int j = 0; j < b[0].size(); j++)
        {
            z[i][j] = a*b[i][j];
        }
    }
    return z;
}


float sum_matrix(vector<vector<double>> a){
    float sum = 0;

    for (int i = 0; i < a.size();i++){
        for (int j = 0; j<a[i].size(); j++){
            sum += a[i][j];
        }
    }
    return sum;
}
