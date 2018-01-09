#include <cstdio>
using namespace std;

float hitung(int lama, float ang, float loan, float dep[]){
	float sisa_pinjaman = loan;
	float harga_kena_pajak = loan + ang;
	float sisa_harga = harga_kena_pajak - (harga_kena_pajak * dep[0]);
	int i = 1;
	int x = 0;
	int c = 0;
	while (i <= lama && x == 0){
		sisa_pinjaman = sisa_pinjaman - ang;
		sisa_harga = sisa_harga - (sisa_harga * dep[i]);
		c++;
		if (sisa_pinjaman < sisa_harga){
			x=1;
		}
		i++;
	}
	return sisa_harga;
}

int main() {
	float ang, loan,bunga;
	float hasil;
	int payment1;
	int lama, payment;
	
	/*lama = 1;
	ang = 1;
	loan = 1;
	payment = 1;*/
		scanf("%d %f %f %d", &lama, &ang, &loan, &payment);
		float dep[100];
		for (int i = 0; i <= lama; i++){
			scanf("%d %f", &payment1,&bunga);
			if (i == payment1){
				dep[i] = bunga;
			} else if (i != payment1){
				dep[i] = dep[i-1];
			}
		}
		hasil = hitung(lama, ang, loan, dep);

		if (hasil > 1){
			printf("%f months\n",hasil);	
		}
		else { 
			printf("%f month\n", hasil);
		}	
		for (int m = 0; m <= lama; m++){
			printf("%f\n", dep[m]);
		}

	return 0;
}