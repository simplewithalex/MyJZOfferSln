#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 0004

// 位运算
class Solution1 {
public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (auto n : nums) {
                if ((n >> i) & 1) ++sum;
            }
            res |= (sum % 3) << i;
        }
        return res;
    }
};

// 状态机（技巧性）
class Solution2 {
public:
    int singleNumber(vector<int> &nums) {
        int one = 0, two = 0;
        for (auto n : nums) {
            one = one ^ n & ~two;
            two = two ^ n & ~one;
        }
        return one;
    }
};
/*
 * https://leetcode.cn/problems/single-number-ii/solution/single-number-ii-mo-ni-san-jin-zhi-fa-by-jin407891/
 * @author https://leetcode.cn/u/jyd/
 */




// 0454
/*

454. 四数相加 II


*/



class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


// practice
class Solution1 {
public:
    vector<vector<int>> adj;
    vector<int> visited;
    vector<int> result;
    bool valid = true;
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        adj.resize(numCourses);
        visited.resize(numCourses);
        for (const auto &edge : prerequisites) adj[edge[1]].push_back(edge[0]);
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) dfs(i);
        }
        if (!valid) return {};
        reverse(result.begin(), result.end());
        return result;
    }
    void dfs(int u) {
        visited[u] = 1;
        for (int v : adj[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) return;
            } else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
        result.push_back(u);
    }
};

class Solution2 {
public:
    vector<vector<int>> adj;
    vector<int> indegrees;
    vector<int> result;
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        adj.resize(numCourses);
        indegrees.resize(numCourses);
        for (const auto &edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            ++indegrees[edge[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            for (int v : adj[u]) {
                --indegrees[v];
                if (indegrees[v] == 0) q.push(v);
            }
        }
        if (result.size() != numCourses) return {};
        return result;
    }
};

class Solution3 {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};

class Solution4 {
public:
    int ans = INT_MIN;
    int maxPathSum(TreeNode *root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode *node) {
        if (!node) return 0;
        int l_val = dfs(node->left);
        int r_val = dfs(node->right);
        ans = max(ans, node->val + l_val + r_val);
        return max(0, node->val + max(l_val, r_val));
    }
};

// 邻接矩阵
class Solution5 {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int cities = isConnected.size();
        vector<char> visited(cities);
        int provinces = 0;
        for (int i = 0; i < cities; ++i) {
            if (!visited[i]) {
                dfs(isConnected, visited, cities, i);
                ++provinces;
            }
        }
        return provinces;
    }
    void dfs(vector<vector<int>> &isConnected, vector<char> &visited,
             int cities, int idx) {
        for (int j = 0; j < cities; ++j) {
            if (isConnected[idx][j] && !visited[j]) {
                visited[j] = true;
                dfs(isConnected, visited, cities, j);
            }
        }
    }
};

class Solution6 {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int cities = isConnected.size();
        vector<char> visited(cities);
        int provinces = 0;
        queue<int> q;
        for (int i = 0; i < cities; ++i) {
            if (!visited[i]) {
                q.push(i);
                while (!q.empty()) {
                    int j = q.front();
                    q.pop();
                    visited[j] = true;
                    for (int k = 0; k < cities; ++k) {
                        if (isConnected[j][k] && !visited[k]) q.push(k);
                    }
                }
                ++provinces;
            }
        }
        return provinces;
    }
};


// 并查集
class UF {
private:
	vector<int> id;

public:
    int count;
	UF(vector<vector<int>> &isConnected) {
        int cities = isConnected.size();
		for (int i = 0; i < cities; ++i) id.push_back(i);
        count = cities;
	}
	int find(int x) {
		if (id[x] != x) id[x] = find(id[x]);
		return id[x];
	}
	void unionpq(int p, int q) {
		int pRoot = find(p);
		int qRoot = find(q);
		if (pRoot == qRoot) return;
		id[pRoot] = qRoot;
        --count;
	}
};

class Solution7 {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        UF uf(isConnected);
        int cities = isConnected.size();
        for (int i = 0; i < cities; ++i) {
            for (int j = i + 1; j < cities; ++j) {
                if (isConnected[i][j]) uf.unionpq(i, j);
            }
        }
        return uf.count;
    }
};

class Solution8 {
public:
    int rows = 0;
    int cols = 0;
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) return;
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            dfs(board, i, 0);
            dfs(board, i, cols - 1);
        }
        for (int j = 1; j < cols - 1; ++j) {
            dfs(board, 0, j);
            dfs(board, rows - 1, j);
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || x >= rows || y < 0 || y >= cols || board[x][y] != 'O') return;
        board[x][y] = '#';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
};

class Solution9 {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    void solve(vector<vector<char>> &board) {
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = '#';
            }
            if (board[i][cols - 1] == 'O') {
                q.push({i, cols - 1});
                board[i][cols - 1] = '#';
            }
        }
        for (int j = 1; j < cols; ++j) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                board[0][j] = '#';
            }
            if (board[rows - 1][j] == 'O') {
                q.push({rows - 1, j});
                board[rows - 1][j] = '#';
            }
        }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx == rows || ny == cols ||
                    board[nx][ny] != 'O')
                    continue;
                q.push({nx, ny});
                board[nx][ny] = '#';
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};

class UF1 {
public:
    vector<int> id;
    UF1(int total) {
        for (int i = 0; i < total; ++i) id.push_back(i);
    }
    int find(int x) {
        if (id[x] != x) id[x] = find(id[x]);
        return id[x];
    }
    void unionpq(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) return;
        id[pRoot] = qRoot;
    }
    bool isConnected(int p, int q) { return find(p) == find(q); }
};

