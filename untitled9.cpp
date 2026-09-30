#include<bits/stdc++.h>
using namespace std;

int main()
{
	string op;
	vector<string> opo;      // 按顺序存所有操作名
	vector<int> num;         // 和 opo 下标对齐，NUM 的参数放这里
	
	bool inputBad = false;
	while(cin >> op && op != "END"){
		if(op == "NUM"){
			int x;
			if(!(cin >> x)){ inputBad = true; break; }
			opo.push_back("NUM");
			num.push_back(x);
		}
		else{
			opo.push_back(op);
			num.push_back(0);   // 占位
		}
	}
	
	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		
		if(inputBad || abs(x) > 1000000000){
			cout << "ERROR" << endl;
			continue;
		}
		
		stack<int> st;
		st.push(x);
		bool bad = false;
		
		for(int i = 0; i < (int)opo.size(); i++){
			string &c = opo[i];
			
			if(c == "NUM"){
				if(abs(num[i]) > 1000000000){ bad = true; break; }
				st.push(num[i]);
			}
			else if(c == "POP"){
				if(st.empty()){ bad = true; break; }
				st.pop();
			}
			else if(c == "INV"){
				if(st.empty()){ bad = true; break; }
				int t = st.top(); st.pop();
				t = -t;
				if(abs(t) > 1000000000){ bad = true; break; }
				st.push(t);
			}
			else if(c == "DUP"){
				if(st.empty()){ bad = true; break; }
				st.push(st.top());
			}
			else if(c == "SWP"){
				if(st.size() < 2){ bad = true; break; }
				int a = st.top(); st.pop();
				int b = st.top(); st.pop();
				st.push(a);
				st.push(b);
			}
			else if(c == "ADD"){
				if(st.size() < 2){ bad = true; break; }
				int a = st.top(); st.pop();
				int b = st.top(); st.pop();
				int r = b + a;
				if(abs(r) > 1000000000){ bad = true; break; }
				st.push(r);
			}
			else if(c == "SUB"){
				if(st.size() < 2){ bad = true; break; }
				int a = st.top(); st.pop();   // 第一个（栈顶）
				int b = st.top(); st.pop();   // 第二个
				int r = b - a;                // 第二个减第一个
				if(abs(r) > 1000000000){ bad = true; break; }
				st.push(r);
			}
			else if(c == "MUL"){
				if(st.size() < 2){ bad = true; break; }
				int a = st.top(); st.pop();
				int b = st.top(); st.pop();
				long long r = 1LL * b * a;    // 防溢出
				if(llabs(r) > 1000000000){ bad = true; break; }
				st.push((int)r);
			}
			else if(c == "DIV"){
				if(st.size() < 2){ bad = true; break; }
				int a = st.top(); st.pop();
				int b = st.top(); st.pop();
				if(a == 0){ bad = true; break; }   // 除数不能为 0
				int r = b / a;                     // 第二个除以第一个
				if(abs(r) > 1000000000){ bad = true; break; }
				st.push(r);
			}
			else if(c == "MOD"){
				if(st.size() < 2){ bad = true; break; }
				int a = st.top(); st.pop();
				int b = st.top(); st.pop();
				if(a == 0){ bad = true; break; }
				int r = b % a;
				if(abs(r) > 1000000000){ bad = true; break; }
				st.push(r);
			}
			else{
				bad = true; break;
			}
		}
		
		if(bad || st.size() != 1) cout << "ERROR" << endl;
		else cout << st.top() << endl;
	}
	
	return 0;
}
