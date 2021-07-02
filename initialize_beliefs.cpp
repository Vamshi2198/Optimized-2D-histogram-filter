#include "headers/initialize_beliefs.h"

using namespace std;

// OPTIMIZATION: passed height and width instead of grid
vector< vector <float> > initialize_beliefs(int height, int width) {

	// OPTIMIZATION: Removed variables which are not necessary
	// OPTIMIZATION: Reserve space in memory for vectors

  	vector < vector <float> > newGrid;
    newGrid.reserve(height);
	vector <float> newRow;
    newRow.reserve(width);
	int i, j;
	float prob_per_cell;
    prob_per_cell = 1.0 / float(height * width) ;

  	// OPTIMIZATION: removed nested for loops
	
		for (j=0; j<width; j++) {
			newRow.push_back(prob_per_cell);
		}
        for (i=0; i<height; i++) {
		newGrid.push_back(newRow);
	}
	return newGrid;
}