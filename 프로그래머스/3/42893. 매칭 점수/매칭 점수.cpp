#include <bits/stdc++.h>
using namespace std;

map<string, int> url_to_idx;
struct Page {
    int idx;
    int basic_score = 0;
    vector<string> external_links;
    double link_score = 0.0;
};
vector<Page> pages_info;

string toLower(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

int solution(string word, vector<string> pages) {
    // 1. 전역 변수 및 데이터 초기화
    url_to_idx.clear();
    pages_info.clear();
    pages_info.resize(pages.size());
    string target_word = toLower(word);

    // 2. 파싱 단계 (기본 점수 계산 및 링크 수집)
    for (int i = 0; i < pages.size(); ++i) {
        pages_info[i].idx = i;
        string& s = pages[i];

        // 2-1. 내 URL 찾기 (<meta property="og:url" content="URL"/>)
        string meta_sig = "<meta property=\"og:url\" content=\"";
        size_t meta_pos = s.find(meta_sig);
        if (meta_pos != string::npos) {
            size_t start = meta_pos + meta_sig.length();
            size_t end = s.find('"', start);
            string my_url = s.substr(start, end - start);
            url_to_idx[my_url] = i;
        }

        // 2-2. 본문 파싱 (기본 점수 & 외부 링크)
        bool inside_tag = false;
        string current_word = "";
        
        for (int k = 0; k < s.size(); ++k) {
            // 태그 시작
            if (s[k] == '<') {
                // 직전까지 읽던 단어 체크
                if (!inside_tag && !current_word.empty()) {
                    if (toLower(current_word) == target_word) pages_info[i].basic_score++;
                    current_word = "";
                }
                
                inside_tag = true;
                
                // <a href="URL"> 체크
                if (s.substr(k, 9) == "<a href=\"") {
                    size_t start = k + 9;
                    size_t end = s.find('"', start);
                    if (end != string::npos) {
                        pages_info[i].external_links.push_back(s.substr(start, end - start));
                        k = end; // URL 부분 건너뛰기
                    }
                }
                continue;
            }

            // 태그 끝
            if (s[k] == '>') {
                inside_tag = false;
                continue;
            }

            // 본문 텍스트 읽기
            if (!inside_tag) {
                if (isalpha(s[k])) {
                    current_word += s[k];
                } else {
                    // 알파벳이 아닌 문자가 나오면 단어 끝으로 간주
                    if (!current_word.empty()) {
                        if (toLower(current_word) == target_word) pages_info[i].basic_score++;
                        current_word = "";
                    }
                }
            }
        }
    }

    // 3. 링크 점수 계산 단계 (모든 파싱이 끝난 후 실행)
    for (int i = 0; i < pages.size(); ++i) {
        if (pages_info[i].external_links.empty()) continue;
        
        double score_to_give = (double)pages_info[i].basic_score / pages_info[i].external_links.size();
        
        for (const string& link : pages_info[i].external_links) {
            if (url_to_idx.count(link)) {
                int target_idx = url_to_idx[link];
                pages_info[target_idx].link_score += score_to_give;
            }
        }
    }

    // 4. 결과 찾기 (최대 점수)
    double max_score = -1.0;
    int answer = 0;

    for (int i = 0; i < pages.size(); ++i) {
        double total = pages_info[i].basic_score + pages_info[i].link_score;
        if (total > max_score) {
            max_score = total;
            answer = i;
        }
    }

    return answer;
}