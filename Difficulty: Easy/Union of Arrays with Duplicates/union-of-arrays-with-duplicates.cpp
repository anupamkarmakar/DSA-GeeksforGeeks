class Solution {
  public:
vector<int> findUnion(vector<int>& a, vector<int>& b) {
    unordered_set<int> s;  // handles negatives too
    vector<int> result;
    
    for (int x : a) s.insert(x);
    for (int x : b) s.insert(x);

    // Copy set into result
    result.assign(s.begin(), s.end());

    // Sort result
    sort(result.begin(), result.end());
    return result;
}

};