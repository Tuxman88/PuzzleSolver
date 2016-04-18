# ifndef PUZZLEVIEWER_HH_
# define PUZZLEVIEWER_HH_

# include <qt5/QtWidgets/QWidget>
# include <qt5/QtWidgets/QGridLayout>
# include <qt5/QtWidgets/QLabel>
# include <qt5/QtGui/QPixmap>
# include <qt5/QtCore/QDebug>
# include <qt5/QtCore/QList>
# include <qt5/QtWidgets/QApplication>
# include "../../core/core.hh"

namespace Gui
{
   class PuzzleViewer : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit PuzzleViewer ( QWidget* parent = 0 );
         virtual ~PuzzleViewer ( void );
         
         void setSize ( int new_height , int new_width );
         void update ( Core::Field& field );
         void clean ( void );

      private:
         void buildGui ( void );
         
      private:
         int width;
         int height;
         QList< QList< QLabel* > > icons;
         QGridLayout* grid_layout;
   };
}

# endif
