# include "matrix.hh"

Core::Matrix::Matrix ( void )
{
   width = 1;
   height = 1;
   id = 0;
}

Core::Matrix::~Matrix ( void )
{
}
      
void Core::Matrix::print ( void )
{
   for ( unsigned int i = 0; i < contents.size (); i++ )
   {
      for ( unsigned int j = 0; j < contents[ i ].size (); j++ )
      {
         cout << contents[ i ][ j ] << " ";
      }
      cout << endl;
   }
   
   return;
}
      
void Core::Matrix::load ( ifstream& file )
{
   file >> width >> height;
   
   for ( int i = 0; i < height; i++ )
   {
      vector< int > row;
      for ( int j = 0; j < width; j++ )
      {
         int tmp;
         file >> tmp;
         row.push_back ( tmp );
         
         if ( tmp > 0 )
         {
            id = tmp;
         }
      }
      contents.push_back ( row );
   }
}
      
int Core::Matrix::getWidth ( void )
{
   return ( width );
}
      
int Core::Matrix::getHeight ( void )
{
   return ( height );
}
      
int Core::Matrix::getPoint ( int x , int y )
{
   return ( contents[ y ][ x ] );
}
      
int Core::Matrix::getId ( void )
{
   return ( id );
}
