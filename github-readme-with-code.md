# Recursive Problem Solutions in C++

This repository contains solutions to 10 challenging recursive problems implemented in C++. Each solution focuses on using pure recursion with minimal data structures.

## 1. Expression Evaluation with Parentheses
Evaluates mathematical expressions with nested parentheses.

```cpp
#include <iostream>
using namespace std;

int eval(char curr, char next, int acc) {
    // Base case
    if (curr == '\0') return acc;
    
    // Process digit
    if (curr >= '0' && curr <= '9') {
        return eval(next, getNext(), curr - '0');
    }
    
    // Process operators
    if (curr == '+') {
        return eval(next, getNext(), acc + eval(next, getNext(), 0));
    }
    if (curr == '-') {
        return eval(next, getNext(), acc - eval(next, getNext(), 0));
    }
    if (curr == '*') {
        return eval(next, getNext(), acc * eval(next, getNext(), 0));
    }
    if (curr == '/') {
        int divisor = eval(next, getNext(), 0);
        if (divisor != 0) {
            return eval(next, getNext(), acc / divisor);
        }
        return 0;
    }
    
    // Process parentheses
    if (curr == '(') {
        return eval(next, getNext(), eval(next, getNext(), 0));
    }
    if (curr == ')') {
        return acc;
    }
    
    return eval(next, getNext(), acc);
}

// Example usage: "3+(6*2)-(5/(2+3))"
```

## 2. Generate All Valid Braces Combinations
Generates valid combinations of N pairs of braces.

```cpp
#include <iostream>
using namespace std;

void generateBraces(int n, int open, int close) {
    // Base case: used all braces
    if (open == n && close == n) {
        printCurrentBraces();
        return;
    }
    
    // Add opening brace if we have not used all
    if (open < n) {
        addBrace('{');
        generateBraces(n, open + 1, close);
        removeBrace();
    }
    
    // Add closing brace if valid
    if (close < open) {
        addBrace('}');
        generateBraces(n, open, close + 1);
        removeBrace();
    }
}

// Example usage: generateBraces(2, 0, 0) generates {{}} and {}
```

## 3. Optimal Move in a Game Board
Finds optimal path in a grid with scores.

```cpp
#include <iostream>
using namespace std;

int findOptimalPath(int row, int col, int backtrack) {
    // Base cases
    if (row < 0 || col < 0) return 0;
    if (row == 0 && col == 0) return getCellScore(0, 0);
    
    // Try all possible moves including backtracking
    int score = 0;
    
    // Move right
    if (col > 0) {
        score = max(score, getCellScore(row, col) + 
                   findOptimalPath(row, col-1, backtrack));
    }
    
    // Move down
    if (row > 0) {
        score = max(score, getCellScore(row, col) + 
                   findOptimalPath(row-1, col, backtrack));
    }
    
    // Backtrack if steps available
    if (backtrack > 0) {
        // Try backtracking up
        score = max(score, getCellScore(row, col) + 
                   findOptimalPath(row+1, col, backtrack-1));
        
        // Try backtracking left
        score = max(score, getCellScore(row, col) + 
                   findOptimalPath(row, col+1, backtrack-1));
    }
    
    return score;
}
```

## 4. Sudoku Solver
Solves 9x9 Sudoku using backtracking.

```cpp
#include <iostream>
using namespace std;

bool solveSudoku(int row, int col) {
    // Base case: reached end
    if (row == 9) return true;
    
    // Move to next cell
    int nextRow = (col == 8) ? row + 1 : row;
    int nextCol = (col == 8) ? 0 : col + 1;
    
    // If cell is filled, move to next cell
    if (getCell(row, col) != 0) {
        return solveSudoku(nextRow, nextCol);
    }
    
    // Try digits 1-9
    for (int num = 1; num <= 9; num++) {
        if (isValid(row, col, num)) {
            setCell(row, col, num);
            if (solveSudoku(nextRow, nextCol)) {
                return true;
            }
            setCell(row, col, 0);  // backtrack
        }
    }
    
    return false;
}
```

## 5. N-Queens Problem
Counts all valid N-Queens arrangements.

```cpp
#include <iostream>
using namespace std;

int countNQueens(int row, int n) {
    // Base case: placed all queens
    if (row == n) return 1;
    
    int total = 0;
    
    // Try placing queen in each column
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            placeQueen(row, col);
            total += countNQueens(row + 1, n);
            removeQueen(row, col);
        }
    }
    
    return total;
}
```

## 6. Word Break Problem
Segments string into dictionary words.

