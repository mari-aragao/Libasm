#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int	main(void)
{
	int fd;
	ssize_t ret1, ret_ft, ret_libc;
	char buffer[100];
	char dst1[500], dst2[500];

	printf("-----------------------------------------------------------------------------------\n\n");
	
	// Teste ft_strlen
	printf("*********** ft_strlen ***********\n\n");

	// Teste 1: String comum
	printf("--- Teste 1: String comum\n");
	printf("ft_strlen(\"Hello\") = %zu\n", ft_strlen("Hello"));
	printf("strlen(\"Hello\")    = %zu\n\n", strlen("Hello"));

	// Teste 2: String vazia
	printf("--- Teste 2: String vazia\n");
	printf("ft_strlen(\"\") = %zu\n", ft_strlen(""));
	printf("strlen(\"\")    = %zu\n\n", strlen(""));

	// Teste 3: String longa
	printf("--- Teste 3: String grande\n");
	const char *long_str = "Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.";
	printf("ft_strlen(\"Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.\") = %zu\n", ft_strlen(long_str));
	printf("strlen(\"Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.\")    = %zu\n\n", strlen(long_str));


	printf("-----------------------------------------------------------------------------------\n\n");

	// Teste ft_strcpy
	printf("*********** ft_strcpy ***********\n\n");

	char src1[] = "Copy this!";

	// Teste 1: String comum
	printf("--- Teste 1: String comum\n");

	memset(dst1, 0, sizeof(dst1));
	memset(dst2, 0, sizeof(dst2));

	printf("ft_strcpy: %s\n", ft_strcpy(dst1, src1));
	printf("strcpy:    %s\n\n", strcpy(dst2, src1));

	// Teste 2: String vazia
	printf("--- Teste 2: String vazia\n");

	memset(dst1, 0, sizeof(dst1));
	memset(dst2, 0, sizeof(dst2));

	char src2[] = "";
	printf("ft_strcpy: %s\n", ft_strcpy(dst1, src2));
	printf("strcpy:    %s\n\n", strcpy(dst2, src2));

	printf("--- Teste 3: String grande\n");
	char src4[] = "Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.";

	memset(dst1, 0, sizeof(dst1));
	memset(dst2, 0, sizeof(dst2));

	printf("ft_strcpy: %s\n", ft_strcpy(dst1, src4));
	printf("strcpy:    %s\n\n", strcpy(dst2, src4));

	printf("-----------------------------------------------------------------------------------\n\n");

	// Teste ft_strcmp
	printf("*********** ft_strcmp ***********\n\n");

	// Teste 1: Strings iguais
	printf("--- Teste 1: Strings iguais\n");
	printf("ft_strcmp(\"abc\", \"abc\") = %d\n", ft_strcmp("abc", "abc"));
	printf("strcmp(\"abc\", \"abc\")    = %d\n\n", strcmp("abc", "abc"));

	//teste 2 : strings vazias
	printf("--- Teste 2: Strings vazias\n");
	printf("ft_strcmp(\"\", \"\") = %d\n", ft_strcmp("", ""));
	printf("strcmp(\"\", \"\")    = %d\n\n", strcmp("", ""));


	// Teste 3: Primeira string vazia
	printf("--- Teste 3: Primeira string vazia\n");
	printf("ft_strcmp(\"\", \"abc\") = %d\n", ft_strcmp("", "abc"));
	printf("strcmp(\"\", \"abc\")    = %d\n\n", strcmp("", "abc"));

	//Teste 4: Segunda string vazia
	printf("--- Teste 4: Segunda string vazia\n");
	printf("ft_strcmp(\"abc\", \"\") = %d\n", ft_strcmp("abc", ""));
	printf("strcmp(\"abc\", \"\")    = %d\n\n", strcmp("abc", ""));

	// Teste 5: String s1 maior que s2
	printf("--- Teste 5: String s1 maior que s2\n");
	printf("ft_strcmp(\"abc\", \"ABC\") = %d\n", ft_strcmp("abc", "ABC"));
	printf("strcmp(\"abc\", \"ABC\")    = %d\n\n", strcmp("abc", "ABC"));


	// Teste 6: String s1 menor que s2
	printf("--- Teste 6: String s1 menor que s2\n");
	printf("ft_strcmp(\"ABC\", \"abc\") = %d\n", ft_strcmp("ABC", "abc"));
	printf("strcmp(\"ABC\", \"abc\")    = %d\n\n", strcmp("ABC", "abc"));


	printf("-----------------------------------------------------------------------------------\n\n");

	// Teste ft_write
	printf("*********** ft_write ***********\n\n");

	// Teste 1: Escrita normal no stdout
	printf("--- Teste 1: Escrever no stdout\n");
	ret1 = ft_write(1, "ft_write: Hello World!\n", 23);
	printf("ret = %zd\n", ret1);
	ret1 = write(1, "write:    Hello World!\n", 23);
	printf("ret = %zd\n\n", ret1);

	// Teste 2: Escrita em um arquivo valido
	printf("--- Teste 2: Escrever em um fd aberto\n");
	fd = open("write_test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		perror("open");
	else {
		ret_ft = ft_write(fd, "ft_write: File test\n", 21);
		printf("ft_write ret = %zd\n", ret_ft);
		ret_libc = write(fd, "write:    File test\n", 21);
		printf("write ret    = %zd\n", ret_libc);
		close(fd);
	}
	printf("\n");

	// Teste 3: Escrever com fd inválido
	printf("--- Teste 3: Escrever com fd inválido\n");
	ret_ft = ft_write(-1, "test", 4);
	printf("ft_write(-1): ret = %zd | errno = %d\n", ret_ft, errno);
	perror("ft_write");

	ret_libc = write(-1, "test", 4);
	printf("write(-1):    ret = %zd | errno = %d\n", ret_libc, errno);
	perror("write");
	printf("\n");

	// Teste 3: Escrita zero bytes
	printf("--- Teste 4: Escrever zero bytes\n");
	ret1 = ft_write(1, "should not print", 0);
	printf("ft_write (0 bytes): ret = %zd\n", ret1);
	ret1 = write(1, "should not print", 0);
	printf("write (0 bytes):    ret = %zd\n\n", ret1);

	// Teste 4: Escrita em stderr
	printf("--- Teste 5: Escrever no stderr\n");
	ret1 = ft_write(2, "ft_write to stderr\n", 19);
	printf("ret = %zd\n", ret1);
	ret1 = write(2, "   write to stderr\n", 19);
	printf("ret = %zd\n\n", ret1);

	// Teste 4: Comparar valores retornados
	printf("--- Teste 6: Checar retorno com mesma entrada\n");
	const char *msg = "compare return values\n";
	ret_ft = ft_write(1, msg, 23);
	ret_libc = write(1, msg, 23);
	printf("ft_write ret = %zd | write ret = %zd\n\n", ret_ft, ret_libc);

	printf("-----------------------------------------------------------------------------------\n\n");

	printf("*********** ft_read ***********\n\n");
	
	// Teste 1: Ler do stdin
	printf("--- Teste 1: Ler do stdin (digite algo e pressione Enter)\n");
	printf("ft_read: ");
	ret_ft = ft_read(0, buffer, sizeof(buffer) - 1);
	buffer[ret_ft > 0 ? ret_ft : 0] = '\0';
	printf("ret = %zd | input = \"%s\"\n", ret_ft, buffer);

	printf("read:    ");
	ret_libc = read(0, buffer, sizeof(buffer) - 1);
	buffer[ret_libc > 0 ? ret_libc : 0] = '\0';
	printf("ret = %zd | input = \"%s\"\n\n", ret_libc, buffer);

	// Teste 2: Ler de um fd aberto (arquivo)
	printf("--- Teste 2: Ler de um fd aberto (arquivo)\n");
	fd = open("read_test.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0) {
		perror("open");
	} else {
		write(fd, "This is a test.", 16);
		lseek(fd, 0, SEEK_SET); // volta pro início do arquivo

		ret_ft = ft_read(fd, buffer, 16);
		buffer[ret_ft > 0 ? ret_ft : 0] = '\0';
		printf("ft_read: ret = %zd | content = \"%s\"\n", ret_ft, buffer);

		lseek(fd, 0, SEEK_SET);
		ret_libc = read(fd, buffer, 16);
		buffer[ret_libc > 0 ? ret_libc : 0] = '\0';
		printf("read:    ret = %zd | content = \"%s\"\n", ret_libc, buffer);
		close(fd);
	}
	printf("\n");

	// Teste 3: Ler de fd inválido
	printf("--- Teste 3: Ler de um fd inválido\n");
	ret_ft = ft_read(-1, buffer, 10);
	printf("ft_read(-1): ret = %zd | errno = %d\n", ret_ft, errno);
	perror("ft_read");

	ret_libc = read(-1, buffer, 10);
	printf("read(-1):    ret = %zd | errno = %d\n", ret_libc, errno);
	perror("read");
	printf("\n");

	// Teste 4: Comparar valores de retorno com entrada igual
	printf("--- Teste 4: Checar valores de retorno (mesmo arquivo)\n");
	fd = open("read_test.txt", O_RDONLY);
	if (fd < 0) {
		perror("open");
	} else {
		ret_ft = ft_read(fd, buffer, 10);
		printf("ft_read ret = %zd\n", ret_ft);

		lseek(fd, 0, SEEK_SET);
		ret_libc = read(fd, buffer, 10);
		printf("read ret    = %zd\n", ret_libc);
		close(fd);
	}
	printf("\n");
	printf("-----------------------------------------------------------------------------------\n\n");

	// Teste ft_strdup
	printf("*********** ft_strdup ***********\n\n");

	// Teste 1: String comum
	printf("--- Teste 1: String comum\n");
	char *dup1 = ft_strdup("Duplicated string!");
	char *dup2 = strdup("Duplicated string!");
	printf("ft_strdup: %s\n", dup1);
	printf("strdup:    %s\n\n", dup2);
	free(dup1); free(dup2);

	// Teste 2: String vazia
	printf("--- Teste 2: String vazia\n");
	dup1 = ft_strdup("");
	dup2 = strdup("");
	printf("ft_strdup(\"\"): \"%s\"\n", dup1);
	printf("strdup(\"\"):    \"%s\"\n\n", dup2);
	free(dup1); free(dup2);

	// Teste 3: String grande
	printf("--- Teste 3: String grande\n");
	const char *long_dup_str = "Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.";
	dup1 = ft_strdup(long_dup_str);
	dup2 = strdup(long_dup_str);
	printf("ft_strdup: %s\n", dup1);
	printf("strdup:    %s\n\n", dup2);
	free(dup1); free(dup2);
	
	printf("-----------------------------------------------------------------------------------\n");

	return 0;
}
