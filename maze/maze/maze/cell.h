//
//  cell.h
//  maze
//
//  Created by Alpha on 03/06/2019.
//  Copyright © 2019 Alpha. All rights reserved.
//

#ifndef cell_h
#define cell_h

#include <string>
#include <vector>
#include <queue>

using std::string;
using std::vector;

class Cell;

typedef enum {
    BORDER,
    EMPTY,
    SAND,
    START,
} Status;
typedef struct{
    vector<vector<Cell>> maze;
    vector<Cell> route;
    float distance;
} Result;


class Cell {
    Status status;
    short row;
    short column;
    float value;
    float speed;
    bool visited;
public:
    static Cell* newCell(Cell * const cell, const short &row, const short &column);
    //---------getters------------//
    Status getStatus() const;
    float getValue() const;
    float getSpeed() const;
    bool getVisited() const;
    short getRow() const;
    short getColumn() const;
    //---------setters-------------------//
    void setStatus(const Status &st);
    void setValue(const float &val);
    void setSpeed(const float &spd);
    void setVisited(const bool &flag);
};

#endif /* cell_h */