class Solution10 {
  public:
    void solve(vector<vector<char>> &board) {
        int rows = board.size(), cols = board[0].size();
        UF1 uf(rows * cols + 1);
        int dummyNode = rows * cols;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                        uf.unionpq(i * cols + j, dummyNode);
                    } else {
                        if (board[i - 1][j] == 'O')
                            uf.unionpq(i * cols + j, (i - 1) * cols + j);
                        if (board[i + 1][j] == 'O')
                            uf.unionpq(i * cols + j, (i + 1) * cols + j);
                        if (board[i][j - 1] == 'O')
                            uf.unionpq(i * cols + j, i * cols + j - 1);
                        if (board[i][j + 1] == 'O')
                            uf.unionpq(i * cols + j, i * cols + j + 1);
                    }
                }
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!uf.isConnected(i * cols + j, dummyNode)) board[i][j] = 'X';
            }
        }
    }
};

class Solution11 {
public:
    unordered_map<string, int> wordId;
    vector<vector<int>> adj;
    int nodeNum = 0;
    void addWord(const string &word) {
        if (!wordId.count(word)) {
            wordId[word] = nodeNum++;
            adj.emplace_back();
        }
    }
    void addEdge(string &word) {
        addWord(word);
        int id1 = wordId[word];
        for (char &c : word) {
            char tmp = c;
            c = '*';
            addWord(word);
            int id2 = wordId[word];
            adj[id1].push_back(id2);
            adj[id2].push_back(id1);
            c = tmp;
        }
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        for (string &word : wordList) addEdge(word);
        addEdge(beginWord);
        if (!wordId.count(endWord)) return 0;
        vector<int> dis(nodeNum, -1);
        int beginId = wordId[beginWord], endId = wordId[endWord];
        dis[beginId] = 0;

        queue<int> q;
        q.push(beginId);
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            if (tmp == endId) return dis[endId] / 2 + 1;
            for (const int &id : adj[tmp]) {
                if (dis[id] == -1) {
                    dis[id] = dis[tmp] + 1;
                    q.push(id);
                }
            }
        }
        return 0;
    }
};

class Solution12 {
public:
    unordered_map<string, int> wordId;
    vector<vector<int>> adj;
    int nodeNum = 0;
    void addWord(const string &word) {
        if (!wordId.count(word)) {
            wordId[word] = nodeNum++;
            adj.emplace_back();
        }
    }
    void addEdge(string &word) {
        addWord(word);
        int id1 = wordId[word];
        for (char &c : word) {
            char tmp = c;
            c = '*';
            addWord(word);
            int id2 = wordId[word];
            adj[id1].push_back(id2);
            adj[id2].push_back(id1);
            c = tmp;
        }
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        for (string &word : wordList) addEdge(word);
        addEdge(beginWord);
        if (!wordId.count(endWord)) return 0;

        vector<int> disBegin(nodeNum, -1);
        int beginId = wordId[beginWord];
        disBegin[beginId] = 0;
        queue<int> qb;
        qb.push(beginId);

        vector<int> disEnd(nodeNum, -1);
        int endId = wordId[endWord];
        disEnd[endId] = 0;
        queue<int> qe;
        qe.push(endId);

        while (!qb.empty() && !qe.empty()) {
            int qbLen = qb.size();
            for (int i = 0; i < qbLen; ++i) {
                int tmp = qb.front();
                qb.pop();
                if (disEnd[tmp] != -1) return (disBegin[tmp] + disEnd[tmp]) / 2 + 1;
                for (const int &id : adj[tmp]) {
                    if (disBegin[id] == -1) {
                        disBegin[id] = disBegin[tmp] + 1;
                        qb.push(id);
                    }
                }
            }

            int qeLen = qe.size();
            for (int i = 0; i < qeLen; ++i) {
                int tmp = qe.front();
                qe.pop();
                if (disBegin[tmp] != -1) return (disBegin[tmp] + disEnd[tmp]) / 2 + 1;
                for (const int &id : adj[tmp]) {
                    if (disEnd[id] == -1) {
                        disEnd[id] = disEnd[tmp] + 1;
                        qe.push(id);
                    }
                }
            }
        }
        return 0;
    }
};

class Solution13 {
public:
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    int rows, cols;
    vector<vector<int>> memo;
    int dfs(vector<vector<int>> &matrix, int row, int col) {
        if (memo[row][col]) return memo[row][col];
        ++memo[row][col];
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dx[i], newCol = col + dy[i];
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                matrix[newRow][newCol] > matrix[row][col]) {
                memo[row][col] =
                    max(memo[row][col], dfs(matrix, newRow, newCol) + 1);
            }
        }
        return memo[row][col];
    }
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        rows = matrix.size(), cols = matrix[0].size();
        memo.resize(rows, vector<int>(cols));
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};

class Solution14 {
public:
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    int rows, cols;
    vector<vector<int>> outdegrees;
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        rows = matrix.size(), cols = matrix[0].size();
        outdegrees.resize(rows, vector<int>(cols));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int newRow = i + dx[k], newCol = j + dy[k];
                    if (newRow >= 0 && newRow < rows && newCol >= 0 &&
                        newCol < cols && matrix[newRow][newCol] > matrix[i][j]) {
                        ++outdegrees[i][j];
                    }
                }
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (outdegrees[i][j] == 0) q.push({i, j});
            }
        }
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                pair<int, int> tmp = q.front();
                q.pop();
                int row = tmp.first, col = tmp.second;
                for (int k = 0; k < 4; ++k) {
                    int newRow = row + dx[k], newCol = col + dy[k];
                    if (newRow >= 0 && newRow < rows && newCol >= 0 &&
                        newCol < cols && matrix[newRow][newCol] < matrix[row][col]) {
                        --outdegrees[newRow][newCol];
                        if (outdegrees[newRow][newCol] == 0) q.push({newRow, newCol});
                    }
                }
            }
        }
        return ans;
    }
};

// 构造线段树，单点更新
struct Node {
    Node *left;
    Node *right;
    int val;
    Node() : left(nullptr), right(nullptr), val(0) {}
};

