#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"

// TODO: Your Sudoku class goes here:

class Sudoku {

private:
  int size;
  vector<vector<set<int>>> incomplete;

public:

  Sudoku(int inSize) {
    size = inSize;
  }


};


#endif
