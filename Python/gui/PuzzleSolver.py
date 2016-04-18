#!/usr/bin/env python3

from PyQt4 import QtGui
from collections import deque
import copy

from .PuzzleViewer import PuzzleViewer
from .PuzzleActions import PuzzleActions
from core.Field import Field
from core.Piece import Piece

class PuzzleSolver ( QtGui.QWidget ):
   """Main container of the program"""
   def __init__ ( self ):
      super ( PuzzleSolver , self ).__init__ ()
      # Create the main container
      self.__horizontal_layout = QtGui.QHBoxLayout ()
      # Create components
      self.__puzzle_actions = PuzzleActions ()
      self.__puzzle_viewer = PuzzleViewer ()
      # Add components
      self.setLayout ( self.__horizontal_layout )
      self.__horizontal_layout.addWidget ( self.__puzzle_viewer )
      self.__horizontal_layout.addWidget ( self.__puzzle_actions )
      # Connect signals and slots
      self.__puzzle_actions.signal_open_file.connect ( self.__openFile )
      self.__puzzle_actions.signal_run_puzzle.connect ( self.__runPuzzle )
      self.__puzzle_pieces = []
      
   def __openFile ( self ):
      print ( "PuzzleSolver::openFile: Opening puzzle file" )
      file_path = QtGui.QFileDialog ().getOpenFileName ( self , "Open file" , "" , "Files (*)" )
      print ( "Trying to open file:" , file_path )
      
      try:
         file = open ( file_path , "r" )
      except IOError:
         print ( "Error opening file. Try again" )
         return
      
      file_contents = []
      
      for line in file:
         clean_line = line.rstrip ()
         words = clean_line.split ( " " )
         if len ( words ) == 1:
            if words[ 0 ] == "":
               continue
         file_contents.extend ( words )
         
      # Remove empty words
      while file_contents.count ( "" ) > 0:
         file_contents.remove ( "" )
      
      file.close ()
      # Convert the contents of the file into a queue
      file_queue = deque ( file_contents )
      
      puzzle_width = int ( file_queue.popleft () )
      puzzle_height = int ( file_queue.popleft () )
      self.__field = Field ( puzzle_width , puzzle_height )
      
      piece_amount = int ( file_queue.popleft () )
      
      # Clean all
      self.__puzzle_pieces[:] = []

      for i in range ( 0 , piece_amount ):
         piece = Piece ()
         piece.load ( file_queue )
         self.__puzzle_pieces.append ( piece )
         
      self.__puzzle_viewer.clean ()
      self.__puzzle_viewer.setSize ( puzzle_width , puzzle_height )
      
      print ( "File loaded" )
      
   def __runPuzzle ( self ):
      print ( "PuzzleSolver::runPuzzle: Running puzzle solver" )
      
      self.__puzzle_viewer.clean ()
      
      field_copy = copy.deepcopy ( self.__field )
      
      print ( "Original field size:" , self.__field.getWidth (), "x", self.__field.getHeight () )
      print ( "Copy field size:" , field_copy.getWidth (), "x", field_copy.getHeight () )
      
      if not self.__solve ( field_copy , self.__puzzle_pieces , 0 ):
         print ( "Solution not found" )
         QtGui.QMessageBox ().critical ( self , "Search complete" , "No solution found" )
      else:
         QtGui.QMessageBox ().information ( self , "Search complete" , "Solution found" )
      
   def __solve ( self , field , working_pieces , current_piece ):
      print ( "Adding piece ID:" , current_piece )
      
      if current_piece == len ( working_pieces ):
         print ( "Solution found" )
         field.print ()
         self.__puzzle_viewer.update ( field )
         
         return True
      
      working_pieces[ current_piece ].print ()
      
      print ( "Into this field:" )
      field.print ()
      self.__puzzle_viewer.update ( field )
      
      solved = False
      
      print ( "Trying to place..." )
      
      y = 0
      while ( y < field.getHeight () ) and not solved:
         x = 0
         while ( x < field.getWidth () ) and not solved:
            if field.canBeInserted ( working_pieces[ current_piece ] , x , y ):
               temp_field = copy.deepcopy ( field )
               temp_field.insertPiece ( working_pieces[ current_piece ] , x , y )
               
               print ( "Piece added at ", x, ",", y )
               
               print ( "New field:" )
               temp_field.print ()
               self.__puzzle_viewer.update ( temp_field )
               
               solved = self.__solve ( temp_field , working_pieces , current_piece + 1 )
               
               if not solved:
                  print ( "Trying another position with piece" , current_piece )
            x += 1
         y += 1
         
      return solved
