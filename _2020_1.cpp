#include <iostream>
#include <fstream>

using namespace std;

const int m1 = 30;
const int m2 = 31;
const int m3 = 31;

int start_days(int arr[]);
int end_days(int arr[]);

int main()
{
    int days[m1 + m2 + m3 + 1] = {0};
    ifstream duom("Duomenys.txt");
    ofstream rez("Rezultatai.txt");
    int n;
    duom >> n;
    for (int i = 0; i < n; i++)
    {
        int m_b, m_e, d_b, d_e;
        duom >> m_b;
        duom >> m_b >> d_b >> m_e >> d_e;
        
        int start = 0, end = 0;
        if (m_b == 6) { start = d_b; }
        else if (m_b == 7) { start = m1 + d_b; }
        else { start = m1 + m2 + d_b; }

        if (m_e == 6) { end = d_e; }
        else if (m_e == 7) { end = m1 + d_e; }
        else { end = m1 + m2 + d_e; }

        for (int j = start; j <= end; j++) { days[j]++; }
    }
    
    int start = start_days(days);
    int end = end_days(days);
    rez << days[start] << '\n';
    if (start > m1 + m2) { rez << 8 << ' ' << start - m1 - m2 << '\n'; }
    else if (start > m1) { rez << 7 << ' ' << start - m1 << '\n'; }
    else { rez << 6 << ' ' << start << '\n'; }

    if (end > m1 + m2) { rez << 8 << ' ' << end - m1 - m2 << '\n'; }
    else if (end > m1) { rez << 7 << ' ' << end - m1 << '\n'; }
    else { rez << 6 << ' ' << end << '\n'; }
    duom.close();
    rez.close();

    return 0;
}

int start_days(int arr[])
{
    int x=0, c=0;
    for (int i = 0; i < m1 + m2 + m3 + 1; i++)
    {
        if (arr[i] > x) { x = arr[i]; c = i; }
    }
    return c;
}

int end_days(int arr[])
{
    int x = 0, c = 0;
    for (int i = 0; i < m1 + m2 + m3 + 1; i++)
    {
        if (arr[i] >= x) { x = arr[i]; c = i; }
    }
    return c;
}
