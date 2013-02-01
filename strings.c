/* strings.c */
#include <stdio.h>
#include <string.h>

char str1[10];			/* This reserves space for 10 characters */
char str2[10];
char str3[] = "initial text";	/* str3 is set to the right size for you
				 * and automatically terminated with a 0
				 * byte. You can only initialise
				 * strings this way when defining.
				 */
char *c_ptr;			/* declares a pointer, but doesn't initialise it. */

unsigned int len;

main()
{
	/* copy "hello" into str1. If str1 isn't big enough, hard luck */
	strcpy(str1, "hello");
	/* if you looked at memory location str1 you'd see these byte
	   values:  'h','e','l','l','o','\0'
	 */

	/* concatenate " sir" onto str1. If str1 is too small, hard luck */
	strcat(str1, " sir");
	/* values at str1 :  'h','e','l','l','o',' ','s','i','r','\0'
	 */

	len = strlen(str1);	/* find the number of characters */
	printf("Length of <%s> is %d characters\n", str1, len);

	if (strcmp(str1, str3))
		printf("<%s> and <%s> are different\n", str1, str3);
	else
		printf("<%s> and <%s> are the same\n", str1, str3);

	if (strstr(str1, "boy") == (char *)NULL)
		printf("The string <boy> isn't in <%s>\n", str1);
	else
		printf("The string <boy> is in <%s>\n", str1);

	/* find the first `o' in str1 */
	c_ptr = strchr(str1, 'o');

	if (c_ptr == (char *)NULL)
		printf("There is no o in <%s>\n", str1);
	else {
		printf("<%s> is from the first o in <%s> to the end.\n", c_ptr,
		       str1);
		/* Now copy this part of str1 into str2 */
		strcpy(str2, c_ptr);
	}
}
