#include <stdio.h>
#include <string.h> //tested with AMATH, PMATH, ENVE

char v[1000000000], r[300][100], a[8];
int room_num, ind;


void cpy(int j) {
  int it;
	
	for(it=0;it<j;it++)
		a[it]=v[ind+it];
	a[j]='\0';
}

int main() {
	int i, u, n;

	freopen("in","r",stdin);
	for(n=0;scanf("%c", &v[n]) != EOF ;n++);  //stores input into v
	v[n]='\0';
	fclose(stdin);
	
	for(cpy(7);strcmp(a, "</HTML>");) {
		for(cpy(7);strcmp(a, "<TABLE>") && strcmp(a, "</HTML>");)
			++ind, cpy(7);  //moves index to the first character after <TABLE>
		ind+=7;
		
		ind++; //move past the endline

		if(ind==n)  break;

		for(cpy(5);strcmp(a, "</TR>");)
				++ind, cpy(5); //moves index to the first character of the second TR
		ind+=5;

		ind++; //moves past endline
		
		for(cpy(8);strcmp(a, "</TABLE>");) {
			cpy(15);
			if(!strcmp(a, "<TR><TD COLSPAN")) {
				for(cpy(5);strcmp(a, "</TR>");)
					++ind, cpy(5);
				ind+=5;

				ind++;
			
				cpy(8);
				continue;
			}

			for(i=1;i<=11;i++) {          // moves index to the "<TD" of building line
				for(cpy(5);strcmp(a, "</TD>");)
					++ind, cpy(5);
				ind+=5;
			}

			for(;v[ind]!='>';ind++);  //moves index to the first character from the building name
			ind++;
		
			for(u=0, ++room_num;v[ind]!='<';ind++, u++)  //moves index past building name and gets room name
				r[room_num][u]=v[ind];
			r[room_num][u]='\0';
		
			for(cpy(5);strcmp(a, "</TR>");)   //same as before
				++ind, cpy(5);
			ind+=5;

			ind++; //moves past endline
		
			cpy(8);
		}

		ind+=8; //moves over <\table>

		ind++; //moves past endline
	}
	freopen("out", "w", stdout);
	for(i=1;i<=room_num;i++) {
		for(ind=0;r[i][ind]!='\0';ind++)
			printf("%c", r[i][ind]);
		printf("\n");
	}
	printf("%d\n", n);
	fclose(stdout);
	return 0;
}
