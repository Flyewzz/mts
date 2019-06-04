//
//  main.cpp
//  maze
//
//  Created by Alpha on 03/06/2019.
//  Copyright © 2019 Alpha. All rights reserved.
//

#include <iostream>
#include "maze.h"
using std::cin;
using std::cout;
using std::endl;


int main(int argc, const char * argv[]) {
    vector<string> maz;
    string line;
    while (getline(cin, line)) {
        maz.push_back(line);
    }
    try {
        Maze maze(maz);
        Result result = maze.solve();
        if (result.distance == std::numeric_limits<float>::max()) {
            throw string("Maze is impassable");
        }
        for (Cell cell : result.route) {
            maz[cell.getRow()][cell.getColumn()] = '*';
        }
        cout << endl;
        for (string line : maz) {
            cout << line << endl;
        }
    }
    catch(string err) {
        if (err == "Maze is impassable") {
            return 1;
        }
        cout << err << endl;
    }
    return 0;
}
