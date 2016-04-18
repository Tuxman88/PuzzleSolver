# ifndef MATRIX_HH_
# define MATRIX_HH_

# include <vector>
# include <fstream>
# include <iostream>

using std::vector;
using std::ifstream;
using std::cout;
using std::endl;

namespace Core
{
   class Matrix
   {
      public:
         explicit Matrix ( void );
         virtual ~Matrix ( void );
         
         void print ( void );
         void load ( ifstream& file );
         int getWidth ( void );
         int getHeight ( void );
         int getPoint ( int x , int y );
         int getId ( void );
         
      protected:
         vector< vector< int > > contents;
         int width;
         int height;
         int id;
   };
}

# endif
