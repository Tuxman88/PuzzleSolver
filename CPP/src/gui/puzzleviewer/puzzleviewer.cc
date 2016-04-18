# include "puzzleviewer.hh" 

Gui::PuzzleViewer::PuzzleViewer ( QWidget* parent )
   : QWidget ( parent )
{
   buildGui ();
}

Gui::PuzzleViewer::~PuzzleViewer ( void )
{
}

void Gui::PuzzleViewer::buildGui ( void )
{
   grid_layout = new QGridLayout ( this );
   setLayout ( grid_layout );
   
   for ( int i = 0; i < 15; i++ )
   {
      QList< QLabel* > row;
      for ( int j = 0; j < 15; j++ )
      {
         QLabel* label;
         label = new QLabel ();
         
         QPixmap zero ( ":/n" );
         label->setPixmap ( zero.scaledToHeight ( 40 , Qt::SmoothTransformation ) );
         
         row.append ( label );
         grid_layout->addWidget ( label , j , i );
      }
      icons.append ( row );
   }
   
   return;
}

void Gui::PuzzleViewer::clean ( void )
{
   for ( int i = 0; i < 15; i++ )
   {
      for ( int j = 0; j < 15; j++ )
      {
         QPixmap zero ( ":/n" );
         icons[ i ][ j ]->setPixmap ( zero.scaledToHeight ( 40 , Qt::SmoothTransformation ) );
         icons[ i ][ j ]->update ();
      }
   }
   
   return;
}

void Gui::PuzzleViewer::update ( Core::Field& field )
{
   for ( int i = 0; i < field.getHeight (); i++ )
   {
      for ( int j = 0; j < field.getWidth (); j++ )
      {
         QPixmap zero ( QString ( ":/%1" ).arg ( field.getPoint ( j , i ) ) );
         icons[ j ][ i ]->setPixmap ( zero.scaledToHeight ( 40 , Qt::SmoothTransformation ) );
         icons[ j ][ i ]->update ();
      }
   }
   
   QApplication::processEvents ();
   
   return;
}

void Gui::PuzzleViewer::setSize ( int new_height , int new_width )
{
   for ( int i = 0; i < new_height; i++ )
   {
      for ( int j = 0; j < new_width; j++ )
      {
         QPixmap zero ( ":/0" );
         icons[ i ][ j ]->setPixmap ( zero.scaledToHeight ( 40 , Qt::SmoothTransformation ) );
         icons[ i ][ j ]->update ();
      }
   }
   
   return;
}
