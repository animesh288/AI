#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int vertex;
    int f_score;
    int g_score;
};
struct CompareNodes
{
    bool operator()(Node a, Node b)
    {
        return a.f_score > b.f_score;
    }
};
int heuristic(int a, int b)
{
    return abs(a - b);
}
vector<int> a_star(vector<vector<pair<int, int>>> graph, int start, int goal)
{
    int n = graph.size();
    priority_queue<Node, vector<Node>, CompareNodes> frontier;
    frontier.push({start, heuristic(start, goal), 0});
    vector<bool> visited(n, false);
    vector<int> g_scores(n, -1);
    g_scores[start] = 0;
    vector<int> parents(n, -1);
    while (!frontier.empty())
    {
        Node current_node = frontier.top();
        frontier.pop();
        if (current_node.vertex == goal)
        {
            vector<int> path;
            int current_vertex = goal;
            while (current_vertex != start)
            {
                path.push_back(current_vertex);
                current_vertex = parents[current_vertex];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }
        visited[current_node.vertex] = true;
        for (auto neighbor : graph[current_node.vertex])
        {
            int neighbor_vertex = neighbor.first;
            int neighbor_distance = neighbor.second;
            int tentative_g_score = g_scores[current_node.vertex] +
                                    neighbor_distance;
            if (!visited[neighbor_vertex] || tentative_g_score <
                                                 g_scores[neighbor_vertex])
            {
                int f_score = tentative_g_score +
                              heuristic(neighbor_vertex, goal);
                g_scores[neighbor_vertex] = tentative_g_score;
                Node neighbor_node = {neighbor_vertex, f_score,
                                      tentative_g_score};
                frontier.push(neighbor_node);
                parents[neighbor_vertex] = current_node.vertex;
            }
        }
    }
    return vector<int>();
}
int main()
{
    vector<vector<pair<int, int>>> graph;
    graph.push_back({{1, 4}, {7, 8}});
    graph.push_back({{0, 4}, {7, 11}, {2, 8}});
    graph.push_back({{1, 8}, {8, 2}, {3, 7}, {5, 4}});
    graph.push_back({{2, 7}, {4, 9}, {5, 14}});
    graph.push_back({{3, 9}, {5, 10}});
    graph.push_back({{2, 4}, {3, 14}, {4, 10}, {6, 2}});
    graph.push_back({{5, 2}, {7, 1}, {8, 6}});
    graph.push_back({{0, 8}, {1, 11}, {6, 1}, {8, 7}});
    graph.push_back({{2, 2}, {6, 6}, {7, 7}});
    int start = 0;
    int goal = 8;
    vector<int> path = a_star(graph, start, goal);
    if (!path.empty())
    {
        cout << "Shortest path from " << start << " to " << goal << ": ";
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i];
            if (i != path.size() - 1)
            {
                cout << " -> ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "No path found from " << start << " to " << goal << "." << endl;
    }
    return 0;
}