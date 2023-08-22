/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:38:07 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/21 16:05:17 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
/*==================| parte 1 |======================*/

/* Checks if the character is a printable character in ASCII. */
int		ft_isprint(int C);

/* Checks if the character belongs to the ASCII table. */
int		ft_isascii(int C);

/* It is alphabetical and numeric. */
int		ft_isalnum(int C);

/* It is alphabetical. */
int		ft_isalpha(int C);

/* It is numeric. */
int		ft_isdigit(int C);

/* Converts a lowercase letter to uppercase. */
int		ft_toupper(int C);

/* Converts an uppercase letter to lowercase. */
int		ft_tolower(int C);

/* Sets a certain number of bytes in memory to the specified value. */
void	*ft_memset(void *stg, int C, size_t size);

/* Copies a specified number of bytes from source to destination. */
void	*ft_memcpy(void *dest, const void *src, size_t size);

/* Copies a specified number of bytes from source to
destination, handling overlapping memory areas. */
void	*ft_memmove(void *dest, const void *src, size_t size);

/* Returns the string starting from the first character
found in a given number of bytes. */
void	*ft_memchr(const void *stg, int C, size_t num);

/* Copy bytes until a specific character,
returning a pointer if found, otherwise NULL.*/ 
void	*ft_memccpy(void *dest, const void *src, int C, size_t num);

/* Is a function that compares two memory regions byte by byte.*/
int		ft_memcmp(const void *stg_01, const void *stg_02, size_t size);

/* Safely copies a string, preventing buffer overflow,
by specifying the destination buffer's size.*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/* Sets a specified number of bytes in memory to 0. */
void	ft_bzero(void *dest, size_t size);

/* Safely concatenates strings, preventing buffer overflow, by
specifying the destination buffer's size.*/
size_t	ft_strlcat(char *dest, const char *src, size_t size);

/* Length of a string */
size_t	ft_strlen(const char *stg);

/* Returns the string from the first character found. */
char	*ft_strchr(const char *stg, int C);

/* Returns the string from the last character found. */
char	*ft_strrchr(const char *stg, int C);

/* Copies a string.*/
char	*ft_strcpy(char *s1, char *s2);

/* Compares a certain quantity of bytes */
int		ft_strncmp(const char *stg_01, const char *stg_02, size_t size);

/* Finds the first occurrence of a substring within a string,
limiting the search to a specified number of bytes. */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/* Converts a string representation of an integer to an integer value. */
int		ft_atoi(const char *stg);

/* Allocates memory for an array of 'count' elements,
each of 'size' bytes, and initializes the memory to zero. */
void	*ft_calloc(size_t count, size_t size);

/* Creates a duplicate of the input string 'stg'. */
char	*ft_strdup(const char *stg);

/*==================| parte 2 |======================*/

/* Writes a character 'C' to a file descriptor 'fd'. */
void	ft_putchar_fd(char C, int fd);

/* Writes the integer 'num' to a file descriptor 'fd'. */
void	ft_putnbr_fd(int num, int fd);

/* Writes the string 'stg' to a file descriptor 'fd'. */
void	ft_putstr_fd(char *stg, int fd);

/* Writes the string 'stg' followed by a newline to a file descriptor 'fd'. */
void	ft_putendl_fd(char *stg, int fd);

/* Converts an integer 'n' to a string representation. */
char	*ft_itoa(int n);

/* Allocates memory for a new string containing the substring 
   of 'stg' starting from 'start' index and having 'len' characters. */
char	*ft_substr(const char *stg, unsigned int start, size_t len);

/* Applies the function 'func' to each character of the string 'stg'. 
   Creates a new string from the results and returns it. */
char	*ft_strmapi(char const *stg, char (*funcion)(unsigned int, char));

/* Trims leading and trailing characters specified by the set 'set' 
   from the string 's1'. Returns a new trimmed string. */
char	*ft_strtrim(char const *s1, char const *set);

/* Trims leading and trailing characters specified by the set 'set' 
   from the string 'stg_1'. Returns a new trimmed string. */
char	*ft_strtrim(char const *stg_1, char const *set);

/* Concatenates two strings 'stg_01' and 'stg_02' into a new string. */
char	*ft_strjoin(char const *stg_01, char const *stg_02);

/* Splits the string 's' into an array of strings using the character 'c' 
   as a delimiter. Returns the array of substrings. */
char	**ft_split(char const *s, char c);

/* Applies a function 'f' to each character of the string 's'. */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif /*LIBFT*/


