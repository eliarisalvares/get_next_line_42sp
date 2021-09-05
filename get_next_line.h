/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:55:11 by elraira-          #+#    #+#             */
/*   Updated: 2021/09/03 14:27:47 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/**
 * @brief computes the length of the string str up to, but not including
 * the terminating null character.
 *
 * @param str this is the string whose length is to be found.
 * @return size_t this function returns the length of string.
 */
size_t			ft_strlen(const char *str);

/**
 * @brief searches for first occurrence of "c" in the string *str
 *
 * @param str the string
 * @param c character to be checked
 * @return char*, a pointer to the first occurrence of character c in *str or
 * NULL if the character is not found. The terminating null byte is considered
 * part of the string.
 */
char			*ft_strchr(const char *str, int c);

/**
 * @brief  copies up to size - 1 characters from the NUL-terminated string src
 * to dst, NUL-terminating the result.
 *
 * @param dest destination string
 * @param src source string
 * @param size (dest) nothing will be written beyond dest + size - 1.
 * @return size_t, the total length of the string it tried to create (entire
 * source string)
 */
size_t			ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief returns a pointer to a new string duplicated of the string s. Memory
 *for the new string is obtained with malloc
 *
 * @param s1 the string which will be duplicated
 * @return char*, a pointer to the new string
 */
char			*ft_strdup(const char *s1);

/**
 * @brief allocates (with malloc) and returns a substring from the string 's'.
 * The substring begins at index 'start' and is of maximum size ’len’.
 *
 * @param s the string from which to create the substring.
 * @param start the start index of the substring in the string 's'.
 * @param len the maximum length of the substring.
 * @return char*, the substring. NULL if the allocation fails.
 */
char			*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates (with malloc) and returns a new string, which is the result
 * of the concatenation of ’s1’ and ’s2’.
 *
 * @param s1 the prefix string.
 * @param s2 the suffix string.
 * @return char* the new string. NULL if the allocation fails
 */
char			*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Reads a file from a file descriptor
 *
 * @param fd file descriptor to read from
 * @return char* a line read from a file descriptor, if NULL: nothing else to
 * read or error
 */
char			*get_next_line(int fd);

#endif
