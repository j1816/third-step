#include <stdio.h>
#include <math.h>

int sum(int []);
double standard_deviation(int []);
int deviation(int,double,double);

int main(){
    int i;
    int science[20] = {65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70};
    int english[20] = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84};
    double s_ave,e_ave;
    double s_sta_dev,e_sta_dev;

    s_ave = sum(science)/20.0;
    e_ave = sum(english)/20.0;
    s_sta_dev = standard_deviation(science);
    e_sta_dev = standard_deviation(english);

    printf("理科\n");
    printf("合計点：%d,平均点：%.2f,標準偏差：%.2f\n",sum(science),s_ave,s_sta_dev);
    printf("英語\n");
    printf("合計点：%d,平均点：%.2f,標準偏差：%.2f\n",sum(english),e_ave,e_sta_dev);

    for(i=0;i<20;i++){
	printf("学生%2d：理科=>%d，英語=>%d\n",i+1,deviation(science[i],s_ave,s_sta_dev),deviation(english[i],e_ave,e_sta_dev));
    }
}

int sum(int arr[]){
    int i;
    int sum = 0;
    for(i=0;i<20;i++){
	sum += arr[i];
    }
    return sum;
}

double standard_deviation(int arr[]){
    int i;
    double ave = sum(arr) / 20.0;
    double var = 0;
    for(i=0;i<20;i++){
	var += (arr[i]-ave)*(arr[i]-ave);
    }
    return sqrt(var/20);
}

int deviation(int score,double ave,double sta_dev){
    return (score - ave) / sta_dev * 10 + 50;
}
