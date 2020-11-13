#ifndef PUZZLE_H
#define PUZZLE_H

class Puzzle {
private:
	int grid[9][9];
public:
	bool possible(int y, int x, int n);
	void solve();
	void run();
	void displayGrid();
	Puzzle(int grid_meta[9][9] = {0});
};

#endif // PUZZLE_H
