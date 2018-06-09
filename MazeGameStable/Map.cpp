#include "Map.hpp"

Map::Map(int size)
{
    mMapHeight = size;
    mMapWidth = size;
}

Map::~Map()
{

}

void Map::create()
{
    vector<char> row(mMapWidth);

    for (int i = 0; i < mMapHeight; ++i)
    {
        mMap.push_back(row);
    }

    initialize(mMap);
    endpoints(mMap);
}

void Map::initialize(vector< vector<char> >& map)
{
    for (int i = 0; i < map.size(); ++i)
    {
        for (int j = 0; j < map[0].size(); ++j)
        {
            map[i][j] = '#';
        }
    }
    
    generate(map, 1, 1);
}

void Map::generate(vector< vector<char> >& map, int i, int j)
{
    int direct[][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
    int visitOrder[] = {0,1,2,3};
    
    if(i < 1 || j < 1 || i >= map.size() - 1 || j >= map[0].size() - 1) return;
    if(map[i][j] == ' ') return;
    if(countVisitedNeighbor(map, i, j) > 1) return;

    map[i][j] = ' ';

    shuffle(visitOrder, 4);
    
    for (int k = 0; k < 4; ++k)
    {
        int ni = i + direct[visitOrder[k]][0];
        int nj = j + direct[visitOrder[k]][1];
        generate(map, ni, nj);
    }
}

int Map::countVisitedNeighbor(vector< vector<char> >& map, int i, int j)
{
    int direct[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int count = 0;

    for (int k = 0; k < 4; ++k)
    {
        int ni = i + direct[k][0];
        int nj = j + direct[k][1];
        if(ni < 0 || nj < 0 || ni >= map.size() || nj >= map[0].size()) continue;
        if(map[ni][nj] == ' ') count++;
    }

    return count;
}

void Map::shuffle(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        swap(a[i], a[rand() % n]);
    }
}

void Map::swap(int & a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void Map::endpoints(vector< vector<char> >& map)
{
    bool notStart = true;
    bool notEnd = true;
    int start = 1;
    int end = map.size() - 2;

    while(notStart)
    {
        if(map[start][1] == ' ')
        {
            map[start][1] = 'S';
            notStart = false;
        }
        else
        {
            start++;
        }
    }

    while(notEnd)
    {
        if(map[end][map.size() - 2] == ' ')
        {
            map[end][map.size() - 2] = 'E';
            notEnd = false;
        }
        else
        {
            end--;
        }
    }
}

char Map::getMap(int i, int j)
{
    return mMap[i][j];
}