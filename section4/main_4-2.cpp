//아직 마무리하지 못함 ㅠㅠ

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
        void PrintDistanc();
        void PrintNumMeets();

    private:
        Point* point_array[100];
        int num_points;


};
void Geometry::PrintDistanc(){
    for(int i=0;i<num_points;i++){
        int pos1_x=point_array[i]->getX();
        int pos1_y=point_array[i]->getY();
        for (int j=i+1;j<num_points;j++){
            int pos2_x=point_array[j]->getX();
            int pos2_y=point_array[j]->getY();

            double distance=sqrt(pow(pos1_x-pos2_x,2)+pow(pos1_y-pos2_y,2));

            std::cout<<"Distance between pos"<<(i+1)<<"and pos"<<(j+1)<<"is"<<distance<<std::endl;
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



    

    return 0;
}