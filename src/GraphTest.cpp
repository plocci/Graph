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

int main() {

	srand(time(0));
	vector < double > vecrow = vector < double > (10, 0);

	vector<vector<double> > Matrix (10, vecrow);
	for (unsigned int row = 0 ; row < Matrix.size(); row ++ ){
		for (unsigned int col = 0 ; col < Matrix[row].size(); col ++ ){
			if (row != col && ((rand()%30+1))>200){
				Matrix[row][col] = rand() % 20 + 1;
			}
			cout <<  setw(6) << Matrix[row][col];
		}
		cout << endl;
	}
	cout << endl;
	Graph G1 = Graph(Matrix);

	G1.print_graph();
	cout << endl << endl;
	G1.add_bidirectional(0, 100, 45);

	G1.remove_bidirectional( 0, 45);
	G1.add_unidirectional(5, 3, 13);
	G1.print_graph();
	G1.print_graph();
	G1.remove_bidirectional( 0, 100);
	G1.print_graph();

	G1.remove_bidirectional( 0, 45);
	G1.add_unidirectional(5, 3, 13);
	G1.print_graph();
	G1.print_graph();
	G1.remove_bidirectional( 0, 100);
	G1.print_graph();

	return 0;
}
