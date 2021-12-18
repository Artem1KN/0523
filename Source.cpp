#include <iostream>
#include <algorithm>
#include <math.h>
#include <functional>
using namespace std;

int main()
{
    int n, k, ans;
    cout << "chapters" << endl;
    cin >> n;
    cout << "pages" << endl;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "vol" << endl;
    cin >> k;
    cout << " * * * * * * * * * * *" << endl;
    cout << " " << endl;

    short max = *max_element(arr, arr + n);
    short* vol = new short[k] { 0 };

    function <bool(short, short)>
        foo = [&](short h, short g)
    {
        for (; h >= g && vol[g] + arr[h] <= max; --h)
        {
            vol[g] += arr[h];
        }
        return !g ? h >= g ? false : true : foo(h, g - 1);
        cout << vol[g] << endl;
    };

    for (; !foo(n - 1, k - 1); ++max) {
        fill(vol, vol + k, 0);
    }

    ans = *max_element(vol, vol + k);
    cout << ans;

    return 0;
}