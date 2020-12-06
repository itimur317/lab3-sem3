#pragma once
#include "Graph.h"
#include <cassert>


void Test_Graph() {
    int* a = new int[25];
    for (int i = 0; i < 25; i++) {
        a[i] = 0;
    }
    a[8] = 100;
    a[7] = 30;
    a[11] = 30;
    a[14] = 40;
    a[16] = 100;
    a[19] = 20;
    a[22] = 40;
    a[23] = 20;
    Graph* current = new Graph(a, 5);

    //common path
    Sequence<int>* testing = current->Dijkstra(3, 2);
    assert(testing->GetLength() == 3);
    assert(testing->Get(0) == 3);
    assert(testing->Get(1) == 4);
    assert(testing->Get(2) == 2);
    assert(current->path_distance(testing) == 60);

    //from i vertex to i vertex
    testing = current->Dijkstra(1, 1);
    assert(testing->GetLength() == 1);
    assert(testing->Get(0) == 1);
    assert(current->path_distance(testing) == 0);

    //path when it`s choose 
    testing = current->Dijkstra(1, 4);
    assert(testing->GetLength() == 3);
    assert(testing->Get(0) == 1);
    assert(testing->Get(1) == 2);
    assert(testing->Get(2) == 4);
    assert(current->path_distance(testing) == 70);

    // unconnected path
    testing = current->Dijkstra(1, 0);
    assert(testing->GetLength() == 0);
    assert(current->path_distance(testing) == INT_MAX);

    // 2nd unconnected path
    testing = current->Dijkstra(0, 4);
    assert(testing->GetLength() == 0);
    assert(current->path_distance(testing) == INT_MAX);

    // path when algprithm choose long but less weigth path
    testing = current->Dijkstra(1, 3);
    assert(testing->GetLength() == 4);
    assert(testing->Get(0) == 1);
    assert(testing->Get(1) == 2);
    assert(testing->Get(2) == 4);
    assert(testing->Get(3) == 3);
    assert(current->path_distance(testing) == 90);

    // path when algprithm choose long but less weigth path
    testing = current->Dijkstra(3, 1);
    assert(testing->GetLength() == 4);
    assert(testing->Get(0) == 3);
    assert(testing->Get(1) == 4);
    assert(testing->Get(2) == 2);
    assert(testing->Get(3) == 1);
    assert(current->path_distance(testing) == 90);
}
