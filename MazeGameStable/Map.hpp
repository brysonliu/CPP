#ifndef Map_hpp
#define Map_hpp

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
using namespace std;

class Map
{
    public:
        Map(int size);
        ~Map();
        
        void create();
        char getMap(int i, int j);
    
    private:
        int mMapHeight;
        int mMapWidth;
        vector< vector<char> > mMap;

        void initialize(vector< vector<char> >& map);
        void generate(vector< vector<char> >& map, int i, int j);
        int countVisitedNeighbor(vector< vector<char> >& map, int i, int j);
        void shuffle(int a[], int n);
        void swap(int & a, int &b);
        void endpoints(vector< vector<char> >& map);
};

#endif