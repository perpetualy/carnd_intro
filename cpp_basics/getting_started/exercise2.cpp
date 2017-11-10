#include <iostream>
#include <vector>
#include <string>

using namespace std;

float dot_product(vector < float > a, vector < float > b);
vector < vector < float > > transpose(vector < vector <float> > a);
vector < vector < float > > multi(vector < vector < float > > a, vector < vector < float > > b);


int main(){
	vector < vector < float > > a(3, vector < float >(2, 3.0f));
	vector < vector < float > > b(2, vector < float >(3, 8.0f));

	vector < vector < float > > p;

	p = multi(a, b);

	for (int r = 0; r < p.size(); ++r){
		cout << "[";
		for (int c = 0; c < p[0].size(); ++c){
			cout << p[r][c] << ",";
		}
		cout << "]" << endl;
	}

    return 0;
}

float dot_product(vector < float > a, vector < float > b){
	int al = a.size();
	int bl = b.size();
	if (al <= 0) return 0.0;
	if (al != bl) return -1.0f;
	float s = 0.0f;

	for (int i=0; i < al; ++i )
		s += a[i]*b[i];
	return s;
}

vector < vector < float > > transpose(vector < vector < float > > a){
	vector < vector < float > > t(a[0].size(), vector < float > (a.size(), 0.0f));
	for (int c = 0; c < a[0].size(); ++c){
		for (int r = 0; r < a.size(); ++r){
			t[c][r]=a[r][c];
		}
	}
	return t;
}

vector < vector < float > > multi(vector < vector < float > > a, vector < vector < float > > b){
	vector < vector < float > > product(a.size(), vector < float >(b[0].size(), 0.0));
	vector < vector < float > > t = transpose(b);

	for (int r = 0; r < a.size(); ++r){
		for (int c = 0; c < t.size(); ++c){
			product[r][c] = dot_product(a[r], t[c]);
		}
	}

	return product;

}