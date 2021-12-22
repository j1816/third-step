#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double sum(int score[], int n){
	double sum = 0.0;
	for (int i = 0;i<n;i++){
		sum += score[i];
	}
	return sum;
}

double avg(int score[], int n){
	return sum(score,n)/ n;
}

double dev(int score[],int n){//標準偏差
	double m = avg(score,n);
	double var = 0.0;
	for(int i=0;i<n;i++){
		var += (score[i]-m)*(score[i]-m);
	}
	return sqrt(var/n);
}

int compare(const void *n1,const void *n2){
	if(*(int *)n1 > *(int *)n2) return -1;
	else if(*(int *)n1 < *(int *)n2) return 1;
	else return 0;
}

int main(){
	int sci[20]= {65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70};
	int eng[20]={44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84};

	double dev_sci[20] = {0};//偏差値
	double dev_eng[20] = {0};
	for(int i=0;i<20;i++){
		dev_sci[i] = (sci[i]-avg(sci,20))/dev(sci,20)*10+50;
		dev_eng[i] = (eng[i]-avg(eng,20))/dev(eng,20)*10+50;

	}
	
	qsort(sci,20,sizeof(int),compare);
	qsort(eng,20,sizeof(int),compare);


        printf("理科の平均:%f, 標準偏差:%f,合計点%f\n", avg(sci,20),dev(sci,20),sum(sci,20));
	printf("英語の平均:%f, 標準偏差:%f,合計点%f\n", avg(eng,20),dev(eng,20),sum(eng,20));
	for(int i=0;i<20;i++){
		printf("%d人目偏差値｜英語：%f, 理科：%f\n",i,dev_eng[i],dev_sci[i]);
	}
	printf("点数の高い順に表示します。\n");
	for(int i=0;i<20;i++){
		printf("理科:%d, 英語:%d\n",sci[i],eng[i]);
	}

}
