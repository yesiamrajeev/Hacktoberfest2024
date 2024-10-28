vector<int> sortArr(vector<int>arr, int n){
    vector<int> ans;
    vector<int> ans2(n);
    int max = 1;
    for(int i=0;i<n;i++)
    {
        string str = to_string(arr[i]);
        if(str.length()>max)
            max = str.length();
    }
    for(auto x:arr)
    {
        ans.push_back(x);
    }
    int cc = 1;
    for (int x = 0; x < max; x++)
    {
        vector<vector<int>> temp(10);
        int hh = cc*10;
        for (int i = 0; i < n; i++)
        {
            int k = (ans[i] % hh)/cc;
            temp[k].push_back(i);
        }
        int rr = 0;
        for(int i = 0;i<10;i++)
        {
            for(int j = 0;j<temp[i].size();j++)
            {
                ans2[rr] = ans[temp[i][j]];
                rr++;
            }
        }
        // temp.clear();
        for(int i = 0;i<n;i++)
        {
            ans[i] = ans2[i];
        }
        cc = 10 * cc;
    }

    return ans2;
}
