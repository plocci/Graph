//============================================================================
// Name        : GrahProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include <iomanip>
#include "Graph.h"
#include <random>
#include <algorithm>
using namespace std;


const unsigned int vertexesNumber = 50;

int main() {

	srand(time(0));
	clock_t    start=clock();
	vector < double > vecrow = vector < double > (vertexesNumber, 0);
	vector<vector<double> > Matrix (vertexesNumber, vecrow);
	for (unsigned int row = 0 ; row < Matrix.size(); row ++ ){
		for (unsigned int col = 0 ; col < Matrix[row].size(); col ++ ){
			if (row != col && ((rand()%100+1))>90){
				Matrix[row][col] = rand() % 20 + 1;
			}
		}
	}
	cout << "Matrix has been generated in " << clock() -start << endl;
	Graph G1 = Graph(Matrix);

	cout << endl  << endl <<"G1 generate "<< clock()-start << endl;
	G1.add_unidirectional(1,5,7);
	cout << endl  << endl <<"G1 generate "<< clock()-start << endl;
	cout << endl  << endl ;

	cout <<"Edge number "<<G1.E();
	cout << endl << endl;
	cout <<"Vertex number "<<G1.V();

	return 0;
}
