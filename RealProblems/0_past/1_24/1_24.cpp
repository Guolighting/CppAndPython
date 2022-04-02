#include<bits/stdc++.h>
using namespace std;

int CalcDistance(int initFloor, const vector<pair<int, int>> &peopleInfo){
		int result{};
		int curIdx{};
		int nextIdx{};
		int minFloor{};
		int maxFloor{};
		int stopFloor = initFloor;
		while(curIdx < peopleInfo.size()){
			result += abs(stopFloor - peopleInfo[curIdx].first); // 求第一层
			bool isUp = peopleInfo[curIdx].second > peopleInfo[curIdx].first; //确定方向, 假定向上
			minFloor = peopleInfo[curIdx].first;	//from
			maxFloor = peopleInfo[curIdx].second;	//to

			for(nextIdx = curIdx + 1; nextIdx < peopleInfo.size(); ++nextIdx){

				// 确定下个也是向上
				if(isUp != (peopleInfo[nextIdx].second > peopleInfo[nextIdx].first)){
					break;
				}
				// 方向向上， 确定下个要上电梯的乘客， 在当前乘客的[from, to]之间
				if(isUp && peopleInfo[nextIdx].first <= peopleInfo[curIdx].first){
					break;
				}

				// 方向向下， 确定下个要上电梯的乘客， 在当前乘客的[from, to]之间
				if(!isUp && peopleInfo[nextIdx].first >= peopleInfo[curIdx].first){
					break;
				}
				// 更新电梯的最低值
				minFloor = peopleInfo[nextIdx].first < minFloor ? peopleInfo[nextIdx].first : minFloor;
				// 更新电梯的最高值
				maxFloor = peopleInfo[nextIdx].second > maxFloor ? peopleInfo[nextIdx].second : maxFloor;
				// 比较下个电梯
				curIdx = nextIdx;
			}

			curIdx = nextIdx;
			result += abs(maxFloor - minFloor);
			stopFloor = isUp ? maxFloor : minFloor;
		}

		return result;
	}
int main(){
	vector<pair<int, int>> peopleInfo{};
	peopleInfo.emplace_back(make_pair(60,80));
	peopleInfo.emplace_back(make_pair(70,90));
	peopleInfo.emplace_back(make_pair(90,80));

	cout<<CalcDistance(50, peopleInfo)<<endl;
	return 0;
} 