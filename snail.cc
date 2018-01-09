#include <cstdio>
using namespace std;


int main() {
	int height, capability, sleep, fatigue, loss;
	while (scanf("%d %d %d %d", &height, &capability, &sleep, &fatigue) != EOF){	
		if (height == 0){
			break;
		}
		height = height * 100;
		int day=0;
		capability = capability * 100;
		sleep = sleep * 100;
		loss = capability * fatigue/100;	

		int current_height=0;
		bool pass=false;
		while (pass == false){
			day++;
			current_height = current_height + capability;
			if (current_height > height){
				pass = true;
			}else{
				int slide = current_height - sleep;
				if (slide < 0){
					pass = false;
					break;
				}else{
					current_height = slide;
					capability = capability - loss;
					if (capability < 0){
						capability = 0;
					}
				}	
			}	
		}

		if (pass == false){
			printf("failure on day %d\n", day);
		}
		else if (pass == true){
			printf("success on day %d\n", day);
		}	
	}
	return 0;	
}