// Author: Justin Im
/* This serves as the infinite loop that the chess game will
function on. The entire game operates in the command line.
This main function assumes the completion of the
following classes:
* Piece
* Board
* UI (which interacts with Board)
*/

// Necessary includes.
#include "include/ui.h"
#include "include/Board.h"
#include "include/Display.h"
#include "include/piece.h"
#include "include/pawn.h"
#include "include/knight.h"
#include "include/rook.h"
#include "include/bishop.h"
#include "include/queen.h"
#include "include/king.h"

// #include <stdio.h>
// #include <windows.h>

using namespace std;

int main() {
  // system("chcp 65001  > nul");
  // Generates a new ui for the game instance.
  ui *UserInterface = new ui();
  // Output Start Menu.
  /* This function reads input from the terminal and decides:
  *1: Start the game. First player is white and second player is black by default. Enters the infinite game cycle while loop.
  *2: Quit the game. IDoes not enter the game cycle loop and returns 0.  */
  bool runGame = UserInterface->outputStartMenu(std::cin);
  if (!runGame) {
      return 0;
  }
  while(UserInterface->outputTurnMenu(std::cin)) {}

  delete UserInterface;
  return 0;
}