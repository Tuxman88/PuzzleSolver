#!/usr/bin/env python3

from PyQt4 import QtGui
from PyQt4 import QtCore

from core.Field import Field

class PuzzleViewer ( QtGui.QWidget ):
   """Viewer of the puzzle while solving"""
   def __init__ ( self ):
      super ( PuzzleViewer , self ).__init__ ()
      # Create components
      self.__grid_layout = QtGui.QGridLayout ()
      self.__icons = [] # Create empty list, which will contain the rows of icons of the image
      # Add components
      self.setLayout ( self.__grid_layout ) 
      # Configure components
      for i in range ( 0 , 15 ):
         row = []
         for j in range ( 0 , 15 ):
            pixmap = QtGui.QPixmap ( "resources/n.png" )
            label = QtGui.QLabel ()
            label.setPixmap ( pixmap.scaledToHeight ( 40 , QtCore.Qt.SmoothTransformation ) )
            row.append ( label )
            self.__grid_layout.addWidget ( label , i , j )
         self.__icons.append ( row )

   def clean ( self ):
      for i in range ( 0 , 15 ):
         for j in range ( 0 , 15 ):
            pixmap = QtGui.QPixmap ( "resources/n.png" )
            self.__icons[ i ][ j ].setPixmap ( pixmap.scaledToHeight ( 40 , QtCore.Qt.SmoothTransformation ) )
            self.__icons[ i ][ j ].update ()
            
   def update ( self , field ):
      for i in range ( 0 , field.getHeight () ):
         for j in range ( 0 , field.getWidth () ):
            zero= QtGui.QPixmap ( "resources/" + str ( field.getPoint ( j , i ) ) + ".png" )
            self.__icons[ i ][ j ].setPixmap ( zero.scaledToHeight ( 40 , QtCore.Qt.SmoothTransformation ) )
            self.__icons[ i ][ j ].update ()
   
      QtGui.QApplication.processEvents ()
   
   def setSize ( self , new_width , new_height ):
      for i in range ( 0 , new_height ):
         for j in range ( 0 , new_width ):
            pixmap = QtGui.QPixmap ( "resources/0.png" )
            self.__icons[ i ][ j ].setPixmap ( pixmap.scaledToHeight ( 40 , QtCore.Qt.SmoothTransformation ) )
            self.__icons[ i ][ j ].update ()