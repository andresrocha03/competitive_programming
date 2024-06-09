#include <bits/stdc++.h>
#define pb push_back

using namespace std;

struct player {
    string name;
    vector<int> points;
};

vector<player> arr;

int findi (string name) {
    for (int i=0; i<arr.size(); i++) {
        if (arr[i].name==name) return i;
    }
    return -1;
}

void add_player(string name, int point) {
    player newplayer;
    newplayer.name= name;
    newplayer.points.pb(0);
    newplayer.points.pb(point);
    if 
    arr.pb(newplayer);
}

void update_players(int i) {
    for (int j=0; j<arr.size(); j++) {
        if (j!= i) arr[j].points.pb(0);
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string name; 
    int point, last, round=0; 
    cin >> t;

    while (t--) {
        cin >> name >> point;
        round++;
        int i = findi(name);
        if (i==-1) { 
            add_player(name, point); 
            i = findi(name);
        }
        else {
            int last = arr[i].points.back();
            arr[i].points.pb(last + point);
        }
        update_players(i);
    }

    int max = INT32_MIN;
    for (int j=0;j<arr.size();j++) {
        if (arr[j].points.back() > max) max = arr[j].points.back(); 
    }

    vector<int> winners; 
    for (int j=0;j<arr.size();j++) {
        if (arr[j].points.back() == max) winners.pb(j); 
    }

    int min = 100000, owner;
    for (int j=0; j<winners.size();j++) {
        for (int k=0; k<arr[winners[j]].points.size(); k++) {
            if (arr[winners[j]].points[k] == max) {
                if (k<min) min = k;
                owner = winners[j];
            }
        }
    }

    cout << arr[owner].name << "\n";
    

    return 0;
}