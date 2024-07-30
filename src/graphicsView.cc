#include "graphicsView.h"

GraphicsView::GraphicsView(Board* b) : View(), board{b}, graphicsWindow{500,500} {
    graphicsWindow.fillRectangle(0, 0, 500, 500, Xwindow::Brown);
    
    for(int i = 0; i < 2; i++){
      graphicsWindow.drawString(50*1 + 25, 25 + (450 * i), "A");
      graphicsWindow.drawString(50*2 + 25, 25 + (450 * i), "B");
      graphicsWindow.drawString(50*3 + 25, 25 + (450 * i), "C");
      graphicsWindow.drawString(50*4 + 25, 25 + (450 * i), "D");
      graphicsWindow.drawString(50*5 + 25, 25 + (450 * i), "E");
      graphicsWindow.drawString(50*6 + 25, 25 + (450 * i), "F");
      graphicsWindow.drawString(50*7 + 25, 25 + (450 * i), "G");
      graphicsWindow.drawString(50*8 + 25, 25 + (450 * i), "H");
      graphicsWindow.drawString(25 + (450 * i), 50*9 - 25, "1");
      graphicsWindow.drawString(25 + (450 * i), 50*8 - 25, "2");
      graphicsWindow.drawString(25 + (450 * i), 50*7 - 25, "3");
      graphicsWindow.drawString(25 + (450 * i), 50*6 - 25, "4");
      graphicsWindow.drawString(25 + (450 * i), 50*5 - 25, "5");
      graphicsWindow.drawString(25 + (450 * i), 50*4 - 25, "6");
      graphicsWindow.drawString(25 + (450 * i), 50*3 - 25, "7");
      graphicsWindow.drawString(25 + (450 * i), 50*2 - 25, "8");
    }
}

void GraphicsView::renderDisplay(){
    for (int i=7; i>=0; i--) {
    for (int j=0; j<8; j++) {
      if((i+j)%2 == 0){
        graphicsWindow.fillRectangle(50*(j + 1), 50*(8-i), 50, 50, Xwindow::Black);
      } else {
        graphicsWindow.fillRectangle(50*(j + 1), 50*(8-i), 50, 50, Xwindow::White);
      }
      
      Piece* p = board->getSquare(j,i).getPiece();
      
      if(p){ 
        string s;
        
        if (p->getColor() == Color::White){
          PieceType t = p->getType();
          if (t == PieceType::Bishop) s = "B";
          if (t == PieceType::King) s = "K";
          if (t == PieceType::Knight) s = "N";
          if (t == PieceType::Queen) s = "Q";
          if (t == PieceType::Pawn) s = "P";
          if (t == PieceType::Rook) s = "R";
          graphicsWindow.drawString(50*(j + 1) + 25, 50*(9-i) - 25, s, Xwindow::Red);


        } else if (p->getColor() == Color::Black){
          PieceType t = p->getType();
          if (t == PieceType::Bishop) s = "b";
          if (t == PieceType::King) s = "k";
          if (t == PieceType::Knight) s = "n";
          if (t == PieceType::Queen) s = "q";
          if (t == PieceType::Pawn) s = "p";
          if (t == PieceType::Rook) s = "r";
          graphicsWindow.drawString(50*(j + 1) + 25, 50*(9-i) - 25, s, Xwindow::Blue);

        }
        
        
      }
    }
  }

}