# ifndef PUZZLESOLVER_HH_
# define PUZZLESOLVER_HH_

# include <qt5/QtWidgets/QWidget>
# include <qt5/QtWidgets/QHBoxLayout>
# include <qt5/QtWidgets/QVBoxLayout>
# include <qt5/QtWidgets/QFileDialog>
# include <qt5/QtWidgets/QMessageBox>
# include <qt5/QtCore/QDebug>
# include <qt5/QtCore/QString>
# include <fstream>
# include <vector>

# include "../puzzleviewer/puzzleviewer.hh"
# include "../puzzleactions/puzzleactions.hh"
# include "../../core/core.hh"

using std::ifstream;
using std::vector;

namespace Gui
{
   class PuzzleSolver : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit PuzzleSolver ( QWidget* parent = 0 );
         virtual ~PuzzleSolver ( void );
         
      private:
         void buildGui ( void );
         bool solve ( Core::Field field , vector< Core::Piece >& working_pieces , int current_piece );
         
      private slots:
         void openFile ( void );
         void runPuzzle ( void );
         
      private:
         QHBoxLayout* horizontal_layout;
         QVBoxLayout* vertical_layout_left;
         QVBoxLayout* vertical_layout_right;
         
         Gui::PuzzleViewer* viewer;
         Gui::PuzzleActions* actions;
         Core::Field* field;
         vector< Core::Piece > puzzle_pieces;
   };
}

# endif
