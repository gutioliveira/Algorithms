#include <bits/stdc++.h>
using namespace std;

int main() {

	int T;

	cin >> T;
	
	while(T--){

		int begin = 0, end;

		cin >> end;

		vector< pair<pair<int,int>,int> > segs;

		int l, r;

		while( cin >> l >> r, l || r ) {

			int swaped = 0;

			if(l > r) {

				swap(l,r);
				swaped = 1;
			}

			segs.push_back(make_pair(make_pair(l,r),swaped));
		}

		sort(segs.begin(), segs.end());
		
		vector< pair<pair<int,int>,int> > out;

		while(begin < end) {

			int cur_begin = 0, cur_end = 0, swaped = 0;

			for( auto seg : segs ) {

				if( seg.first.first > begin ) 
					break;
				if( seg.first.second > cur_end ){

					cur_begin = seg.first.first;
					cur_end = seg.first.second;
					swaped = seg.second;
				}
			}

			begin = cur_end;

			out.push_back(make_pair(make_pair(cur_begin,cur_end),swaped));

			if(!cur_begin && !cur_end) 
				break;

		}

		if(!out.back().first.first && !out.back().first.second)
			cout << "0" << endl;
		else{

			cout << out.size() << endl;

			for(auto x : out){
				if( x.second ) 
					cout << x.first.second << " " << x.first.first << endl;
				else 
					cout << x.first.first << " " << x.first.second << endl;
			}

		}

		if(T) 
			cout << endl;
	}	
	
	return 0;
}
