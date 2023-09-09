#include<iostream>
#include<stdlib.h>
//#include<string>
#include<windows.h>
#include<conio.h>
using namespace std;

// Defines the chess pieces
enum Piece {
    EMPTY,
    PAWNW,
    ROOKW,
    KNIGHTW,
    BISHOPW,
    QUEENW,
    KINGW,
    
    PAWNB,
    ROOKB,
    KNIGHTB,
    BISHOPB,
    QUEENB,
    KINGB
    
};

class ChessGame{
private:
    Piece board[8][8];
    bool whiteTurn;

public:
    ChessGame() {
        initializeBoard();
        whiteTurn = true;
    }
    void intro(){
    cout<<"                     *                        "<<endl;
	Sleep(50);
	cout<<"                   * * *                      "<<endl;
	Sleep(55);
	cout<<"                     *                        "<<endl;
	Sleep(60);
	cout<<"                 * * * * *                    "<<endl;
	Sleep(65);
	cout<<"                  * * * *                     "<<endl;
	Sleep(70);
	cout<<"                   * * *                      "<<endl;
	Sleep(75);
	cout<<"                   * * *                      "<<endl;
	Sleep(80);
	cout<<"                 * * * * *                    "<<endl;
	Sleep(80);
	cout<<"                 * * * * *                    "<<endl;
	Sleep(85);
	cout<<"                   * * *                      "<<endl;
	Sleep(85);
	cout<<"                  * * * *                     "<<endl;
	Sleep(90);
	cout<<"                 * * * * *                    "<<endl;
	Sleep(90);
	cout<<"                * * * * * *                   "<<endl;
	Sleep(90);
	cout<<"               * * * * * * *                  "<<endl;
	Sleep(90);
	cout<<"              * * * * * * * *                 "<<endl;
	Sleep(90);
	cout<<"            * * * * * * * * * *               "<<endl;
	Sleep(100);
	cout<<"          * * * * * * * * * * * *             "<<endl;
	char ch;
	cout<<endl;
	cout<<"Made by Tahir"<<endl;
	cout<<"Press any key to Play....."<<endl;
	ch = getch();
	
	}

