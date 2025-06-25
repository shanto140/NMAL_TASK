
#include <bits/stdc++.h>
using namespace std;

#define dl double

dl f(dl x) { 
    return x*x*x - x - 2;
 }


pair<dl,dl> autoBracket(dl x0){

    dl step = 0.1 , limit = 1e9;
    int max_step = 60;

    dl a = x0, fa = f(a);


    for (int k = 0; k < max_step; ++k){
        dl b  = x0 + step * pow(1.0, (dl)k);     
        if (abs(f(b)) > limit) break;
        dl fb = f(b);
        if (fa * fb < 0) return {a, b};
    }

   
    for (int k = 0; k < max_step; ++k){
        dl a2 = x0 - step * pow(1.0, (dl)k);
        if (abs(f(a2)) > limit) break;
        dl fa2 = f(a2);
        if (fa2 * fa < 0) return {a2, a};
    }

}

dl bisection(dl a, dl b, int &it){

    dl error = 1e-6 ;

    dl fa = f(a), fb = f(b);

    for (it = 0; (b - a) / 2 > error; ++it){

        dl m  = (a + b) / 2;

        dl fm = f(m);
        if (fm == 0) return m;

        if(fa * fm < 0){
            b = m, fb = fm ;
         }
         else {
            a = m, fa = fm;
         }
    }
    return (a + b) / 2;
}

int main()
{
    dl x0 = 1.5;   
    auto [a, b] = autoBracket(x0);      

    
    int it=0;
    dl root = bisection(a, b, it);
    cout << "root        : " << root << "\n";
    cout << "Iterations  : " << it   << "\n";
}
