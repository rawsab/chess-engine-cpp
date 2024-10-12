# ♟️ C++ Chess Engine
> **Collaborators**: Rawsab Said, Mihir Kachroo, Faseeh Irfan

A chess game built using object-oriented design principles, supporting both human and computer players. It follows standard chess rules, including en passant, castling, and pawn promotion. The game detects checks, checkmates, and stalemates and offers multiplayer functionality with turn-based gameplay. A **command-line interface (CLI)** and a **graphical display using X11** are available.

Computer players are implemented with four difficulty levels, using heuristic-based decision-making. These levels prioritize capturing pieces, avoiding capture, and other strategies, depending on the difficulty.

## Key Features
- Standard chess mechanics with special moves like castling, en passant, and pawn promotion.
- Support for both human and computer players (with four levels of difficulty).
- Undo feature: Unlimited undo moves are supported.
- Custom board setup mode, allowing players to customize the starting positions of pieces.

## Setup Instructions

**1. Clone the repository:**
```
git clone https://github.com/rawsab/chess-engine-cpp.git
cd chess-engine-cpp
```

**2. Build the program:**

Navigate to the `src` directory and run the Makefile:
```
cd src
make
```

**3. Run the program:**
```
./chess
```

## Commands

**1. Starting a game:**

Command: `game <player1> <player2>`

Examples:

```
game human human            # Human vs. Human game
game human computer1        # Human vs. Computer (Easy level)
game computer2 computer3    # Computer (Medium level) vs. Computer (Hard level)
```

**2. Making a move:**

Command: `move`

Example: Input start and destination move coordinates.
```
move e2 e4   # Move a piece from e2 to e4
```

**3. Undo a move:**
```
undo        # Undo the last move made
```

**4. Setting up the board:** 

Command: `setup`

Example setup commands:
```
+ R a1       # Add a white Rook at position a1
+ p d7       # Add a black Pawn at position d7
- d7         # Remove the piece at position d7
= white      # Set the next turn to be White's move
done         # Exit setup mode once the board setup is complete
```
**5. Resign:** Command:
```
resign      # The current player resigns and the opponent wins
```

## Computer Difficulty Levels
- **Level 1** (`computer1`): Random valid moves from random pieces.
- **Level 2** (`computer2`): Prioritizes capturing opponent pieces and placing the opponent’s king in check.
- **Level 3** (`computer3`): Avoids capture and uses more sophisticated strategies for piece positioning.
- **Level 4** (`computer4`): Prioritizes capturing high-value pieces, avoiding capture, and maximizing board control.

