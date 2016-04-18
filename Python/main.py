#!/usr/bin/env python3

import sys
from PyQt4 import QtGui
from gui.MainWindow import MainWindow

# Program start

application = QtGui.QApplication ( sys.argv )
main_window = MainWindow ()
main_window.show ()
sys.exit ( application.exec_ () )