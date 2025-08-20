class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        int lo = 0, hi = enemyEnergies.size() - 1;
        long long points = 0, maxPoints = 0;
        if(enemyEnergies[0] > currentEnergy)return 0;
        while (hi >= 0) {
            if (currentEnergy >= enemyEnergies[0]) {
                points += currentEnergy / enemyEnergies[0];
                currentEnergy = currentEnergy % enemyEnergies[0];
            } 
            else{
                
                currentEnergy += enemyEnergies[hi];
                hi--;
            } 
        }
        return points;
    }
};