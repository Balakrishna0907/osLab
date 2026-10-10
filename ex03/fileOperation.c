#include <stdio.h>
#include <fcntl.h> // open()
#include <unistd.h> // read(), write(), close()
#include <sys/stat.h> // stat(), mkdir()
#include <dirent.h> // opendir(), readdir()
#include <string.h> //strlen()
int main()
{
	   int fd; //file descriptor (unique id)
       char buffer[100];
       struct stat fileInfo;
       DIR *dir;
       struct dirent *entry;


       // PART 1: Create and write data into a file using open() and write()
       printf("\n--- Creating and Writing File ---\n");
       /*
       * open() system call:
       * Opens/creates "student.txt".
       * O_CREAT: Creates the file if it doesn't exist.
       * O_WRONLY: Opens the file in write-only mode.
       * 0644: Sets permissions to Owner (Read/Write), Group (Read), Others (Read).
       */
       fd = open("student.txt", O_CREAT | O_WRONLY, 0644);

       /* Checks if open() failed (returns -1 on error) */
       if (fd < 0)
       {
              printf("File creation failed\n");
              return 1;
       }
       char data[] = "Linux System Calls Experiment\n"
                "B.Sc Cyber Security Laboratory";

	   /* write() system call: Writes data string up to its exact length into the file descriptor */
       write(fd, data, strlen(data));

       /* close() system call: Closes the file descriptor to free system resources */
       close(fd);

       printf("Data written successfully\n");

       // PART 2: Read file contents using open() and read()
       printf("\n--- Reading File Content ---\n");
	
       /* open() system call: Opens "student.txt" in read-only mode (O_RDONLY) */
       fd = open("student.txt", O_RDONLY);

       /* Checks if the file failed to open */
       if (fd < 0)
       {
              printf("File opening failed\n");
              return 1;
       }
       /*
        * read() system call:
        * Reads up to 99 bytes from fd into 'buffer'.
        * Leaves 1 byte free at the end for the null-terminator.
        */
       int bytes = read(fd, buffer, sizeof(buffer) - 1);

       /* Safely null-terminates the string at the exact index where reading stopped */
       buffer[bytes] = '\0';
       printf("%s\n", buffer);
	
       close(fd);

       //PART 3: Display file information using stat()
       printf("\n--- File Information ---\n");
       /*
       * stat() system call:
       * Retrieves file metadata for "student.txt" and stores it inside the 'fileInfo' structure.
       * Returns 0 on success.
       */
       if (stat("student.txt", &fileInfo) == 0)
       {
             /* fileInfo.st_size extracts the total file size in bytes */
             printf("File Size : %ld bytes\n", fileInfo.st_size);

             /* fileInfo.st_nlink extracts the number of hard links pointing to this file */
             printf("Number of Links: %ld\n", fileInfo.st_nlink);


			 // fileInfo.st_mode combined with bitwise AND (& 0777) isolates the octal permission bits
             printf("Permissions : %o\n", fileInfo.st_mode & 0777);
       }
       else
       {
             printf("Unable to get file information\n");
       }

       //PART 4: Create directory using mkdir()
       printf("\n--- Creating Directory ---\n");
       /*
       * mkdir() system call:
       * Creates a new directory named "TestDirectory".
       * 0755: Read/Write/Execute for Owner; Read/Execute for Group and Others.
       */
       if (mkdir("TestDirectory", 0755) == 0)
              printf("Directory created successfully\n");
       else
              printf("Directory may already exist\n");


       // PART 5: Display directory contents using opendir() and readdir()
       printf("\n--- Directory Contents ---\n");
       /* opendir() system call: Opens the current directory (".") for reading stream contents */
       dir = opendir(".");
       /* Checks if opening the directory stream failed */
       if (dir == NULL)
       {
              printf("Cannot open directory\n");
              return 1;
       }
       /* readdir() system call loop:
       * Reads directory entries sequentially.
       * Terminates when it hits the end of the directory (returns NULL).     */
       while ((entry = readdir(dir)) != NULL)
       {
              /* entry->d_name accesses the string filename of the current record */
              printf("%s\n", entry->d_name);
       }

       closedir(dir);
       printf("\nProgram completed successfully\n");
       return 0;
}
