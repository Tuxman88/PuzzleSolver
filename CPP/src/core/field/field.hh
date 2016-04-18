# ifndef FIELD_HH_
# define FIELD_HH_

# include "../matrix/matrix.hh"
# include "../piece/piece.hh"

namespace Core
{
   class Field : public Matrix
   {
      public:
         explicit Field ( void );
         explicit Field ( int x , int y );
         virtual ~Field ( void );
         
         bool canBeInserted ( Core::Piece piece , int x , int y );
         void insertPiece ( Core::Piece piece , int x , int y );
         void removePiece ( int piece_id );
   };
}

# endif
