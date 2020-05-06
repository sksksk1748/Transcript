#include <iostream>
#include <iomanip>
#include <algorithm> 
#include <cstdlib>
#include <string>

using namespace std;

struct student {
	char id[10];
	float ch;
	float en;
	float ma;
	float in;  
	float total;
	float average;
	int failed;
};

int cmp(const void *a, const void *b) {
	student *orderA = (student *)a;
	student *orderB = (student *)b;
  	return ( orderB->average - orderA->average); 
}

int main() {
	struct student score[]={
		{"B08030038", 66, 82, 44, 99, 291, 72.75, 1},
		{"B08030180", 43, 75, 56, 13, 187, 46.75, 3},
		{"B08030155", 21,  6, 72, 83, 182, 45.50, 2},
		{"B08030051", 19, 98, 98, 51, 266, 66.50, 2},
		{"B08030029", 81, 86, 18,  1, 186, 46.50, 2}
	};
	int n;
	char again; // loop again? y or n
	do{
	cout << "請輸入學生人數 : " ;
	cin >> n;
	cout << endl; 
	cout << " NO.       學號      國文   英文   數學   資訊   總和   平均   不及格" << endl;
	cout << "=====================================================================" << endl;
	for(int i=0;i<n;i++){
		cout << setw(3) << i+1 ;
		cout << setw(15) << score[i].id << setw(7) << score[i].ch << setw(7) << score[i].en;
		cout << setw(7) << score[i].ma << setw(7) << score[i].in << setw(7) << score[i].total; 
		cout << setw(7) << score[i].average << setw(7) << score[i].failed << endl;
	}
	float sum_ch,sum_en,sum_ma,sum_in,average_ch,average_en,average_ma,average_in,average_max,average_min;
	cout << "-------------------------------------------------------------" << endl;
	average_max = 0, average_min = 99999;
	for(int i=0;i<n;i++){
		sum_ch = sum_ch + score[i].ch;
		sum_en = sum_en + score[i].en;
		sum_ma = sum_ma + score[i].ma;
		sum_in = sum_in + score[i].in;
		if (average_max < score[i].average){
			average_max = score[i].average;
		}
		else
		{
			if(average_min > score[i].average){
				average_min = score[i].average;
			}
		}
	}
	average_ch = sum_ch / n;
	average_en = sum_en / n;
	average_ma = sum_ma / n;
	average_in = sum_in / n;
	cout << "    各科平均 :     " << setw(5) << average_ch << setw(6) << average_en << setw(6) << average_ma << setw(6) << average_in << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "平均最高分 : " << average_max << setw(5) << "      平均最低分 : " << average_min << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << endl << endl ;
	
	cout << "---------------------------排序------------------------------" << endl;
	cout << " NO.       學號      國文   英文   數學   資訊   總和   平均   不及格" << endl;
	cout << "=====================================================================" << endl;
	
	for(int i=0;i<n;i++){
		cout << setw(3) << i+1 ;
		qsort(score,5,sizeof(student),cmp);
      	cout << setw(15) << score[i].id << setw(7) << score[i].ch << setw(7) << score[i].en;
		cout << setw(7) << score[i].ma << setw(7) << score[i].in << setw(7) << score[i].total; 
		cout << setw(7) << score[i].average << setw(7) << score[i].failed << endl;
	}
	
	string student_number;
	cout << endl << endl ;
	cout << "請輸入學號 : " ;
	cin >> student_number;
	
	cout << student_number << endl;
	for(int i=0;i<n;i++){
		if(student_number == score[i].id){
			cout << "         學號      國文   英文   數學   資訊   總和   平均   不及格" << endl;
			cout << "=====================================================================" << endl;
			cout << setw(15) << score[i].id << setw(7) << score[i].ch << setw(7) << score[i].en;
			cout << setw(7) << score[i].ma << setw(7) << score[i].in << setw(7) << score[i].total; 
			cout << setw(7) << score[i].average << setw(7) << score[i].failed << endl;
			break; 
		}else{
			cout << "沒有這個學號的成績" << endl;
			break; 
		}
	}
	cout << endl <<"-------------------------------------------------------------" << endl;
	cout << "要在執行一次嗎?(y or n)" << endl;
	cin >> again;
	}while(again == 'y' || again == 'Y');
	
	return 0;
}