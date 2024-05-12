/*
 ID: 211791041, Email: lior16122000@gmail.com
*/
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(graph) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK((ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->1->2->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->0->2->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->2->1->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->2->0->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->0->1->2") == true);
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    graph.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(graph.loadGraph(graph1));
}
// More tests
TEST_CASE("Test cycleCheck") {
    ariel::Graph graph;
    // Unweighted graph without a cycle
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");

    // Weighted graph with a cycle
    vector<vector<int>> graph2 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(graph) != "0");

    // Unweighted graph with a cycle
    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(graph) != "0");
}
TEST_CASE("Graph with isolated vertices") {
    ariel::Graph graph;
    vector<vector<int>> graph0 ={
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph0);
    CHECK(ariel::Algorithms::isConnected(graph) == false);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "The graph doesn't contain negative cycles");
    CHECK((ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2, 3, 4}, B={1}" ||
    ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={1}, B={0, 2, 3, 4})") == true);
}

TEST_CASE("Graph with a single vertex and no edges") {
    ariel::Graph graph;
    vector<vector<int>> graph0 ={
        {0}};
    graph.loadGraph(graph0);
    CHECK(ariel::Algorithms::isConnected(graph) == true);       // one vertice only is connected
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "The graph doesn't contain negative cycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0}, B={}");
}

TEST_CASE("ConnectedGraph") {
    ariel::Graph graph;
    vector<vector<int>> graph0 ={
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    graph.loadGraph(graph0);
    CHECK(ariel::Algorithms::isConnected(graph) == true);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "0->1->2->3->4");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "The graph doesn't contain negative cycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    vector<vector<int>> graph2 = {
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 0}
    };
    graph.loadGraph(graph2); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(graph) == true);      
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");    
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph3 = {
    {0, 1, 2, 0, 0},
    {1, 0, 3, 0, 0},
    {2, 3, 0, 4, 0},
    {0, 0, 4, 0, 5},
    {0, 0, 0, 5, 0}
    };
    graph.loadGraph(graph3); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(graph) == true);        
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "0->2->3->4");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2");
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}

TEST_CASE("Graph with self-loop") {
    ariel::Graph graph;
    vector<vector<int>> graph0 ={
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph0);
    CHECK(ariel::Algorithms::isConnected(graph) == false);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1");
    CHECK((ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->1->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->0->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->0") == true);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "The graph doesn't contain negative cycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}



TEST_CASE("UnconnectedGraph") {
    ariel::Graph graph;
    vector<vector<int>> graph2 = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    };
    graph.loadGraph(graph2); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(graph) == false);        
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1"); 
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2");    
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");        
}    

TEST_CASE("Test BipartiteGraph") {
    ariel::Graph graph;
    // Unweighted graph that is bipartite
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2}, B={1}");

    // Weighted graph that is not bipartite
    vector<vector<int>> graph2 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");

    // Unweighted graph that is not bipartite
    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}
TEST_CASE("UndirectedGraph") {
    ariel::Graph graph;
    vector<vector<int>> graph1 ={
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(graph) == true);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "0->1->2->3->4");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "The graph doesn't contain negative cycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}

TEST_CASE("ConnectedGraphNegativeCycle") {
    ariel::Graph graph;
    vector<vector<int>> graph1 ={
        {0, -1, 0},
        {0, 0, -1},
        {-1, 0, 0}
    };
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(graph) == true);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 2) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "The graph contain negative cycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}
TEST_CASE("DirectedGraph") {
    ariel::Graph graph;
    vector<vector<int>> graph1 ={
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(graph) == true);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "0->1->2->3->4");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "The graph doesn't contain negative cycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}

TEST_CASE("Test negativeCycles") {
    ariel::Graph graph;
    // Weighted graph without a negative cycle
    vector<vector<int>> graph1 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "The graph doesn't contain negative cycles");

    // Unweighted graphs without a negative cycle
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "The graph doesn't contain negative cycles");

    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "The graph doesn't contain negative cycles");

    // Unweigthted graphs with a negative cycle
    vector<vector<int>> graph4 = {
        {0, -1, 0},
        {0, 0, -1},
        {-1, 0, 0}};
    graph.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "The graph contain negative cycles");

    vector<vector<int>> graph5 = {
        {0, -1, 0, 0, 0},
        {0, 0, -1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "The graph doesn't contain negative cycles");

    // Weighted graph with a negative cycle
    vector<vector<int>> graph6 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, -5},
        {0, 0, 0, -5, 0}};
    graph.loadGraph(graph6);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "The graph contain negative cycles");
}

