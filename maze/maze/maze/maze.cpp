//
//  maze.cpp
//  maze
//
//  Created by Alpha on 03/06/2019.
//  Copyright © 2019 Alpha. All rights reserved.
//

#include <stdio.h>
#include "maze.h"

Maze::Cell* Maze::newCell(Maze::Cell *cell, const size_t &row, const size_t &column) {
    cell->row = row;
    cell->column = column;
    cell->marked = false;
    cell->value = 0;
    cell->speed = 0;
    return cell;
}

Maze::Maze(vector<string> maze) {
    rowCount = maze.size();
    columnCount = maze[0].length();
    field.resize(rowCount);
    for (int i = 0; i < rowCount; ++i) {
        field[i].resize(columnCount);
    }
    
    for (size_t i = 0; i < rowCount; ++i) {
        for (size_t j = 0; j < columnCount; ++j) {
            Cell *cell = Maze::newCell(&field[i][j], i, j);
            switch (maze[i][j]) {
                case '#':
                    cell->status = Maze::Status::BORDER;
                    break;
                case ' ':
                    cell->status = Maze::Status::EMPTY;
                    cell->speed = 1;
                    break;
                case '.':
                    cell->status = Maze::Status::SAND;
                    cell->speed = 1.5;
                    break;
                case 's':
                    cell->status = Maze::Status::FINISH;
                    break;
                default:
                    throw "Undefined symbol";
                    break;
            }
        }
    }
}



void Maze::setStartPoint(const size_t &row, const size_t &column) {
    rowStartPoint = row;
    columnStartPoint = column;
}

void Maze::propagation() {
//    ЦИКЛ
//    ДЛЯ каждой ячейки loc, помеченной числом d
//    пометить все соседние свободные не помеченные ячейки числом d + 1
//    КЦ
//    d := d + 1
//    ПОКА (финишная ячейка не помечена) И (есть возможность распространения волны, шаг < количества ячеек)
    
}

Maze::Result Maze::solve(size_t rowStart, size_t columnStart, vector<vector<Maze::Cell>> maze, vector<Cell> route) {
    Cell *startCell = &field[rowStart][columnStart];
    if (startCell->status == Status::FINISH) {
        Result result;
        result.route = route;
        result.distance = startCell->value;
        return result;
    }
    vector<Result> results;
    results.resize(4);
    if ((rowStart + 1) != rowCount - 1) {
        Cell *cell = &maze[rowStart + 1][columnStart];
        if (cell->status != Status::BORDER) {
            cell->value = startCell->value + cell->speed;
            Result result = solve(rowStart + 1, columnStart, maze, route);
            results.push_back(result);
        }
    }
    if ((columnStart + 1) != columnCount - 1) {
        Cell *cell = &maze[rowStart][columnStart + 1];
        if (cell->status != Status::BORDER) {
            cell->value = startCell->value + cell->speed;
            Result result = solve(rowStart, columnStart + 1, maze, route);
            results.push_back(result);
        }
    }
    if ((rowStart - 1) != 0) {
        Cell *cell = &maze[rowStart - 1][columnStart];
        if (cell->status != Status::BORDER) {
            cell->value = startCell->value + cell->speed;
            Result result = solve(rowStart - 1, columnStart, maze, route);
            results.push_back(result);
        }
    }
    if ((columnStart - 1) != 0) {
        Cell *cell = &maze[rowStart][columnStart - 1];
        if (cell->status != Status::BORDER) {
            cell->value = startCell->value + cell->speed;
            Result result = solve(rowStart, columnStart - 1, maze, route);
            results.push_back(result);
        }
    }
}

void Maze::recovery() {
//    ЕСЛИ финишная ячейка помечена
//    ТО
//    перейти в финишную ячейк у
//    ЦИКЛ
//    выбрать среди соседних ячейку, помеченную числом на 1 меньше числа в текущей ячейке
//    перейти в выбранную ячейку и добавить её к пути
//    ПОКА текущая ячейка — не стартовая
//    ВОЗВРАТ путь найден
//    ИНАЧЕ
//    ВОЗВРАТ путь не найден
    
}



//vector<string> Maze::solve() {
//    scan();
//    initialize();
//    propagation();
//    recovery();
//    vector<string> a;
//    return a;
//}

vector<Cell> Maze::solve(int rowStart, int columnStart, vector<string> maze) {
    
}
Maze::~Maze() {
//    for (int i = 0; i < rowCount; ++i) {
//        delete[] field[i];
//    }
//    delete[] field;
}
