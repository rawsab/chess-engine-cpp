#include "graphicsView.h"

GraphicsView::GraphicsView(Board* b) : View(), board{b}, graphicsWindow{500, 500} {
    graphicsWindow.fillRectangle(0, 0, 500, 500, Xwindow::Black);

    for (int i = 0; i < 2; i++) {
        graphicsWindow.drawString(50 * 1 + 25, 25 + (450 * i), "A", Xwindow::White);
        graphicsWindow.drawString(50 * 2 + 25, 25 + (450 * i), "B", Xwindow::White);
        graphicsWindow.drawString(50 * 3 + 25, 25 + (450 * i), "C", Xwindow::White);
        graphicsWindow.drawString(50 * 4 + 25, 25 + (450 * i), "D", Xwindow::White);
        graphicsWindow.drawString(50 * 5 + 25, 25 + (450 * i), "E", Xwindow::White);
        graphicsWindow.drawString(50 * 6 + 25, 25 + (450 * i), "F", Xwindow::White);
        graphicsWindow.drawString(50 * 7 + 25, 25 + (450 * i), "G", Xwindow::White);
        graphicsWindow.drawString(50 * 8 + 25, 25 + (450 * i), "H", Xwindow::White);
        graphicsWindow.drawString(25 + (450 * i), 50 * 9 - 25, "7", Xwindow::White);
        graphicsWindow.drawString(25 + (450 * i), 50 * 8 - 25, "6", Xwindow::White);
        graphicsWindow.drawString(25 + (450 * i), 50 * 7 - 25, "5", Xwindow::White);
        graphicsWindow.drawString(25 + (450 * i), 50 * 6 - 25, "4", Xwindow::White);
        graphicsWindow.drawString(25 + (450 * i), 50 * 5 - 25, "3", Xwindow::White);
        graphicsWindow.drawString(25 + (450 * i), 50 * 4 - 25, "2", Xwindow::White);
        graphicsWindow.drawString(25 + (450 * i), 50 * 3 - 25, "1", Xwindow::White);
        graphicsWindow.drawString(25 + (450 * i), 50 * 2 - 25, "0", Xwindow::White);
    }
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                graphicsWindow.fillRectangle(50 * (j + 1), 50 * (8 - i), 50, 50, Xwindow::Red);
            } else {
                graphicsWindow.fillRectangle(50 * (j + 1), 50 * (8 - i), 50, 50, Xwindow::Blue);
            }
        }
    }
}

void GraphicsView::renderDisplay() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // Calculate the positions correctly to render the board vertically
            int x = 50 * (i + 1);
            int y = 50 * (j + 1);

            if ((i + j) % 2 == 0) {
                graphicsWindow.fillRectangle(x, y, 50, 50, Xwindow::Red);
            } else {
                graphicsWindow.fillRectangle(x, y, 50, 50, Xwindow::Blue);
            }

            Piece* p = board->getSquare(j, i).getPiece();

            if (p) {
                string s;

                if (p->getColor() == Color::White) {
                    PieceType t = p->getType();
                    if (t == PieceType::Bishop) s = "B";
                    if (t == PieceType::King) s = "K";
                    if (t == PieceType::Knight) s = "N";
                    if (t == PieceType::Queen) s = "Q";
                    if (t == PieceType::Pawn) s = "P";
                    if (t == PieceType::Rook) s = "R";
                    graphicsWindow.drawString(x + 25, y + 25, s, Xwindow::White);
                } else if (p->getColor() == Color::Black) {
                    PieceType t = p->getType();
                    if (t == PieceType::Bishop) s = "b";
                    if (t == PieceType::King) s = "k";
                    if (t == PieceType::Knight) s = "n";
                    if (t == PieceType::Queen) s = "q";
                    if (t == PieceType::Pawn) s = "p";
                    if (t == PieceType::Rook) s = "r";
                    graphicsWindow.drawString(x + 25, y + 25, s, Xwindow::Black);
                }
            }
        }
    }
}