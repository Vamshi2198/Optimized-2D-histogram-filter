#include "headers/blur.h"
#include "headers/zeros.h"

using namespace std;

vector < vector <float> > blur(vector < vector < float> > grid, float blurring) {
	
// OPTIMIZATION: Used static keyword function
    static float center = 1.0 - blurring;
	static float corner = blurring / 12.0;
	static float adjacent = blurring / 6.0;

	static vector < vector <float> > window = { {corner, adjacent, corner}, {adjacent, center, adjacent}, {corner, adjacent, corner} };

	static vector <int> DX = {-1, 0, 1};
	static vector <int> DY = {-1, 0, 1};

	
	vector < vector <float> > newGrid;
	vector <float> row;
	vector <float> newRow;

	int height = grid.size();
	int width = grid[0].size();
	float val;
    int i, j, dx, dy, ii, jj, new_i, new_j, multiplier, newVal;
  
	// OPTIMIZATION: Used improved zeros function
	newGrid = zeros(height, width);

	for (i=0; i< height; i++ ) {
		for (j=0; j<width; j++ ) {
			val = grid[i][j];
			newVal = val;
			for (ii=0; ii<3; ii++) {
				dy = DY[ii];
				for (jj=0; jj<3; jj++) {
					dx = DX[jj];
					new_i = (i + dy + height) % height;
					new_j = (j + dx + width) % width;
					multiplier = window[ii][jj];
					newGrid[new_i][new_j] += newVal * multiplier;
				}
			}
		}
	}

	return newGrid;
}
