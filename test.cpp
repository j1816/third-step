#include <stdio.h>
#include <math.h>

int sum(int []);
double dev(int []);

int main(){
    int science[20] = {65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70};
    int english[20] = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84};

    printf("理科\n");
    printf("合計点：%d,平均点：%.2f,標準偏差：%.2f\n",sum(science),sum(science)/20.0,dev(science));
    printf("英語\n");
    printf("合計点：%d,平均点：%.2f,標準偏差：%.2f\n",sum(english),sum(english)/20.0,dev(english));

}

int sum(int arr[]){
    int i;
    int sum = 0;
    for(i=0;i<20;i++){
	sum += arr[i];
    }
    return sum;
}

double dev(int arr[]){
    int i;
    double ave = sum(arr) / 20.0;
    double var = 0;
    for(i=0;i<20;i++){
	var += (arr[i]-ave)*(arr[i]-ave);
    }
    return sqrt(var/20);
}
