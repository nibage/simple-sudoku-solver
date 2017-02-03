#include <stack>
#include <iostream>
using namespace std;

class solver {
    bool generator ( unsigned int sudoku[][9] );
    bool check_row ( unsigned int number, unsigned int row, unsigned int sudoku[][9] );
    bool check_column ( unsigned int number, unsigned int column, unsigned int sudoku[][9] );
    bool check_square ( unsigned int number, unsigned int row, unsigned int column, unsigned int sudoku[][9]   );
    bool check_solved (  unsigned int sudoku[][9]  );
    void print_sudoku ( unsigned int sudoku[][9] );
    public:
    solver ( unsigned int sudoku[][9] );
};

void solver::print_sudoku( unsigned int sudoku[][9] )
{
    for (int i = 0; i < 9; i++ )
           for (int j = 0; j < 9; j++) {
              cout << sudoku[i][j] << " ";
                if(j == 8) {cout << "\n";}
            }
}

solver::solver (  unsigned int sudoku[][9]  ){
   print_sudoku( sudoku );
   generator(sudoku);
   cout << "\n";
   print_sudoku( sudoku );
}

bool solver::generator ( unsigned int sudoku[][9] ) {
  for (int i = 0; i < 9; ++i ) {
    for (int j = 0; j < 9; ++j ) {
      if ( sudoku [i][j] == 0 ) {
	for ( int k = 1; k < 10; ++k ) {
	  if (check_row(k, i, sudoku) && check_column(k, j, sudoku) && check_square(k, i, j, sudoku)) {
	    sudoku [i][j] = k;
	    if (check_solved ( sudoku ))
	      return 1;
	    else {
	     bool check = generator (sudoku);
	     if ( check )
	       return 1;
	     else
	     { continue;}
	    }
	  }
	}
	sudoku [i][j] = 0;
	return 0;
      }
    }
  }
}

bool solver::check_row ( unsigned int number, unsigned int row,  unsigned int sudoku[][9]  ){
        for (int i = 0; i < 9; i++ )
              if (sudoku[row][i] == number ) return false;
        return true;
}

bool solver::check_column ( unsigned int number, unsigned int column,  unsigned int sudoku[][9]   ){
        for (int j = 0; j < 9; j++ )
              if (sudoku[j][column] == number ) return false;
        return true;
}

bool solver::check_square ( unsigned int number, unsigned int row, unsigned int column,  unsigned int sudoku[][9]   ){
  for (int i = row - (row % 3) ; i < row - (row % 3) + 3 ; ++i ){
      for (int j = column - ( column % 3) ; j < column - ( column % 3) + 3; ++j) {
                if (sudoku[i][j] == number ) return false;
       }
  }
        return true;
}

bool solver::check_solved (  unsigned int sudoku[][9]  ) {
    for (int i = 0; i < 9; i++ )
           for (int j = 0; j < 9; j++){
               if (sudoku[i][j] == 0) return false;
           }
    return true;
}
