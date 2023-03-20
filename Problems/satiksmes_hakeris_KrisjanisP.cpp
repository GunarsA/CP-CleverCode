#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
* 0 - uz augšu;
* 1 - pa labi;
* 2 - uz leju;
* 3 - pa kreisi.
*/

int main(){
    ll n;
    cin>>n;
    ll x_arr[n];
    ll y_arr[n];
    ll s_arr[n];
    ll v_arr[n];
    for(ll i=0;i<n;i++){
        cin>>x_arr[i];
        cin>>y_arr[i];
        cin>>s_arr[i];
        cin>>v_arr[i];
    }
    set<ll> dmgd;
    // considering case where both cars ARE NOT stationary
    for(ll i=0;i<n;i++){
        if(v_arr[i]==0) continue;
        for(ll j=i+1;j<n;j++){
            if(v_arr[j]==0) continue;
            bool fc_vert = s_arr[i]==0||s_arr[i]==2; // true if first car is going vertically
            bool sc_vert = s_arr[j]==0||s_arr[j]==2; // true if second car is going vertically

            bool fc_up = s_arr[i]==0; // true if first car is going up
            bool fc_down = s_arr[i]==2; // true if first car is going down

            bool sc_up = s_arr[j]==0; // true if second car is going up
            bool sc_down = s_arr[j]==2; // true if second car is going down

            bool fc_higher = y_arr[i]>y_arr[j]; // true if first car is higher than second
            bool fc_lower = y_arr[i]<y_arr[j]; // true if first car is lower than second
            
            bool sc_higher = y_arr[j]>y_arr[i]; // true if second car is higher than first
            bool sc_lower = y_arr[j]<y_arr[i]; // true if second car is lower than first

            bool fc_right = s_arr[i]==1; // true if first car is going right
            bool fc_left = s_arr[i]==3; // true if first car is going left

            bool sc_right = s_arr[j]==1; // true if second car is going right
            bool sc_left = s_arr[j]==3; // true if second car is going left

            bool fc_righter = x_arr[i]>x_arr[j]; // true if first car is to the right of second
            bool fc_lefter = x_arr[i]<x_arr[j]; // true if first car is to the left of second

            bool sc_righter = x_arr[j]>x_arr[i]; // true if second car is to the right of first
            bool sc_lefter = x_arr[j]<x_arr[i]; // true if second car is to the left of first

            bool fc_faster = v_arr[i] > v_arr[j];
            
            if(fc_vert == sc_vert){ // both cars are both either horizontally or vertically
                if(fc_vert){ // both cars are going vertically
                    if(x_arr[i]!=x_arr[j]) continue; // they can't collide if they aren't on the same line
                    
                    if(fc_up==sc_up){ // both cars are going the same direction
                        if(v_arr[i]==v_arr[j]) continue; // they can't collide if they are going the same speed

                        if((fc_up)  && (fc_higher &&fc_faster) ) continue; // if first car is faster, higher, and they are going up
                        if((fc_up)  && (!fc_higher&&!fc_faster)) continue; // if first car is slower, lower, and they are going up
                        if((!fc_up) && (fc_higher &&!fc_faster)) continue; // if first car is slower, higher, and they are going down
                        if((!fc_up) && (!fc_higher&&fc_faster) ) continue; // if first car is faster, lower, and they are going down
                    }
                    else{
                        if(fc_up&&fc_higher) continue; // if first car is higher, going up
                        if((!fc_up)&&(!fc_higher)) continue; // if first car is lower, going down
                    }

                    dmgd.insert(i);
                    dmgd.insert(j);
                }else{ // both cars are going horizontally
                    if(y_arr[i]!=y_arr[j]) continue; // they can't collide if they aren't on the same line
                    
                    if(fc_right==sc_right){ // both cars are going the same direction
                        if(v_arr[i]==v_arr[j]) continue; // they can't collide if they are going the same speed

                        if((fc_right)  && (fc_righter &&fc_faster) ) continue; // if first car is faster, righter, and they are going right
                        if((fc_right)  && (!fc_righter&&!fc_faster)) continue; // if first car is slower, lefter, and they are going right
                        if((!fc_right) && (fc_righter &&!fc_faster)) continue; // if first car is slower, righter, and they are going left
                        if((!fc_right) && (!fc_righter&&fc_faster) ) continue; // if first car is faster, lefter, and they are going left
                    }
                    else{
                        if(v_arr[i]==0&&v_arr[j]==0) continue; // both cars are standing still

                        if(fc_right&&fc_righter) continue; // if first car is righter, going right
                        if((!fc_right)&&(!fc_righter)) continue; // if first car is lefter, going left
                    }

                    dmgd.insert(i);
                    dmgd.insert(j);
                }
            }else{ // one car is going horizontally, the other - vertically
                if(fc_vert){ // first car is going vertically

                    if(sc_right&&sc_righter) continue;
                    if(sc_left&&sc_lefter) continue;

                    if(fc_up&&fc_higher) continue;
                    if(fc_down&&fc_lower) continue;

                    ll f_dist = abs(y_arr[i]-y_arr[j]);
                    ll s_dist = abs(x_arr[i]-x_arr[j]);
                    
                    if(v_arr[j]*f_dist == v_arr[i]*s_dist){
                        dmgd.insert(i);
                        dmgd.insert(j);
                    }
                }else{ // first car is going horizontally

                    if(fc_right&&fc_righter) continue;
                    if(fc_left&&fc_lefter) continue;

                    if(sc_up&&sc_higher) continue;
                    if(sc_down&&sc_lower) continue;

                    ll f_dist = abs(x_arr[i]-x_arr[j]);
                    ll s_dist = abs(y_arr[i]-y_arr[j]);
                    
                    if(v_arr[j]*f_dist == v_arr[i]*s_dist){
                        dmgd.insert(i);
                        dmgd.insert(j);
                    }
                }
            }
        }
    }
    // considering case where one of the cars IS in fact stationary
    for(ll i=0;i<n;i++){
        if(v_arr[i]==0) continue;
        for(ll j=0;j<n;j++){
            if(i==j) continue;
            if(v_arr[j]!=0) continue;
            bool collision = false;

            if(x_arr[i]==x_arr[j]){
                if(s_arr[i]==0 && y_arr[j]>y_arr[i])
                    collision = true;
                else if (s_arr[i]==2 && y_arr[j]<y_arr[i])
                    collision = true;
            }
            else if(y_arr[i]==y_arr[j]){
                if(s_arr[i]==1 && x_arr[j]>x_arr[i])
                    collision = true;
                else if (s_arr[i]==3 && x_arr[j]<x_arr[i])
                    collision = true;
            }

            if(collision){
                dmgd.insert(i);
                dmgd.insert(j);
            }
        }
    }
    for(ll i: dmgd) cout<<i<<endl;
}