#include "minishell.h"

static int	ft_count_words(char *s, char c)
{
	int	i;
	int	word;
	int cot;

	word = 0;
	i = 0;
	cot = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
		{
			cot = s[i];
			i++;
			while (s[i])
			{
				if(s[i] == cot)
					break;
				i++;
			}
		}
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static int	ft_is_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static void	ft_alocate(char **tab, char *s, char c, int w)
{
	int	i;
	int	a;
	int	j;
	int cot;

	i = 0;
	j = 0;
	a = 0;
	cot = 0;
	while (j < w)
	{
		i = 0;
		while (ft_is_sep(s[a], c))
			a++;
		while (ft_is_sep(s[a + i], c) == 0)
		{
			if (s[a + i] == 34 || s[a + i] == 39)
			{
				cot = s[a + i];
				i++;
				while (s[a + i + 1])
				{
					if(s[a + i + 1] == cot)
					{
						i++;
						break;
					}
					i++;
				}
			}
			if (ft_is_sep(s[a + i + 1], c) || s[a + 1 + i] == '\0')
			{
				i++;
				tab[j] = (char *)malloc(i + 1);
				a = a + i;
				break ;
			}
			i++;
		}
		j++;
	}
}

static void	ft_fill_split(char **tab, char *s, char c)
{
	int	i;
	int	j;
	int	a;
	int	skip;
	int cot;

	j = 0;
	i = 0;
	skip = 0;
	cot = 0;
	while (tab[j])
	{
		a = 0;
		while (ft_is_sep(s[i + skip], c) && s[i])
			skip++;
		if (!ft_is_sep(s[i + skip], c) && s[i])
		{
			while (!ft_is_sep(s[i + skip], c) && s[i + skip])
			{
				if(s[i + skip] == 34 || s[i + skip] == 39)
				{
					cot = s[skip + i];
					while (s[i + skip])
					{
						tab[j][a] = s[i + skip];
						i++;
						a++;
						if (s[i + skip] == cot)
							break;
					}
				}
				if (s[i + skip])
				{
					tab[j][a] = s[i + skip];
					i++;
					a++;
				}
			}
			tab[j][a] = '\0';
		}
		j++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		total_words;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	total_words = ft_count_words((char *)s, c);
	printf("%d\n", total_words);
	tab = (char **)malloc(sizeof(char *) * (total_words + 1));
	if (!tab)
		return (NULL);
	tab[total_words] = NULL;
	ft_alocate(tab, (char *)s, c, total_words);
	ft_fill_split(tab, (char *)s, c);
	return (tab);
}