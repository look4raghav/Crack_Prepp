#include <bits/stdc++.h>
using namespace std;

#define MAX 128

bool isVowel(char x)
{
	return (x == 'a' || x == 'e' || x == 'i' ||
			x == 'o' || x == 'u' || x == 'A' ||
			x == 'E' || x == 'I' || x == 'O' ||
			x == 'U');
}

int KDistinctVowel(char s[], int k)
{
	int n = strlen(s);

	int c[MAX];
	memset(c, 0, sizeof(c));

	int result = -1;

	for (int i = 0, j = -1; i < n; ++i) {

		int x = s[i];

		if (isVowel(x)) {
			if (++c[x] == 1) {

				--k;
			}
		}
		while (k < 0) {

			x = s[++j];
			if (isVowel(x)) {

				if (--c[x] == 0) {

					++k;
				}
			}
		}

		if (k == 0)
			result = max(result, i - j);	
	}
	return result;
}

int main(void)
{
	char s[] = "artyebui";
	int k = 2;
	cout << KDistinctVowel(s, k);
	return 0;
}
