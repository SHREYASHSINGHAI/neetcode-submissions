class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        vector<int> boats;
        int i = 0;
        int j = people.size()-1;
        int count = 0;
        while(i<=j){
            if(i<j && people[i]==limit){
                count++;
                i++;
            }
            else if(i<j && people[j]==limit){
                count++;
                j--;
            }
            else if (i<j && people[i]+people[j]<=limit){
                count++;
                i++;
                j--;
            }
            else if (i < j && people[i]+people[j]> limit){
                count++;
                j--;
            }
            else if (i==j && people[i]<=limit){
                count++;
                break;
            }
            
        }
        return count;
    }
};