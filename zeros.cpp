#include "headers/zeros.h"

using namespace std;

vector < vector <float> > zeros(int height, int width) {
	int i, j;
  
	// OPTIMIZATION: Reserve space in memory for vectors
	vector < vector <float> > newGrid;
    newGrid.reserve(width);
	vector <float> newRow;
    newRow.reserve(height);

  	// OPTIMIZATION: nested for loop not needed
    // because every row in the matrix is exactly the same
	
		for (j=0; j<width; j++) {
			newRow.push_back(0.0);
		}
        for (i=0; i<height; i++) {
		newGrid.push_back(newRow);
	}
	return newGrid;
}