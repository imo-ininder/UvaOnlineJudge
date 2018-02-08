#include <stdio.h>
#include <stdlib.h>

int main(){
	int beg, end;
	while(scanf("%d %d" ,&beg ,&end) != EOF ){
		int temp_beg = beg;
		int temp_end = end;

		if(beg > end){
			int tmp = beg;
			beg = end;
			end = tmp;
		}

		int max_cycle = 1;
		int curr_max_cycle =1;
		for(beg; beg<=end; beg++){
			long long int i = beg;
			while(i != 1){
				if(i%2 != 0) i = i*3 + 1;
				else i = i/2;

				curr_max_cycle++;
			}
			if(curr_max_cycle >= max_cycle)
				max_cycle = curr_max_cycle;

			curr_max_cycle = 1;
		}

		printf("%d %d %d\n", temp_beg, temp_end, max_cycle);
	}
	system("pause");
	return 0;
}