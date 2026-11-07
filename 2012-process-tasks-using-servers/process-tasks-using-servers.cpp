class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using T = tuple<long long,int,int>;

        priority_queue<pair<int,int>,
        vector<pair<int,int>>, greater<pair<int,int>>> av;

        priority_queue<T, vector<T>, greater<T>> busy;

        for(int i = 0; i < servers.size(); i++)
            av.push({servers[i], i});

        vector<int> ans;
        long long time = 0;

        for(int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            while(!busy.empty() && get<0>(busy.top()) <= time) {
                auto [t, w, idx] = busy.top();
                busy.pop();
                av.push({w, idx});
            }

            if(av.empty()) {
                time = get<0>(busy.top());

                while(!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [t, w, idx] = busy.top();
                    busy.pop();
                    av.push({w, idx});
                }
            }

            auto [w, idx] = av.top();
            av.pop();

            ans.push_back(idx);
            busy.push({time + tasks[i], w, idx});
        }

        return ans;
    }
};