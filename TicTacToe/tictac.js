/* ==========================================================
   TIC TAC TOE — Version 1 (core game) + Version 2 (extras)
   Plain vanilla JS, no frameworks.
   ========================================================== */

/* ----------------------------
   Constants
   ---------------------------- */
const WINNING_COMBINATIONS = [
    [0, 1, 2], [3, 4, 5], [6, 7, 8], // rows
    [0, 3, 6], [1, 4, 7], [2, 5, 8], // columns
    [0, 4, 8], [2, 4, 6]             // diagonals
];

const STORAGE_KEY = "tttGameState";

/* ----------------------------
   Game state
   ---------------------------- */
const state = {
    board: Array(9).fill(""),
    currentPlayer: "X",
    gameActive: false,          // becomes true once the name modal is confirmed
    round: 1,
    scores: { X: 0, O: 0, draws: 0 },
    playerNames: { X: "Player X", O: "Player O" },
    theme: "light",
    soundMuted: false
};

/* ----------------------------
   DOM references
   ---------------------------- */
const boardEl = document.getElementById("board");
const cellEls = Array.from(document.querySelectorAll(".tic"));
const turnIndicatorEl = document.getElementById("turnIndicator");
const roundIndicatorEl = document.getElementById("roundIndicator");
const resultBannerEl = document.getElementById("resultBanner");

const scoreXValueEl = document.getElementById("scoreXValue");
const scoreOValueEl = document.getElementById("scoreOValue");
const scoreDrawValueEl = document.getElementById("scoreDrawValue");
const scoreXLabelEl = document.getElementById("scoreXLabel");
const scoreOLabelEl = document.getElementById("scoreOLabel");

const restartBtn = document.getElementById("restartBtn");
const newMatchBtn = document.getElementById("newMatchBtn");
const themeToggleBtn = document.getElementById("themeToggle");
const soundToggleBtn = document.getElementById("soundToggle");

const nameModalEl = document.getElementById("nameModal");
const playerXNameInput = document.getElementById("playerXName");
const playerONameInput = document.getElementById("playerOName");
const startGameBtn = document.getElementById("startGameBtn");

/* ==========================================================
   Storage helpers
   ========================================================== */
function saveToStorage() {
    const dataToSave = {
        scores: state.scores,
        round: state.round,
        playerNames: state.playerNames,
        theme: state.theme,
        soundMuted: state.soundMuted
    };
    localStorage.setItem(STORAGE_KEY, JSON.stringify(dataToSave));
}

function loadFromStorage() {
    const raw = localStorage.getItem(STORAGE_KEY);
    if (!raw) return;

    try {
        const saved = JSON.parse(raw);
        if (saved.scores) state.scores = saved.scores;
        if (saved.round) state.round = saved.round;
        if (saved.playerNames) state.playerNames = saved.playerNames;
        if (saved.theme) state.theme = saved.theme;
        if (typeof saved.soundMuted === "boolean") state.soundMuted = saved.soundMuted;
    } catch (err) {
        console.warn("Could not read saved tic tac toe data:", err);
    }
}

/* ==========================================================
   Sound effects (Web Audio API — no external files needed)
   ========================================================== */
let audioCtx = null;

function getAudioContext() {
    if (!audioCtx) {
        audioCtx = new (window.AudioContext || window.webkitAudioContext)();
    }
    return audioCtx;
}

function playTone(frequency, duration, delay = 0) {
    if (state.soundMuted) return;

    const ctx = getAudioContext();
    const oscillator = ctx.createOscillator();
    const gainNode = ctx.createGain();

    oscillator.type = "sine";
    oscillator.frequency.value = frequency;
    gainNode.gain.value = 0.08;

    oscillator.connect(gainNode);
    gainNode.connect(ctx.destination);

    const startTime = ctx.currentTime + delay;
    oscillator.start(startTime);
    gainNode.gain.exponentialRampToValueAtTime(0.001, startTime + duration);
    oscillator.stop(startTime + duration);
}

function playSound(type) {
    if (type === "move") {
        playTone(440, 0.08);
    } else if (type === "win") {
        playTone(523, 0.12);
        playTone(659, 0.12, 0.1);
        playTone(784, 0.18, 0.2);
    } else if (type === "draw") {
        playTone(300, 0.25);
    }
}

function toggleSound() {
    state.soundMuted = !state.soundMuted;
    soundToggleBtn.innerHTML = state.soundMuted ? "&#128263;" : "&#128266;";
    saveToStorage();
}

/* ==========================================================
   Theme (dark mode)
   ========================================================== */
function applyTheme(theme) {
    state.theme = theme;
    document.documentElement.setAttribute("data-theme", theme);
    themeToggleBtn.innerHTML = theme === "dark" ? "&#9728;" : "&#127769;";
}

function toggleTheme() {
    applyTheme(state.theme === "dark" ? "light" : "dark");
    saveToStorage();
}

/* ==========================================================
   Board rendering helpers
   ========================================================== */
function renderCell(index) {
    const cellEl = cellEls[index];
    const value = state.board[index];

    cellEl.textContent = value;
    cellEl.classList.remove("mark-x", "mark-o");
    if (value === "X") cellEl.classList.add("mark-x");
    if (value === "O") cellEl.classList.add("mark-o");
}

function renderBoard() {
    state.board.forEach((_, index) => renderCell(index));
}

