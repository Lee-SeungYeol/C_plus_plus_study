#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<sstream>
#include<vector>

using namespace std;

vector<double *> readData(string path){// path라는 문자열을 입력받도록 함수 구현
    /*
    data.txt와 같은 파일 읽어옴
    */
    std::vector<double * >data; //숫자를 저장하기 위해 double 타입의 벡터 생성
    ifstream file(path,ios::in);// input file stream
    // 파일을 읽기 전용으로 열기
    if (!file.is_open()){
        cerr<<"Iris data file could not be read"<<endl;
        return data;
    }
    string str;
    while (std::getline(file,str)){ //파일에서 한줄 읽어오기
        std::stringstream ss(str);
        vector<string> tokens;
        double *d=new double[4];// 숫자 4개 저장
        double *dptr=d; //d에 대한 포인트 dptr생성
        double value;
        for (string s; ss>> value;){ //한줄 안의 숫자들 한개씩 읽기
            if (ss.peek()==',') ss.ignore(); // 숫자 사이에 쉼표가 있을때 무시하고 넘어가기
            *dptr++=value; // 배열 d에 값넣기
        }
        data.push_back(d); //배열 d를 data에 저장
    }
}