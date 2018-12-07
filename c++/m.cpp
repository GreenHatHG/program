#include <cstdio>
#include <algorithm>
using namespace std;
/*
 *A: 矩形1的左下角横坐标（矩形1左边横坐标）
 *B: 矩形1的左下角纵坐标（矩形1下边纵坐标）
 *C: 矩形1的右上角横坐标（矩形1右边横坐标）
 *D: 矩形1的右上角纵坐标（矩形1上边纵坐标）
 *E: 矩形2的左下角横坐标（矩形2左边横坐标）
 *F: 矩形2的左下角纵坐标（矩形2下边纵坐标）
 *G: 矩形2的右上角横坐标（矩形2右边横坐标）
 *H: 矩形2的右上角纵坐标（矩形2上边纵坐标）
 *return 交叉区域面积
 */
double computeArea(double A, double B, double C, double D, double E, double F, double G, double H) 
{        
        //内部交叉区域（如果有）的四个边界
        double innerLeft = A > E ? A : E;    //交叉区域左边
        double innerRight = C < G ? C : G;    //交叉区域右边
        double innerTop = D < H ? D : H;    //交叉区域上边
        double innerBottom = B > F ? B : F;    //交叉区域底边

        //计算内部交叉区域面积，要考虑两个矩形可能不相交的情况
        double innerWidth = innerTop > innerBottom ? (innerTop - innerBottom) : 0;
        double innerHeight = innerRight > innerLeft ? (innerRight - innerLeft) : 0;
        double innerArea = innerWidth * innerHeight;

        return innerArea;
}

int main()
{
    double A, B ,C ,D ,E, F, G, H;
    while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf", 
                &A, &B, &C, &D, &E, &F, &G, &H))
    {
        if(A > C)
            swap(A, C);
        if(B > D)
            swap(B, D);
        if(E > G)
            swap(E, G);
        if(F > H)
            swap(F, H);
        double ans = computeArea(A, B, C, D, E, F,G ,H);
        printf("%0.2lf", ans);
    }
    return 0;
}
