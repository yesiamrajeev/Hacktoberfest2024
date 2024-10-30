# Chess Game

## Description
This is a simple web-based chess game. The game board is created using HTML, styled with CSS, and the game logic is implemented in JavaScript. Players can drag and drop chess pieces to move them on the board. The game includes timers for each player and keeps track of the players' points.


# Files
- index.html: The main HTML file containing the structure of the webpage.
- style.css: The CSS file for styling the webpage.
- app.js: The JavaScript file containing the game logic and interactivity.

# Features
- Interactive game board allowing drag-and-drop functionality for moving chess pieces.
- Timers for both players to keep track of the game time.
- Scoreboard displaying the points for each player.
- Turn-based gameplay with alternating turns for white and black players.
- Validity checks for each move to ensure the rules of chess are followed.
- Endgame detection to announce the winner.

# Usage
- Open index.html in a web browser or you may also use my deployed link to directly play the game.
- The game board will be displayed, and players can start playing by dragging and dropping pieces.
- The current player's turn is displayed, and the timer counts down from 10 minutes for each player.
- Points are awarded for capturing opponent's pieces.
- The game ends when one of the kings is captured, and the winner is announced.

# JavaScript Code Explanation

## Initialization:

The game board and player details are initialized.
An array startPieces defines the initial positions of the pieces.
createBoard function sets up the game board with pieces.

## Drag and Drop:

Event listeners for dragstart, dragover, and drop are added to handle piece movement.
dragstart stores the initial position and the dragged element.
dragover prevents the default behavior to allow dropping.
dragdrop handles the logic for moving pieces, checking if the move is valid, and changing turns.

## Move Validation:

checkIfValid checks if a move is valid based on the type of piece and the board state.

## Turn Management:

changePlayer alternates turns between white and black players.
reverseIds and revertIds adjust the square IDs based on the current player.

## Winning Condition:

checkForWin checks if one of the kings is captured and declares the winner.
Scoring:

Points are added to the player's score when an opponent's piece is captured.
updatePlayerPoints updates the displayed points for each player.

## Timers:

startTimer1 and startTimer2 start the timers for each player.
updateTimer1 and updateTimer2 update the timer display every second.
stopTimer stops the current timer.

# Installation
Clone or download the repository.
Ensure all files (index.html, style.css, app.js) are in the same directory.
Open index.html in a web browser to start the game.

## Deployed Link 
Deployed link for the game: https://chess-game-coral.vercel.app/

# Enjoy the Game!!!