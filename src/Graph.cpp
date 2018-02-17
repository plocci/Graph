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

Graph::Graph(vector<vector<double> > Matrix) {
	for (unsigned int row = 0; row < Matrix.size(); row++) {
		bool new_el = 1;
		for (unsigned int col = 0; col < Matrix[row].size(); col++) {
			if (Matrix[row][col] > 0) {
				add_unidirectional_sorted(row, col, Matrix[row][col], new_el);
				new_el = 0;
			}
		}
	}
}

unsigned int Graph::V() const {
	return graph.size();
}

unsigned int Graph::E() const {
	unsigned int counter = 0;
	for (auto it : graph) {
		counter += it.vertexes.size();
	}
	return counter;
}

void Graph::add_unidirectional(int v1, int v2, double weight) {
	// search for v1
	vector<Node>::iterator low_N = lower_bound(graph.begin(), graph.end(), v1);
	if (low_N !=graph.end()){
		if (low_N->source_node == v1){
			vector<Vertex>::iterator low_v = lower_bound(low_N->vertexes.begin(), low_N->vertexes.end(), v2);
			if (low_v != low_N->vertexes.end()){
				if (low_v->dest_node == v2){
					*low_v = {v2, weight};
//					for (auto it: low_N->vertexes){
//					}
				}
				else{
					Vertex temp_v ={v2, weight} ;
					low_N->vertexes.insert(low_v + 1, temp_v);
				}
			}
			else {
				Vertex temp_v ={v2, weight} ;
				low_N->vertexes.push_back(temp_v);
			}
		}
		else{
			vector<Vertex> temp_v ={{v2, weight}};
			Node temp_N = {v1, temp_v};
			graph.insert(low_N+1, temp_N);
		}
	}
	else{
		vector<Vertex> temp_v ={{v2, weight}};
		Node temp_N = {v1, temp_v};
		graph.push_back(temp_N);
	}
}

void Graph::add_unidirectional_sorted(int v1, int v2, double weight, bool newline) {
	// Info: use this function only in the constructor adding element in sorted way
	if (!newline) {
		if (graph[graph.size() -1].source_node == v1) {
			Vertex V1 = { v2, weight };
			graph[graph.size() -1].vertexes.push_back(V1);
			return;
		}
	}
	vector<Vertex> vrtx;
	vrtx.push_back( { v2, weight });
	Node N = { v1, vrtx };
	graph.push_back(N);
	return;

}

void Graph::add_bidirectional(int v1, int v2, double weight) {
	add_unidirectional(v1, v2, weight);
	add_unidirectional(v2, v1, weight);
}

void Graph::print_graph() const {
	for (auto it1 : graph) {
		cout << setfill(' ') << setw(5) << it1.source_node << " ";
		for (auto const it2 : it1.vertexes) {
			cout << "--" << setfill('-') << setw(5) << it2.weight << "-->"
					<< setw(-5) << it2.dest_node << "    ";
		}
		cout << endl;
	}
}

void Graph::remove_bidirectional(int v1, int v2) {
	remove_unidirectional(v1, v2);
	remove_unidirectional(v2, v1);
}

void Graph::remove_unidirectional(int v1, int v2) {
	for (vector<Node>::iterator it1 = graph.begin();
			(it1 != graph.end()) && it1->source_node <= v1;) {
		if (it1->source_node == v1) {
			for (auto it2 = it1->vertexes.begin();
					(it2 != it1->vertexes.end() && it2->dest_node <= v2);) {
				if (it2->dest_node == v2) {
					it2 = it1->vertexes.erase(it2);
				} else
					it2++;
			}
		}
		if (it1->vertexes.size() == 0) {
			graph.erase(it1);
		} else {
			it1++;
		}
	}
}

double Graph::get_node_value(int v1, int v2) const {
	for (auto &it1 : graph) {
		if (it1.source_node > v1)
			break;
		if (it1.source_node == v1) {
			for (auto &it2 : it1.vertexes) {
				if (it2.dest_node > v2)
					break;
				if (it2.dest_node == v2) {
					return it2.weight;
				}
			}
		}
	}
	return .0;
}

//double Graph::set_node_value(int v1, int v2);


