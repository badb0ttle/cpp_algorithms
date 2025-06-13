/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define int long long // 十年oi一场空，不开ll见祖宗
#define sc scanf
#define pr printf
string ans = "12345678*"; // 目标状态

void print(string s)
{
    for (int i = 0; i < 9; ++i)
    {
        if (s[i] == '*')
        {
            cout << "* ";
        }
        else
        {
            cout << s[i] << " ";
        }
        if ((i + 1) % 3 == 0)
        {
            cout << '\n';
        }
    }
    cout << "-----------------\n";
}

int heuristic(const string &s);
//  将索引转换为坐标 (x, y)
// 计算当前状态与目标状态中每个数字的位置差之和。
// 例如，数字'1'在当前位置到目标位置的横向和纵向距离之和就是它的曼哈顿距离。
// 总体启发值是所有数字曼哈顿距离的总和。
pair<int, int> index_to_coord(int idx)
{
    return {idx / 3, idx % 3};
}

struct State
{
    string config;
    int cost;      // 已花费的步数
    int heuristic; // 启发式值

    State(string s, int c) : config(s), cost(c)
    {
        this->heuristic = ::heuristic(s); // <-- 使用全局命名空间
    }

    bool operator>(const State &other) const
    {
        return (cost + this->heuristic) > (other.cost + other.heuristic);
    }
};

int heuristic(const string &s)
{
    int sum = 0;
    for (int i = 0; i < 9; ++i)
    {
        if (s[i] == '*')
            continue;
        int num = s[i] - '0';
        int target_x = (num - 1) / 3;
        int target_y = (num - 1) % 3;
        int current_x = i / 3, current_y = i % 3;
        sum += abs(current_x - target_x) + abs(current_y - target_y);
    }
    return sum;
}
// generate函数生成初始状态时确保逆序数与空格位置的奇偶性一致，保证问题有解。
string generate()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    random_device rd;
    mt19937 gen(rd());

    do
    {
        shuffle(nums.begin(), nums.end() - 1, gen);
        int inv_count = 0;
        for (int i = 0; i < 8; ++i)
        {
            for (int j = i + 1; j < 9; ++j)
            {
                if (nums[i] && nums[j] && nums[i] > nums[j])
                    inv_count++;
            }
        }
        int blank_row = 2 - (8 / 3);
        if ((inv_count + blank_row) % 2 == 0)
            break;
    } while (true);

    string s;
    for (int n : nums)
        s += (n == 0) ? "*" : to_string(n); 
    return s;
}

// 生成合法移动
vector<string> get_neighbors(const string &state)
{
    vector<string> neighbors;
    int blank = state.find('*');
    int x = blank / 3, y = blank % 3;

    // 四个移动方向
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto [dx, dy] : dirs)
    {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
            continue;

        int new_pos = nx * 3 + ny;
        string new_state = state;
        swap(new_state[blank], new_state[new_pos]);
        neighbors.push_back(new_state);
    }
    return neighbors;
}

// A*算法实现
// 使用优先队列（最小堆）按f(n) = g(n) + h(n)顺序处理节点，其中g(n)是已花费步数，h(n)是启发式值。
// 这样可以优先处理那些估计更优的状态。
// 使用哈希表came_from和action_map记录每一步的状态转移，以便最后回溯路径并展示详细步骤。
// 在每次扩展节点时，更新到达邻居状态的最小步数和路径信息。
// 当找到目标状态时，立即回溯并返回路径长度及详细步骤。
pair<int, vector<pair<int, int> > > solve(const string &s)
{
    priority_queue<State, vector<State>, greater<State>> pq;
    unordered_map<string, int> cost_so_far;
    unordered_map<string, string> came_from;
    unordered_map<string, pair<int, int>> action_map;

    pq.push(State(s, 0));
    cost_so_far[s] = 0;
    came_from[s] = "";
    action_map[s] = {-1, -1};

    while (!pq.empty())
    {
        State current = pq.top();
        pq.pop();

        if (current.config == ans)
        {
            // 回溯路径
            vector<pair<int, int>> path;
            string state = current.config;
            while (came_from[state] != "")
            {
                auto [old_pos, new_pos] = action_map[state];
                path.emplace_back(old_pos, new_pos);
                state = came_from[state];
            }
            reverse(path.begin(), path.end());
            return {path.size(), path};
        }

        for (const string &next : get_neighbors(current.config))
        {
            int new_cost = cost_so_far[current.config] + 1;
            if (!cost_so_far.count(next) || new_cost < cost_so_far[next])
            {
                cost_so_far[next] = new_cost;
                came_from[next] = current.config;
                // 记录移动动作
                int old_pos = current.config.find('*');
                int new_pos = next.find('*');
                action_map[next] = {new_pos, old_pos}; // 反向存储
                pq.push(State(next, new_cost));
            }
        }
    }
    return {-1, {}};
}

void work()
{
    string title = generate();
    // title="12346875*";
    cout << "初始棋盘：" << '\n';
    print(title);
    auto [steps, path] = solve(title);
    cout << "\n最少交换次数: " << steps << '\n';
    string tmp = title;
    int cnt = 1;
    for (auto [ti, ni] : path)
    {
        swap(tmp[ti], tmp[ni]);
        auto [x1, y1] = index_to_coord(ti);
        auto [x2, y2] = index_to_coord(ni);
        cout << "\n第" << cnt++ << "步：(" << x1 + 1 << "," << y1 + 1 << ") <-> ("<< x2 + 1 << "," << y2 + 1 << ")" << '\n';
        print(tmp);
    }

    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // sc("%d", &_);
    // cin>>_;
    while (_--)
        work();
    return 0;
}