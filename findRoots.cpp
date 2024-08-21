#include <iostream>
#include <cmath>
using namespace std;


class rootFinder{
    public:
    rootFinder(double a, double b):
        lowerBound(a), upperBound(b){
            root = rootLoop();
        }
    double getRoot(){
        return root;
    }
    private:
     double rootLoop(){
        double a = lowerBound;
        double b = upperBound;
        double outputA, outputB, outputMiddle;
        double middle;
        int trash;
        
        while (true){
            outputA = function(a);
            outputB = function(b);
            if (outputA == 0 || abs(outputA) <= 3e-10)
                return a;
            else if(outputB == 0 || abs(outputB) <= 3e-10)
                return b;
            
            middle = (a+b)/2;
            outputMiddle = function(middle);
            
            if (outputMiddle > 0 && outputA < 0)
                b = middle;
            else if (outputMiddle > 0 && outputB < 0)
                a = middle;
            else if (outputMiddle < 0 && outputA > 0)
                b = middle;
            else if (outputMiddle < 0 && outputB > 0)
                a = middle;
            else if (outputMiddle == 0)
                a = middle;
        }
    }
    double function(double x){
        double f = 8 * pow(x,6) - 2 * pow(x,2)+9*x;
        return f;
    }
    double lowerBound, upperBound;
    double root;
    
};
int main(){
    rootFinder a = rootFinder(-2, -1);
    cout << a.getRoot();
    
    return 0;
}