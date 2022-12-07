
#include"ChessBoard.h"

#include<iostream>

using std::cout;

int main() {
  
  
	cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";

	ChessBoard cb;
	cout << '\n';
	
	cb.submitMove("G1", "F3");
	cout << '\n';

	cb.submitMove("H7", "H6");
	cout << '\n';

	cb.submitMove("F3", "D4");
	cout << '\n';

	cb.submitMove("F8", "B4");
	cout << '\n';	
	
	
        
	cout << "=========================\n";
	cout << "Alekhine vs. Vasic (1931)\n";
	cout << "=========================\n\n";
               
	cb.resetBoard();
	cout << '\n';
	
	
	cb.submitMove("E2", "E4");
	cb.submitMove("E7", "E6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cb.submitMove("D7", "D5");
	cout << '\n';

	cb.submitMove("B1", "C3");
	cb.submitMove("F8", "B4");
	cout << '\n';

	cb.submitMove("F1", "D3");
	cb.submitMove("B4", "C3");
	cout << '\n';

	cb.submitMove("B2", "C3");
	cb.submitMove("H7", "H6");
	cout << '\n';

	cb.submitMove("C1", "A3");
	cb.submitMove("B8", "D7");
	cout << '\n';

	cb.submitMove("D1", "E2");
	cb.submitMove("D5", "E4");
	cout << '\n';

	cb.submitMove("D3", "E4");
	cb.submitMove("G8", "F6");
	cout << '\n';

	cb.submitMove("E4", "D3");
	cb.submitMove("B7", "B6");
	cout << '\n';

	cb.submitMove("E2", "E6");
	cb.submitMove("F7", "E6");
	cout << '\n';
        
	cb.submitMove("D3", "G6");
	cout << '\n';

	

  
    // Test for game ending in stalemate
    
    cout << "==========================\n";
    cout << "Hohmeister vs Frank (1993)\n";
    cout << "==========================\n\n";

    cb.resetBoard();

    // ChessBoard cb;
    cout << '\n';
    cb.submitMove("D2", "D4");
    cb.submitMove("E7", "E5");
    cb.submitMove("D1", "D2");
    cb.submitMove("E5", "E4");
    cb.submitMove("D2", "F4");
    cb.submitMove("F7", "F5");
    cb.submitMove("H2", "H3");
    cb.submitMove("F8", "B4");
    cb.submitMove("B1", "D2");
    cb.submitMove("D7", "D6");
    cb.submitMove("F4", "H2");
    cb.submitMove("C8", "E6");
    cb.submitMove("A2", "A4");
    cb.submitMove("D8", "H4");
    cb.submitMove("A1", "A3");
    cb.submitMove("C7", "C5");
    cb.submitMove("A3", "G3");
    cb.submitMove("F5", "F4");
    cb.submitMove("F2", "F3");
    cb.submitMove("E6", "B3");
    cb.submitMove("D4", "D5");
    cb.submitMove("B4", "A5");
    cb.submitMove("C2", "C4");
    cb.submitMove("E4", "E3");
    cout << "\n\n";



    return 0;
}
