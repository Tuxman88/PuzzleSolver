# ifndef MAINWINDOW_HH_
# define MAINWINDOW_HH_

# include <qt5/QtWidgets/QMainWindow>

# include "../puzzlesolver/puzzlesolver.hh"

namespace Gui
{
   class MainWindow : public QMainWindow
   {
      Q_OBJECT
      
      public:
         explicit MainWindow ( void );
         virtual ~MainWindow ( void );
         
      private:
         void buildGui ( void );
         
      private:
         Gui::PuzzleSolver* puzzlesolver;
   };
}

# endif
