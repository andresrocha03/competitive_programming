#include <bits/stdc++.h> 
using namespace std; 
#define N 4 
struct Line
{
    int ax,ay;
    int bx,by;
};
long long getDis(pair<int,int> a, pair<int,int> b){
    return (a.first - b.first)*1ll*(a.first - b.first) + 
        (a.second - b.second)*1ll*(a.second - b.second);
}
bool isNotPoint(pair<int,int> ponto1,pair<int,int> ponto2 ){
    if(ponto1 != ponto2){
        return true;
    }
    return false;
}
bool isParallel(pair<int,int> ponto1,pair<int,int> ponto2 ){
    if (ponto1.first == ponto2.first)
    {
        return true;
    }
    if(ponto1.second  == ponto2.second){
        return true;
    }
    return false;
}
bool isRec(vector<Line> lines){
    set<pair<int,int>> Set;
    set<pair<pair<int,int>,pair<int,int>>> set_linhas;
    for (int i = 0; i < N; i++)
    {
        pair<int,int> ponto1, ponto2;
        pair<pair<int,int>,pair<int,int>> linha_ida;
        pair<pair<int,int>,pair<int,int>> linha_volta;
        ponto1 = make_pair(lines[i].ax, lines[i].ay);
        ponto2 = make_pair(lines[i].bx, lines[i].by);
        linha_ida = make_pair(ponto1, ponto2);
        linha_volta = make_pair(ponto2, ponto1);
        if(isNotPoint(ponto1, ponto2)&& isParallel(ponto1, ponto2)){
            Set.insert(ponto1);
            Set.insert(ponto2);
            set_linhas.insert(linha_ida);
            set_linhas.insert(linha_volta);
        };
        
    }
    if(Set.size() != 4 || set_linhas.size() != 8){
        return false;
    }
    

    set<long long> dist;
    for (auto point1 = Set.begin(); point1 != Set.end(); point1++)
    {
        for (auto point2 = Set.begin(); point2 != Set.end(); point2++)
        {
            if(*point1 != *point2){
                dist.insert(getDis(*point1, *point2));
            }
        }
        
    }

    if(dist.size()>3){
        return false;
    }
    
    return true;
}
int main(){
    vector<Line> lines;
    for (int i = 0; i < N; i++)
    {
        Line line;
        cin >> line.ax >> line.ay >> line.bx >> line.by;
        lines.push_back(line);
        
        
    }
        if (isRec(lines))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
    
    return 0;
}