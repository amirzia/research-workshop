#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

std::string normalize(const std::string& word) {
    std::string result;
    for (char c : word)
        if (std::isalpha(c)) result += std::tolower(c);
    return result;
}

int main(int argc, char* argv[]) {
    std::string filename = "sample.txt";
    int top_n = 10;

    if (argc >= 2) filename = argv[1];
    if (argc >= 3) top_n = std::stoi(argv[2]);

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file '" << filename << "'\n";
        return 1;
    }

    std::map<std::string, int> freq;
    int total = 0;
    std::string token;

    while (file >> token) {
        std::string word = normalize(token);
        if (!word.empty()) {
            freq[word]++;
            total++;
        }
    }

    // Sort by frequency descending
    std::vector<std::pair<std::string, int>> sorted(freq.begin(), freq.end());
    std::sort(sorted.begin(), sorted.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });

    std::cout << "\n File : " << filename << "\n";
    std::cout << " Total words : " << total << "\n";
    std::cout << " Unique words: " << freq.size() << "\n";
    std::cout << "\nTop " << top_n << " most frequent words:\n";
    std::cout << std::string(50, '-') << "\n";
    printf("%-6s %-20s %-8s %s\n", "Rank", "Word", "Count", "Bar");
    std::cout << std::string(50, '-') << "\n";

    int max_count = sorted.empty() ? 1 : sorted[0].second;
    for (int i = 0; i < top_n && i < (int)sorted.size(); i++) {
        const auto& [word, count] = sorted[i];
        int bar_len = (int)((double)count / max_count * 20);
        std::string bar(bar_len, '#');
        printf("%-6d %-20s %-8d %s\n", i + 1, word.c_str(), count, bar.c_str());
    }

    return 0;
}
