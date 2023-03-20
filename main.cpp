#include <iostream>
#include <queue>
#include <stack>
#include <limits>
#include <bits/stdc++.h>
using namespace std;


// Find the shortest path between two vertices in a weighted graph using BFS
// source: the starting vertex
// destination: the ending vertex
// A: adjacency matrix representing the weighted graph
// n: number of vertices in the graph
void shortestPath(int source, int destination, int A[][9], int n) {
    queue<int> q;
    int dist[9] {0};    // array to store the shortest distance from source to each vertex
    int pred[9] {0};    // array to store the predecessor vertex for each vertex on the shortest path
    int visited[9] {0}; // array to keep track of visited vertices

    // Initialization
    for (int i = 0; i < n; i++) {
        dist[i] = -1; // set initial distance to infinity
        pred[i] = -1;      // set initial predecessor to -1 (undefined)
    }

    visited[source] = 1; // mark the source vertex as visited
    dist[source] = 0;    // set the distance to source to 0
    q.emplace(source);   // add the source vertex to the queue

    // Breadth-first search
    while (!q.empty()) {
        int u = q.front(); // get the next vertex from the queue
        q.pop();

        for (int v = 0; v < n; v++) { // for each neighbor v of u
            if (A[u][v] != 0 && visited[v] == 0) { // if v is a neighbor of u and not visited yet
                visited[v] = 1; // mark v as visited
                dist[v] = dist[u] + A[u][v]; // update the distance to v
                pred[v] = u; // set the predecessor of v to u
                q.emplace(v); // add v to the queue
            }
                // If there's an alternative path to v that's shorter than the current shortest path,
                // update the distance and predecessor of v
            else if (A[u][v] != 0 && dist[v] > dist[u] + A[u][v]) {
                dist[v] = dist[u] + A[u][v];
                pred[v] = u;
            }
           
        }
    }

    // Print shortest path sequence
    if (dist[destination] != -1) { // if a path exists
        stack<int> s;
        int current = destination;
        s.push(current);

        while (current != source) { // traverse the path from destination to source using the predecessor array
            current = pred[current];
            s.push(current);
        }

        cout << "Shortest path sequence from " << source << " to " << destination << ": ";
        while (!s.empty()) { // print the path sequence
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
        cout << "Shortest path length from " << source << " to " << destination << ": " << dist[destination] << endl;
    } else { // if no path exists
        cout << "No path found from " << source << " to " << destination << endl;
    }
}


void longestPath(int source, int destination, int A[][9], int n) {
    queue<int> q;
    int dist[9] {-INT_MAX}; // array to store the maximum distance from source to each vertex
    int pred[9] {0};        // array to store the predecessor vertex for each vertex on the maximum path
    int visited[9] {0};     // array to keep track of visited vertices

    // Initialization
    for (int i = 0; i < n; i++) {
        pred[i] = -1; // set initial predecessor to -1 (undefined)
    }

    visited[source] = 1; // mark the source vertex as visited
    dist[source] = 0;    // set the distance to source to 0
    q.emplace(source);   // add the source vertex to the queue

    // Breadth-first search
    while (!q.empty()) {
        int u = q.front(); // get the next vertex from the queue
        q.pop();

        for (int v = 0; v < n; v++) { // for each neighbor v of u
            if (A[u][v] != 0 && visited[v] == 0) { // if v is a neighbor of u and not visited yet
                visited[v] = 1; // mark v as visited
                dist[v] = max(dist[v], dist[u] + A[u][v]); // update the distance to v
                pred[v] = u; // set the predecessor of v to u
                q.emplace(v); // add v to the queue
            }
                // If there's an alternative path to v that's longer than the current maximum path,
                // update the distance and predecessor of v
            else if (A[u][v] != 0 && dist[v] < dist[u] + A[u][v]) {
                dist[v] = max(dist[v], dist[u] + A[u][v]);
                pred[v] = u;
            }
        }
    }

    // Print maximum path sequence
    if (dist[destination] != -INT_MAX) { // if a path exists
        stack<int> s;
        int current = destination;
        s.push(current);

        while (current != source) { // traverse the path from destination to source using the predecessor array
            current = pred[current];
            s.push(current);
        }

        cout << "Maximum path sequence from " << source << " to " << destination << ": ";
        while (!s.empty()) { // print the path sequence
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
        cout << "Maximum path length from " << source << " to " << destination << ": " << dist[destination] << endl;
    } else { // if no path exists
        cout << "No path found from " << source << " to " << destination << endl;
    }
}




int main() {
    int A[][9] = {
            { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
              { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
              { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
              { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
              { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
              { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
              { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
              { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
              { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };


    shortestPath(2, 7, A, 9);

    return 0;
}
