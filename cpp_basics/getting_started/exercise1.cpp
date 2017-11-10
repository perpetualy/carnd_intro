#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sense(vector<float>& p, string Z);
void move(vector<float>& p, int U);

vector<float> p(5, 0.2f);
static const string worldarray[] = {"green", "red", "red", "green", "green"};
vector<string> world (worldarray, worldarray + sizeof(worldarray) / sizeof(worldarray[0]));
static const string measurearray[] = {"red", "green", "green"};
vector<string> measurements (measurearray, measurearray + sizeof(measurearray) / sizeof(measurearray[0]));  
vector<int> motions(2, 1);
float pHit = 0.6f;
float pMiss = 0.2f;
float pExact = 0.8f;
float pOvershoot = 0.1f;
float pUndershoot = 0.1f;

int main(){


    for(int i=0; i < measurements.size(); ++i){
        sense(p, measurements[i]);
        move(p, motions[i]);
    }

    for(int i=0; i < p.size(); ++i){
        cout<<p[i]<<std::endl;
    }

    return 0;
}

void sense(vector<float>& p, string Z){
    int hit = 0;
    //vector<float> q(p.size(), 0.0f);
    float s = 0.0f;
    for(int i=0; i < p.size(); ++i){
        hit = (Z.compare(world[i]) == 0)?1:0;
        p[i] = p[i] * (hit * pHit + (1-hit) * pMiss);
        s += p[i];
    }
    
    for(int i=0; i < p.size(); ++i){
        p[i] = p[i] / s;
    }
}

void move(vector<float>& p, int U){
    //vector<float> q(p.size(), 0.0f);
 
    for(int i=0; i < p.size(); ++i){
        float s = pExact * p[(i-U) % p.size()];
        s = s + pOvershoot * p[(i-U-1) % p.size()];
        s = s + pUndershoot * p[(i-U+1) % p.size()];
        p[i] = s;
    }
}
