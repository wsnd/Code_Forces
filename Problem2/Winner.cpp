#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>
using namespace std;
int main()
{
    size_t max_line;
    cin >> max_line;
    size_t line_cnt = 0;
    int max_points = 0;
    string winner;
    map<string, int> map_points;
    map<string, vector<pair<int, int>>> map_step;
    vector<string>vec_candidates;
    while (line_cnt < max_line) {
        string name;
        int points;
        cin >> name >> points;
        auto iter = map_points.find(name);
        if (iter == map_points.end()) {
            map_points.insert(make_pair(name, points));           
            map_step.insert(make_pair(name, 
            vector<pair<int, int>>{make_pair(static_cast<int>(line_cnt), points)}));
        }
        else {
            iter->second += points;
            map_step.at(name).push_back(make_pair(static_cast<int>(line_cnt), points));       
        }
        ++line_cnt;  
    }
    max_points = map_points.begin()->second;
    for (auto elem : map_points)
        max_points = elem.second > max_points ? elem.second : max_points;
    for (auto elem : map_points)
        if (max_points == elem.second)
            vec_candidates.push_back(elem.first);
    int min_step = max_line;
    for (auto candidate : vec_candidates) {
        int sum = 0;
            for (auto record : map_step.at(candidate)) {
                sum += record.second;
                if (sum >= max_points && record.first < min_step) {
                    min_step = record.first;
                    winner = candidate;
                    break;
                }
            }
    }
    cout << winner << '\n';
    return 0;
}