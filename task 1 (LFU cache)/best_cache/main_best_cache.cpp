#include "best_cache.cpp"

using namespace std;

int main() {
    int sz = 0, val = 0, num = 0, hits = 0;
    cin >> sz;
    vector<int> cache, data;
    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> val;
        data.push_back(val);
    }
    hits = chech_hits_best_cache(data, num, cache, sz);
    cout << "Number of hits: " << hits << "\n";
}