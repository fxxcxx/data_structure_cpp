#include <cstdio>
//findMaxValue 함수를 정의해라.
int findMaxValue(int arr[], int size)
{
	int i;
	int maxVal  = 0;
	for(i=0;i<10;i++){
		if(arr[i]>maxVal ){
			maxVal  = arr[i];
		}
	}
	return maxVal ;
}

int main()
{
	int arr[10] = {3, 24, 82, 12, 34, 7, 53, 17, 26, 51};
//함수 호출 부분
	int maxVal = findMaxValue(arr,10);
	printf( "배열의 최대 값 = %d\n", maxVal );
	
	return 0;
}