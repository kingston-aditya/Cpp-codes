#include <iostream>

using namespace std;
//question 1b

int getMid(int s, int e)
{
  return s + (e -s)/2;
}

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
	// If segment of this node is a part of given range, then return
	// the sum of the segment
	if (qs <= ss && qe >= se)
		return st[si];

	// If segment of this node is outside the given range
	if (se < qs || ss > qe)
		return 0;

	// If a part of this segment overlaps with the given range
	int mid = getMid(ss, se);
	return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
		getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}


int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
	
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}


	int mid = getMid(ss, se);
	st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) +
			constructSTUtil(arr, mid+1, se, st, si*2+2);
	return st[si];
}

int getSum(int *st, int n, int qs, int qe)
{
	// Check for erroneous input values
	if (qs < 0 || qe > n-1 || qs > qe)
	{
		cout<<"Try again";
		return -1;
	}

	return getSumUtil(st, 0, n-1, qs, qe, 0);
}

int *constructST(int arr[], int n)
{
	int x = (int)(ceil(log2(n)));

	int max_size = 2*(int)pow(2, x) - 1;

	int *st = new int[max_size];

	constructSTUtil(arr, 0, n-1, st, 0);

	return st;
}

// Driver program to test above functions
int main()
{
	int arr[800];
  int n;
  int l,r;
  cin>>n;
  cin>>l>>r;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int c;
  c=r-l+1;

	// Build segment tree from given array
	int *st = constructST(arr, n);

	cout<<"Sum of values in given range = "<<getSum(st, n, l-1, r-1)/c<<endl;

	return 0;
}

