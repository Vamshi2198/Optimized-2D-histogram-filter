#include "headers/blur.h"
#include "headers/zeros.h"

using namespace std;

vector < vector <float> > blur(vector < vector < float> > grid, float blurring) {

  	vector < vector <float> > window;
	vector < vector <float> > newGrid;
	vector <float> row;
	vector <float> newRow;

	int height = grid.size();
	int width = grid[0].size();
	
// OPTIMIZATION: Used static keyword function
    static float center = 1.0 - blurring;
	static float corner = blurring / 12.0;
	static float adjacent = blurring / 6.0;


	int i, j;
	float val;

	for (i=0; i<3; i++) {
		row.clear();
		for (j=0; j<3; j++) {
			switch (i) {
				case 0: 
				switch (j) {
					case 0: 
					val = corner;
					break;

					case 1: 
					val = adjacent;
					break;

					case 2: 
					val = corner;
					break;
				}
				break; 

				case 1:
				switch (j) {
					case 0: 
					val = adjacent;
					break;

					case 1: 
					val = center;
					break;
					
					case 2: 
					val = adjacent;
					break;
				}
				break;

				case 2:
				switch(j) {
					case 0: 
					val = corner;
					break;

					case 1: 
					val = adjacent;
					break;
					
					case 2: 
					val = corner;
					break;
				}
				break;
			}
			row.push_back(val);
		}
		window.push_back(row);
	}


	vector <int> DX;
	vector <int> DY;

	DX.push_back(-1); DX.push_back(0); DX.push_back(1);
	DY.push_back(-1); DY.push_back(0); DY.push_back(1);

	int dx, dy, ii, jj, new_i, new_j, multiplier, newVal;
  
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
