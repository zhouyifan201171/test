#include <iostream>
#include <vector>
using namespace std;
class Solver{
    public:
        int MaximumArriveAtSameTime(vector<double> &speed, vector<double>& location, double destination);
};

int Solver::MaximumArriveAtSameTime(vector<double> &speed, vector<double>& location, double destination)
{
    int size = speed.size();
    vector<double> time_to_des(size);
    for(int i = size-1; i >= 0; i--){
        double dis_to_destination = destination - location.at(i) ;
        time_to_des.at(i) = dis_to_destination / speed.at(i);
    }

    int max_car_num = 1, temp_max_car_num = 1;
    for(int i = 0; i < size-1; i++){
        temp_max_car_num = 1;
        for(int j=0; j<size-1; j++){
            if(location.at(j) < location.at(i)){
                if(time_to_des.at(j) < time_to_des.at(i))
                    temp_max_car_num++;
            }
        }
        max_car_num = max_car_num > temp_max_car_num?max_car_num:temp_max_car_num;
    }
    return max_car_num;
}

int main()
{
    int speed_count;
    cin >> speed_count;
    vector<double> speed(speed_count);
    for(int i=0; i<speed_count;i++){
        double speed_item;
        cin >> speed[i];
    }
    int location_count = speed_count;
    vector<double> location(location_count);
    for(int i=0;i<location_count;i++){
        double location_item;
        cin >>location[i];
    }
    double destination;
    cin >>destination;
    Solver solver;
    int res = solver.MaximumArriveAtSameTime(speed, location, destination);
    std::cout << res << "\n";
    return 0;
}
