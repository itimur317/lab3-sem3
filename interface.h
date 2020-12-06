#pragma once
#include "Test_graph.h"
using namespace std;

void interface(){
    cout << "if you see this message tests done!" << endl;
    int amount_vertexes = 0;
    cout << "enter how many vertexes in your graph: ";
    cin >> amount_vertexes;
    if (amount_vertexes < 0)
        throw out_of_range(IndexOutOfRangeEx);
    cout << "enter adjacency matrix" << endl;
    // matrix smezhnosti
    int* array = new int[amount_vertexes * amount_vertexes];
    for (int i = 0; i < amount_vertexes; i++) {
        for (int j = 0; j < amount_vertexes; j++) {
            int cur;
            cin >> cur;
            array[i + j * amount_vertexes] = cur;
        }
        cout << endl;
    }
    Graph* my_graph = new Graph(array, amount_vertexes);
    int flag = 1;
    while (flag) {
        cout << "1. to find the shortest path" << endl;
        cout << "0. to exit" << endl;
        cin >> flag;
        if (flag == 1) {
            cout << "enter start vertex: ";
            int start_vertex;
            cin >> start_vertex;
            cout << "enter end vertex: ";
            int end_vertex;
            cin >> end_vertex;
            Sequence<int>* path = my_graph->Dijkstra(start_vertex, end_vertex);
            cout << "path: ";
            for (int i = 0; i < path->GetLength(); i++) {
                cout << path->Get(i);
                if (path->Get(i) != end_vertex)
                    cout << " --> ";
            }
            cout << endl;
            cout << "path distance = " << my_graph->path_distance(path) << endl << endl;
        }
    }
}
