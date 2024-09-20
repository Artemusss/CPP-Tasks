#include "best_cache.cpp"

using namespace std;

int main() {
    int sz = 0, val = 0, num = 0, hits = 0;
    cout << "Write size of best cache" << "\n";
    cin >> sz;
    vector<int> cache, data;
    cout << "write number of values in data" << "\n";
    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> val;
        data.push_back(val);
    }
    hits = chech_hits_best_cache(data, num, cache, sz);
    cout << "Number of hits: " << hits << "\n";
}