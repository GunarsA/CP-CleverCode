#include <stdio.h>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <cmath>

#define F first
#define S second

using namespace std;

struct Car
{
    int x_axis;
    int y_axis;
    int direction;
    int speed;
};

bool collides(const Car &a_car,const Car &b_car)
{
    if(a_car.y_axis == b_car.y_axis && a_car.x_axis == b_car.x_axis)
    {
        return 1;
    }

    if(a_car.speed == 0 && b_car.speed == 0)
    {
        return 0;
    }
    
    if(a_car.speed == 0)
    {
        if(a_car.y_axis == b_car.y_axis)
        {
            if((a_car.x_axis > b_car.x_axis && b_car.direction == 1)
                || (a_car.x_axis < b_car.x_axis && b_car.direction == 3))
                {
                    return 1;
                }
        }
        if(a_car.x_axis == b_car.x_axis)
        {
            if((a_car.y_axis > b_car.y_axis && b_car.direction == 0)
                || (a_car.y_axis < b_car.y_axis && b_car.direction == 2))
                {
                    return 1;
                }
        }
        return 0;
    }

    if(b_car.speed == 0)
    {
        if(b_car.y_axis == a_car.y_axis)
        {
            if((b_car.x_axis > a_car.x_axis && a_car.direction == 1)
                || (b_car.x_axis < a_car.x_axis && a_car.direction == 3))
                {
                    return 1;
                }
        }
        else if(b_car.x_axis == a_car.x_axis)
        {
            if((b_car.y_axis > a_car.y_axis && a_car.direction == 0)
                || (b_car.y_axis < a_car.y_axis && a_car.direction == 2))
                {
                    return 1;
                }
        }
        return 0;
    }
    
    if(a_car.y_axis == b_car.y_axis)
    {
        if(a_car.direction == 1 && b_car.direction == 1)
        {
            if(a_car.x_axis < b_car.x_axis && a_car.speed > b_car.speed)
            {
                return 1;
            }
            else if(a_car.x_axis > b_car.x_axis && a_car.speed < b_car.speed)
            {
                return 1;
            }
        } 
        else if(a_car.direction == 3 && b_car.direction == 3)
        {
            if(a_car.x_axis < b_car.x_axis && a_car.speed < b_car.speed)
            {
                return 1;
            }
            else if(a_car.x_axis > b_car.x_axis && a_car.speed > b_car.speed)
            {
                return 1;
            }
        }
        else if(a_car.direction == 3 && b_car.direction == 1 
            && a_car.x_axis > b_car.x_axis)
        {
            return 1;
        }
        else if(a_car.direction == 1 && b_car.direction == 3
            && a_car.x_axis < b_car.x_axis)
        {
            return 1;
        }
        return 0;
    } 
    else if(a_car.x_axis == b_car.x_axis)
    {
        if(a_car.direction == 0 && b_car.direction == 0)
        {
            if(a_car.y_axis < b_car.y_axis && a_car.speed > b_car.speed)
            {
                return 1;
            }
            else if(a_car.y_axis > b_car.y_axis && a_car.speed < b_car.speed)
            {
                return 1;
            }
        } 
        else if(a_car.direction == 2 && b_car.direction == 2)
        {
            if(a_car.y_axis < b_car.y_axis && a_car.speed < b_car.speed)
            {
                return 1;
            }
            else if(a_car.y_axis > b_car.y_axis && a_car.speed > b_car.speed)
            {
                return 1;
            }
        }
        else if(a_car.direction == 2 && b_car.direction == 0
            && a_car.x_axis > b_car.x_axis)
        {
            return 1;
        }
        else if(a_car.direction == 0 && b_car.direction == 2
            && a_car.x_axis < b_car.x_axis)
        {
            return 1;
        }
        return 0;
    } 
    
    if(a_car.y_axis > b_car.y_axis)
    {
        if(a_car.x_axis > b_car.x_axis)
        {
            if(a_car.direction == 2 && b_car.direction == 1)
            {
                if(abs(a_car.y_axis - b_car.y_axis) * b_car.speed
                    == abs(a_car.x_axis - b_car.x_axis) * a_car.speed)
                {
                    return 1;
                }
            }
            else if(a_car.direction == 3 && b_car.direction == 0)
            {
                if(abs(a_car.y_axis - b_car.y_axis) * a_car.speed
                    == abs(a_car.x_axis - b_car.x_axis) * b_car.speed)
                {
                    return 1;
                }
            }
        }
        else if(a_car.x_axis < b_car.x_axis)
        {
            if(a_car.direction == 2 && b_car.direction == 3)
            {
                if(abs(a_car.y_axis - b_car.y_axis) * b_car.speed
                    == abs(a_car.x_axis - b_car.x_axis) * a_car.speed)
                {
                    return 1;
                }
            }
            else if(a_car.direction == 1 && b_car.direction == 0)
            {
                if(abs(a_car.y_axis - b_car.y_axis) * a_car.speed
                    == abs(a_car.x_axis - b_car.x_axis) * b_car.speed)
                {
                    return 1;
                }
            }
        }
    }
    else if(a_car.y_axis < b_car.y_axis)
    {
        if(a_car.x_axis > b_car.x_axis)
        {
            if(a_car.direction == 0 && b_car.direction == 1)
            {
                if(abs(a_car.y_axis - b_car.y_axis) * a_car.speed
                    == abs(a_car.x_axis - b_car.x_axis) * b_car.speed)
                {
                    return 1;
                }
            }
            else if(a_car.direction == 3 && b_car.direction == 2)
            {
                if(abs(a_car.y_axis - b_car.y_axis) * b_car.speed
                    == abs(a_car.x_axis - b_car.x_axis) * a_car.speed)
                {
                    return 1;
                }
            }
        }
        else if(a_car.x_axis < b_car.x_axis)
        {
            if(a_car.direction == 0 && b_car.direction == 3)
            {
                if(abs(a_car.y_axis - b_car.y_axis) * a_car.speed
                    == abs(a_car.x_axis - b_car.x_axis) * b_car.speed)
                {
                    return 1;
                }
            }
            else if(a_car.direction == 1 && b_car.direction == 2)
            {
                if(abs(a_car.y_axis - b_car.y_axis) * b_car.speed
                    == abs(a_car.x_axis - b_car.x_axis) * a_car.speed)
                {
                    return 1;
                }
            }
        }
    }
    
    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);
    vector<Car> Cars(N);

    for(auto &i : Cars)
    {
        Car temp;
        scanf(" %d %d %d %d",
            &temp.x_axis, &temp.y_axis, &temp.direction, &temp.speed);
        i = temp;
    }

    set<int> cars_that_collide;
    for(int i = 0; i < N; ++i)
    {
        for(int j = i + 1; j < N; ++j)
        {
            if(collides(Cars[i], Cars[j]))
            {
                cars_that_collide.insert(i);
                cars_that_collide.insert(j);
            }
        }
    }

    for(auto &i : cars_that_collide)
    {
        printf("%d\n", i);
    }

    return 0;
}