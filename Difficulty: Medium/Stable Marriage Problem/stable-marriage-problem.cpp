class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>>& men, vector<vector<int>>& women) {
        int n = men.size();

        vector<int> partnerOfWoman(n, -1);
        vector<int> partnerOfMan(n, -1); 
        vector<int> nextProposal(n, 0); 
        
        vector<vector<int>> womenRank(n, vector<int>(n));
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                womenRank[w][women[w][i]] = i;
            }
        }

        queue<int> freeMen;
        for (int i = 0; i < n; i++) freeMen.push(i);

        while (!freeMen.empty()) {
            int m = freeMen.front();
            freeMen.pop();

            int w = men[m][nextProposal[m]];
            nextProposal[m]++;

            if (partnerOfWoman[w] == -1) {
                partnerOfWoman[w] = m;
                partnerOfMan[m] = w;
            } else {
                int m2 = partnerOfWoman[w];

                // Check preference
                if (womenRank[w][m] < womenRank[w][m2]) {
                    // She prefers new man
                    partnerOfWoman[w] = m;
                    partnerOfMan[m] = w;

                    partnerOfMan[m2] = -1;
                    freeMen.push(m2);
                } else {
                    // Reject
                    freeMen.push(m);
                }
            }
        }

        return partnerOfMan;
    }
};