/*
 ID: 211791041, Email: lior16122000@gmail.com
*/

#include "Graph.hpp"
#include <iostream>

using namespace std;
namespace ariel {
    void Graph::loadGraph(vector<vector<int>> graph) {
        // check each row has the same length as the number of rows
        for (size_t i = 0; i < graph.size(); i++) {
            if (graph[i].size() != graph.size()) {
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        // intialize the graph and the flags
        _graph = graph;
        _hasNegativeCycles = false;
        _hasCycles = false;
    }

    void Graph::printGraph() {
        size_t edges = 0;
        size_t vertices = 0;
        
        for (size_t i = 0; i < _graph.size(); i++) {
            // count the number of vertices and edges while printing the matrix
            vertices++;
            for (size_t j = 0; j < _graph[i].size(); j++) {
                if (_graph[i][j] != 0){
                    edges++;
                }
                // print element in the matrix
                cout << _graph[i][j] << " ";
            }
            // drop a line after each row
            cout << endl;
        }

        cout << "Graph with " << vertices << " vertices and " << edges << " edges." << endl;        
    }

    int Graph::getWeight(size_t ver1, size_t ver2) const{
        return _graph[ver1][ver2];   
    }

    size_t Graph::getVertices(){
        return _graph.size();
    }

    bool Graph::containsNegativeCycles() const{
        return _hasNegativeCycles;
    }
    bool Graph::containsCycles() const{
        return _hasCycles;
    }
    void Graph::setNegativeCycles(){
        _hasCycles = true;
        _hasNegativeCycles = true;
    }
        void Graph::setCycles(){
        _hasCycles = true;
    }

}
