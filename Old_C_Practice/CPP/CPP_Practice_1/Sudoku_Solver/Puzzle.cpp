#include <iostream>
#include <windows.h>
#include "Puzzle.h"

using namespace std;

Puzzle::Puzzle(int grid_meta[9][9]) {
	for(int y = 0; y < 9; y++) {
		for(int x = 0; x < 9; x++) {
			grid[y][x] = grid_meta[y][x];
		}
	}
}
	
bool Puzzle::possible(int y, int x, int n) {
	for(int i = 0; i < 9; i++) {
		if(grid[y][i] == n) return false;
	}
	for(int i = 0; i < 9; i++) {
			if(grid[i][x] == n) return false;
	}
	int x0 = (x/3)*3;
	int y0 = (y/3)*3;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; i < 3; i++) {
			if(grid[y0+i][x0+j] == n) return false;
		}
	}
	return true;
}
	
void Puzzle::solve() {
	for(int y = 0; y < 9; y++) {
		for(int x = 0; x < 9; x++) {
			if(grid[y][x] == 0) {
				for(int n = 1; n < 10; n++) {
					if(possible(y, x, n)) {
						grid[y][x] = n;
						solve();
						grid[y][x] = 0;
					}
				}
				return;
			}
		}
	}
}

void Puzzle::run() {
	displayGrid();
	cout << "running..." << endl;
	solve();
	displayGrid();
}

void Puzzle::displayGrid() {
	system("CLS");
	for(int y = 0; y < 9; y++) {
		cout << "[";
		for(int x = 0; x < 8; x++) {
			cout << grid[y][x] << " ";
		}
		cout << grid[y][8] << "]\n";
	}
	cout << endl;
}