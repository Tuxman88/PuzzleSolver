#!/usr/bin/env python3

from PyQt4 import QtGui
from PyQt4 import QtCore

from .PuzzleSolver import PuzzleSolver

class MainWindow ( QtGui.QMainWindow ):
   """Main window of the program"""
   def __init__ ( self ):
      super ( MainWindow , self ).__init__ ()
      # Create the main widget
      self.__puzzle_solver = PuzzleSolver ()
      # Set components
      self.setCentralWidget ( self.__puzzle_solver )
      self.setWindowTitle ( "Puzzle solver for Python v3" )
