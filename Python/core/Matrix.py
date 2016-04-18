#!/usr/bin/env python3 

from collections import deque

class Matrix:
   """Matrix representation of various components of the program"""
   def __init__ ( self ):
      self._width = 1
      self._height = 1
      self._id = 0
      self._contents = []
      
   def print ( self ):
      for i in range ( 0 , self._height ):
         print ( self._contents[ i ] )
         
   def load ( self , file__contents ):
      self._width = int ( file__contents.popleft () )
      self._height = int ( file__contents.popleft () )
      for i in range ( 0 , self._height ):
         row = []
         for j in range ( 0 , self._width ):
            tmp = int ( file__contents.popleft () )
            row.append ( tmp )
            if tmp > 0:
               self._id = tmp
         self._contents.append ( row )
   
   def getWidth ( self ):
      return self._width
   
   def getHeight ( self ):
      return self._height
   
   def getPoint ( self , x , y ):
      return self._contents[ y ][ x ]
   
   def getId ( self ):
      return self._id