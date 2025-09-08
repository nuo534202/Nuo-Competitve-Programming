#include <bits/stdc++.h>
using namespace std;

struct Problem {
	int id, time;
	char status;
};

bool cmp(const Problem& x, const Problem& y) {
	return x.time < y.time;
}

struct Rank {
	int num, time;
	bool operator< (const Rank& r) const {
		if (r.num == num) return time < r.time;
		return num > r.num;
	}
	bool operator== (const Rank& r) const {
		return num == r.num && time == r.time;
	}
};

void solve() {
	int n;
	cin >> n;
	unordered_map<string, vector<Problem>> submit;
	vector<string> team, champ;
	for (int i = 1; i <= n; i++) {
		string name, status; char pid; int time;
		cin >> name >> pid >> time >> status;
		submit[name].push_back((Problem){ pid - 'A', time, status[0] });
		team.push_back(name);
	}
	sort(team.begin(), team.end());
	team.erase(unique(team.begin(), team.end()), team.end());
	unordered_map<string, Rank> finMax, finMin;
	multiset<Rank> rank;
	for (const string& name : team) {
		sort(submit[name].begin(), submit[name].end(), cmp);
		vector<int> isAC(26, 0), maxR(26, 0), minR(26, 0);
		for (const Problem& p : submit[name]) {
			if (!isAC[p.id]) {
				if (p.status == 'A') {
					isAC[p.id] = 1;
					maxR[p.id] += p.time, minR[p.id] += p.time;
				}
				if (p.status == 'U') {
					isAC[p.id] = 2;
					maxR[p.id] += p.time;
				}
				if (p.status == 'R')
					maxR[p.id] += 20, minR[p.id] += 20;
			}
		}
		int maxNum = 0, maxTime = 0, minNum = 0, minTime = 0;
		for (int i = 0; i < 26; i++) {
			if (isAC[i]) {
				maxNum++, maxTime += maxR[i];
				if (isAC[i] == 1) minNum++, minTime += minR[i];
			}
		}
		finMax[name] = (Rank){ maxNum, maxTime };
		finMin[name] = (Rank){ minNum, minTime };
		rank.insert((Rank){ minNum, minTime });
	}
	for (const string& name : team) {
		rank.erase(rank.find(finMin[name]));
		rank.insert(finMax[name]);
		if (finMax[name] == *rank.begin()) champ.push_back(name);
		rank.erase(rank.find(finMax[name]));
		rank.insert(finMin[name]);
	}
	for (int i = 0; i < (int)champ.size(); i++) {
		cout << champ[i];
		if (i < (int)champ.size() - 1) cout << " ";
		else cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
