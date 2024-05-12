/*
 ID: 211791041, Email: lior16122000@gmail.com
*/

#pragma once
#include <vector>

using namespace std;
namespace ariel {
    class Graph{
        private:
        
        vector<vector<int>> _graph;
        bool _hasNegativeCycles;
        bool _hasCycles;

        public:
            // Constructors
            Graph(){ 
                _hasNegativeCycles = false;
                _hasCycles = false;
                _graph = {};
            }

            Graph(vector<vector<int>> _graph){
                Graph();
                loadGraph(_graph); 
            }
            
            // Functions:
            // Loads adjacency matrix to _graph. Returns 1 if successful, 0 if unsuccessful.
            void loadGraph(vector<vector<int>>);
            
            // Prints the _graph and the number of verices and edges in the graph.
            void printGraph();

            // Returns the size of _graph - the number vertices
            size_t getVertices();

            int getWeight(size_t, size_t) const;
            bool containsNegativeCycles() const;
            bool containsCycles() const;
            void setNegativeCycles();
            void setCycles();
    };
}