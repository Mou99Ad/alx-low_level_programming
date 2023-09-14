#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
/**
 * print_error - Prints an error message and exits with the specified status code.
 * @message: The error message to print.
 * @status: The exit status code.
 */
void print_error(const char *message, int status)
{
	dprintf(2, "%s\n", message);
	exit(status);
}

/**
 * main - Displays the information contained in the ELF header of an ELF file.
 * @ac: The number of arguments.
 * @av: An array of argument strings.
 * Return: 0 on success, or the corresponding error code on failure.
 */
int main(int ac, char **av)
{
	int fd;
	int i;
	Elf64_Ehdr header;

	if (ac != 2)
		print_error("Usage: elf_header elf_filename", 98);

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Cannot open file", 98);
	if (read(fd, &header, sizeof(header)) != sizeof(header))
		print_error("Error: Cannot read from file", 98);

	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Error: Not an ELF file", 98);

	printf("ELF Header:\n");
	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", header.e_ident[i], (i < EI_NIDENT - 1) ? ' ' : '\n');

	printf("  Class:                             %s\n", (header.e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n", (header.e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "Unknown");
	printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", (header.e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "Unknown");
	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", (header.e_type == ET_EXEC) ? "EXEC (Executable file)" : "Unknown");
	printf("  Entry point address:               0x%lx\n", header.e_entry);

	close(fd);
	return (0);
}
