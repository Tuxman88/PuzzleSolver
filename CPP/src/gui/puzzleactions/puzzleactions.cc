# include "puzzleactions.hh" 

Gui::PuzzleActions::PuzzleActions ( QWidget* parent )
   : QWidget ( parent )
{
   buildGui ();
}

Gui::PuzzleActions::~PuzzleActions ( void )
{
}

void Gui::PuzzleActions::buildGui ( void )
{
   vertical_layout = new QVBoxLayout ( this );
   setLayout ( vertical_layout );
   
   button_open = new QPushButton ( "Open puzzle file" );
   button_run = new QPushButton ( "Run puzzle solver" );
   
   vertical_layout->addWidget ( button_open );
   vertical_layout->addWidget ( button_run );
   
   connect ( button_open , SIGNAL ( clicked () ) , this , SIGNAL ( openFile () ) );
   connect ( button_run , SIGNAL ( clicked () ) , this , SIGNAL ( runPuzzle () ) );
   
   return;
}
