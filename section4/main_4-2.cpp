
#include<iostream>

class Point{
    int x, y;

    public:
        Point(int pos_x, int pos_y){
            x=pos_x;
            y=pos_y;
        }
        int getX() const {
            return x;
        }
        int getY() const {
            return y;
        }
};

class Geometry {
    public:
        Geometry(){
            num_points =0;
        }
        void AddPoint(const Point &point){
            point_array[num_points ++] = new Point(point.getX(), point.getY());
        }
        void PrintDistance();
        void PrintNumMeets();
        void PrintPoints();

    private:
        Point* point_array[100];
        int num_points;


};
void Geometry::PrintNumMeets(){
    int  num_line=num_points * (num_points-1)/2;
    float *slope = new float[num_line];
    

    int idx=0;
    for (int i=0;i<num_points;i++){
        int pos1_x=point_array[i]->getX();
        int pos1_y=point_array[i]->getY();
        
        for (int j =i+1;i<num_points; j++){
            int pos2_x = point_array[i]->getX();
            int pos2_y = point_array[i]->getY();

            slope[idx] = ((pos2_y-pos1_y)/(pos2_x-pos1_x));
            idx +=1;
        }
    }
    
    if (num_line != idx) std::cout<<"error"<<std::endl;

    int num_meets=0;
    
    for (int i =0 ;i<num_line;i++){
        for (int j=i+1;j<num_line;j++){
            if(slope[i] !=slope[j]) num_meets++;
        }
    }
    std::cout<<num_meets<<std::endl;

    delete[] slope;
}

void Geometry::PrintPoints(){
    for(int i=0;i<num_points;i++){
        std::cout<<"x : "<<point_array[i]->getX();
        std::cout<<", y : "<<point_array[i]->getY()<<std::endl;
    }
}

void Geometry::PrintDistance(){
    for(int i=0;i<num_points;i++){
        int pos1_x=point_array[i]->getX();
        int pos1_y=point_array[i]->getY();
        for (int j=i+1;j<num_points;j++){
            int pos2_x=point_array[j]->getX();
            int pos2_y=point_array[j]->getY();

            double distance=sqrt(pow(pos1_x-pos2_x,2)+pow(pos1_y-pos2_y,2));

            std::cout<<"Distance between pos"<<(i+1)<<"and pos"<<(j+1)<<" is "<<distance<<std::endl;
        }
    }
}

int main(){
    Point pos1(2,3);
    Point pos2(3,4);
    Point pos3(4,5);

    Geometry geometry;
    geometry.AddPoint(pos1);
    geometry.AddPoint(pos2);
    geometry.AddPoint(pos3);

    geometry.PrintPoints();
    geometry.PrintDistance();
    geometry.PrintNumMeets();



    

    return 0;
}