#include <bits/stdc++.h>
using namespace std;

// Function to shift a deque (Move last element to front)
template<typename T>
void ShiftDeque(T& deq) {
    if (deq.empty()) return;
    deq.push_front(move(deq.back()));
    deq.pop_back();
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    int h = rc.size();
    int w = rc[0].size();
    
    // 1. Move containers inside the function to avoid global state issues
    deque<int> l, r;
    deque<deque<int>> mid;
    
    // 2. Initialize deques
    for(int i = 0; i < h; ++i) {
        l.push_back(rc[i][0]);
        r.push_back(rc[i][w - 1]);
        
        deque<int> temp_row;
        // Only fill mid if width > 2
        for(int j = 1; j < w - 1; ++j) {
            temp_row.push_back(rc[i][j]);
        }
        mid.push_back(move(temp_row));
    }
    
    // 3. Process Operations
    for(const auto& op : operations) {
        if (op == "ShiftRow") {
            ShiftDeque(l);
            ShiftDeque(r);
            ShiftDeque(mid);
        } 
        else if (op == "Rotate") {
            if (w == 2) {
                // Special handling for width 2 (no middle part)
                r.push_front(l.front()); 
                l.pop_front();
                
                l.push_back(r.back());   
                r.pop_back();
            } else {
                // Standard Logic for width > 2
                // 1. Move Left-Top to Mid-Top-Left
                mid.front().push_front(l.front()); 
                l.pop_front();
                
                // 2. Move Mid-Top-Right to Right-Top
                r.push_front(mid.front().back());  
                mid.front().pop_back();
                
                // 3. Move Right-Bottom to Mid-Bottom-Right
                mid.back().push_back(r.back());    
                r.pop_back();
                
                // 4. Move Mid-Bottom-Left to Left-Bottom
                l.push_back(mid.back().front());   
                mid.back().pop_front();
            }
        }
    }
    
    // 4. Reconstruct the answer
    vector<vector<int>> answer(h, vector<int>(w));
    for(int i = 0; i < h; ++i) {
        answer[i][0] = l[i];
        answer[i][w - 1] = r[i];
        for(int j = 1; j < w - 1; ++j) {
            answer[i][j] = mid[i][j - 1];
        }
    }
    
    return answer;
}
