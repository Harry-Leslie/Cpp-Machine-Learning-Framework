#include "Libraries.h"
#include "ArrayList.h"
#include "SimpleLinearRegression.h"
#include "MultipleLinearRegression.h"

typedef vector<vector<long double>> m;

int main() {
    // Enable memory leak detection at program exit
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    m x = {
    {0,0},
    {1,1},
        {2,2}
    };
    m y = { {0}, {1}, {2} };
    /* 
    * 
    * This example uses multiple linear regression 
    * which basically means that there are multiple
    * features 
    * 
    * so in this example y = b0 + b1X1 + b2X2
    * 
    * now in this example it should give us the answer
    * 
    * B0 = 0, B1 = 1, B2 = 1, or any vector which is parallel so B1 = 0.5 and B2 = 0.5 is also correct and is actually the output
    * but B0 is not equal to 0 if you run this 
    * 
    * but because there are colinearities there is an issue so i 
    * have added something called ridge regression which can handle these 
    * colinearities partly but we need something called lasso
    * to completely get rid of the need for these
    * 
    * 
    */


    Matrix m1(x);
    MultipleLinearRegression mlr(x, y);
    mlr.ridgeTrain(0.001);
    return 0;
}