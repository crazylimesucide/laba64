#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <Windows.h>

using namespace std;

void Create(int*& mas, const int size, const int Low, const int High)
{
    mas = new int[size];
    for (int i = 0; i < size; i++)
        mas[i] = (Low + rand() % (High - Low + 1));
}
void Print(int* mas, const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(4) << mas[i];
    cout << endl;
}
int Max(int* mas, const int size)
{
    int max = mas[0];

    for (int i = 1; i < size; i++)
    {
        if (max < mas[i])
        {
            max = mas[i];
        }

    }
    return max;
}
int Sum(int* mas, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        s += mas[i];
    return s;
}
int OstanDod(int* mas, const int size)
{
    for (int i = size - 1; i >= 0; i--)
        if (mas[i] > 0)
            return i;
}
void Zamina(int* mas, const int size, const int min, const int max)
{
    for (int i = size - 1; i >= 0; i--)
        if (abs(mas[i]) >= min && abs(mas[i]) <= max)
            mas[i] = 0;
}
int KilkZero(int* mas, const int size, const int min, const int max)
{
    int k = 0;
    for (int i = size - 1; i > -1; i--)
        if (abs(mas[i]) >= min && abs(mas[i]) <= max)
            k++;
    return k;
}

void Perestanovka(int* mas, const int size, const int min, const int max)
{
    int k = KilkZero(mas, size, min, max);
    int n = 0;
    for (int i = 0; i < size - n; i++)
    {
        if (mas[i] == 0)
        {
            for (int j = i + 1; j < size - k; j++)
            {
                mas[j - 1] = mas[j];
            }
            mas[size - 1] = 0;
            n++;
            if (mas[i] == 0)
                i--;
        }
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));
    int Low = -50;
    int High = 50;

    int n, a, b;

    cout << "Ê³ëüê³ñòü ÷èñåë = "; cin >> n;
    cout << "Ì³í³ìàëüíå çíà÷åííÿ = "; cin >> a;
    cout << "Ìàêñèìàëüíå çíà÷åííÿ = "; cin >> b;

    const int N = n;
    int* mas;

    Create(mas, N, Low, High);
    Print(mas, N);

    cout << endl;



    cout << "Ìàêñèìàëüíèé åëåìåíò ìàñèâó = " << Max(mas, N) << endl;
    cout << "Ñóìa åëåìåíò³â ìàñèâó = " << Sum(mas, OstanDod(mas, N)) << endl;

    Zamina(mas, N, a, b);
    Perestanovka(mas, N, a, b);
    Print(mas, N);


    return 0;
}