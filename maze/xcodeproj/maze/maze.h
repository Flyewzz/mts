//
//  maze.h
//  maze
//
//  Created by Alpha on 03/06/2019.
//  Copyright © 2019 Alpha. All rights reserved.
//

#ifndef maze_h
#define maze_h

#include "cell.h"

class Maze {
    //---Attributes---
    vector<vector<Cell>> field;
    size_t rowCount;
    size_t columnCount;
    short rowStart;
    short columnStart;
    //----Methods-----
    bool solvability() const;
    void setStartPosition(const short &row, const short &column);
    Result propagation(short rowStart, short columnStart, vector<vector<Cell>> maze, vector<Cell> route);
    bool isExit(const short &row, const short &col) const;
    //----------------
public:
    Maze(vector<string> maze);
    Result solve();
    ~Maze();
};

#endif /* maze_h */
