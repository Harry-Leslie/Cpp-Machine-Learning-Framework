# include "libraries.h"
# include "ArrayList.h"
# include "slr.h"

int main() {
    // Enable memory leak detection at program exit
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    vector<double> x = { 5, 6, 8, 9};
    vector<double> y = { 1, 4, 6, 9};

    ArrayList x1(x);
    ArrayList y1(y);

    SimpleLinearRegression slr(x1, y1);
    slr.train();

    return 0;
}
