#include<iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <utility>

using namespace std; 

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

template<typename F>
double funcTime(F func){
    TimeVar t1=timeNow();
    func();
    return duration(timeNow()-t1);
}

void run() {
	int N = 100; 

	unsigned char x[5][N];

	vector<unsigned char> y; 
	vector<unsigned char> z; 

	float c[5] = {0.03, -0.03, 0.999999, -0.9999999, 0.0}; 

	// Creating x1 -> x5 of random unsigned chars 
	for (int xIdx = 0; xIdx < 5; xIdx++) { // x_ list
		for (int i = 0; i < N; i++) {
			unsigned char temp = rand()%256;
			x[xIdx][i] = temp;
		}
	}

	// Actual calculations
	for (int j = 0; j < N; j++) {
		int tempY = c[0]*x[0][j] + c[1]*x[1][j] + c[2]*x[2][j] + c[3]*x[3][j] + c[4]*x[4][j];
		if (tempY > 0) {
			y.push_back(tempY);
			z.push_back(c[4]*x[0][j] + c[3]*x[1][j] + c[2]*x[2][j] + c[1]*x[3][j] + c[0]*x[4][j]);
		}
	}

	// Output to valid
	// for (int xIdx = 0; xIdx < 5; xIdx++) { // x_ list
	// 	cout << "x" << to_string(xIdx) << endl; 
	// 	for (int i = 0; i < N; i++) {
	// 		cout << (int)x[xIdx][i] << endl; 
	// 	}
	// 	cout << endl; 
	// }

	// cout << endl; 

	// for (int i = 0; i < (int)y.size(); i++)
    //     cout<< +y.at(i) <<endl;

	// cout << endl; 

	// for (int i = 0; i < (int)z.size(); i++)
    //     cout<< +z.at(i) <<endl;
}

int main() {
	
	cout << "C++ runtime: " << funcTime(run) << " nanoseconds" << endl;

	return 0; 
}
