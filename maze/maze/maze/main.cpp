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
    vector<string> lab;
    for (int i = 0; i < 4; ++i) {
        string str;
        getline(cin, str);
        lab.push_back(str);
    }
    Maze maze(lab);
    lab = maze.solve();
    for (int i = 0; i < lab.size(); ++i) {
        cout << lab[i] << endl;
    }
    return 0;
}
