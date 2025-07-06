#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int	main(void)
{
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

	// Teste 3: String com espaços
	printf("--- Teste 3: String com espaços\n");
	printf("ft_strlen(\"   space   \") = %zu\n", ft_strlen("   space   "));
	printf("strlen(\"   space   \")    = %zu\n\n", strlen("   space   "));

	// Teste 4: String longa
	printf("--- Teste 4: String grande\n");
	const char *long_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	printf("ft_strlen(\"Lorem ipsum dolor sit amet, consectetur adipiscing elit.\") = %zu\n", ft_strlen(long_str));
	printf("strlen(\"Lorem ipsum dolor sit amet, consectetur adipiscing elit.\")    = %zu\n\n", strlen(long_str));

	// Teste 5: String com caracteres especiais
	// Teste 5: String com caracteres especiais
	// Teste 5: String com caracteres especiais
	printf("--- Teste 5: String com caracteres especiais\n");
	const char *special_str = "\t!@#$%^&*()";
	printf("ft_strlen(\"\\t!@#$%%^&*()\") = %zu\n", ft_strlen(special_str));
	printf("strlen(\"\\t!@#$%%^&*()\")    = %zu\n\n", strlen(special_str));

	printf("-----------------------------------------------------------------------------------\n\n");

	// Teste ft_strcpy
	printf("*********** ft_strcpy ***********\n\n");

	char src1[] = "Copy this!";
	char dst1[50], dst2[50];

	// Teste 1: String comum
	printf("--- Teste 1: String comum\n");
	printf("ft_strcpy: %s\n", ft_strcpy(dst1, src1));
	printf("strcpy:    %s\n\n", strcpy(dst2, src1));

	// Teste 2: String vazia
	printf("--- Teste 2: String vazia\n");
	char src2[] = "";
	printf("ft_strcpy: %s\n", ft_strcpy(dst1, src2));
	printf("strcpy:    %s\n\n", strcpy(dst2, src2));

	// Teste 3: String com caracteres especiais
	printf("--- Teste 3: String com caracteres especiais\n");
	char src3[] = "123\t\tABC";
	printf("ft_strcpy: %s\n", ft_strcpy(dst1, src3));
	printf("strcpy:    %s\n\n", strcpy(dst2, src3));

	// Teste 4: String grande
	printf("--- Teste 4: String grande\n");
	char src4[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	printf("ft_strcpy: %s\n", ft_strcpy(dst1, src4));
	printf("strcpy:    %s\n\n", strcpy(dst2, src4));

	printf("-----------------------------------------------------------------------------------\n\n");

	// Teste ft_strcmp
	printf("*********** ft_strcmp ***********\n\n");

	// Teste 1: Strings iguais
	printf("--- Teste 1: Strings iguais\n");
	printf("ft_strcmp(\"abc\", \"abc\") = %d\n", ft_strcmp("abc", "abc"));
	printf("strcmp(\"abc\", \"abc\")    = %d\n\n", strcmp("abc", "abc"));

	// Teste 2: String s1 maior que s2
	printf("--- Teste 2: String s1 maior que s2\n");
	printf("ft_strcmp(\"abc\", \"ABC\") = %d\n", ft_strcmp("abc", "ABC"));
	printf("strcmp(\"abc\", \"ABC\")    = %d\n\n", strcmp("abc", "ABC"));

	// Teste 3: Uma string vazia
	printf("--- Teste 3: Uma string vazia\n");
	printf("ft_strcmp(\"\", \"test\") = %d\n", ft_strcmp("", "test"));
	printf("strcmp(\"\", \"test\")    = %d\n\n", strcmp("", "test"));

	printf("-----------------------------------------------------------------------------------\n\n");

	// Teste ft_write
	printf("*********** ft_write ***********\n\n");

	// Teste 1: Escrita normal no stdout
	printf("--- Teste 1: Escrever no stdout\n");
	ssize_t ret1 = ft_write(1, "ft_write: Hello World!\n", 23);
	printf("ret = %zd\n", ret1);
	ret1 = write(1, "write:    Hello World!\n", 23);
	printf("ret = %zd\n\n", ret1);

	// Teste 2: Escrita com fd inválido
	printf("--- Teste 2: Escrever com fd inválido\n");
	ret1 = ft_write(-1, "test", 4);
	printf("ft_write(-1): ret = %zd | errno = %d\n", ret1, errno);
	perror("ft_write");

	ret1 = write(-1, "test", 4);
	printf("write(-1): ret = %zd | errno = %d\n", ret1, errno);
	perror("write");
	printf("\n");

	// Teste 3: Escrita zero bytes
	printf("--- Teste 3: Escrever zero bytes\n");
	ret1 = ft_write(1, "should not print", 0);
	printf("ft_write (0 bytes): ret = %zd\n", ret1);
	ret1 = write(1, "should not print", 0);
	printf("write (0 bytes):    ret = %zd\n\n", ret1);

	// Teste 4: Escrita em stderr
	printf("--- Teste 4: Escrever no stderr\n");
	ret1 = ft_write(2, "ft_write to stderr\n", 19);
	printf("ret = %zd\n", ret1);
	ret1 = write(2, "   write to stderr\n", 19);
	printf("ret = %zd\n\n", ret1);

	printf("-----------------------------------------------------------------------------------\n\n");

	printf("*********** ft_read ***********\n\n");
	char buf1[100], buf2[100];

	// Teste 1: Ler de um arquivo válido
	printf("--- Teste 1: Ler arquivo válido\n");
	int fd = open("test/main.c", O_RDONLY);
	if (fd == -1) perror("open");
	ssize_t r1 = ft_read(fd, buf1, 42);
	if (r1 >= 0) buf1[r1] = '\0';
	printf("ft_read (%zd bytes):\n%s\n", r1, buf1);
	close(fd);

	fd = open("test/main.c", O_RDONLY);
	if (fd == -1) perror("open");
	ssize_t r2 = read(fd, buf2, 42);
	if (r2 >= 0) buf2[r2] = '\0';
	printf("read    (%zd bytes):\n%s\n\n", r2, buf2);
	close(fd);

	// Teste 2: FD inválido
	printf("--- Teste 2: Ler FD inválido\n");
	r1 = ft_read(-1, buf1, 10);
	printf("ft_read(-1): %zd | errno = %d\n", r1, errno);
	perror("ft_read");

	r2 = read(-1, buf2, 10);
	printf("read(-1):    %zd | errno = %d\n", r2, errno);
	perror("read");
	printf("\n");

	// Teste 3: Zero bytes
	printf("--- Teste 3: Ler zero bytes\n");
	fd = open("test/main.c", O_RDONLY);
	r1 = ft_read(fd, buf1, 0);
	printf("ft_read (0 bytes): %zd\n", r1);
	r2 = read(fd, buf2, 0);
	printf("read (0 bytes):    %zd\n\n", r2);
	close(fd);

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
	printf("ft_strdup(\"\"): %s\n", dup1);
	printf("strdup(\"\"):    %s\n\n", dup2);
	free(dup1); free(dup2);

	// Teste 3: String com espaços
	printf("--- Teste 3: String com espaços\n");
	dup1 = ft_strdup("   ");
	dup2 = strdup("   ");
	printf("ft_strdup(\"   \"): %s\n", dup1);
	printf("strdup(\"   \"):    %s\n\n", dup2);
	free(dup1); free(dup2);

	// Teste 4: String com caracteres especiais
	printf("--- Teste 4: String com caracteres especiais\n");
	dup1 = ft_strdup("\t!@#$%^&*()");
	dup2 = strdup("\t!@#$%^&*()");
	printf("ft_strdup(\"\\t!@#$%%^&*()\"): %s\n", dup1);
	printf("strdup(\"\\t!@#$%%^&*()\"):    %s\n\n", dup2);
	free(dup1); free(dup2);

	printf("-----------------------------------------------------------------------------------\n");

	return 0;
}