class Solution15 {
public:
    void update(Node *node, int start, int end, int idx, int val) {
        if (start == end) {
            node->val += val;
            return;
        }
        int mi = start + (end - start) / 2;
        if (!node->left) node->left = new Node();
        if (!node->right) node->right = new Node();
        if (idx <= mi) update(node->left, start, mi, idx, val);
        else update(node->right, mi + 1, end, idx, val);
        node->val = node->left->val + node->right->val;
    }
    int query(Node *node, int start, int end, int l, int r) {
        if (!node) return 0;
        if (l <= start && r >= end) return node->val;
        int mi = start + (end - start) / 2, ans = 0;
        if (l <= mi) ans += query(node->left, start, mi, l, r);
        if (r > mi) ans += query(node->right, mi + 1, end, l, r);
        return ans;
    }
    vector<int> countSmaller(vector<int> &nums) {
        int len = nums.size();
        vector<int> count(len);
        int minNum = nums[0], maxNum = nums[0];
        for (int i = 1; i < len; ++i) {
            minNum = min(minNum, nums[i]);
            maxNum = max(maxNum, nums[i]);
        }
        Node *root = new Node();
        for (int i = len - 1; i >= 0; --i) {
            int cur = nums[i] - 1;
            count[i] = cur >= minNum ? query(root, minNum, maxNum, minNum, cur) : 0;
            update(root, minNum, maxNum, nums[i], 1);
        }
        return count;
    }
};

class Solution16 {
public:
    vector<int> ans;
    vector<int> index;
    vector<int> countSmaller(vector<int> &nums) {
        int len = nums.size();
        ans.resize(len);
        index.resize(len);
        for (int i = 0; i < len; ++i) index[i] = i;
        mergeSort(0, len - 1, nums);
        return ans;
    }
    void merge(int lo, int hi, int mi, const vector<int> &nums) {
        int leftLen = mi - lo + 1;
        vector<int> ltmp(leftLen);
        for (int idx1 = 0, idx2 = lo; idx1 < leftLen; ++idx1, ++idx2) {
            ltmp[idx1] = index[idx2];
        }
        int i = 0, j = mi + 1, k = lo;
        while (i < leftLen && j <= hi) {
            if (nums[ltmp[i]] <= nums[index[j]]) {
                index[k] = ltmp[i];
                ans[index[k]] += j - mi - 1;
                ++k, ++i;
            } else {
                index[k++] = index[j++];
            }
        }
        while (i < leftLen) {
            index[k] = ltmp[i];
            ans[index[k]] += j - mi - 1;
            ++k, ++i;
        }
    }
    void mergeSort(int lo, int hi, const vector<int> &nums) {
        if (lo == hi) return;
        int mi = lo + (hi - lo) / 2;
        mergeSort(lo, mi, nums);
        mergeSort(mi + 1, hi, nums);
        if (nums[index[mi]] <= nums[index[mi + 1]]) return;
        merge(lo, hi, mi, nums);
    }
};

class Solution17 {
public:
    vector<string> res;
    unordered_set<string> s;
    string tmp;
    size_t maxLen = 0;
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words) {
        if (board.empty() || board[0].empty()) return {};
        int rows = board.size(), cols = board[0].size();
        for (const auto &str : words) {
            maxLen = max(maxLen, str.size());
            s.insert(str);
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dfs(board, i, j);
            }
        }
        return res;
    }
    void dfs(vector<vector<char>> &board, int i, int j) {
        int rows = board.size(), cols = board[0].size();
        if (i < 0 || i == rows || j < 0 || j == cols || board[i][j] == '*') return;
        if (tmp.size() > maxLen) return;
        tmp.push_back(board[i][j]);
        if (s.count(tmp)) {
            res.push_back(tmp);
            s.erase(tmp);
        }
        board[i][j] = '*';
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
        board[i][j] = tmp.back();
        tmp.pop_back();
    }
};

class TrieNode {
public:
    int num = 26;
    string str;
    vector<TrieNode *> v;
    TrieNode() : v(vector<TrieNode *>(num, nullptr)) {}
    bool containsKey(char ch) { return v[ch - 'a']; }
    TrieNode *get(char ch) { return v[ch - 'a']; }
    void put(char ch, TrieNode *node) { v[ch - 'a'] = node; }
    void setStr(const string &word) { str = word; }
    const string &getStr() { return str; }
    void clearStr() { str.clear(); }
};

class Solution18 {
public:
    vector<string> res;
    void insert(string word, TrieNode *root) {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            if (!node->containsKey(ch)) node->put(ch, new TrieNode());
            node = node->get(ch);
        }
        node->setStr(word);
    }
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words) {
        if (board.empty() || board[0].empty()) return {};
        int rows = board.size(), cols = board[0].size();
        TrieNode *root = new TrieNode();
        for (const auto &str : words) insert(str, root);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dfs(board, i, j, root);
            }
        }
        return res;
    }
    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *node) {
        if (!node->getStr().empty()) {
            res.push_back(node->getStr());
            node->clearStr();
        }
        int rows = board.size(), cols = board[0].size();
        if (i < 0 || i == rows || j < 0 || j == cols || board[i][j] == '*' ||
            !node->containsKey(board[i][j])) {
            return;
        }
        char ch = board[i][j];
        board[i][j] = '*';
        dfs(board, i - 1, j, node->get(ch));
        dfs(board, i + 1, j, node->get(ch));
        dfs(board, i, j - 1, node->get(ch));
        dfs(board, i, j + 1, node->get(ch));
        board[i][j] = ch;
    }
};