function setCellsDisabled(disabled) {
    cellEls.forEach((cell) => { cell.disabled = disabled; });
}

function clearWinningHighlight() {
    cellEls.forEach((cell) => cell.classList.remove("winning-cell"));
}

function highlightWinningCells(combo) {
    combo.forEach((index) => cellEls[index].classList.add("winning-cell"));
}

/* ==========================================================
   UI text updates
   ========================================================== */
function updateTurnIndicator() {
    const name = state.playerNames[state.currentPlayer];
    turnIndicatorEl.textContent = `${name}'s turn (${state.currentPlayer})`;
}

function updateRoundIndicator() {
    roundIndicatorEl.textContent = `Round ${state.round}`;
}

function updateScoreboard() {
    scoreXValueEl.textContent = state.scores.X;
    scoreOValueEl.textContent = state.scores.O;
    scoreDrawValueEl.textContent = state.scores.draws;
    scoreXLabelEl.textContent = state.playerNames.X;
    scoreOLabelEl.textContent = state.playerNames.O;
}

function showResultBanner(message) {
    resultBannerEl.textContent = message;
}

function clearResultBanner() {
    resultBannerEl.textContent = "";
}

/* ==========================================================
   Core game logic
   ========================================================== */
function checkWinner() {
    for (const combo of WINNING_COMBINATIONS) {
        const [a, b, c] = combo;
        const valA = state.board[a];
        if (valA && valA === state.board[b] && valA === state.board[c]) {
            return { winner: valA, combo };
        }
    }
    return null;
}

function checkDraw() {
    return state.board.every((cell) => cell !== "");
}

function switchPlayer() {
    state.currentPlayer = state.currentPlayer === "X" ? "O" : "X";
}

function handleCellClick(event) {
    const cell = event.currentTarget;
    const index = cellEls.indexOf(cell);

    if (!state.gameActive || state.board[index] !== "") return;

    state.board[index] = state.currentPlayer;
    renderCell(index);
    playSound("move");

    const result = checkWinner();

    if (result) {
        endRound(result.winner, result.combo);
        return;
    }

    if (checkDraw()) {
        endRound(null, null);
        return;
    }

    switchPlayer();
    updateTurnIndicator();
}

function endRound(winner, combo) {
    state.gameActive = false;
    setCellsDisabled(true);

    if (winner) {
        state.scores[winner] += 1;
        highlightWinningCells(combo);
        playSound("win");
        showResultBanner(`${state.playerNames[winner]} wins this round!`);
    } else {
        state.scores.draws += 1;
        playSound("draw");
        showResultBanner("It's a draw!");
    }

    updateScoreboard();
    saveToStorage();

    // Automatically move to the next round after a short pause
    setTimeout(nextRound, 1400);
}

function resetBoard() {
    state.board = Array(9).fill("");
    state.currentPlayer = "X";
    state.gameActive = true;
    clearWinningHighlight();
    clearResultBanner();
    renderBoard();
    setCellsDisabled(false);
    updateTurnIndicator();
}

function nextRound() {
    state.round += 1;
    updateRoundIndicator();
    resetBoard();
    saveToStorage();
}

function restartRound() {
    // Redo the current round without changing scores or round number
    resetBoard();
}

function startNewMatch() {
    state.scores = { X: 0, O: 0, draws: 0 };
    state.round = 1;
    updateRoundIndicator();
    updateScoreboard();
    resetBoard();
    saveToStorage();
}

/* ==========================================================
   Name modal
   ========================================================== */
function openNameModal() {
    playerXNameInput.value = state.playerNames.X === "Player X" ? "" : state.playerNames.X;
    playerONameInput.value = state.playerNames.O === "Player O" ? "" : state.playerNames.O;
    nameModalEl.classList.remove("hidden");
    playerXNameInput.focus();
}

function closeNameModal() {
    nameModalEl.classList.add("hidden");
}

function handleStartGame() {
    const nameX = playerXNameInput.value.trim();
    const nameO = playerONameInput.value.trim();

    state.playerNames.X = nameX || "Player X";
    state.playerNames.O = nameO || "Player O";

    updateScoreboard();
    updateTurnIndicator();
    saveToStorage();
    closeNameModal();

    resetBoard();
}

/* ==========================================================
   Event listeners
   ========================================================== */
function attachEventListeners() {
    cellEls.forEach((cell) => cell.addEventListener("click", handleCellClick));

    restartBtn.addEventListener("click", restartRound);
    newMatchBtn.addEventListener("click", startNewMatch);

    themeToggleBtn.addEventListener("click", toggleTheme);
    soundToggleBtn.addEventListener("click", toggleSound);

    startGameBtn.addEventListener("click", handleStartGame);

    // Allow pressing Enter inside either name field to start the game
    [playerXNameInput, playerONameInput].forEach((input) => {
        input.addEventListener("keydown", (event) => {
            if (event.key === "Enter") handleStartGame();
        });
    });
}

/* ==========================================================
   Init
   ========================================================== */
function init() {
    loadFromStorage();
    applyTheme(state.theme);
    soundToggleBtn.innerHTML = state.soundMuted ? "&#128263;" : "&#128266;";

    updateRoundIndicator();
    updateScoreboard();
    setCellsDisabled(true); // locked until the name modal is confirmed

    attachEventListeners();
    openNameModal();
}

document.addEventListener("DOMContentLoaded", init);