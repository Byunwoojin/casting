#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct names {
	char  first[20];
	char  last[20];
};

struct date {
	char  month[12];
	int  day, year;
};

struct person {
	struct  names  name;
	struct  date  birthday;
};
int i;
/* Converts "January", "February", ..., "December"
into corresponding numbers 1, 2, ..., 12 */
int convert(char *mon) {
	static char *name[] = { "Illegal month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	for (i = 1; i < 13; i++) {
		if (strcmp(mon, name[i]) == 0)
			return i;
	}
	return 0;
	/* TO BE COMPLETED  */
	/* 5장의 month_name()은 숫자를 매개변수로
	받아 달 이름을 가리키는 포인터를 반환하는데,
	이 함수는 그 역에 해당하는 작업을 수행함 */
}

/* argv[1] contains the filename: cast.txt */
main(int argc, char  *argv[]) {
	struct  person  cast[20];
	int  ncast = 0;
	FILE  *f;
	int  i;

	if (argc < 2) {
		fprintf(stderr, "usage:  %s  filename\n", argv[0]);
		exit(1);
	}

	if ((f = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "%s: can't open %s\n", argv[0], argv[1]);
		exit(1);
	}

	/* Reads the file contents into cast[] */

	/* TO BE COMPLETED */
	/* 파일 크기를  가정하지 말고, EOF 를 인식하여 처리해야 함 */
	for (i = 0; (fscanf(f, "%s %s %s %d, %d", cast[i].name.first, cast[i].name.last, cast[i].birthday.month, &cast[i].birthday.day, &cast[i].birthday.year) != EOF); i++)
		ncast++;

	fclose(f);

	printf("Cast of Captain America: Civil War\n");
	printf("==================================\n\n");
	printf("Name   (Birthday)\n\n");
	for (i = 0; i < ncast; i++)
		printf("%s, %s  (%02d/%02d/%02d)\n",
			cast[i].name.last, cast[i].name.first,
			convert(cast[i].birthday.month),
			cast[i].birthday.day,
			cast[i].birthday.year % 100);
}