#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

struct Vertex
{
    string name;
    int distance;
};

vector<vector<int>> createGraph(vector<string> &vertices)
{
    int numVertices189;
    cout << "MASUKAN JUMLAH SIMPUL : ";
    cin >> numVertices189;

    vertices.resize(numVertices189);
    for (int i = 0; i < numVertices189; i++)
    {
        cout << "MASUKAN SIMPUL : " << i + 1 << ": ";
        cin >> vertices[i];
    }

    vector<vector<int>> adjacencyMatrix(numVertices189, vector<int>(numVertices189));
    for (int i = 0; i < numVertices189; i++)
    {
        for (int j = 0; j < numVertices189; j++)
        {
            if (i == j)
            {
                adjacencyMatrix[i][j] = 0;
            }
            else
            {
                cout << "MASUKAN BOBOT SIMPUL : " << vertices[i] << "-->" << vertices[j] << ": ";
                cin >> adjacencyMatrix[i][j];
            }
        }
    }

    return adjacencyMatrix;
}

int findDistance(const vector<vector<int>> &adjacencyMatrix, const vector<string> &vertices,
                 const string &startCity, const string &endCity)
{
    auto startIt = find(vertices.begin(), vertices.end(), startCity);
    auto endIt = find(vertices.begin(), vertices.end(), endCity);

    if (startIt == vertices.end() || endIt == vertices.end())
    {
        return -1;
    }

    int startIndex = distance(vertices.begin(), startIt);
    int endIndex = distance(vertices.begin(), endIt);

    vector<int> distances(vertices.size(), INT_MAX);
    distances[startIndex] = 0;

    set<int> unvisitedVertices;
    for (int i = 0; i < vertices.size(); i++)
    {
        unvisitedVertices.insert(i);
    }

    while (!unvisitedVertices.empty())
    {
        int currentVertex = *min_element(unvisitedVertices.begin(), unvisitedVertices.end(),
                                         [&](int i, int j)
                                         { return distances[i] < distances[j]; });
        unvisitedVertices.erase(currentVertex);

        for (int neighbor = 0; neighbor < vertices.size(); neighbor++)
        {
            if (adjacencyMatrix[currentVertex][neighbor] > 0 &&
                distances[currentVertex] + adjacencyMatrix[currentVertex][neighbor] < distances[neighbor])
            {
                distances[neighbor] = distances[currentVertex] + adjacencyMatrix[currentVertex][neighbor];
            }
        }
    }

    return distances[endIndex];
}

int main()
{

    vector<string> vertices;
    vector<vector<int>> adjacencyMatrix = createGraph(vertices);

    string startCity, endCity;
    cout << "MASUKAN NAMA KOTA AWAL : ";
    cin >> startCity;
    cout << "MASUKAN NAMA KOTA TUJUAN : ";
    cin >> endCity;

    int distance = findDistance(adjacencyMatrix, vertices, startCity, endCity);

    if (distance == -1)
    {
        cout << "TIDAK ADA JALUR DARI " << startCity << " ke " << endCity << "." << endl;
    }
    else
    {
        cout << "JARAK DARI " << startCity << " KE " << endCity << " ADALAH " << distance << " KILOMETER" << endl;
    }

    return 0;
}