#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "/home/code/Kerrisk_Linux/lib/ugid_functions.c" 

#define STATUS_FILE "status"
#define MAX_LINE 256

void listProcessesForUser(const char *username) {
    DIR *proc_dir;
    struct dirent *entry;
    char status_path[MAX_LINE];
    FILE *status_file;
    char line[MAX_LINE];
    uid_t target_uid = userIdFromName(username);

    if (target_uid == -1) {
        fprintf(stderr, "Error: Unable to find UID for user %s\n", username);
        return;
    }

    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Error opening /proc directory");
        return;
    }

    printf("PID\tCommand\n");

    while ((entry = readdir(proc_dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        if (isdigit(entry->d_name[0])) {
            snprintf(status_path, MAX_LINE, "/proc/%s/%s", entry->d_name, STATUS_FILE);
            status_file = fopen(status_path, "r");
            if (status_file != NULL) {
                while (fgets(line, MAX_LINE, status_file) != NULL) {
                    if (strncmp(line, "Uid:", 4) == 0) {
                        uid_t pid_uid;
                        sscanf(line, "Uid:\t%u", &pid_uid);
                        if (pid_uid == target_uid) {
                            printf("%s\t", entry->d_name);
                            while (fgets(line, MAX_LINE, status_file) != NULL) {
                                if (strncmp(line, "Name:", 5) == 0) {
                                    printf("%s", line + 6);
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
                fclose(status_file);
            }
        }
    }

    closedir(proc_dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    listProcessesForUser(argv[1]);
	printf("\n");
    return 0;
}

