#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
class FoldPaper
{
public:
	vector<string> foldPaper(int n)
	{
		int len = pow(2,n) -1;
		vector<string> order(len);
		int left = 0, right = len-1, mid = (left+right)/2;
		order[mid] = "down";
		if(left < right)
		{
			func(left, right, order);
		}
			
		
		return order;	
		
	}
private:
	void func(int left, int right, vector<string> &order)
	{
		if(left < right)
		{
			int mid = (left+right)/2;
			int mid_left = (left+mid-1)/2;
			int mid_right = (mid+1+right)/2;
			order[mid_left] = "down";
			order[mid_right] = "up";
			func(left, mid-1, order);
			func(mid+1, right, order);	
		}
			
	}			
};

int main(void)
{
	vector<string> result;
	FoldPaper method;
	cout << "Input:";
	int n;
	cin >> n; 
	result = method.foldPaper(n);
	//cout<<result.size()<<endl;
	for(auto i:result)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
	
}
