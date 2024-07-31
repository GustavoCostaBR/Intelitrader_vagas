#include <iostream>
#include <vector>

using namespace std;

int findMinimumDistance(const vector<int> & n, const vector<int> & n2) {
	int minimumDistance = INT32_MAX;
	for (int i = 0; i < n.size(); i++) {
		for (int j = 0; j < n2.size(); j++) {
			minimumDistance = minimumDistance < abs(n[i] - n2[j]) ? minimumDistance : abs(n[i] - n2[j]);
		}
	}
	return minimumDistance;

}



int main() {
	int array1[21] = {37, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	vector<int> v1(array1, array1 + sizeof(array1)/sizeof(array1[0]));
	int array2[20] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39};
	vector<int> v2(array2, array2 + sizeof(array2)/sizeof(array2[0]));




	cout << findMinimumDistance(v1, v2) << endl;

	return 0;
}