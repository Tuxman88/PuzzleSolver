# ifndef PUZZLEACTIONS_HH_
# define PUZZLEACTIONS_HH_

# include <qt5/QtWidgets/QWidget>
# include <qt5/QtWidgets/QPushButton>
# include <qt5/QtWidgets/QVBoxLayout>

namespace Gui
{
   class PuzzleActions : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit PuzzleActions ( QWidget* parent = 0 );
         virtual ~PuzzleActions ( void );
         
      signals:
         void openFile ( void );
         void runPuzzle ( void );
         
      private:
         void buildGui ( void );
         
      private:
         QVBoxLayout* vertical_layout;
         QPushButton* button_open;
         QPushButton* button_run;
   };
}

# endif
