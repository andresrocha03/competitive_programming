#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

typedef pair<int,int> coord;

bool taken[MAX][MAX];
int h[MAX][MAX];

priority_queue<pair<int,coord>> pq;

vector<coord> possible_neighbors = {
    {-1,0}, {0,-1}, {1,0}, {0,1}
};

void process(int i, int j, int M, int N) {
    taken[i][j] = true;
    for (auto &[diff_i,diff_j]:possible_neighbors) {
        int row=i+diff_i, col = j +diff_j;
        if (row >=0 && row <M && col) {

        }
    }
}