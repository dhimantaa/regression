using namespace std;
#include <vector>

class LinearRegression
{
private:
	vector<vector<double>> X;

    vector<vector<double>> Y;

    vector<vector<double>> b0;
    vector<vector<double>> b1;

    int no_of_iteration;
    
    double alpha;

    void initialization();
    void optimize();
	
public:
	LinearRegression(vector<vector<double>> X, vector<vector<double>> Y, int no_of_iteration, double alpha);
	void fit();
	vector<vector<double>> predict(vector<vector<double>> x_predict);
};