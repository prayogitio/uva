#include <cstdio>
using namespace std;


int main() {
	int n;
	long long target;
	while (scanf("%d %lld", &n,&target) != EOF) {
		int x=n/2;
		int y=n/2;
		long long max = n * n;
		int current_x = n/2+1;
		int current_y = n/2+1;
		bool found = false;
		long long val_bottom;
		long long val_top;
		if (target == 1) {
			printf("Line = %d, column = %d.",current_x,current_y);
			n=0;
		} else if (target == max) {
			printf("Line = %d, column = %d.",n,n);
			n=0;
		} else {
			x = n;
			y = n;
			val_top = n*n;
			val_bottom = n*n;
			int count = n;
			for (int i=n;i>=1 && found==false;i--) {
				if (i == n) {
					count--;//4
					val_bottom = val_bottom - count;
					if (target <= val_top && target >= val_bottom) {
						int awal = val_bottom;
						int akhir = val_top;
						while (awal!=akhir) {
							int tengah = awal+akhir/2;
							if (tengah == target) {
								y = y - (val_top - tengah);
								found = true;
								awal=akhir;
							} else if (target < tengah) {
								akhir = tengah-1;
							} else {
								awal = tengah+1;
							}
						}
					} else {
						x = x - 1;
						y = y - count;
					}
				} else if (i % 2 == 0) {
					val_top = val_bottom-1;
					count--;//3
					val_bottom = val_top-count;
					if (target <= val_top && target >= val_bottom) {
						int awal = val_bottom;
						int akhir = val_top;
						while (awal!=akhir) {
							int tengah = awal+akhir/2;
							if (tengah == target) {
								x = x - (val_top - tengah);
								found = true;
								awal=akhir;
							} else if (target < tengah) {
								akhir = tengah-1;
							} else {
								awal = tengah+1;
							}
						}
					} else {
						x = x - count;
						y = y + count + 1;
					}
					val_top = val_bottom - 1;
					val_bottom = val_top - count;
					if (target <= val_top && target >= val_bottom) {
						int awal = val_bottom;
						int akhir = val_top;
						while (awal!=akhir) {
							int tengah = awal+akhir/2;
							if (tengah == target) {
								y = y - (val_top - tengah);
								found = true;
								awal=akhir;
							} else if (target < tengah) {
								akhir = tengah-1;
							} else {
								awal = tengah+1;
							}
						}
					} else {
						x = x + 1;
						count--;//2
					}
				} else if (i % 2 != 0) {
					val_top = val_bottom - 1;
					val_bottom = val_top - count;
					if (target <= val_top && target >= val_bottom) {
						int awal = val_bottom;
						int akhir = val_top;
						while (awal!=akhir) {
							int tengah = awal+akhir/2;
							if (tengah == target) {
								x = x - (val_top - tengah);
								found = true;
								awal=akhir;
							} else if (target < tengah) {
								akhir = tengah-1;
							} else {
								awal = tengah+1;
							}
						}
					} else {
						x = x + count;
						y--;
					}
					val_top = val_bottom - 1;
					val_bottom = val_top - count;
					if (target <= val_top && target >= val_bottom) {
						int awal = val_bottom;
						int akhir = val_top;
						while (awal!=akhir) {
							int tengah = awal+akhir/2;
							if (tengah == target) {
								y = y - (val_top - tengah);
								found = true;
								awal=akhir;
							} else if (target < tengah) {
								akhir = tengah-1;
							} else {
								awal = tengah+1;
							}
						}
					} else {
						x--;
						y=y-2;;
					}
				}
			}
			if (n!=0) {
				printf("Line = %d, column = %d.",x,y);
			}
		}
		
	}
	return 0;
}