class ParkingSystem {
protected:
    vector<int> park = vector (3, 0);
public:
    ParkingSystem(int big, int medium, int small) {
        park [0] = big;
        park [1] = medium;
        park [2] = small;
    }
    
    bool addCar(int carType) {
        if (park [carType - 1] == 0)
            return false;
        // else
        park [carType - 1] -= 1;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

