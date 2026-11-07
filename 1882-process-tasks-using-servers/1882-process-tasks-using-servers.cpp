#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> ans;
        ans.clear();
                  //  {-weight, -i} {-tFree, i}
        priority_queue<pll> freepq, taskpq;
        while(!freepq.empty()) {freepq.pop();}
        while(!taskpq.empty()) {taskpq.pop();}
        for(int i=0; i<servers.size(); i++) {
            freepq.push({-servers[i], -i});
        }
        ll t = 0;
        for(int i=0; i<tasks.size();) {
            ll now = tasks[i];
            while(!taskpq.empty() && -taskpq.top().fi == t) {
                ll idx = taskpq.top().se;
                freepq.push({-servers[idx], -idx});
                taskpq.pop();
            }
            if(freepq.empty()) {
                // Wait
                t = -taskpq.top().fi;
            } else {
                // Consume until (i == t)
                while(i <= t && !freepq.empty()) {
                    ans.push_back(-freepq.top().se);
                    taskpq.push({-(t+now), ans.back()});
                    freepq.pop();
                    i++;
                    if(i>t) {t++; break ;}
                    if(i == tasks.size()) {break ;}
                    now = tasks[i];
                }
            }
        }
        return ans;
    }
};