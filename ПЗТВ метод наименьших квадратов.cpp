#include <iostream>
using namespace std;

const int У = 8;		//коэффициент трения 
const int X = 9;		//качество обработанной поверхности 

int main()
{
    int n = 0;
    int n1 = 0;
    double my = 0;
    double mx = 0;
    double Dx = 0;
    double Kxy = 0;
    double a = 0;
    double b = 0;
    double t = 0;
    setlocale(LC_ALL, "Russian");
    system("color F0");				//экран белый, буквы черные
    double z[X][У] = {      0,  0.1,0.2,0.3,0.4,0.5,0.6,0.7,
                            1,  3,  6,  0,  0,  0,  0,  0,
                            2,  27, 108,42, 8,  2,  0,  0,
                            3,  5,  50, 56, 21, 5,  5,  0,
                            4,  1,  13, 32, 24, 15, 2,  0,
                            5,  0,  5,  5,  13, 13, 7,  3,
                            6,  0,  0,  1,  2,  11, 6,  2,
                            7,  0,  1,  0,  1,  0,  0,  3,
                            8,  0,  0,  0,  0,  0,  0,  2, };

    cout << "\tТАБУЛИРОВАНИЕ ДАННЫХ\n";
    for (int i = 0; i < X; i++)
    {    
        for (int j = 0; j < У; j++)       
            cout << z[i][j] << "\t";
        cout << "\n";
    }

   //подсчет n
    for (int i = 1; i < X; i++)
    {
        for (int j = 1; j < У; j++)
           n = n + z[i][j] ;
    }
    cout << "\n";
    cout << "n = " << n;
    cout << "\n";

    //матожилание х
    for (int i = 1; i < X; i++)
    {
        for (int j = 1; j < У; j++)
        {
            n1 = n1 + z[i][j];
            t = t + z[i][j] * z[0][j];
            mx = mx + z[i][j] * z[i][0];
        }
        cout << "m" << i << " = " << t / n1 << "\t";
        t = 0; n1 = 0;
    }
    cout << "\n";

    //матожилание у
    for (int i = 1; i < У; i++)
    {
        for (int j = 1; j < X; j++)
        {
            n1 = n1 + z[j][i];
            t = t + z[j][i] * z[j][0];
            my = my + z[j][i] * z[0][i];
        }
        cout << "m" << i << " = " << t / n1 << "\t";
        t = 0; n1 = 0;
    }
    cout << "\n";
    mx = mx / n;
    cout << "mx = " << mx;
    cout << "\n";
    my = my / n;
    cout << "my = " << my;
    cout << "\n";

    //дисперсия х
    for (int i = 1; i < X; i++)
    {
        for (int j = 1; j < У; j++)
            Dx = Dx + z[i][j] * (z[i][0] - mx) * (z[i][0] - mx);
    }
    Dx = Dx / n;
    cout << "Dx = " << Dx;
    cout << "\n";

    //дисперсия y
    for (int i = 1; i < X; i++)
    {
        for (int j = 1; j < У; j++)
            t = t + z[i][j] * (z[0][j] - my) * (z[0][j] - my);
    }
    t = t / n;
    cout << "Dy = " << t;
    cout << "\n";

    //кореляция
    for (int i = 1; i < X; i++)
    {
        for (int j = 1; j < У; j++)
            Kxy = Kxy + z[i][j] * (z[i][0] - mx) * (z[0][j] - my);
    }
    Kxy = Kxy / n;
    cout << "Kxy = " << Kxy;
    cout << "\n";
    cout << "\n";

    //коэфициенты
    a = Kxy / Dx;
    cout << "a = " << a;
    cout << "\n";
    b = my - a * mx;
    cout << "b = " << b;
    cout << "\n";
    cout << "\n";

    a = Kxy / t;
    cout << "a = " << a;
    cout << "\n";
    b = mx - a * my;
    cout << "b = " << b;
    cout << "\n";
}
