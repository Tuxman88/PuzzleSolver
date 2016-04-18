# include "puzzlesolver.hh"

Gui::PuzzleSolver::PuzzleSolver ( QWidget* parent )
   : QWidget ( parent )
{
   field = 0;
   buildGui ();
}

Gui::PuzzleSolver::~PuzzleSolver ( void )
{
}

void Gui::PuzzleSolver::buildGui ( void )
{
   horizontal_layout = new QHBoxLayout ( this );
   this->setLayout ( horizontal_layout );
   
   vertical_layout_left = new QVBoxLayout ();
   vertical_layout_right = new QVBoxLayout ();
   
   horizontal_layout->addLayout ( vertical_layout_left );
   horizontal_layout->addLayout ( vertical_layout_right );
   
   viewer = new Gui::PuzzleViewer ();
   actions = new Gui::PuzzleActions ();
   
   vertical_layout_left->addWidget ( viewer );
   
   vertical_layout_right->addStretch ();
   vertical_layout_right->addWidget ( actions );
   vertical_layout_right->addStretch ();
   
   connect ( actions , SIGNAL ( openFile () ) , this , SLOT ( openFile () ) );
   connect ( actions , SIGNAL ( runPuzzle () ) , this , SLOT ( runPuzzle () ) );
   
   return;
}

void Gui::PuzzleSolver::openFile ( void )
{
   qDebug () << "Gui::PuzzleSolver::openFile: Opening puzzle file";
   
   std::ifstream file;
   
   QString file_path;
   file_path = QFileDialog::getOpenFileName ( this ,
                                              "Open File" ,
                                              "" ,
                                              "Files (*)"
                                            );
   
   qDebug () << "Puzzle file path: " << file_path;
   
   file.open ( file_path.toStdString ().c_str () , std::ios::in );
   
   if ( !file.is_open () )
   {
      qDebug () << "Can't open file";
      return;
   }
   
   // Get puzzle size
   int puzzle_width , puzzle_height;
   file >> puzzle_width >> puzzle_height;
   
   if ( field != 0 )
   {
      delete field;
   }
   
   field = new Core::Field ( puzzle_width , puzzle_height );
   
   int piece_amount;
   file >> piece_amount;
   puzzle_pieces.clear ();
   
   for ( int i = 0; i < piece_amount; i++ )
   {
      Core::Piece piece;
      piece.load ( file );
      puzzle_pieces.push_back ( piece );
   }
   
   viewer->clean ();
   viewer->setSize ( puzzle_width , puzzle_height );
   
   qDebug () << "Puzzle file loaded: " << puzzle_width << "x" << puzzle_height;
   
   return;
}

void Gui::PuzzleSolver::runPuzzle ( void )
{
   if ( field == 0 )
   {
      return;
   }
   
   viewer->clean ();
   
   qDebug () << "Gui::PuzzleSolver::runPuzzle: Running solver";
   
   if ( !solve ( (*field) , puzzle_pieces , 0 ) )
   {
      qDebug () << "No solution found" << endl;
      QMessageBox::critical ( this , "Search complete" , "No solution found" );
   }
   else
   {
      QMessageBox::information ( this , "Search complete" , "Solution found" );
   }
   
   return;
}

bool Gui::PuzzleSolver::solve ( Core::Field field , vector< Core::Piece >& working_pieces , int current_piece )
{
   qDebug () << "Adding piece ID " << current_piece << endl << endl;
   
   if ( current_piece == (int)(working_pieces.size ()) )
   {
      qDebug () << "Solution found:" << endl << endl;
      field.print ();
      viewer->update ( field );
      
      return ( true );
   }
   
   working_pieces[ current_piece ].print ();
   
   qDebug () << endl << "Into this field:" << endl;
   field.print ();
   viewer->update ( field );
   qDebug () << endl;
   
   bool solved = false;
   
   qDebug () << "Trying to place..." << endl;
   
   for ( int y = 0; y < field.getHeight () && !solved; y++ )
   {
      for ( int x = 0; x < field.getWidth () && !solved; x++ )
      {
         if ( field.canBeInserted ( working_pieces[ current_piece ] , x , y ) )
         {
            Core::Field temp_field = field;
            temp_field.insertPiece ( working_pieces[ current_piece ] , x , y );
            
            qDebug () << endl <<"Piece added at " << x << "," << y << endl;
            
            qDebug () << "New field: " << endl;
            temp_field.print ();
            viewer->update ( temp_field );
            
            qDebug () << endl;
            
            solved = solve ( temp_field , working_pieces , current_piece + 1 );
            
            if ( !solved )
            {
               qDebug () << "Trying another position with piece " << current_piece << endl;
            }
         }
      }
   }
   
   return ( solved );
}
