#include "../include/Q2_Sort_By_Distance.h"
#include <algorithm>


// const means we can not change it.
// & means the variable pass by reference -> we do not copy it, the operation is directly on the variable
// const & means we can not change the variable that pass by reference
void sort_points_by_distance(std::vector<std::array<double, 3>>& points){
    std::sort(points.begin(), points.end(), [] (auto& a, auto& b){
        return a[0] * a[0] + a[1] * a[1] + a[2] * a[2] < b[0] * b[0] + b[1] * b[1] + b[2] * b[2];
    });
}

