#include<iostream>
using namespace std;

size_t merge(int *src, size_t left, size_t mid, size_t right){
	size_t l = 0, r = 0,
			cnt = 0;

	int *tmp = new int [right - left];
	while (left + l < mid && mid + r < right){
		if (src[left + l] <= src[mid + r])
			tmp[l + r] = src[left + l], l++;
		else{
			tmp[l + r] = src[mid + r], r++;
			cnt+=(mid - left - l);
		}
	}
	while (left + l <mid){
		tmp[l + r] = src[left + l], l++;
	}
	while (mid + r < right){
		tmp[l + r] = src[mid + r], r++;
	}
	for(int i = 0; i < l + r; i++)
		src[left + i] = tmp[i];

	delete[] tmp;
	return cnt;
}


size_t mergeSort(int *src, size_t left, size_t right){
	if(left + 1 >= right)
		return 0;
	size_t mid = (left + right) / 2,	
			cnt = 0;
	cnt += mergeSort(src,left, mid) + mergeSort(src, mid, right);;
	cnt += merge(src, left, mid, right);
	return cnt;
}

int main(){
	int n, t;
	
	cin>>n;
	int *a = new int[n];
	for (size_t i = 0; i < n; i++){
		cin>>a[i];
	};
	cout<<mergeSort(a, 0, n);
	return 0;
}
