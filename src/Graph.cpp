/*
 * Graph.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: plocci
 */

#include "Graph.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

Graph::Graph() {
	// TODO Auto-generated constructor stub

}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

Graph::Graph(vector<vector<double> > Matrix){
	for (unsigned int row = 0; row < Matrix.size(); row++ ){
		for (unsigned int col = 0; col < Matrix[row].size(); col++){
			if (Matrix[row][col] > 0){
				add_unidirectional(row, col, Matrix[row][col]);
			}
		}
	}
}

unsigned int Graph::V () const {
	return graph.size();
}

unsigned int Graph::E () const {
	unsigned int counter = 0;
	for (auto it : graph){
		counter +=  it.vertexes.size();
	}
	return counter;
}

void Graph::add_unidirectional (int v1, int v2, double weight){
	cout << "TRY" << endl;
	for (auto &it1: graph){
		if (it1.source_node == v1){
			for (auto &it2 : it1.vertexes){
				if (it2.dest_node == v2){
					it2.weight = weight;
					return;
				}
			}
			Vertex V1 ={v2, weight};
			it1.vertexes.push_back(V1);
			sort(it1.vertexes.begin(), it1.vertexes.end());
			return;
		}
	}
	vector<Vertex> vrtx;
	vrtx.push_back({v2, weight});
	Node N = {v1, vrtx};
	graph.push_back(N);
	sort(graph.begin(), graph.end());
	return;
}

void Graph::add_bidirectional (int v1, int v2, double weight){
	add_unidirectional (v1, v2, weight);
	add_unidirectional (v2, v1, weight);
}

void Graph::print_graph() const{
	for (auto it1: graph){
		cout << setfill(' ') << setw(5) << it1.source_node << " ";
		for (auto const it2 : it1.vertexes){
			cout << "--" << setfill('-') << setw(5) << it2.weight << "-->" << setw(-5) << it2.dest_node << "    " ;
		}
		cout << endl;
	}
}

void Graph::remove_bidirectional (int v1, int v2){
	remove_unidirectional (v1, v2);
	remove_unidirectional (v2, v1);
}



void Graph::remove_unidirectional (int v1, int v2){
	for (vector<Node>::iterator it1 = graph.begin(); it1 != graph.end();){
		if (it1->source_node == v1){
			for (auto it2  = it1->vertexes.begin(); it2 != it1->vertexes.end();){
				cout << distance(it2, it1->vertexes.begin() ) << endl;
				if (it2->dest_node == v2){
					it2 = it1->vertexes.erase(it2);
				}
				else it2 ++;
			}
		}
		if (it1->vertexes.size() == 0){
			graph.erase(it1);
		}
		else
		{
			it1++;
		}
	}
}
double Graph::get_node_value(int v1, int v2) const {
	for (auto  &it1: graph){
		if (it1.source_node == v1){
			for (auto  &it2: it1.vertexes){
				if (it2.dest_node == v2){
					return it2.weight;
				}
			}
		}
	}
	return .0;
}
//double Graph::set_node_value(int v1, int v2);
