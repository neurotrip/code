#include <ctype.h>
#include <limits.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "/home/code/Kerrisk_Linux/lib/print_wait_status.h"
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

#define POPEN_FMT "/bin/ls -d %s 2> /dev/null"
#define PAT_SIZE 50
#define PCMD_BUF_SIZE (sizeof(POPEN_FMT) + PAT_SIZE)

int main(int argc, char *argv[])
{
	char pat[PAT_SIZE];
	char popenCmd[PCMD_BUF_SIZE];
	FILE *fp;
	Boolean badPattern;
	int len, status, fileCnt, j;
	char pathname[PATH_MAX];

	for (;;) {
		printf("pattern: ");
		fflush(stdout);
		if (fgets(pat, PAT_SIZE, stdin) == NULL)
			break;
		len = strlen(pat);
		if (len <= 1)
			continue;

		if (pat[len - 1] == '\n')
			pat[len - 1] = '\0';

		for (j = 0, badPattern = FALSE; j < len && !badPattern; j++)
			if (!isalnum((unsigned char) pat[j]) &&
					strchr("_*?[^-].", pat[j]) == NULL)
				badPattern = TRUE;

		if (badPattern) {
			printf("Bad pattern character: %c\n", pat[j - 1]);
			continue;
		}

		snprintf(popenCmd, PCMD_BUF_SIZE, POPEN_FMT, pat);
		popenCmd[PCMD_BUF_SIZE - 1] = '\0';

		fp = popen(popenCmd, "r");
		if (fp == NULL) {
			printf("popen() failed\n");
			continue;
		}
		
		fileCnt = 0;
		while(fgets(pathname, PATH_MAX, fp) != NULL) {
			printf("%s", pathname);
			fileCnt++;
		}

		status = pclose(fp);
		printf(" 	%d matching file%s\n", fileCnt,
				(fileCnt != 1) ? "s" : "");
		printf(" 	pclose() status = %#x\n", (unsigned int) status);
		if (status != -1)
			printWaitStatus("\t", status);
	}

	exit(EXIT_SUCCESS);
}

