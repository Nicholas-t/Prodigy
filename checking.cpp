#include <vector>
#include <iostream>
#include <tuple>
using namespace std;

//checking w.r.t limit


vector <vector <int> > check(int limit, vector<vector<int> > mat){
	vector<vector<int> > out = mat;
	vector<vector<int> > list_index(mat.size());
	for (int i = 0; i < mat.size(); i++) { 
        	for (int j = 0; j < mat[i].size(); j++) {
            		if ((mat[i][j] > limit) || (mat[i][j]<0)){
				list_index[i].push_back(j);
			}			
			else{
				list_index[i].push_back(-1);
			}
		}
	}
	int c = 0;
	for (int i = 0; i < list_index.size(); i++) { 
        	for (int j = 0; j < list_index[i].size(); j++) {
            		if (list_index[i][j] != -1){
				out[i].erase(out[i].begin()+j-c);
				c += 1;
			}
		}
	c = 0;
	}
	return out;
}


int main(){
	vector<vector<int> > mat = { {2,4,6},
				{7,2,8},
				{9,10,11,23,93,1,1,1},
				{4,6,2,4,7,4,9} ,
				{100,3,2,5,109},
				{98,123,6,2,4,6,2,6,9,3,4,5,345},
				{9,18,2,3,5,12,3},
				{94,82,57,2,1,23,3,3}};
	for (int i = 0; i < mat.size(); i++) { 
        	for (int j = 0; j < mat[i].size(); j++) {
            		cout << mat[i][j] << " "; 
		}
        	cout << endl; 
	}
	cout<<"before checking"<<endl;
	int limit = 10;
	mat = check(limit, mat);
	for (int i = 0; i < mat.size(); i++) { 
        	for (int j = 0; j < mat[i].size(); j++) {
            		cout << mat[i][j] << " "; 
		}
        	cout << endl; 
	}
	cout<<"after checking"<<endl;
	return 0; 
} 
