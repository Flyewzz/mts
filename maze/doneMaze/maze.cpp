//
//  maze.cpp
//  maze
//
//  Created by Alpha on 03/06/2019.
//  Copyright © 2019 Alpha. All rights reserved.
//

#include <stdio.h>
#include "maze.h"

#include <iostream>

Maze::Maze(vector<string> maze) {
    // Maze is an input data
    rowCount = maze.size();
    columnCount = maze[0].length();
    // Field is a maze of logical cells (contain speed, status etc.)
    field.resize(rowCount);
    for (int i = 0; i < rowCount; ++i) {
        field[i].resize(columnCount);
    }
    for (size_t i = 0; i < rowCount; ++i) {
        for (size_t j = 0; j < columnCount; ++j) {
            Cell *cell = Cell::newCell(&field[i][j], i, j);
            switch (maze[i][j]) {
                case '#':
                    cell->setStatus(Status::BORDER);
                    break;
                case ' ':
                    cell->setStatus(Status::EMPTY);
                    cell->setSpeed(1);
                    break;
                case '.':
                    cell->setStatus(Status::SAND);
                    cell->setSpeed(2);
                    break;
                case 's':
                    cell->setStatus(Status::START);
                    setStartPosition(i, j); // Set start position for solving
                    break;
                default:
                    throw string("Undefined symbol");
                    break;
            }
        }
    }
    if (!solvability()) {
        throw string("This maze is impassable");
    }
//    result = propagation(rowStart, columnStart, field, vector<Cell>());
}

bool Maze::solvability() const {
    for (int j = 0; j < columnCount; ++j) {
        if (field[0][j].getStatus() != Status::BORDER ||
            field[rowCount - 1][j].getStatus() != Status::BORDER) {
            return true;
        }
    }
    for (int i = 0; i < rowCount; ++i) {
        if (field[i][0].getStatus() != Status::BORDER ||
            field[i][columnCount - 1].getStatus() != Status::BORDER) {
            return true;
        }
    }
    return false; // This maze is impassable :(
}

void Maze::setStartPosition(const short &row, const short &column) {
    rowStart = row;
    columnStart = column;
}

bool Maze::isExit(const short &row, const short &col) const {
    // The position is an exit, if it is in the border
    if (row == 0 || row == rowCount - 1
        || col == 0 || col == columnCount - 1) {
        return true;
    }
    return false;
}

Result Maze::solve() {
    return propagation(rowStart, columnStart, field, vector<Cell>());
}

Result Maze::propagation(short rowBegin, short columnBegin, vector< vector<Cell> > maze, vector<Cell> route) {
    Cell *startCell = &maze[rowBegin][columnBegin];
    startCell->setVisited(true);
    if (startCell->getStatus() != Status::START) {
        route.push_back(*startCell); // We shouldn't select the start position '*'
    }
    vector<Result> results;
    bool impasse = true; // If all the cells around are visited or border, we consider that this cell is impasse
    if ((rowBegin + 1) <= rowCount - 1) { // Down cell
        Cell *cell = &maze[rowBegin + 1][columnBegin];
        if (cell->getStatus() != Status::BORDER && !cell->getVisited()) { // We shouldn't look at the border or visited cells
            cell->setValue(startCell->getValue() + cell->getSpeed());
            impasse = false;
            if (isExit(cell->getRow(), cell->getColumn())) {
                Result result; // The cell is an exit
                route.push_back(*cell);
                result.route = route;
                result.distance = cell->getValue();
                results.push_back(result);
                goto end; // Summing up...
            }
            Result result = propagation(cell->getRow(), cell->getColumn(), maze, route);
            results.push_back(result);
        }
    }
    if ((columnBegin + 1) <= columnCount - 1) { // Right cell
        Cell *cell = &maze[rowBegin][columnBegin + 1];
        if (cell->getStatus() != Status::BORDER && !cell->getVisited()) {
            cell->setValue(startCell->getValue() + cell->getSpeed());
            impasse = false;
            if (isExit(cell->getRow(), cell->getColumn())) {
                Result result;
                route.push_back(*cell);
                result.route = route;
                result.distance = cell->getValue();
                results.push_back(result);
                goto end;
            }
            Result result = propagation(cell->getRow(), cell->getColumn(), maze, route);
            results.push_back(result);
        }
    }
    if ((rowBegin - 1) >= 0) { // Up cell
        Cell *cell = &maze[rowBegin - 1][columnBegin];
        if (cell->getStatus() != Status::BORDER && !cell->getVisited()) {
            cell->setValue(startCell->getValue() + cell->getSpeed());
            impasse = false;
            if (isExit(cell->getRow(), cell->getColumn())) {
                Result result;
                route.push_back(*cell);
                result.route = route;
                result.distance = cell->getValue();
                results.push_back(result);
                goto end;
            }
            Result result = propagation(cell->getRow(), cell->getColumn(), maze, route);
            results.push_back(result);
        }
    }
    if ((columnBegin - 1) >= 0) { // Left cell
        Cell *cell = &maze[rowBegin][columnBegin - 1];
        if (cell->getStatus() != Status::BORDER && !cell->getVisited()) {
            cell->setValue(startCell->getValue() + cell->getSpeed());
            impasse = false;
            if (isExit(cell->getRow(), cell->getColumn())) {
                Result result;
                route.push_back(*cell);
                result.route = route;
                result.distance = cell->getValue();
                results.push_back(result);
                goto end;
            }
            Result result = propagation(cell->getRow(), cell->getColumn(), maze, route);
            results.push_back(result);
        }
    }
    if (impasse) {
        Result result;
        // We can't achive the exit position from this cell (distance is machine infinity)
        result.distance = std::numeric_limits<float>::max(); // Impassive situation... :(
        return result;
    }
end:
    // We need to find shortest distance to the exit position
    auto result = *std::min_element(results.begin(), results.end(), [](const Result &res1, const Result &res2) {
        return res1.distance < res2.distance;
    });
    return result;
}

Maze::~Maze() { /* Just destructor :) */ }
