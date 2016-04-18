# include "mainwindow.hh"

Gui::MainWindow::MainWindow ( void )
   : QMainWindow ()
{
   buildGui ();
}

Gui::MainWindow::~MainWindow ( void )
{
}

void Gui::MainWindow::buildGui ( void )
{
   puzzlesolver = new Gui::PuzzleSolver ();
   
   this->setCentralWidget ( puzzlesolver );
   
   return;
}