class Solution19 {
public:
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        int lremove = 0, rremove = 0;
        for (char c : s) {
            if (c == '(') {
                ++lremove;
            } else if (c == ')') {
                if (lremove == 0) ++rremove;
                else --lremove;
            }
        }
        dfs(s, 0, lremove, rremove);
        return res;
    }
    void dfs(string str, int start, int lremove, int rremove) {
        if (lremove == 0 && rremove == 0) {
            if (isValid(str)) res.push_back(str);
            return;
        }
        for (int i = start; i < str.size(); ++i) {
            if (i != start && str[i] == str[i - 1]) continue;
            if (lremove + rremove > str.size() - i) return;
            if (lremove > 0 && str[i] == '(') {
                dfs(str.substr(0, i) + str.substr(i + 1), i, lremove - 1, rremove);
            }
            if (rremove > 0 && str[i] == ')') {
                dfs(str.substr(0, i) + str.substr(i + 1), i, lremove, rremove - 1);
            }
        }
    }
    bool isValid(const string &s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++count;
            } else if (s[i] == ')') {
                --count;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }
};

class Solution20 {
public:
    bool isValid(const string &s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++count;
            } else if (s[i] == ')') {
                --count;
                if (count < 0)
                    return false;
            }
        }
        return count == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> curSet;

        curSet.insert(s);
        while (true) {
            for (const auto &s : curSet) {
                if (isValid(s)) res.push_back(s);
            }
            if (res.size() > 0) return res;
            unordered_set<string> nextSet;
            for (const auto &s : curSet) {
                for (int i = 0; i < s.size(); ++i) {
                    if (i > 0 && s[i] == s[i - 1]) continue;
                    if (s[i] == '(' || s[i] == ')') {
                        nextSet.insert(s.substr(0, i) + s.substr(i + 1));
                    }
                }
            }
            curSet = nextSet;
        }
    }
};

class Solution21 {
public:
    vector<vector<char>> mem;
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        mem.resize(sLen + 1, vector<char>(pLen + 1, -1));
        return helper(sLen, pLen, s, p);
    }
    bool helper(int i, int j, const string &s, const string &p) {
        if (j == 0) return i == 0;
        if (mem[i][j] != -1) return mem[i][j];
        if (i > 0 && (p[j - 1] == '?' || s[i - 1] == p[j - 1])) {
            mem[i][j] = helper(i - 1, j - 1, s, p);
        } else if (p[j - 1] == '*') {
            mem[i][j] =
                helper(i, j - 1, s, p) || (i > 0 && helper(i - 1, j, s, p));
        } else {
            mem[i][j] = false;
        };
        return mem[i][j];
    }
};

class Solution22 {
public:
    vector<vector<char>> memo;
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        memo.resize(sLen + 1, vector<char>(pLen + 1, -1));
        return helper(sLen, pLen, s, p);
    }
    bool helper(int i, int j, const string &s, const string &p) {
        if (j == 0) return i == 0;
        if (memo[i][j] != -1) return memo[i][j];
        if (p[j - 1] == '*') {
            return memo[i][j] =
                       helper(i, j - 2, s, p) ||
                       (i > 0 && (p[j - 2] == '.' || s[i - 1] == p[j - 2]) &&
                        helper(i - 1, j, s, p));
        } else {
            return memo[i][j] = i > 0 &&
                                (p[j - 1] == '.' || s[i - 1] == p[j - 1]) &&
                                helper(i - 1, j - 1, s, p);
        }
        return memo[i][j] = false;
    }
};


class Solution23 {
public:
    int len;
    int mid;
    void wiggleSort(vector<int> &nums) {
        len = nums.size();
        int mid = len / 2;
        quickSelect(nums, 0, len - 1, mid);
        int midNum = nums[mid];
        int lo = 0, hi = len - 1, k = 0;
        while (k <= hi) {
            if (nums[getIdx(k)] > midNum) swap(nums[getIdx(k++)], nums[getIdx(lo++)]);
            else if (nums[getIdx(k)] < midNum) swap(nums[getIdx(k)], nums[getIdx(hi--)]);
            else ++k;
        }
    }
    void quickSelect(vector<int> &nums, int lo, int hi, int mi) {
        int index = partition(nums, lo, hi);
        while (index != mid) {
            if (index > mid) {
                hi = index - 1;
                index = partition(nums, lo, hi);
            } else {
                lo = index + 1;
                index = partition(nums, lo, hi);
            }
        }
    }
    int partition(vector<int> &nums, int lo, int hi) {
        swap(nums[lo], nums[lo + rand() % (hi - lo + 1)]);
        int pivot = nums[lo];
        while (lo < hi) {
            while (lo < hi) {
                if (pivot < nums[hi]) --hi;
                else {
                    nums[lo++] = nums[hi];
                    break;
                }
            }
            while (lo < hi) {
                if (pivot > nums[lo]) ++lo;
                else {
                    nums[hi--] = nums[lo];
                    break;
                }
            }
        }
        nums[lo] = pivot;
        return lo;
    }
    int getIdx(int x) { return (2 * x + 1) % (len | 1); }
};

class Solution24 {
public:
    int rows, cols, k;
    bool helper(vector<vector<int>> &matrix, int target) {
        int cnt = 0;
        int i = 0, j = cols - 1;
        while (i < rows && j >= 0 && cnt < k) {
            if (matrix[i][j] > target) {
                --j;
            } else {
                cnt += j + 1;
                ++i;
            }
        }
        return cnt >= k;
    }
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        rows = matrix.size(), cols = matrix[0].size(), this->k = k;
        int lo = matrix[0][0], hi = matrix[rows - 1][cols - 1];
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            helper(matrix, mi) ? hi = mi : lo = mi + 1;
        }
        return lo;
    }
};

class Solution25 {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int len = nums1.size() + nums2.size();
        if (len & 1) return findKth(nums1, nums2, len / 2 + 1);
        else return (findKth(nums1, nums2, len / 2) +
                     findKth(nums1, nums2, len / 2 + 1)) / 2.0;
    }
    int findKth(vector<int> &nums1, vector<int> &nums2, int k) {
        int len1 = nums1.size(), len2 = nums2.size();
        int lo = max(0, k - len2), hi = min(k, len1);
        while (lo < hi) {
            int i = lo + ((hi - lo) / 2);
            int j = k - i;
            nums2[j - 1] > nums1[i] ? lo = i + 1 : hi = i;
        }
        int nums1Kth = lo == 0 ? INT_MIN : nums1[lo - 1];
        int nums2Kth = lo == k ? INT_MIN : nums2[k - lo - 1];
        return max(nums1Kth, nums2Kth);
    }
};

