#include <iostream>
using namespace std;


#include <stdio.h>

#include <stdlib.h>

void FindTwoNum(int arr[], int size, int* num1, int* num2) {     

	int sum = 0;

	for (int i = 0; i < size; i++) {

		sum ^= arr[i];

	}

	int pos = 0;

	for (; pos < 32; pos++) {

		if ((sum&(1 << pos)) != 0) {

			break;

		}

	}

	*num1 = 0;

	*num2 = 0;

	for (int i = 0; i < size; i++) {

		if ((arr[i] & (1 << pos)) == 0) {

			*num1 ^= arr[i];

		}

		else {

			*num2 ^= arr[i];

		}

	}

}

int main() {

	int arr[] = { 1,1,2,4,4,5,5,6,7,7 };

	int num1 = 0;

	int num2 = 0;

	FindTwoNum(arr, 10, &num1, &num2);

	printf("num1 = %d num2 = %d", num1, num2);

	system("pause");

	return 0;

}
//2.Ä£ÄâÊµÏÖatoi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MyAtoi(const char* str) {
	int flag = 0;
	int ret = 0;
	if (str == NULL || *str == '\0') {
		return 0;
	}

	while (isspace(*str)) {

		str++;

	}

	if (*str == '-') {

		flag = -1;

		str++;

	}

	if (*str == '+') {

		str++;

	}

	while (*str != '\0') {

		if (isdigit(*str)) {

			ret = ret * 10 + (*str - '0');

		}

		else {

			return ret;

		}

		str++;

	}

	return ret * flag;

}

int main() {

	char str[] = "r16tb";

	int result = MyAtoi(str);

	printf("%d", result);

	system("pause");

	return 0;

}