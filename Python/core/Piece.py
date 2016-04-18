#!/usr/bin/env python3 

from .Matrix import Matrix

class Piece ( Matrix ):
   """Piece representation"""
   def __init__ ( self ):
      super ( Piece , self ).__init__ ()
      print ( "Piece created" )