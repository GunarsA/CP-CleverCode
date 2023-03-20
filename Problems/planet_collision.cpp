#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

double get_collision_time(double distance_in_degrees,
    double closing_speed, double radius)
{
    if(!closing_speed)
    {
        return -1;
    }
    double distance_in_percents = distance_in_degrees / 360;
    double distance_in_units = radius * 2 * M_PI * distance_in_percents;
    double closing_time = distance_in_units / closing_speed;
    return closing_time;
}

int main()
{
    int N, R;
    cin >> N >> R;
    vector< pair<int, int> > Planets(N);
    for(auto &i : Planets)
    {
        cin >> i.first >> i.second;
    }

    double smallest_catch_up_time = 1.79769e+308;
    for(int i = 0; i < N; ++i)
    {
        for(int j = i + 1; j < N; ++j)
        {
            pair<int,int> faster_planet = Planets[i];
            pair<int,int> slower_planet = Planets[j];
            if(Planets[i].second < Planets[j].second)
            {
                faster_planet = Planets[j];
                slower_planet = Planets[i];
            }
            int closing_speed = faster_planet.second - slower_planet.second;
            int closing_distance = slower_planet.first - faster_planet.first;
            if(closing_distance < 0)
            {
                closing_distance += 360;
            }
            double temp
                = get_collision_time(closing_distance, closing_speed, R);
            if(temp != -1)
            {
                smallest_catch_up_time = min(smallest_catch_up_time, temp);
            }
        }
    }

    if(smallest_catch_up_time == 1.79769e+308)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << fixed << setprecision(5) << smallest_catch_up_time << endl;
    }

    return 0;
}