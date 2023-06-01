#include <stdio.h>

void main()
{
    FILE *fp = fopen("Data.bin", "wb+");
    char *ch = "Binary file handling is a fundamental aspect of computer programming that revolves around the manipulation of binary files. These files store data in a machine-readable format consisting of 0s and 1s, unlike text files that store data in a human-readable format. Binary files are commonly used to store complex data structures, such as images, audio files, videos, or serialized objects. The process of binary file handling involves several important steps. It begins with opening the binary file in the desired mode, whether it is for reading or writing. Opening the file grants access to its contents for subsequent operations. Once the file is opened, various operations can be performed, such as reading data from the file or writing data to it. Reading data from a binary file entails specifying the data type and the number of bytes to be read. This allows for precise retrieval of information. Similarly, when writing data to a binary file, the data needs to be converted into its binary representation before being written. Seeking to specific positions within the file is also an important aspect of binary file handling, enabling the ability to read or write data at desired locations. Proper error handling techniques should be implemented throughout the process to handle any unexpected situations that may arise. Once all necessary operations are completed, it is crucial to close the file to release system resources and ensure that any changes made to the file are saved. Binary file handling is a critical skill for working with complex data structures and file formats, facilitating accurate and efficient manipulation of binary data.";
    fwrite(ch, sizeof(char), sizeof(ch), fp);
    char ch1[100], ch2[10];
    fseek(fp, -100, SEEK_END);
    fread(ch1, sizeof(char), 100, fp);
    fseek(fp, 0, SEEK_SET);
    fread(ch2, sizeof(char), 10, fp);
    printf("%s %s", ch1, ch2);
    fclose(fp);
}