class Solution26 {
public:
    vector<pair<int, int>> memo;
    int ans;
    int maxProduct(vector<int> &nums) {
        int len = nums.size();
        memo.resize(len, {INT_MIN, INT_MIN});
        ans = nums[0];
        for (int i = 0; i < len; ++i) helper(nums, i);
        return ans;
    }
    pair<int, int> helper(const vector<int> &nums, int idx) {
        if (memo[idx].first != INT_MIN) return memo[idx];
        if (idx == 0) {
            memo[idx] = {nums[0], nums[0]};
            ans = max(ans, nums[0]);
            return memo[idx];
        }
        pair<int, int> prev = helper(nums, idx - 1);
        int current_max =
            max({nums[idx], nums[idx] * prev.first, nums[idx] * prev.second});
        int current_min =
            min({nums[idx], nums[idx] * prev.first, nums[idx] * prev.second});
        memo[idx] = {current_max, current_min};
        ans = max(ans, current_max);
        return memo[idx];
    }
};


class Solution27 {
public:
    vector<vector<int>> memo;
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        memo.resize(len, vector<int>(2, INT_MIN));
        return helper(prices, len - 1, 0);
    }
    int helper(vector<int> &prices, int i, int r) {
        if (i == -1 || i == -2) return r == 0 ? 0 : INT_MIN;
        if (memo[i][r] != INT_MIN) return memo[i][r];
        int v1 = 0, v2 = 0, v3 = 0;
        v1 = helper(prices, i - 1, r);
        if (r) v2 = helper(prices, i - 2, 0) - prices[i];
        else v3 = helper(prices, i - 1, 1) + prices[i];
        return memo[i][r] = r == 0 ? max(v1, v3) : max(v1, v2);
    }
};

vector<vector<int>> memo(101, vector<int>(10001, -1));
class Solution28 {
public:
    int numSquares(int n) { return helper(sqrt(n), n); }
    int helper(int i, int j) {
        if (i == 0) return j == 0 ? 0 : INT_MAX;
        if (memo[i][j] != -1) return memo[i][j];
        return memo[i][j] =
                   j < i * i ? helper(i - 1, j)
                             : min(helper(i - 1, j), helper(i, j - i * i) + 1);
    }
};

class Helper {
public:
    const int N = 10000;
    vector<int> dp;
    Helper() {
        dp.resize(N + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= N; ++i) {
            for (int j = i * i; j <= N; ++j) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
    }
};
Helper helper;

class Solution29 {
  public:
    int numSquares(int n) { return helper.dp[n]; }
};

class Solution30 {
public:
    vector<int> memo;
    unordered_set<string> set;
    int max_length = 0;
    bool wordBreak(string s, vector<string> &wordDict) {
        set.insert(wordDict.begin(), wordDict.end());
        for (const auto &str : wordDict) max_length = max(max_length, (int)str.length());
        int len = s.size();
        memo.resize(len + 1, -1);
        return helper(s, len);
    }
    bool helper(string &s, int i) {
        if (i == 0) return true;
        if (memo[i] != -1) return memo[i];
        for (int j = i - 1; j >= max(i - max_length, 0); --j) {
            if (set.count(s.substr(j, i - j)) && helper(s, j)) return memo[i] = true;
        }
        return memo[i] = false;
    }
};

class Solution31 {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        int max_length = 0;
        for (const auto &str : wordDict) max_length = max(max_length, (int)str.length());
        int len = s.size();
        vector<int> dp(len + 1);
        dp[0] = true;
        for (int i = 1; i <= len; ++i) {
            for (int j = i - 1; j >= max(i - max_length, 0); --j) {
                if (set.count(s.substr(j, i - j)) && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};

class Solution32 {
public:
    unordered_set<string> set;
    unordered_map<int, vector<string>> map;
    int max_length = 0;
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        set.insert(wordDict.begin(), wordDict.end());
        for (const auto &str : wordDict) max_length = max(max_length, (int)str.length());
        int len = s.size();
        helper(s, len);
        return map[len];
    }
    void helper(string &s, int i) {
        if (map.count(i)) return;
        map[i] = {};
        if (i == 0) {
            map[i].push_back("");
            return;
        }
        for (int j = i - 1; j >= max(i - max_length, 0); --j) {
            string word = s.substr(j, i - j);
            if (set.count(word)) {
                helper(s, j);
                for (const string &prefix : map[j]) {
                    map[i].push_back(prefix.empty() ? word
                                                    : prefix + " " + word);
                }
            }
        }
    }
};

class Solution33 {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        int max_length = 0;
        for (const auto &str : wordDict) max_length = max(max_length, (int)str.length());
        int len = s.size();
        unordered_map<int, vector<string>> dp;
        dp[0] = {""};
        for (int i = 1; i <= len; ++i) {
            dp[i] = {};
            for (int j = i - 1; j >= max(i - max_length, 0); --j) {
                string word = s.substr(j, i - j);
                if (set.count(word)) {
                    for (const string &prefix : dp[j]) {
                        dp[i].push_back(prefix.empty() ? word
                                                       : prefix + " " + word);
                    }
                }
            }
        }
        return dp[len];
    }
};

class Solution34 {
public:
    vector<vector<int>> memo;
    vector<int> val;
    int solve(int left, int right) {
        if (left >= right - 1) return 0;
        if (memo[left][right] != -1) return memo[left][right];
        for (int i = left + 1; i < right; ++i) {
            int sum = val[left] * val[i] * val[right];
            sum += solve(left, i) + solve(i, right);
            memo[left][right] = max(memo[left][right], sum);
        }
        return memo[left][right];
    }
    int maxCoins(vector<int> &nums) {
        int len = nums.size();
        val.resize(len + 2);
        memo.resize(len + 2, vector<int>(len + 2, -1));
        for (int i = 1; i <= len; ++i) val[i] = nums[i - 1];
        val[0] = val[len + 1] = 1;
        return solve(0, len + 1);
    }
};

class Solution35 {
public:
    int maxCoins(vector<int> &nums) {
        int len = nums.size();
        vector<vector<int>> dp(len + 2, vector<int>(len + 2));
        vector<int> val(len + 2);
        val[0] = val[len + 1] = 1;
        for (int i = 1; i <= len; ++i) val[i] = nums[i - 1];
        for (int i = 2; i < len + 2; ++i) {
            for (int j = i - 2; j >= 0; --j) {
                for (int k = j + 1; k < i; ++k) {
                    int sum = val[j] * val[k] * val[i];
                    sum += dp[j][k] + dp[k][i];
                    dp[j][i] = max(dp[j][i], sum);
                }
            }
        }
        return dp[0][len + 1];
    }
};

struct Node {
    int k;
    int v;
    Node *pre;
    Node *next;
    Node(int k, int v) : k(k), v(v) {}
};

class LRUCache {
  public:
    int capacity;
    Node *dummy;
    unordered_map<int, Node *> m;

