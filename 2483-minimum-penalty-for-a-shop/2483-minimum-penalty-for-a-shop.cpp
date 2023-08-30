class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int ind = -1,cnt = 0,maxi = 0;
        for(int i = 0;i < n;i++)
        {
            cnt += (customers[i] == 'Y') ? 1 : -1;
            if(cnt > maxi)
            {
                maxi = cnt;
                ind = i;
            }
        }
        return ind+1;
    }
//     int bestClosingTime(string customers) {
//         int n = customers.size();
//         vector<int> pre(n+1,0),suf(n+1,0);
//         for(int i = 0;i < n;i++)
//         {
//             if(customers[i] == 'N') pre[i+1] = pre[i] + 1;
//             else pre[i+1] = pre[i];
            
//             if(customers[n-i-1] == 'Y') suf[n-i-1] = suf[n-i] + 1;
//             else suf[n-i-1] = suf[n-i];
//         }
//         int ans = 1e9,ind = 0;
//         for(int i = 0;i < n+1;i++)
//         {
//             if(pre[i] + suf[i] < ans)
//             {
//                 ans = pre[i] + suf[i];
//                 ind = i;
//             }
//         }
//         for(int i = 0;i < n+1;i++)
//         {
//             cout << pre[i] << " "<<suf[i]<<endl;
//         }
//         return ind;
//     }
};