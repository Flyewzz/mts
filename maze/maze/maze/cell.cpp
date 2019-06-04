//
//  cell.cpp
//  maze
//
//  Created by Alpha on 03/06/2019.
//  Copyright © 2019 Alpha. All rights reserved.
//

#include <stdio.h>
#include "cell.h"

Cell* Cell::newCell(Cell * const cell, const short &row, const short &column) {
    cell->row = row;
    cell->column = column;
    cell->visited = false;
    cell->value = 0;
    cell->speed = 0;
    return cell;
}

Status Cell::getStatus() const {
    return status;
}
float Cell::getValue() const {
    return value;
}
float Cell::getSpeed() const {
    return speed;
}
bool Cell::getVisited() const {
    return visited;
}
short Cell::getRow() const {
    return row;
}
short Cell::getColumn() const {
    return column;
}
void Cell::setStatus(const Status &st) {
    status = st;
}
void Cell::setValue(const float &val) {
    value = val;
}
void Cell::setSpeed(const float &spd) {
    speed = spd;
}
void Cell::setVisited(const bool &flag) {
    visited = flag;
}