    void remove(Node *node) {
        node->next->pre = node->pre;
        node->pre->next = node->next;
    }

    void push_front(Node *node) {
        node->pre = dummy;
        node->next = dummy->next;
        node->pre->next = node;
        node->next->pre = node;
    }

    Node *get_node(int k) {
        if (m.count(k)) {
            Node *node = m[k];
            remove(node);
            push_front(node);
            return node;
        }
        return nullptr;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->dummy = new Node(0, 0);
        dummy->pre = dummy;
        dummy->next = dummy;
    }

    int get(int key) {
        Node *node = get_node(key);
        return node ? node->v : -1;
    }

    void put(int key, int value) {
        Node *node = get_node(key);
        if (node) {
            node->v = value;
            return;
        }
        m[key] = node = new Node(key, value);
        push_front(node);
        if (m.size() > capacity) {
            Node *backnode = dummy->pre;
            m.erase(backnode->k);
            remove(backnode);
            delete backnode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

struct Node {
    Node *son[26] = {};
    bool end = false;
};

class Trie {
public:
    Node *root = new Node();
    int find(string word) {
        Node *cur = root;
        for (char c : word) {
            c -= 'a';
            if (!cur->son[c]) return 0;
            cur = cur->son[c];
        }
        return cur->end ? 2 : 1;
    }

    void destroy(Node *node) {
        if (!node) return;
        for (Node *son : node->son) destroy(son);
        delete node;
    }
    Trie() {}
    ~Trie() { destroy(root); }

    void insert(string word) {
        Node *cur = root;
        for (char c : word) {
            c -= 'a';
            if (!cur->son[c]) cur->son[c] = new Node();
            cur = cur->son[c];
        }
        cur->end = true;
    }

    bool search(string word) { return find(word) == 2; }

    bool startsWith(string prefix) { return find(prefix) != 0; }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a
    // nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a
    // single integer The result is undefined if this NestedInteger holds a
    // nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a
    // nested list The result is undefined if this NestedInteger holds a single
    // integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    vector<int> res;
    vector<int>::iterator it;
    void dfs(const vector<NestedInteger> &nestedList) {
        for (const auto &nest : nestedList) {
            if (nest.isInteger()) res.push_back(nest.getInteger());
            else dfs(nest.getList());
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        it = res.begin();
    }

    int next() { return *it++; }

    bool hasNext() { return it != res.end(); }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {}

    void addNum(int num) {
        if (left.size() == right.size()) {
            right.push(num);
            left.push(right.top());
            right.pop();
        } else {
            left.push(num);
            right.push(left.top());
            left.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) return left.top();
        return (left.top() + right.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class Solution36 {
public:
    ListNode *middleNode(ListNode *head) {
        ListNode *pre = head;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        return slow;
    }
    ListNode *merge(ListNode *l, ListNode *r) {
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        while (l && r) {
            if (l->val < r->val) {
                cur->next = l;
                l = l->next;
            } else {
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
        }
        cur->next = l ? l : r;
        cur = dummy->next;
        delete dummy;
        return cur;
    }
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *l = nullptr, *r = nullptr;
        r = middleNode(head);
        l = sortList(head);
        r = sortList(r);
        return merge(l, r);
    }
};

class Solution37 {
public:
    ListNode *split(ListNode *head, int step) {
        ListNode *cur = head;
        for (int i = 0; i < step - 1 && cur; ++i) cur = cur->next;
        if (!cur || !cur->next) return nullptr;
        ListNode *next_head = cur->next;
        cur->next = nullptr;
        return next_head;
    }
    ListNode *merge(ListNode *l, ListNode *r, ListNode *head) {
        ListNode *cur = head;
        while (l && r) {
            if (l->val < r->val) {
                cur->next = l;
                l = l->next;
            } else {
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
        }
        cur->next = l ? l : r;
        while (cur->next) cur = cur->next;
        return cur;
    }
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        int len = 0;
        ListNode *cur = head;
        while (cur) {
            ++len;
            cur = cur->next;
        }
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *l = nullptr, *r = nullptr, *tail = nullptr;
        for (int step = 1; step < len; step <<= 1) {
            cur = dummy->next;
            tail = dummy;
            while (cur) {
                l = cur;
                r = split(l, step);
                cur = split(r, step);
                tail = merge(l, r, tail);
            }
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};

class Solution38 {
public:
    ListNode *mergeTwoLists(ListNode *l, ListNode *r) {
        ListNode dummy;
        ListNode *cur = &dummy;
        while (l && r) {
            if (l->val < r->val) {
                cur->next = l;
                l = l->next;
            } else {
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
        }
        cur->next = l ? l : r;
        return dummy.next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists, int i, int j) {
        int m = j - i;
        if (m == 0) return lists[i];
        ListNode *l = mergeKLists(lists, i, i + m / 2);
        ListNode *r = mergeKLists(lists, i + m / 2 + 1, j);
        return mergeTwoLists(l, r);
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;
        return mergeKLists(lists, 0, lists.size() - 1);
    }
};


class Solution39 {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int len = nums.size();
        vector<int> pre(len, 1);
        for (int i = 1; i < len; ++i) pre[i] = pre[i - 1] * nums[i - 1];
        vector<int> suf(len, 1);
        for (int i = len - 2; i >= 0; --i) suf[i] = suf[i + 1] * nums[i + 1];
        vector<int> ans;
        for (int i = 0; i < len; ++i) ans.push_back(pre[i] * suf[i]);
        return ans;
    }
};

class Solution40 {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int len = nums.size();
        vector<int> suf(len, 1);
        for (int i = len - 2; i >= 0; --i) suf[i] = suf[i + 1] * nums[i + 1];
        int pre = 1;
        for (int i = 0; i < len; ++i) {
            suf[i] *= pre;
            pre *= nums[i];
        }
        return suf;
    }
};

class Solution41 {
public:
    const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m * n);
        int i = 0, j = 0, di = 0;
        for (int k = 0; k < m * n; ++k) {
            ans[k] = matrix[i][j];
            matrix[i][j] = INT_MIN;
            int x = i + dir[di][0];
            int y = j + dir[di][1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == INT_MIN) {
                di = (di + 1) % 4;
            }
            i += dir[di][0], j += dir[di][1];
        }
        return ans;
    }
};

class Solution42 {
public:
    const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int len = m * n;
        vector<int> ans;
        int i = 0, j = -1;
        for (int di = 0; ans.size() < len; di = (di + 1) % 4) {
            for (int k = 0; k < n; ++k) {
                i += dir[di][0], j += dir[di][1];
                ans.push_back(matrix[i][j]);
            }
            --m;
            swap(n, m);
        }
        return ans;
    }
};

class Solution43 {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                     vector<int> &nums4) {
        unordered_map<int, int> cnt;
        for (int i : nums1) {
            for (int j : nums2) ++cnt[i + j];
        }
        int ans = 0;
        for (int k : nums3) {
            for (int l : nums4) ans += cnt[-k - l];
        }
        return ans;
    }
};

class Solution44 {
public:
    int maxArea(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            if (height[l] <= height[r]) ++l;
            else --r;
        }
        return ans;
    }
};

class Solution45 {
public:
    string minWindow(string s, string t) {
        int cnt[128]{};
        int counter = 0;
        for (char c : t) {
            if (cnt[c] == 0) ++counter;
            ++cnt[c];
        }
        int len = s.size();
        int ans_left = -1, ans_right = len - 1;
        int left = 0;
        for (int right = 0; right < len; ++right) {
            --cnt[s[right]];
            if (cnt[s[right]] == 0) --counter;
            while (counter == 0) {
                if (right - left < ans_right - ans_left) {
                    ans_left = left;
                    ans_right = right;
                }
                if (cnt[s[left]] == 0) ++counter;
                ++cnt[s[left]];
                ++left;
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};

class Solution46 {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int len = nums.size();
        vector<int> ans(len - k + 1);
        deque<int> q;
        for (int i = 0; i < len; ++i) {
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            int left = i - k + 1;
            if (q.front() < left) q.pop_front();
            if (left >= 0) ans[left] = nums[q.front()];
        }
        return ans;
    }
};


class Solution47 {
public:
    void gameOfLife(vector<vector<int>> &board) {
        int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
        int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int curX = 0, curY = 0, live = 0;
                for (int k = 0; k < 8; ++k) {
                    curX = i + dx[k], curY = j + dy[k];
                    if (curX < 0 || curX >= rows || curY < 0 || curY >= cols) continue;
                    if (board[curX][curY] == 1 || board[curX][curY] == 2) ++live;
                }
                if (board[i][j] == 0) {
                    if (live == 3) board[i][j] = -1;
                } else {
                    if (live < 2 || live > 3) board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 2) board[i][j] = 0;
                if (board[i][j] == -1) board[i][j] = 1;
            }
        }
    }
};

class Solution48 {
public:
    int firstMissingPositive(vector<int> &nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            while (nums[i] >= 1 && nums[i] <= len &&
                   nums[i] != nums[nums[i] - 1]) {
                int j = nums[i] - 1;
                swap(nums[i], nums[j]);
            }
        }
        for (int i = 0; i < len; ++i) {
            if (nums[i] - 1 != i) return i + 1;
        }
        return len + 1;
    }
};


class Solution49 {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (int n : s) {
            if (s.count(n - 1)) continue;
            int next = n + 1;
            while (s.count(next)) ++next;
            ans = max(ans, next - n);
            if (ans * 2 >= s.size()) break;
        }
        return ans;
    }
};

// 并查集
class UF {
private:
    vector<int> id;
    vector<int> size;

public:
    UF(int len) {
        for (int i = 0; i < len; ++i) {
            id.push_back(i);
            size.push_back(1);
        }
    }
    int find(int x) {
        if (id[x] != x) id[x] = find(id[x]);
        return id[x];
    }
    void unionpq(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) return;
        id[pRoot] = qRoot;
        size[qRoot] += size[pRoot];
    }
    int getMax() {
        int ans = 0;
        for (int i = 0; i < id.size(); ++i) {
            if (i == id[i]) ans = max(ans, size[i]);
        }
        return ans;
    }
};
class Solution50 {
  public:
    int longestConsecutive(vector<int> &nums) {
        int len = nums.size();
        unordered_map<int, int> m;
        UF uf(len);
        for (int i = 0; i < len; ++i) {
            if (m.count(nums[i])) continue;
            if (m.count(nums[i] - 1)) uf.unionpq(i, m[nums[i] - 1]);
            if (m.count(nums[i] + 1)) uf.unionpq(i, m[nums[i] + 1]);
            m[nums[i]] = i;
        }
        return uf.getMax();
    }
};

class Solution51 {
public:
    int findDuplicate(vector<int> &nums) {
        int len = nums.size();
        int lo = 1, hi = len - 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            int cnt = 0;
            for (int n : nums) {
                if (n <= mi) ++cnt;
            }
            cnt <= mi ? lo = mi + 1 : hi = mi;
        }
        return lo;
    }
};

class Solution52 {
public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (fast == slow) break;
        }
        int head = 0;
        while (head != slow) {
            head = nums[head];
            slow = nums[slow];
        }
        return slow;
    }
};

