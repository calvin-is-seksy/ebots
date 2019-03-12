#include<stdio.h>
#include<iostream>
#include<bitset>

#include <vector>
#include <random>
#include <climits>
#include <algorithm>
#include <functional>

using namespace std; 

using random_bytes_engine = independent_bits_engine<
    default_random_engine, CHAR_BIT, unsigned char>;

int main() {
	int N = 5; 

	// unsigned char x1[N];
	// unsigned char x2[N];
	// unsigned char x3[N];
	// unsigned char x4[N];
	// unsigned char x5[N];
	unsigned char x[5][N];
	// unsigned char y[N];
	// unsigned char z[N]; 
	vector<unsigned char> y; 
	vector<unsigned char> z; 
	
	float c1 =  0.03;
	float c2 =  -0.03;
	float c3 =  0.999999;
	float c4 =  -0.99999999;
	float c5 =  0.0;

	// random_bytes_engine rbe;
	// vector<unsigned char> data(1000);
    // generate(begin(data), end(data), std::ref(rbe));
	// cout << rbe << endl; 

	// unsigned char num = rand() % 256;
	// cout << num << endl; 

	// unsigned char a = (unsigned char) rand()%256;
	// cout << printf("%u", a) << endl; 
	// cout << static_cast<unsigned>(a) << endl;

	// string binary = bitset<8>(rand()%256).to_string(); 
	// cout << binary << endl; 

	// unsigned long dec = bitset<8>(rand()%256).to_ulong(); 
	// cout << dec << endl; 

	// Creating x1 -> x5 of random unsigned chars 
	for (int xIdx = 0; xIdx < 5; xIdx++) { // x_ list
		for (int i = 0; i < N; i++) {
			unsigned char temp = rand()%256;
			x[xIdx][i] = temp;
		}
	}

	// Actual calculations
	for (int j = 0; j < N; j++) { 
		int tempY = c1*x[1][j] + c2*x[2][j] + c3*x[3][j] + c4*x[4][j] + c5*x[5][j];
		if (tempY > 0) {
			y.push_back(tempY);
			z.push_back(c5*x[1][j] + c4*x[2][j] + c3*x[3][j] + c2*x[4][j] + c1*x[5][j]);
		}
	}

	// Output to valid
	for (int xIdx = 0; xIdx < 5; xIdx++) { // x_ list
		cout << "x" << to_string(xIdx) << endl; 
		for (int i = 0; i < N; i++) {
			cout << (int)x[xIdx][i] << endl; 
		}
		cout << endl; 
	}

	cout << endl; 

	for (int i = 0; i < (int)y.size(); i++)
        cout<< +y.at(i) <<endl;

	cout << endl; 

	for (int i = 0; i < (int)z.size(); i++)
        cout<< +z.at(i) <<endl;

	return 0; 
}
