#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <utility>
#include <map>

using namespace std;

const int MOVES = 510 * 100 + 205;


map <pair <int, int>, int> theMap;

#define mp make_pair
#define fi first
#define se second



int main(){

	int x = 0, y = 0;
	char dir = 'N';
	int r = 0, last = 0;
	

	// Change the initial map to chess board 100x100

	for(int i = -50; i < 50; i++){
		if(last == r){
			r ^= 1;
			last = r;
		}
		for(int j = -50; j < 50; j++){
			theMap[mp(i, j)] = r;
			r ^= 1;
		}
	}


	int maxX = 0, minX = 0, maxY = 0, minY = 0;

	for(int i = 0; i < MOVES; i++){
		if(theMap[mp(x, y)] == 0){
			// direction counterclockwise
			if(dir == 'N') dir = 'W';
			else if(dir == 'W')	dir = 'S';
			else if(dir == 'S') dir = 'E';
			else if(dir == 'E') dir = 'N';
		}
		else{
			// direction clockwise
			if(dir == 'N') dir = 'E';
			else if(dir == 'W') dir = 'N';
			else if(dir == 'S') dir = 'W';
			else if(dir == 'E') dir = 'S';			
		}

		theMap[mp(x, y)] = !theMap[mp(x, y)];
			
		if(dir == 'N') y++;
		else if(dir == 'W') x--;
		else if(dir == 'S') y--;
		else if(dir == 'E') x++;

		maxX = max(maxX, x);
		minX = min(minX, x);
		maxY = max(maxY, y);
		minY = min(minY, y);
	}
	cerr << maxX << " - " << minX << endl;
	cerr << maxX << " - " << minY << endl;
	
	int n = max(abs(maxX), abs(minX));
	
	n = max(n, abs(minY));
	n = max(n, abs(maxY));
	
	printf("%d\n", n);
	
	cerr << n;

	for(int i = n ; i >= -n; i--){
		for(int j = -n; j < n; j++){
			if(theMap[mp(j, i)] == 0){
				printf("0 ");
			}
			else{
				printf("1 ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
