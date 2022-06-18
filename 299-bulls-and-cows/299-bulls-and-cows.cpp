class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;

        string a = secret;
        string b = guess;

        int ma[26] = {0};
        int mb[26] = {0};

        for(int i=0; i<secret.length(); i++)
        {
            if(a[i] == b[i])
            {
                bulls++;
            }
            else
            {
                ma[a[i]-'0']++;
                mb[b[i]-'0']++;
            }
        }

        for(int i=0; i<26; i++)
        {
            cows += min(ma[i], mb[i]);
        }

        cout<<bulls<<'A'<<cows<<'B'<<endl;

        return to_string(bulls) + "A" + to_string(cows) + "B";



        
    }
};