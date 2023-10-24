#include <iostream>
#include <map>
#include <algorithm>
#include <vector>


using namespace std;

int main()
{
	// Given vector v
	vector <int> v;
  int n,k;
  cin>>n>>k;

  for(int i=0;i<n;i++)
  {
    int a;
    cin>>a;
    v.push_back(a);
  }



  // created map to store the frequency of element
	// for every subarray
	map<int, int> Map;

	// To count the subarray array size
	// while traversing array
	int l = 0;

	// Traverse the array
	for (int i = 0; i < n; i++)
  {

		// Incrementing until we store the
		// frequency of first K elements
		l++;

		// Updating the count for current
		// elements
		Map[v[i]]++;

		// If subarray size is K, then
		// find the minimum and maximum
		// for each subarray
		if (l == k) {

			// Iterator points to end
			// of the Map
			auto itMax = Map.end();
			itMax--;

			// Iterator points to start of
			// the Map
			auto itMin = Map.begin();

			// Print the difference of minimum and maximum
			// elements of current sub-array
			cout << (itMax->first)-(itMin->first) << endl;

			// Decrements the frequency of
			// arr[i - K + 1]
			Map[v[i - k + 1]]--;

			// if arr[i - K + 1] is zero
			// remove from the map
			if (Map[v[i - k + 1]] == 0)
      {
				Map.erase(v[i - k + 1]);
			}

			l--;
		}
	}

	return 0;
}
