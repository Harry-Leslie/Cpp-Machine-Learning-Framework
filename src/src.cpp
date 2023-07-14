# include "libraries.h"
# include "ArrayList.h"
# include "single_linear_regression.h"
#include "multiple_linear_regression.h"
# include "Matrix.h"

typedef vector<vector<long double>> m;

int main() {
    // Enable memory leak detection at program exit
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    m x = {
    {0, 0},
    {1, 1},
    {2, 2},
    };
    m y = { {0}, {1}, {2}, };


    Matrix m1(x);

    multiple_linear_regressor mlr(x, y);
    mlr.ridge_train(0.000000000000005);
    return 0;
}
