# include "libraries.h"
# include "ArrayList.h"
# include "slr.h"
# include "Matrix.h"

typedef vector<vector<double>> m;

int main() {
    // Enable memory leak detection at program exit
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    m x = {
        {1,2,1,44,12}, 
        {1,2,2,88,24}, 
        {1,2,3,132,33}
    };
    m y = { 
        {0,0,8}, 
        {0,0,0}
    };


    Matrix m1(x);
    m1.removedScaledVector();
    Matrix m2 = m1.copy();
    m1.transpose();
    m1.printMatrix();
    m2.printMatrix();
    m1.multiply(m2);
    m1.printMatrix();

    return 0;
}
