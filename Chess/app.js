
const gameBoard = document.querySelector("#gameboard");
const playerDetails = document.querySelector("#player");
const infoDisplay = document.querySelector("#info-display");
const err = document.querySelector("#err");
const width = 8

let playerTurn = 'white';
playerDetails.textContent = 'white'

const startPieces = [
    rook1, knight1, bishop1, queen1, king1, bishop1, knight1, rook1,
    pawn1, pawn1, pawn1, pawn1, pawn1, pawn1, pawn1, pawn1,
    '', '', '', '', '', '', '', '',
    '', '', '', '', '', '', '', '',
    '', '', '', '', '', '', '', '',
    '', '', '', '', '', '', '', '',
    pawn2, pawn2, pawn2, pawn2, pawn2, pawn2, pawn2, pawn2,
    rook2, knight2, bishop2, king2, queen2, bishop2, knight2, rook2,
    
]

function createBoard() {
    startPieces.forEach((startPiece, i) => {
        const square = document.createElement("div");
        square.classList.add("square");
        square.innerHTML = startPiece

        square.setAttribute("square-id", i);
        square.firstChild?.setAttribute('draggable', true)

        const row = Math.floor((63 - i) / 8) + 1;

        if (row % 2 === 0) {
            square.classList.add(i % 2 == 0 ? "beige" : "brown");
        } else {
            square.classList.add(i % 2 == 0 ? "brown" : "beige");
        }

        if (i <= 15) {
            square.firstChild.firstChild.classList.add("black");
        }
        if (i >= 48) {
            square.firstChild.firstChild.classList.add("white");
        }


        gameBoard.append(square);
    });
};

createBoard();


const allSquares = document.querySelectorAll("#gameboard .square");
// console.log(allSquares)

allSquares.forEach(square => {
    square.addEventListener('dragstart', dragstart);
    square.addEventListener('dragover', dragover);
    square.addEventListener('drop', dragdrop);
})

let startPositionId
let draggedElement


function dragstart(e) {
    console.log(e.target)
    startPositionId = e.target.parentNode.parentNode.getAttribute("square-id")
    draggedElement = e.target
}

function dragover(e) {
    e.preventDefault();
}

function dragdrop(e) {
    e.stopPropagation();

    console.log('player go', playerTurn)
    console.log('target', e.target)
    console.log(draggedElement)

    const correctTurn = draggedElement.classList.contains(playerTurn);
    const taken = e.target.classList.contains('piece');
    
    const opponentTurn = playerTurn === 'black' ? 'white' : 'black';
    const takenByOpponent = e.target?.classList.contains(opponentTurn);
    const valid = checkIfValid(e.target,takenByOpponent);
    console.log(opponentTurn)
    console.log(takenByOpponent)
    console.log(valid)
    console.log('opp go', opponentTurn)
    stopTimer();
    if (correctTurn) {
        // must check this condition
        if (takenByOpponent && valid) {
            e.target.parentNode.append(draggedElement);
            e.target.remove();
            addPointsToPlayer(playerTurn,1);
            checkForWin();
            changePlayer();
            return
        }
        if (taken && !takenByOpponent) {
            err.textContent = 'Can not go there'
            setTimeout(() => {
                err.textContent = ''
            }, 2000);
            return
        }
        if (valid) {
            e.target.append(draggedElement);
            checkForWin();
            changePlayer();
            return
        }
    }
}