```cpp
#include <iostream>
using namespace std;

void wordBreak(int start, int len) {
    // Base case: processed whole string
    if (start == len) {
        printCurrentSegmentation();
        return;
    }
    
    // Try all possible words from current position
    for (int end = start + 1; end <= len; end++) {
        if (isValidWord(start, end)) {
            addToSegmentation(start, end);
            wordBreak(end, len);
            removeFromSegmentation();
        }
    }
}
```

## 7. Tiling Problem
Counts ways to tile 2xN board.

```cpp
#include <iostream>
using namespace std;

int countTilings(int width) {
    // Base cases
    if (width == 0) return 1;
    if (width < 0) return 0;
    
    // Try placing 2x1 tile
    int ways = countTilings(width - 1);
    
    // Try placing 2x2 tile
    ways += countTilings(width - 2);
    
    return ways;
}
```

## 8. Sum of All Root-to-Leaf Paths
Sums numbers formed by root-to-leaf paths.

```cpp
#include <iostream>
using namespace std;

int sumPaths(int currentSum, int value) {
    // Base case: leaf node
    if (isLeaf()) {
        return currentSum * 10 + value;
    }
    
    int total = 0;
    
    // Recurse on left child if exists
    if (hasLeft()) {
        total += sumPaths(currentSum * 10 + value, getLeftValue());
    }
    
    // Recurse on right child if exists
    if (hasRight()) {
        total += sumPaths(currentSum * 10 + value, getRightValue());
    }
    
    return total;
}
```

## 9. Permutation of Subsets with Conditions
Generates permutations with sum greater than k.

```cpp
#include <iostream>
using namespace std;

void generateSubsets(int pos, int r, int sum, int k) {
    // Base case: found subset of size r
    if (r == 0) {
        if (sum > k) {
            printCurrentSubset();
        }
        return;
    }
    
    // Base case: reached end or not enough elements left
    if (pos == 0) return;
    
    int currentVal = getValue(pos);
    
    // Include current element
    addToSubset(currentVal);
    generateSubsets(pos - 1, r - 1, sum + currentVal, k);
    removeFromSubset();
    
    // Exclude current element
    generateSubsets(pos - 1, r, sum, k);
}
```

## 10. Crossword Puzzle Solver
Fills crossword grid with given words.

```cpp
#include <iostream>
using namespace std;

bool solveCrossword(int wordIndex) {
    // Base case: placed all words
    if (wordIndex == 0) {
        printSolution();
        return true;
    }
    
    // Try each empty cell as starting point
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (isEmpty(row, col)) {
                // Try horizontally
                if (canPlaceHorizontal(row, col, wordIndex)) {
                    placeWordHorizontal(row, col, wordIndex);
                    if (solveCrossword(wordIndex - 1)) {
                        return true;
                    }
                    removeWordHorizontal(row, col, wordIndex);
                }
                
                // Try vertically
                if (canPlaceVertical(row, col, wordIndex)) {
                    placeWordVertical(row, col, wordIndex);
                    if (solveCrossword(wordIndex - 1)) {
                        return true;
                    }
                    removeWordVertical(row, col, wordIndex);
                }
            }
        }
    }
    
    return false;
}
```

## Helper Functions
These functions need to be implemented based on your specific needs:

```cpp
// Common helper functions needed across solutions
char getNext();
bool isValid(int row, int col, int num);
int getCellScore(int row, int col);
void placeQueen(int row, int col);
void removeQueen(int row, int col);
bool isSafe(int row, int col);
bool isValidWord(int start, int end);
void printCurrentSegmentation();
void addToSegmentation(int start, int end);
void removeFromSegmentation();
bool isLeaf();
bool hasLeft();
bool hasRight();
int getLeftValue();
int getRightValue();
int getValue(int pos);
void addToSubset(int val);
void removeFromSubset();
void printCurrentSubset();
void printSolution();
bool isEmpty(int row, int col);
bool canPlaceHorizontal(int row, int col, int wordIndex);
bool canPlaceVertical(int row, int col, int wordIndex);
void placeWordHorizontal(int row, int col, int wordIndex);
void placeWordVertical(int row, int col, int wordIndex);
void removeWordHorizontal(int row, int col, int wordIndex);
void removeWordVertical(int row, int col, int wordIndex);
void addBrace(char brace);
void removeBrace();
void printCurrentBraces();
```

## Building and Running

To compile any solution:
```bash
g++ <problem_name>.cpp -o solution
./solution
```

### Example Compilation
```bash
g++ expression_eval.cpp -o expr
./expr
```

## Contributing
Feel free to contribute by:
1. Implementing helper functions
2. Adding test cases
3. Improving documentation
4. Optimizing solutions

## License
This project is licensed under the MIT License.
