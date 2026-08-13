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

       stack <double> st;
       for(int i = speed.size()-1; i >= 0; i--){
            double time = cars[i].second; 
        if(st.empty() || time > st.top()){
            st.push(time);
        }
       }
       return st.size();
    }
};
