#include <iostream>
#include "ArraySequence.h"
#include "Sequence.h"
#include "my_sorts.h"
#include <vector>
using namespace std;




class Graph {
private:
    Sequence<int>* graph; // our Graph
    int n;

public:
    Graph(int* arr, int n) {
        graph = new ArraySequence<int>(n * n);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                graph->Set(j + i * n, arr[j + i * n]);
                if (arr[j + i * n])
                    count++;
            }
        }  // copy matrix 
        this->n = n;
    }

    ~Graph() {
        delete graph;
    }

    void print_matrix(){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << graph->Get(j + i * n) << "  ";
            }
            cout << endl;
        }
    }
private:
    int min_path(int* short_dist, bool* visited_vertexes) {
        int min_index;
        int min = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!visited_vertexes[i] && (short_dist[i] <= min)) {
                min = short_dist[i];// from visited take minimum
                min_index = i;
            }
        } 
        return min_index;
    }

public:
    int* Dijkstra(int start_vertex, int end_vertex) {
        if (start_vertex < 0 || (end_vertex > n - 1) && (n > 1)
            || start_vertex > end_vertex) 
            throw out_of_range(IndexOutOfRangeEx);
        // just check edges

        int* short_dist = new int[n];
        bool* visited_vertexes = new bool[n];
        Sequence<int>* path = new ArraySequence<int>;

        for (int i = 0; i < n; i++) {
            short_dist[i] = INT_MAX; 
            visited_vertexes[i] = 0;
        }

        short_dist[start_vertex] = 0;

        

        for (int i = 0; i + 1 < n; i++) {
            // cycle n - 1 times
            // i < n - 1  <=>  i + 1 < n
            // index of short branch
            int min = min_path(short_dist, visited_vertexes);
            // min`s vertexes isn`t free anymore 
            // min - index of the shortest path
            visited_vertexes[min] = 1;

            for (int j = 0; j < n; j++) {
                if (!visited_vertexes[j] &&
                    // it wasn`t visited
                    (graph->Get(j + min * n)) &&
                    // it isn`t zero
                    (short_dist[min] != INT_MAX) &&
                    // if it = INT_MAX then it illogical
                    (short_dist[min] + graph->Get(j + min * n) < short_dist[j])) {
                    // if this path less than past
                    
                    short_dist[j] = short_dist[min] + graph->Get(j + min * n);
                }
            }
        }

        return short_dist;
    }
};

int main()
{
    int* a = new int[25];
    for (int i = 0; i < 25; i++) {
        a[i] = 0;
    }
    a[8] = 1;
    a[7] = 1;
    a[11] = 1;
    a[14] = 1;
    a[16] = 1;
    a[19] = 1;
    a[22] = 1;
    a[23] = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << a[j + i * 5] << "  ";
        }
        cout << endl;
    }
    cout << endl;

    Graph* current = new Graph(a, 5);
    current->print_matrix();
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << (current->Dijkstra(1, 3))[i] << "  ";
    }
    return 0;
}
