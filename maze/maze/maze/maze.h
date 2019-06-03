//
//  maze.h
//  maze
//
//  Created by Alpha on 03/06/2019.
//  Copyright © 2019 Alpha. All rights reserved.
//

#ifndef maze_h
#define maze_h

#include <string>
#include <vector>
#include <queue>

using std::string;
using std::vector;
using std::queue;


class Maze {
    typedef enum {
        BORDER,
        EMPTY,
        SAND,
        FINISH,
    } Status;
    typedef struct {
        Status status;
        size_t row;
        size_t column;
        int value;
        unsigned int speed;
        bool marked;
    } Cell;
    typedef struct{
        vector<vector<Cell>> maze;
        vector<Cell> route;
        float distance;
    } Result;
    size_t rowStartPoint;
    size_t columnStartPoint;
    //---Attributes---
    vector<vector<Cell>> field;
    size_t rowCount;
    size_t columnCount;
    //----Methods-----
    void setStartPoint(const size_t &row, const size_t &column);
    void propagation();
    void recovery();
    //----------------
public:
    Maze(vector<string> maze);
    static Cell* newCell(Cell *cell, const size_t &row, const size_t &column);
    Result solve(size_t rowStart, size_t columnStart, vector<vector<Cell>> maze, vector<Cell> route);
    ~Maze();
};

#endif /* maze_h */