    void initializeBoard() {
        // Place the pawns
        for (int i = 0; i < 8; i++) {
            board[1][i] = PAWNB;
            board[6][i] = PAWNW;
        }

        // Place the rooks
        board[0][0] = ROOKB;
        board[0][7] = ROOKB;
        board[7][0] = ROOKW;
        board[7][7] = ROOKW;

        // Place the knights
        board[0][1] = KNIGHTB;
        board[0][6] = KNIGHTB;
        board[7][1] = KNIGHTW;
        board[7][6] = KNIGHTW;

        // Place the bishops
        board[0][2] = BISHOPB;
        board[0][5] = BISHOPB;
        board[7][2] = BISHOPW;
        board[7][5] = BISHOPW;

        // Place the queens
        board[0][3] = QUEENB;
        board[7][3] = QUEENW;

        // Place the Kings
        board[0][4] = KINGB;
        board[7][4] = KINGW;

        // Initialize the chessboard with empty squares
        for (int i = 2; i < 6; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = EMPTY;
            }
        }
    }

    // Display the board on the screen
    void displayBoard() {
    	char latter;
        cout << "   ";
        for (int i = 0; i < 8; i++) {
        	latter = 'A' + i;
            cout << " " << latter << "  ";
        }
        cout << endl;

        for (int i = 0; i < 8; i++) {
            cout << "  +---+---+---+---+---+---+---+---+" << endl;
            cout << i+1 << " ";
            for (int j = 0; j < 8; j++) {
                char getch = ' ';
                switch (board[i][j]) {
                case EMPTY:
                    getch = '-';
                    break;
                case PAWNW:
                    getch = 'P';
                    break;
                case ROOKW:
                    getch = 'R';
                    break;
                case KNIGHTW:
                    getch = 'N';
                    break;
                case BISHOPW:
                    getch = 'B';
                    break;
                case QUEENW:
                    getch = 'Q';
                    break;
                case KINGW:
                    getch = 'K';
                    break;
                case PAWNB:
                    getch = 'p';
                    break;
                case ROOKB:
                    getch = 'r';
                    break;
                case KNIGHTB:
                    getch = 'n';
                    break;
                case BISHOPB:
                    getch = 'b';
                    break;
                case QUEENB:
                    getch = 'q';
                    break;
                case KINGB:
                    getch = 'k';
                    break;
                }

                cout << "|" << " " << getch << " ";
            }
            cout << "|" << endl;
        }
        cout << "  +---+---+---+---+---+---+---+---+" << endl;
    }

    bool isWhitePiece(int srcX, int srcY) {
        if (board[srcX][srcY] == PAWNW || board[srcX][srcY] == ROOKW ||
            board[srcX][srcY] == KNIGHTW || board[srcX][srcY] == BISHOPW ||
            board[srcX][srcY] == QUEENW || board[srcX][srcY] == KINGW) {
            return true;
        }
        return false;
    }

    bool isBlackPiece(int srcX, int srcY) {
        if (board[srcX][srcY] == PAWNB || board[srcX][srcY] == ROOKB ||
            board[srcX][srcY] == KNIGHTB || board[srcX][srcY] == BISHOPB ||
            board[srcX][srcY] == QUEENB || board[srcX][srcY] == KINGB) {
            return true;
        }
        return false;
    }

    bool isSameColor(int srcX, int srcY, int destX, int destY) {
        if (isWhitePiece(srcY, srcX) && isWhitePiece(destY, destX)) {
            return true;
        }
        if (isBlackPiece(srcY, srcX) && isBlackPiece(destY, destX)) {
            return true;
        }
        return false;
    }
    bool isKingInCheak(bool whiteKing){
    	int kingX,kingY;
    	Piece kingPiece = whiteKing ? KINGW : KINGB;
    	
    	for(int i=0; i<8; i++){
    		for(int j=0; j<8; j++){
    			if(board[i][j] == kingPiece){
    				kingX = j;
    				kingY = i;
    				break;
				}
			}
		}
		
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				if((whiteTurn && isBlackPiece(i,j)) || (!whiteTurn && isWhitePiece(i,j))){
					whiteTurn = !whiteTurn;
					if(isValidMove(j,i,kingX,kingY)){
						whiteTurn = !whiteTurn;
						return true;
					}
					whiteTurn = !whiteTurn;
				}
				
			}
		}
		return false;
	}
	bool isCheckmate(bool whiteKing){
		if(!isKingInCheak(whiteKing)){
			return false;
		}
		
		// Cheak if the player any valid move to get out of cheak
		for(int srcY=0; srcY<8; srcY++){
			for(int srcX=0; srcX<8; srcX++){
				if((whiteKing && isWhitePiece(srcY,srcX)) || (!whiteKing && isBlackPiece(srcY,srcX))){
					for(int destY=0; destY<8; destY++){
						for(int destX=0; destX<8; destX++){
							if(isValidMove(srcX,srcY,destX,destY)){
								// Simulate the move and check if the king is still in cheak
								Piece destPiece = board[destY][destX];
								board[destY][destX] = board[srcY][srcX];
								board[srcY][srcX] = EMPTY;
								bool stillInCheak = isKingInCheak(whiteKing);
								board[srcY][srcX] = board[destY][destX];
								board[destY][destX] = destPiece;
								
								if(!stillInCheak){
									// The player has a valid move to get out of cheak
									return false;
								}
							}
						}
					}
				}
			}
		}
		// The player is in checkmate
		return true;
	}
	bool isStalemate(bool whiteTurn){
		if(isKingInCheak(whiteTurn)){
			return false;
		}
		// Cheak if the player has any valid move to make
		for(int srcY=0; srcY<8; srcY++){
			for(int srcX=0; srcX<8; srcX++){
				if((whiteTurn && isWhitePiece(srcY,srcX)) || (!whiteTurn && isBlackPiece(srcY,srcX))){
					for(int destY=0; destY<8; destY++){
						for(int destX=0; destX<8; destX++){
							if(isValidMove(srcX,srcY,destX,destY)){
								// The player has a valid move to make
								return false;
							}
						}
					}
				}
			}
		}
		// The Player is in stalemate
		return true;
	}
	bool isInsufficientMaterial(){
		int pieceCount =0;
		for(int i=0;i<8;i++){
			for(int j=0; j<8;j++){
				Piece piece = board[i][j];
				if(piece != EMPTY && piece != KINGW && piece != KINGB){
					pieceCount++;
					if(pieceCount > 2){
						// There is more than just kings on the board
						return false;
					}
				}
			}
		}
		// There are only kings on the board
		return true;
	}
    bool isValidMove(int srcX, int srcY, int destX, int destY) {
        Piece piece = board[srcY][srcX];
        int forwardDirection = isWhitePiece(srcY, srcX) ? -1 : 1;

        // Check if the move is within the bounds of the board
        if (srcX < 0 || srcX >= 8 || srcY < 0 || srcY >= 8 ||
            destX < 0 || destX >= 8 || destY < 0 || destY >= 8) {
            return false;
        }

        // Check if the source and destination squares are different
        if (srcX == destX && srcY == destY) {
            return false;
        }
        // ----------------------------------------- New ---------------------------------------------------

        if (piece == PAWNW && whiteTurn) {
        	
            // Check if the pawn is moving one square forward
            if (destY == srcY - 1 && board[destY][destX] == EMPTY && isWhitePiece(srcY,srcX)) {
                return true;
            }

            // Check if the pawn is moving two squares forward from the initial position
            if (srcY == 6 && destY == srcY - 2 && board[destY][destX] == EMPTY &&
                board[destY+1][destX] == EMPTY) {
                return true;
            }

            // Check if the pawn is capturing diagonally
            if (abs(destX - srcX) == 1 && destY == srcY + forwardDirection &&
            isBlackPiece(destY, destX)) {
                return true;
            }

            return false;
        }
        else if (piece == PAWNB && !whiteTurn) {
            // Check if the pawn is moving one square forward
            if (destY == srcY + 1 && board[destY][destX] == EMPTY && isBlackPiece(srcY,srcX)) {
                return true;
            }

            // Check if the pawn is moving two squares forward from the initial position
            if (srcY == 1 && destY == srcY + 2 && board[destY][destX] == EMPTY &&
                board[destY-1][destX] == EMPTY) {
                return true;
            }

            // Check if the pawn is capturing diagonally
            if (abs(destX - srcX) == 1 && destY == srcY + forwardDirection &&
            isWhitePiece(destY, destX)){
                return true;
            }
            return false;
        }

            else if ((piece == ROOKW && whiteTurn) || (piece == ROOKB && !whiteTurn)){
                if (srcX != destX && srcY != destY) {
                    // Rook can move only horizontally or vertically
                    return false;
                }

                // Check if the rook is moving horizontally
                if (srcX == destX) {
                    // Check if there are pieces blocking the rook's path
                    int step = (destY > srcY) ? 1 : -1;
                    for (int i = srcY + step; i != destY; i += step) {
                        if (board[i][srcX] != EMPTY) {
								return false;
							}
                    }
                }
                // Check if the rook is moving vertically
                if (srcY == destY) {
                    int step = (destX > srcX) ? 1 : -1;
                    for (int i = srcX + step; i != destX; i += step) {
                        if (board[srcY][i] != EMPTY) {
                            // There is a piece blocking the path
                            return false;
                        }
                }
                }
                if (board[destY][destX] == EMPTY || (whiteTurn && isBlackPiece(destY, destX)) ||
                    (!whiteTurn && isWhitePiece(destY, destX))) {
                    // Valid rook move
                       return true;
                }
                return false;
            }
            else if ((piece == KNIGHTW && whiteTurn)|| (piece == KNIGHTB && !whiteTurn)) {
                int diffX = abs(srcX - destX);
                int diffY = abs(srcY - destY);
                if ((diffX == 2 && diffY == 1) || (diffX == 1 && diffY == 2)) {
                    // Valid knight move
                    if(board[destY][destX] == EMPTY || (whiteTurn && isBlackPiece(destY,destX)) ||
                    (!whiteTurn && isWhitePiece(destY,destX))){
                    	return true;
					}
                }
                return false;
            }
            else if (piece == BISHOPW || piece == BISHOPB) {
                int diffX = abs(srcX - destX);
                int diffY = abs(srcY - destY);

                // Check if the piece moves diagonally
                if (diffX == diffY) {
                    // Bishop can move
                    int rowStep = (destX > srcX) ? 1 : -1;
                    int colStep = (destY > srcY) ? 1 : -1;
                    int x = srcX + rowStep;
                    int y = srcY + colStep;

                    while (x != destX || y != destY) {
                        if (board[y][x] != EMPTY) {
                            return false;
                        }
                        x += rowStep;
                        y += colStep;
                    }

                    if (board[destY][destX] == EMPTY || (whiteTurn && isBlackPiece(destY,destX))||
					   (!whiteTurn && isWhitePiece(destY,destX))) {
                        return true;
                    }
                }
                return false;
            }
            else if (piece == QUEENB || piece == QUEENW) {
                int diffX = abs(srcX - destX);
                int diffY = abs(srcY - destY);               
                if(srcX == destX || srcY == destY || diffX == diffY){
                	if (srcX == destX || srcY == destY) {
                		if (srcX == destX) {
                    // Check if there are pieces blocking the rook's path
                    int step = (destY > srcY) ? 1 : -1;
                    for (int i = srcY + step; i != destY; i += step) {
                        if (board[i][srcX] != EMPTY) {
								return false;
							}
                    }
                }
                // Check if the rook is moving vertically
                if (srcY == destY) {
                    int step = (destX > srcX) ? 1 : -1;
                    for (int i = srcX + step; i != destX || i == destX; i += step) {
                        if (board[srcY][i] != EMPTY) {
                            // There is a piece blocking the path
                            return false;
                        }
                }
                }
                if(board[destY][destX] == EMPTY || (whiteTurn && isBlackPiece(destY,destX)) ||
				  (!whiteTurn && isWhitePiece(destY,destX))){
				  	return true;
				  }
                	
				}

                else if (diffX == diffY) {
                	int rowStep = (destX > srcX) ? 1 : -1;
                    int colStep = (destY > srcY) ? 1 : -1;
                    int x = srcX + rowStep;
                    int y = srcY + colStep;

                    while (x != destX || y != destY) {
                        if (board[y][x] != EMPTY) {
                            return false;
                        }
                        x += rowStep;
                        y += colStep;
                    }

                    if (board[destY][destX] == EMPTY || (whiteTurn && isBlackPiece(destY,destX))||
					   (!whiteTurn && isWhitePiece(destY,destX))) {
                        return true;
                    }
                	
            }
        }
        return false;
    }
            else if (piece == KINGB || piece == KINGW) {
                int diffX = abs(srcX - destX);
                int diffY = abs(srcY - destY);

                if (diffX <= 1 && diffY <= 1) {
                    if(board[destY][destX] == EMPTY || (whiteTurn && isBlackPiece(destY,destX)) ||
					  (!whiteTurn && isWhitePiece(destY,destX))){
					  	return true;
					  }
                }
                // Invalid king move
                return false;
            }
            else {
                return false;
            }
    }
        void makeMove(){
        	string srcPos,destPos;
        	int srcX,srcY,destX,destY;
            //char srcColumn, destColumn;

            cout << "Player " << (whiteTurn ? "White" : "Black") << ", make your move." << endl;
            cout << "Enter the source position (e.g., A2): ";
            cin>>srcPos;
            srcX = srcPos[0] - 'a';
            srcY = srcPos[1] - '1';
            
            cout << "Enter the destination position (e.g., A2): ";
            cin >> destPos;
            destX = destPos[0] - 'a';
            destY = destPos[1] - '1';
            
            if(whiteTurn && isWhitePiece(srcY,srcX)){
            if (isValidMove(srcX, srcY, destX, destY)) {
                // Perform the move
                Piece piece = board[srcY][srcX];
                board[destY][destX] = piece;
                board[srcY][srcX] = EMPTY;
//                whiteTurn = !whiteTurn;
                
                if(isKingInCheak(true)){
                	cout<<"Invalid Move! Your king is in check. Make a move to protect your king"<<endl;
                	// Revert the move
                	board[srcY][srcX] = piece;
                	board[destY][destX] = EMPTY;
				} else{
					whiteTurn = !whiteTurn;
				}
				
            } else {
            	cout<<"Invalid Move! Try Again."<<endl;
			}
        }if(!whiteTurn && isBlackPiece(srcY,srcX)){
        	    if (isValidMove(srcX, srcY, destX, destY)) {
                // Perform the move
                Piece piece = board[srcY][srcX];
                board[destY][destX] = piece;
                board[srcY][srcX] = EMPTY;
                
                if(isKingInCheak(false)){
                	cout<<"Invalid move! Your king is in Check. Make a move to protect your king"<<endl;
                	board[srcY][srcX] = piece;
                	board[destY][destX] = EMPTY;
				} else {
					whiteTurn = !whiteTurn;
				}
            } else {
                cout << "Invalid move! Try again." << endl;
            }
		}
		// Cheak for checkmate
		if(isCheckmate(false)){
			cout<<"Ceckmate! Player "<<(whiteTurn ? "Black" : "White")<<" Wins!"<<endl;
			return;
		}
		if(isStalemate(false)){
			cout<<"Stalemate! The game is Drawn."<<endl;
			return;
		}
		if(isInsufficientMaterial()){
			cout<<"Insufficient material! The game is drawn."<<endl;
			return;
		}
    }
};
int main(){
	ChessGame game;
	game.intro();
	while(true){
		system("cls");
		game.displayBoard();
		game.makeMove();
	}
	return 0;
}
