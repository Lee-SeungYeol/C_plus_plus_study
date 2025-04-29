#include<iostream>
#include<ctime>

class Date{
    private:
        int year_;
        int month_;
        int day_;

    public:
        void SetDate(int year, int month, int date){
            year_=year;
            month_=month;
            day_=date;
            

        };
        void AddDay(int inc){
            day_+=inc;
            if ((month_ ==1) || month_ ==3 ||month_ ==5 ||month_ ==7 || month_ ==8 ||
            month_ ==10|| month_ ==12){
                if (day_>31){
                    day_ -=31;
                    month_+=1;
                    if (month_ >12)
                        month_=12;
                }
            }
            else if ((month_ ==4) || month_ ==6 ||month_ ==9 ||month_ ==11){
                if (day_>30){
                    day_ -=30;
                    month_+=1;
                }
            }
            else{
                if (day_>29){
                    day_ -=29;
                    month_+=1;
                }
            }
        };
        void AddMonth(int inc){
            month_ +=inc;
            if (month_>12)
                month_-=12;

        };
        void AddYear(int inc){
            year_ +=inc;

        };
        void ShowDate(){
            std::cout<<"현재 시간은  : "<<year_<<"년 "<<month_<<" 월 "<<day_<<"일 입니다"<<std::endl;
        };
};

int main(){

    struct tm* t;
    Date date;

    int month=3;
    int day=28;
    
    time_t current_time=time(NULL);
    t=localtime(&current_time);

    date.SetDate((t->tm_year+1900),month,day);
    date.AddDay(4);
    date.ShowDate();

}