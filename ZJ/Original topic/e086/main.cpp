#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#define number first
#define name second
#define jazz ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

using namespace std;

struct data
{
    int scoore[21];
}stuData[100];
int n, m, tmp, maxi, maxii;
string correctAns[21], s;
map<int,string> subjectName, studentName;

int main()
{
    jazz;
    while(cin >> n >> m)
    {
        maxii = maxi = 0x80808080;
        subjectName.clear();
        studentName.clear();
        for(auto it : correctAns) it.clear();
        for(int i = 0; i < n; i++)
        {
            cin >> tmp;
            cin >> s;
            subjectName.emplace(tmp, s);
            cin >> correctAns[tmp];
        }
        for(int i = 0; i < m; i++)
        {
            cin >> tmp;
            cin >> s;
            studentName.emplace(tmp, s);
            maxi = max(maxi, tmp);
        }
        for(int i = 0, stu, suj, T, scoore; i < n * m; i++)
        {
            scoore = 0;
            cin >> stu >> suj >> s;
            T = correctAns[suj].size();
            for(int index = 0; index < T; index++)
            {
                if(index >= s.size()) break;
                if(correctAns[suj][index] == s[index])
                    scoore += 100 / T;
            }
            stuData[stu].scoore[suj] = scoore;
        }
        for(auto stu : studentName)
        {
            for(auto sub : subjectName)
            {
                cout << setw(3) << setfill('0') << stu.number << ',';
                cout << stu.name << ',';
                cout << setw(2) << setfill('0') << sub.number << ',';
                cout << sub.name << ',';
                cout << stuData[stu.number].scoore[sub.number]<<'\n';
            }
        }
    }
    return 0;
}