class Solution53 {
public:
    int calculate(string s) {
        stack<int> st;
        int len = s.size();
        int num = 0;
        char preOp = '+';
        for (int i = 0; i < len; ++i) {
            if (isdigit(s[i])) num = num * 10 + s[i] - '0';
            if (!isdigit(s[i]) && s[i] != ' ' || i == len - 1) {
                switch (preOp) {
                case '+':
                    st.push(num);
                    break;
                case '-':
                    st.push(-num);
                    break;
                case '*':
                    st.top() *= num;
                    break;
                case '/':
                    st.top() /= num;
                    break;
                }
                preOp = s[i];
                num = 0;
            }
        }
        while (!st.empty()) {
            num += st.top();
            st.pop();
        }
        return num;
    }
};

class Solution54 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(),
             [](vector<int> &v1, const vector<int> &v2) {
                 return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
             });
        int len = people.size();
        vector<vector<int>> ans;
        for (int i = 0; i < len; ++i) {
            if (people[i][1] >= i) ans.push_back(people[i]);
            else ans.insert(ans.begin() + people[i][1], people[i]);
        }
        return ans;
    }
};

class Solution55 {
public:
    vector<int> memoLeft;
    vector<int> memoRight;
    int getLeftMax(const vector<int> &height, int idx) {
        if (idx < 0) return 0;
        if (memoLeft[idx] != -1) return memoLeft[idx];
        return memoLeft[idx] = max(getLeftMax(height, idx - 1), height[idx]);
    }
    int getRightMax(const vector<int> &height, int idx) {
        if (idx >= height.size()) return 0;
        if (memoRight[idx] != -1) return memoRight[idx];
        return memoRight[idx] = max(getRightMax(height, idx + 1), height[idx]);
    }
    int trap(vector<int> &height) {
        int len = height.size();
        memoLeft.resize(len, -1);
        memoRight.resize(len, -1);
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            ans += min(getLeftMax(height, i), getRightMax(height, i)) - height[i];
        }
        return ans;
    }
};

