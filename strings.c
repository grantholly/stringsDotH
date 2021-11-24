/*
 * memchr
 * memcmp
 * memcpy
 * memmove
 * memset
 *
 * strcat
 * strncat
 * strchr
 * strcmp
 * strncmp
 * strcoll
 * strcpy
 * strncpy
 * strcspn
 * strerror
 * strlen
 * strpbrk
 * strrchr
 * strspn
 * strstr
 * strtok
 * strxfrm
*/
#include <stdio.h>

// size_t strlen (const char *__s)
size_t strlen(const char *str) {
	size_t len = 0;

	while (str[len] != '\0') {
		len++;
	}
	return len;
}

// char *strcpy (char *__restrict __dest, const char *__restrict __src)
char *strcpy(char *dest, const char *src) {
	size_t slen = strlen(src);
	size_t dlen = strlen(dest);
	int i;

	if (dest == NULL) {
		printf("ERR: destination string is NULL and cannot be used\n");
		return NULL;
	}

	if (dlen <= slen) {
		printf("ERR: dst '%s' with size '%zu' will not contain\
 src '%s' with size '%zu'\n", dest, dlen, src, slen);
		return dest;
	}
	
	for (i = 0; src[i] != '\0'; i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}

// char *strncpy (char *__restrict __dest, const char *__restrict __src, size_t __n)
char *strncpy(char *dest, const char *src, size_t n) {
	size_t slen = strlen(src);
	size_t dlen = strlen(dest);
	int i;

	if (dest == NULL) {
		printf("ERR: destination string is NULL and cannot be used\n");
		return NULL;
	}

	if (dlen <= slen) {
                printf("WARN: truncating dst '%s' with size '%zu' will not contain\
 src '%s' with size '%zu'\n", dest, dlen, src, slen);
                return dest;
        }

	for (i = 0; src[i] != '\0' && i <= n; i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}

// char *strcat (char *__restrict __dest, const char *__restrict __src)
char *strcat(char *s1, const char *s2) {
	size_t len = strlen(s1);
	int i;

	for (i = 0; s2[i] != '\0'; i++) {
		s1[len + i] = s2[i];
	}
	s1[len + i] = '\0';
	return s1;
}

// char *strncat (char *__restrict __dest, const char *__restrict __src, size_t __n)
char *strncat(char *s1, char *s2, size_t n) {
        size_t len = strlen(s1);
        int i;

        for (i = 0; s2[i] != '\0' && i < n; i++) {
                s1[len + i] = s2[i];
        }
        s1[len + i] = '\0';
        return s1;
}

// char *strchr (char *__s, int __c)
char *strchr(char *s, int c) {
	int i = 0;

	while (s[i] != '\0') {
		if (s[i] == c) {
			return &s[i];
		}
		i++;
	}
	return NULL;
}

// int strcmp (const char *__s1, const char *__s2)
int strcmp(const char *s1, const char *s2) {
	int i = 0;
	int diff = 0;

	while (s1[i] == s2[i]) {
		i++;
	}
	diff = s1[i] - s2[i];
	return diff;
}

// int strncmp (const char *__s1, const char *__s2, size_t __n)
int strncmp(const char *s1, const char *s2, size_t n) {
	int i = 0;
	int diff = 0;

	while (s1[i] == s2[i] && i < n) {
		i++;
	}
	diff = s1[i] - s2[i];
	return diff;
}

// size_t strcspn (const char *__s, const char *__reject)
size_t strcspn(const char *s, const char *reject) {
	size_t j = 0;
	int k = 0;

	while (s[j] != '\0') {
		while (reject[k] != '\0') {
			if (s[j] == reject[k]) {
				return j + 1;
			}
			k++;
		}
		k = 0;
		j++;
	}

	return j + 1;
}

// char *strpbrk (char *__s, const char *__accept)
char *strpbrk(char *s, char *accept) {
	int i = 0;
	int j = 0;

	while (s[i] != '\0') {
		while (accept[j] != '\0') {
			if (s[i] == accept[j]) {
				return s[i];
			}
			j++;
		}
		j = 0;
		i++;
	}

	return s[i];
}

// size_t strspn (const char *__s, const char *__accept)
size_t strspn(const char *s, const char *accept) {
	size_t i = 0;

	while ((s[i] != '\0' || accept[i] != '\0') && (s[i] == accept[i])) {
		i++;
	}

	return i;
}

// char *strstr (char *__haystack, const char *__needle)
char *strstr(char *haystack, const char *needle) {
	int i = 0;
	int j = 0;
	int k = 0;
	size_t len = strlen(needle);

	while (haystack[i] != '\0') {
		// beginning of possible matching substring
		if (haystack[i] == needle[j]) {
			k = i;
			while (haystack[k] == needle[j]) {
				k++;
				j++;
			}
		}
		if (needle[j] == '\0') {
			return &haystack[i];
		}
		k = 0;
		j = 0;
		i++;
	}
	
	return NULL;
}

int main() {
	char *str = "grant";

	printf("input -> '%s' len -> %zu\n", str, strlen(str));

	char d[] = "ok this is the end";
	printf("src -> '%s'\nattempting copy to '%s'\n", str, d);
	strcpy(d, str);
	printf("dest -> '%s'\n", d);

	char e[] = "holly is my last name";
	size_t nChars = 5;
	printf("src -> '%s'\nattempting copy of '%zu' chars to '%s'\n", str, nChars, e);
	strncpy(e, str, nChars);
	printf("%s\n", e);

	char str1[] = "grant";
	char str2[] = " holly";
	printf("concatenating '%s' and '%s'\n", str1, str2);
	strcat(str1, str2);
	printf("'%s'\n", str1);

	char name[] = "carrie";
	char lname[] = " holly";
	size_t nChar = 4;
	printf("contatenating '%s' and '%s' limited to %zu chars\n", name, lname, nChar);
	strncat(name, lname, nChar);
	printf("'%s'\n", name);

	char searchString[] = "search this string";
	char ch = 't';
	printf("searching '%s' for first '%c'\n", searchString, ch);
	char *found = strchr(searchString, ch);
	printf("found first '%c' in string '%s'\n", ch, searchString);
	printf("the remainder of '%s' at cahr '%c' is %s\n", searchString, ch, found);

	char *as = "aaa";
	char *bs = "bbb";
	int strdiff;

	strdiff = strcmp(as, bs);
	printf("comparing '%s' and '%s' resulting in a diff of '%d'\n", as, bs, strdiff);
	strdiff = strcmp(as, as);
	printf("comparing '%s' and '%s' resulting in a diff of '%d'\n", as, as, strdiff);
	strdiff = strcmp(bs, as);
	printf("comparing '%s' and '%s' resulting in a diff of '%d'\n", bs, as, strdiff);

	size_t strncmpChars = 2;
	strdiff = strncmp(as, bs, strncmpChars);
        printf("comparing '%s' and '%s' up to '%zu' chars resulting in a diff of '%d'\n", as, bs, strncmpChars, strdiff);
	strdiff = strncmp(as, as, strncmpChars);
        printf("comparing '%s' and '%s' up to '%zu' chars resulting in a diff of '%d'\n", as, as, strncmpChars, strdiff);
	strdiff = strncmp(bs, as, strncmpChars);
        printf("comparing '%s' and '%s' up to '%zu' chars resulting in a diff of '%d'\n", as, bs, strncmpChars, strdiff);

	char *check = "this might contain one or more stop characters";
	char *stopChars = "az";
	size_t unmatched;

	unmatched = strcspn(check, stopChars);
	printf("found stop char from '%s' in '%s' and length of unmatched chars is %zu\n", stopChars, check, unmatched);

	char *scanThis = "this is the main string to scan";
	char *matchThis = "this is the second string";
	size_t matched;

	matched = strspn(scanThis, matchThis);
	printf("'%s' matched '%s' to %zu chars\n", scanThis, matchThis, matched);

	char *here = "zzzzzzzzzzzzzzrrr";
	char *there = "rr";
	printf("searching for first substring '%s' in '%s' and found start at '%s'\n", there, here, strstr(here, there));
}
