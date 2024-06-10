#include <bits/stdc++.h>
#define pb push_back

using namespace std;

struct player {
    string name;
    int points;
};

vector<player> arr;
vector<player> emulate_arr;

int findi (string name, vector<player> &vec) {
    for (int i=0; i<vec.size(); i++) {
        if (vec[i].name==name) return i;
    }
    return -1;
}

void add_player(string name, int point, vector<player>& vec) {
    player newplayer;
    newplayer.name = name;
    newplayer.points = point;
    vec.pb(newplayer); 
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string name; 
    vector<pair<string,int>> name_score;
    int point, last; 
    cin >> t;

    // find final pontuations
    while (t--) {
        cin >> name >> point;
        name_score.pb(make_pair(name,point));
        int i = findi(name, arr);
        if (i==-1) { 
            add_player(name, point,arr); 
            i = findi(name,arr);
        }
        else {
            arr[i].points = arr[i].points + point;
        } 
    }

    //find max
    int max = INT32_MIN;
    for (int j=0;j<arr.size();j++) {
        if (arr[j].points > max) max = arr[j].points; 
    }

    //find finalists
    vector<string> finalists;
    for (int j=0;j<arr.size();j++) {
        if (arr[j].points == max) finalists.pb(arr[j].name); 
    }

    int winner;
    
    // emulate the game, the first finalist to score max is the winner
    for (int j=0; j<name_score.size(); j++) {
        name = name_score[j].first;
        point = name_score[j].second;
        int i = findi(name, emulate_arr);
        if (i==-1) { 
            add_player(name, point, emulate_arr); 
            i = findi(name, emulate_arr);
        }
        else {
            emulate_arr[i].points = emulate_arr[i].points + point;
        }

        if (emulate_arr[i].points >= max && find(finalists.begin(),finalists.end(), emulate_arr[i].name) != finalists.end()) {
            winner = i; 
            break;
        }
    }

    cout << emulate_arr[winner].name;

    return 0;
}