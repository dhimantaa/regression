```cpp
#include<bits/stdc++.h> // header file for all c++ libraries
using namespace std;

#include "linear_regression.h"

int main()
{
    vector<vector<double>> X {{0.11, 0.4, 0.12}, {0.12, 0.3, 0.15}, {0.1, 0.2, 0.19}, {0.90, 0.0, 0.9}, {0.8, 0.1, 0.7}};
    vector<vector<double>> Y {{0.1, 0.3}, {0.9, 0.5}, {0.8, 0.7}, {0.9,0.1}, {0.7,0.54}};

    vector<vector<double>> x_predict{{0.13, 0.1}, {0.452, 0.323}, {0.10, 0.25}, {0.432, 0.65}, {0.73, 0.9}};

    int no_of_iteration = 1000000;
    double alpha = 0.01;

    LinearRegression lr(X,Y,no_of_iteration,alpha);

    lr.fit();
    vector<vector<double>> y_predict = lr.predict(x_predict);
    print_matrix(y_predict);
}
```
