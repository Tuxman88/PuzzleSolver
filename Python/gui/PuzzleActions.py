#!/usr/bin/env python3

from PyQt4 import QtGui
from PyQt4 import QtCore

class PuzzleActions ( QtGui.QWidget ):
   """Viewer of the puzzle while solving"""
   signal_open_file = QtCore.pyqtSignal ()
   signal_run_puzzle = QtCore.pyqtSignal ()
      
   def __init__ ( self ):
      super ( PuzzleActions , self ).__init__ ()
      # Create container components
      self.__vertical_layout = QtGui.QVBoxLayout ()
      # Create visual components
      self.__button_open = QtGui.QPushButton ( "Open puzzle file" )
      self.__button_run = QtGui.QPushButton ( "Run puzzle solver" )
      # Add components
      self.setLayout ( self.__vertical_layout )
      self.__vertical_layout.addStretch ()
      self.__vertical_layout.addWidget ( self.__button_open )
      self.__vertical_layout.addWidget ( self.__button_run )
      self.__vertical_layout.addStretch ()
      # Prepare signals
      # Connect components
      self.__button_open.clicked.connect ( self.__openFile )
      self.__button_run.clicked.connect ( self.__runPuzzle )
      
   def __openFile ( self ):
      self.signal_open_file.emit ()
      
   def __runPuzzle ( self ):
      self.signal_run_puzzle.emit ()
