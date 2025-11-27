//double newton(double x0, double a3, double a2, double epsilon){
//    int k = 1;
//    double xk = iter_newton(x0, a3, a2, epsilon);
//    double f_xk = f(xk, a3, a2);
//
//    while (abs(f_xk) >= epsilon){
//        xk = iter_newton(xk, a3, a2, epsilon);
//        f_xk = f(xk, a3, a2);
//        k++;
//    }
//
//    return xk;
//}