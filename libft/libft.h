/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:49:55 by tramants          #+#    #+#             */
/*   Updated: 2018/06/14 16:27:41 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(const char *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_strsplit(char const *s, char c);
char	*ft_strchr(char *s, int c);
char	*ft_strrchr(char *s, int c);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strdup(char *s1);
int		ft_strlen(const char *str);
int		ft_wordcountdel(const char *str, char c);
int		ft_wordlendel(const char *str, char c);
size_t	ft_nbrlen(int num);
char	*ft_itoa(int n);
char	**ft_strsplit(char const *s, char c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(char *haystack, const char *needle, size_t len);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	ft_strclr(char *s);
void	ft_memdel(void **ap);
void	ft_strdel(char **as);
char	*ft_strnew(size_t size);
char	*ft_strtrim(char const *s);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_spacecount(char const *str);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

#endif
