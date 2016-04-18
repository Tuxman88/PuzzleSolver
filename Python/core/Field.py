#!/usr/bin/env python3 

from .Matrix import Matrix

class Field ( Matrix ):
   """Field representation"""
   def __init__ ( self , x , y ):
      super ( Field , self ).__init__ ()
      for i in range ( 0 , y ):
         row = []
         for j in range ( 0 , x ):
            row.append ( 0 )
         self._contents.append ( row )
         
      self._width = x
      self._height = y
      
      print ( "Field created with size:", self._width, "x", self._height )
      print ( "Field values stored:", self.getWidth (), "x", self.getHeight () )
      
   def canBeInserted ( self , piece , x , y ):
      if ( x + piece.getWidth () ) > self._width:
         return False
      
      if ( y + piece.getHeight () ) > self._height:
         return False
      
      # Validate positions
      all_ok = True
      field_y = y
      piece_y = 0
      
      while ( piece_y < piece.getHeight () ) and ( all_ok == True ):
         field_x = x
         piece_x = 0
         while ( piece_x < piece.getWidth () ) and ( all_ok == True ):
            if self._contents[ field_y ][ field_x ] > 0: # Space used
               if piece.getPoint ( piece_x , piece_y ) > 0:
                  all_ok = False
            piece_x += 1
            field_x += 1
         piece_y += 1
         field_y += 1
      
      return all_ok
   
   def insertPiece ( self , piece , x , y ):
      print ( "Inserting piece:" )
      piece.print ()
      print ( "In coordinates:" , x , "," , y )
      field_y = y
      for piece_y in range ( 0 , piece.getHeight () ):
         field_x = x
         for piece_x in range ( 0 , piece.getWidth () ):
            print ( "Checking coordinate:",piece_x , ",", piece_y )
            if piece.getPoint ( piece_x , piece_y ) > 0:
               self._contents[ field_y ][ field_x ] = piece.getPoint ( piece_x , piece_y )
            field_x += 1
         field_y += 1
         
   def removePiece ( self , piece_id ):
      for i in range ( 0 , self._height ):
         for j in range ( 0 , self._width ):
            if self._contents[ i ][ j ] == piece_id:
               self._contents[ i ][ j ] = 0