function checkIfValid(target,takenByOpponent) {
    const targetId = Number(target.getAttribute('square-id')) || Number(target.parentNode.parentNode.getAttribute('square-id'))||Number(target.parentNode.getAttribute('square-id'));
    const startId = Number(startPositionId) || Number(draggedElement.parentNode.getAttribute('square-id'));
    const piece = draggedElement.id;
    const diff = Math.abs(targetId - startId);
    const startRow = Math.floor(startId / width);
    const startCol = startId % width;
    const targetRow = Math.floor(targetId / width);
    const targetCol = targetId % width;
    const rowDiff = Math.abs(targetRow - startRow);
    const colDiff = Math.abs(targetCol - startCol);
    console.log("startId",startId);
    console.log("targetId",targetId);
    switch (piece) {
        case 'rook':
            if (targetId % width === startId % width || Math.floor(targetId / width) === Math.floor(startId / width)) {
                return true;
            }
            break;
    
        case 'knight':
            if ((diff === 15 || diff === 17 || diff === 10 || diff === 6) && (targetId % width !== startId % width)) {
                return true;
            }
            break;
    
        case 'bishop':
            if (rowDiff === colDiff) {
                // Check if the diagonal path is continuous or wraps around the board's edges
                let currentRow = startRow;
                let currentCol = startCol;
                while (currentRow !== targetRow && currentCol !== targetCol) {
                    currentRow += (targetRow > startRow) ? 1 : -1;
                    currentCol += (targetCol > startCol) ? 1 : -1;
                    const currentId = currentRow * width + currentCol;
                    if (currentId === targetId) {
                        return true;
                    }
                }
            }
            break;
    
        case 'queen':
            if ((targetId % width === startId % width || Math.floor(targetId / width) === Math.floor(startId / width)) || (rowDiff === colDiff)) {
                return true;
            }
            break;
    
        case 'king':
            if (diff === 1 || diff === width || diff === width + 1 || diff === width - 1) {
                return true;
            }
            break;
            
            case 'pawn':
        const starterRow = [48, 49, 50, 51, 52, 53, 54, 55];
        if ((starterRow.includes(startId) && startId + width * 2 === targetId && !document.querySelector(`[square-id="${startId + width}"]`).firstChild) || // Two-square initial move
            (startId - width === targetId)|| // Move one square forward
            (startId - width + 1 === targetId && takenByOpponent && targetId % 8 !== 0) || // Diagonal capture to the right
            (startId - width - 1 === targetId && takenByOpponent && targetId % 8 !== 7) || // Diagonal capture to the left
            (startId + width * 2 === targetId && startId >= 8 && startId < 16 && !document.querySelector(`[square-id="${startId + width}"]`).firstChild) || // Two-square initial move for white pawn
            (startId - width * 2 === targetId && startId >= 48 && startId < 56 && !document.querySelector(`[square-id="${startId - width}"]`).firstChild)) { // Two-square initial move for black pawn
            return true;
        }
            break;
    
        default:
            return false;
    }
    
}



function changePlayer() {
    if (playerTurn === 'white') {
        startTimer2();
        reverseIds()
        playerTurn = 'black';
        playerDetails.textContent = 'black'
    } else {
        startTimer1();
        revertIds();
        playerTurn = 'white'
        playerDetails.textContent = 'white'
    }
}

function reverseIds() {
    const allSquares = document.querySelectorAll('#gameboard .square');
    allSquares.forEach((square, i) => {
        square.setAttribute('square-id', (width * width - 1) - i)
    })
}

function revertIds() {
    const allSquares = document.querySelectorAll('#gameboard .square');
    allSquares.forEach((square, i) => {
        square.setAttribute('square-id', i)
    })
}

function checkForWin() {
    const kings = Array.from(document.querySelectorAll('#king'));

    if (!kings.some(king => king.classList.contains('white'))) {
        infoDisplay.innerHTML = "Black Player Wins!";
        const allSquares = document.querySelectorAll('.square');
        allSquares.forEach(square => square.firstChild?.setAttribute('draggable', false));
    }
    if (!kings.some(king => king.classList.contains('black'))) {
        infoDisplay.innerHTML = "White Player Wins!";
        const allSquares = document.querySelectorAll('.square');
        allSquares.forEach(square => square.firstChild?.setAttribute('draggable', false));
    }
    stopTimer();
}


// Define initial points for each player
let player1Points = 0;
let player2Points = 0;

// Update player points on the UI
function updatePlayerPoints() {
    document.querySelector('.player1 span').textContent = player1Points;
    document.querySelector('.player2 span').textContent = player2Points;
}

// Add points to a player
function addPointsToPlayer(player, points) {
    if (player === 'black') {
        player1Points += points;
    } else {
        player2Points += points;
    }
    updatePlayerPoints();
}




const timerDisplay1 = document.querySelector("#time-left1");
const timerDisplay2=document.querySelector("#time-left2");
let timerInterval;
let timerSeconds = 600; // 10 minutes in seconds

function startTimer1() {
    timerInterval = setInterval(updateTimer1, 1000);
}

function updateTimer1() {
    timerSeconds--;
    const minutes = Math.floor(timerSeconds / 60);
    const seconds = timerSeconds % 60;
    timerDisplay1.textContent = `${minutes.toString().padStart(2, '0')}:${seconds.toString().padStart(2, '0')}`;
    if (timerSeconds === 0) {
        clearInterval(timerInterval);
    }
}


function startTimer2() {
    timerInterval = setInterval(updateTimer2, 1000);
}

function updateTimer2() {
    timerSeconds--;
    const minutes = Math.floor(timerSeconds / 60);
    const seconds = timerSeconds % 60;
    timerDisplay2.textContent = `${minutes.toString().padStart(2, '0')}:${seconds.toString().padStart(2, '0')}`;
    if (timerSeconds === 0) {
        clearInterval(timerInterval);
        startTimer1();
    }
}


function stopTimer() {
    clearInterval(timerInterval);
}



startTimer1();