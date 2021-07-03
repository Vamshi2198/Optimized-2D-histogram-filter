#include "headers/sense.h"

using namespace std;

vector< vector <float> > sense(char color, vector< vector <char> > &grid, vector< vector <float> > &beliefs,  float p_hit, float p_miss) 
{
  	for (int i=0; i < grid.size(); ++i) {
		for (int j=0; j < grid[0].size(); ++j) {
			// remove the cell and prior variables since not needed
			if (grid[i][j] == color) {
				// update the belief vector instead of creating new variable
				beliefs[i][j] = beliefs[i][j] * p_hit;
			}
			// removed the extra if statement since not needed
			else {
				// update the belief vector instead of creating new variable
				beliefs[i][j] = beliefs[i][j] * p_miss;
			}
		}
	}
	return beliefs;
}