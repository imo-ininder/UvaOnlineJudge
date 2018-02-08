#include <stdio.h>
#include <stdlib.h>

struct Point
{
	double x;
	double y;
};

Point P[101], CH[101];
int nodes = 0;

int cmp(const void *a, const void *b){
 	if ((*(Point *)a).x == (*(Point *)b).x) return (*(Point *)a).y - (*(Point *)b).y ;
 	else return (*(Point *)a).x - (*(Point *)b).x ;
}

int cross(Point *o, Point *a, Point *b){
	return (a->x - o->x)*(b->y - o->y) - 
			(a->y - o->y)*(b->x - o->x);
}

void getCenter(int m){
	double sum = 0.0,cx = 0.0,cy = 0.0,w ;

	if (m == 1) { 
		printf("%.3lf %.3lf\n",CH[0].x, CH[0].y); 
	} else if (m == 2) {
		cx = (CH[0].x + CH[1].x)/2;
		cy = (CH[0].y + CH[1].y)/2;
		printf("%.3lf %.3lf\n",cx, cy);
	} else {
		for(int i = m-1, j = 0 ; j < m ; i = j++){
			w = ( CH[i].x*CH[j].y - CH[i].y*CH[j].x );
			cx += ( CH[i].x + CH[j].x )*w;
			cy += ( CH[i].y + CH[j].y )*w;
			sum += w;
		}
		printf("%.3lf %.3lf\n", cx/3/sum,  cy/3/sum);
	}
}

void getCH(){
	qsort(P, nodes, sizeof(Point), cmp);

	int m = 0;
	for(int i = 0 ; i < nodes ; i++){
		while ( m >= 2 && cross(&CH[m-2], &CH[m-1], &P[i]) <= 0) m--;
		CH[m++] = P[i];
	}
	for(int i = nodes-1 , t = m+1; i >= 0 ; i--){
		while ( m >= t && cross(&CH[m-2], &CH[m-1], &P[i]) <= 0) m--;
		CH[m++] = P[i];
	}
	m--;
	getCenter(m);
}

int main(){
	
	while (scanf("%d", &nodes) && nodes > 2){
		for(int i = 0 ; i < nodes ; i++)
			scanf("%lf%lf", &P[i].x, &P[i].y);			
		getCH();
	}
	return 0;
}
