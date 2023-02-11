// link - https://practice.geeksforgeeks.org/problems/counting-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article 


    string countSort(string arr){
        int freq[26]={0};
        for(char ch:arr){
            freq[ch-'a']++;
        }
        for(int i=1;i<26;++i){
            freq[i]=freq[i-1]+freq[i];
        }
        char ans[arr.length()];
        for(char ch:arr){
            ans[freq[ch-'a']-1]=ch;
            freq[ch-'a']--;
        }
        return ans;
    }
