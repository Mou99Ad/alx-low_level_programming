/* 100-elf_header.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/**
 * main - Displays the ELF header of an ELF file.
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 * Return: 0 if successful, 98 if there's an error.
 */
int main(int argc, char *argv[])
{
	int fd;
	int i;
	Elf64_Ehdr elf_header;

	/* Check for correct number of arguments */
	if (argc != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	/* Open the ELF file */
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}

	/* Read and verify ELF header */
	if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		close(fd);
		exit(98);
	}

	/* Check for ELF magic number */
	if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		dprintf(2, "Error: Not an ELF file: %s\n", argv[1]);
		close(fd);
		exit(98);
	}

	/* Display ELF header information */
	printf("ELF Header:\n");
	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", elf_header.e_ident[i], i < EI_NIDENT - 1 ? ' ' : '\n');
	printf("  Class:                             %s\n",
			elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
			(elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "Invalid ELF class"));
	printf("  Data:                              %s\n",
			elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
			(elf_header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Invalid data encoding"));
	printf("  Version:                           %d (current)\n", elf_header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
			elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
			(elf_header.e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
			 (elf_header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
			  (elf_header.e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" : "Unknown"))));
	printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
			elf_header.e_type == ET_NONE ? "NONE (No file type)" :
			(elf_header.e_type == ET_REL ? "REL (Relocatable file)" :
			 (elf_header.e_type == ET_EXEC ? "EXEC (Executable file)" :
			  (elf_header.e_type == ET_DYN ? "DYN (Shared object file)" :
			   (elf_header.e_type == ET_CORE ? "CORE (Core file)" : "Unknown")))));
	printf("  Entry point address:               %#lx\n", (unsigned long)elf_header.e_entry);

	/* Cleanup and exit */
	close(fd);
	return (0);
}
