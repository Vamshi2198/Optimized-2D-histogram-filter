#include "headers/initialize_beliefs.h"

using namespace std;


vector< vector <float> > initialize_beliefs(vector< vector <char> > grid) {

  	vector< vector <float> > newGrid;
	vector<float> newRow;
	int i, j, height, width, area;
	float total, prob_per_cell;

	height = grid.size();
	width = grid[0].size();
 
	area = height * width;

  	prob_per_cell = 1.0 / ( (float) area) ;

	for (i=0; i<grid.size(); i++) {
		newRow.clear();
		for (j=0; j<grid[0].size(); j++) {
			newRow.push_back(prob_per_cell);
		}
		newGrid.push_back(newRow);
	}
	return newGrid;
}