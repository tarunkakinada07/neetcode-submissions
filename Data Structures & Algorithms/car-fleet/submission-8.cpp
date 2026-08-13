class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       vector<pair< int, double>> cars (speed.size());
       for(int i = 0; i < speed.size(); i++){
        double time = (double) (target - position[i]) / (double) (speed[i]);
        pair < int, double > newpair = {position[i], time};
        cars[i] = newpair;
       }

       sort(cars.begin(), cars.end());

       int no_flees = 1;
       double least_time = cars.back().second;
       for(int i = speed.size()-2; i >= 0; i--){
        if(cars[i].second > least_time){
            no_flees++;
            least_time = cars[i].second;
        }
       } 
       return no_flees;
    }
};