class Solution56 {
public:
    int trap(vector<int> &height) {
        int ans = 0, leftMax = 0, rightMax = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            ans += leftMax < rightMax ? leftMax - height[left++]
                                      : rightMax - height[right--];
        }
        return ans;
    }
};

class Solution57 {
public:
    int trap(vector<int> &height) {
        int ans = 0;
        stack<int> stk;
        int len = height.size();
        for (int i = 0; i < len; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int left = stk.top();
                int curWidth = i - left - 1;
                int curHeight = min(height[left], height[i]) - height[top];
                ans += curWidth * curHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};

class Solution58 {
public:
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(-1);
        stack<int> stk;
        stk.push(-1);
        int len = heights.size(), ans = 0;
        for (int right = 0; right < len; ++right) {
            int h = heights[right];
            while (stk.size() > 1 && heights[stk.top()] >= h) {
                int i = stk.top();
                stk.pop();
                int left = stk.top();
                ans = max(ans, heights[i] * (right - left - 1));
            }
            stk.push(right);
        }
        return ans;
    }
};


class Solution59 {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<vector<int>> ans;
        vector<vector<int>> ps;
        for (vector<int> v : buildings) {
            int l = v[0], r = v[1], h = v[2];
            ps.push_back({l, h, -1});
            ps.push_back({r, h, 1});
        }
        sort(ps.begin(), ps.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 if (a[0] != b[0]) return a[0] < b[0];
                 if (a[2] != b[2]) return a[2] < b[2];
                 if (a[2] == -1) return a[1] > b[1];
                 else return a[1] < b[1];
             });
        unordered_map<int, int> m;
        priority_queue<int> pq;
        int pre = 0;
        pq.push(pre);
        for (vector<int> p : ps) {
            int point = p[0], height = p[1], flag = p[2];
            if (flag == -1) pq.push(height);
            else ++m[height];
            while (!pq.empty()) {
                int h = pq.top();
                if (m.count(h)) {
                    if (m[h] == 1) m.erase(h);
                    else --m[h];
                    pq.pop();
                } else {
                    break;
                }
            }
            int cur = pq.top();
            if (cur != pre) {
                vector<int> v{point, cur};
                ans.push_back(v);
                pre = cur;
            }
        }
        return ans;
    }
};

class Solution60 {
public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        if (nums[0] == 0) return "0";
        string res;
        for (const int &n : nums) res += to_string(n);
        return res;
    }
};

class Solution61 {
public:
    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
    int maxPoints(vector<vector<int>> &points) {
        int len = points.size();
        if (len <= 2) return len;
        int res = 0;
        for (int i = 0; i < len; ++i) {
            if (res >= len - i || res > len / 2) break;
            unordered_map<int, int> m;
            for (int j = i + 1; j < len; ++j) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                if (dx == 0) {
                    dy = 1;
                } else if (dy == 0) {
                    dx = 1;
                } else {
                    if (dy < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                    int gcdXY = gcd(abs(dx), abs(dy));
                    dx /= gcdXY, dy /= gcdXY;
                }
                ++m[(2 * 1E4 + 1) * dx + dy];
            }
            int maxn = 0;
            for (const auto &p : m) maxn = max(maxn, p.second + 1);
            res = max(res, maxn);
        }
        return res;
    }
};

