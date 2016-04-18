# include "field.hh"

Core::Field::Field ( void )
{
}
      
Core::Field::Field ( int x , int y )
{
   for ( int i = 0; i < y; i++ )
   {
      vector< int > row;
      for ( int j = 0; j < x; j++ )
      {
         row.push_back ( 0 );
      }
      contents.push_back ( row );
   }
   
   width = x;
   height = y;
}

Core::Field::~Field ( void )
{
}
      
bool Core::Field::canBeInserted ( Core::Piece piece , int x , int y )
{
   // Check sizes
   if ( x + piece.getWidth () > width )
   {
      return ( false );
   }
   
   if ( y + piece.getHeight () > height )
   {
      return ( false );
   }
   
   // Validate positions
   bool all_ok = true;
   for ( int field_y = y , piece_y = 0; piece_y < piece.getHeight () && all_ok; piece_y++ , field_y++ )
   {
      for ( int field_x = x , piece_x = 0; piece_x < piece.getWidth () && all_ok; piece_x++ , field_x++ )
      {
         if ( contents[ field_y ][ field_x ] > 0 ) // Space used
         {
            if ( piece.getPoint ( piece_x , piece_y ) > 0 )
            {
               all_ok = false; // Collition
            }
         }
      }
   }
   
   return ( all_ok );
}
      
void Core::Field::insertPiece ( Core::Piece piece , int x , int y )
{
   // Copy positions
   for ( int field_y = y , piece_y = 0; piece_y < piece.getHeight (); piece_y++ , field_y++ )
   {
      for ( int field_x = x , piece_x = 0; piece_x < piece.getWidth (); piece_x++ , field_x++ )
      {
         if ( piece.getPoint ( piece_x , piece_y ) > 0 )
         {
            contents[ field_y ][ field_x ] = piece.getPoint ( piece_x , piece_y );
         }
      }
   }
   
   return;
}
      
void Core::Field::removePiece ( int piece_id )
{
   for ( int y = 0; y < height; y++ )
   {
      for ( int x = 0; x < width; x++ )
      {
         if ( contents[ y ][ x ] == piece_id )
         {
            contents[ y ][ x ] = 0;
         }
      }
   }
   
   return;
}
