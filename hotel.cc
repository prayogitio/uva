#include <cstdio>
#include <algorithm>
using namespace std;

bool getMinBed(int n, int w, int sw[]){
	int minimalBed = -1;
	bool adaBed = false;
	sort(sw, sw + w);
	for (int y=0;y<w;y++){
		if (sw[y] >= n){
			minimalBed = sw[y];
			w=0;
			adaBed = true;
		}
	}
	return adaBed;
}

int getMinCost(int n, int price){
	return n * price;
}

int main() {
	int n, budget, hotels, weeks, hotel_price;
	while(scanf("%d %d %d %d",&n,&budget,&hotels,&weeks) != EOF){
		int cost[20];
		int min_cost;
		bool isBed = false;
		int select_weeks[20];
		for (int i=0;i<hotels;i++){
			scanf("%d", &hotel_price);
			for (int j=0;j<weeks;j++){
				scanf("%d ", &select_weeks[j]);
			}
			isBed = getMinBed(n, weeks, select_weeks);
			if (isBed == false){
				cost[i] = budget;
			}else{
				cost[i]= getMinCost(hotel_price,n);
			}
		}
		sort(cost, cost + hotels);
		int super_min_cost = cost[0];
		if (super_min_cost < budget){
			printf("%d\n", super_min_cost);
		}	
		else {
			printf("stay home\n");
		}
	
	}
	return 0;
}